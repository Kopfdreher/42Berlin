#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

typedef struct s_map
{
	int 	rows;
	int 	cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
}	t_map;

typedef struct s_bsq
{
	int	size;
	int	r;
	int	c;
}	t_bsq;

void	process_stream(FILE *stream);
int	parse_header(FILE *stream, t_map *map);
int	read_grid(FILE *stream, t_map *map);
void	solve_bsq(t_map *map);
void	free_map(t_map *map);
void	print_map(t_map *map);

static int	min3(int a, int b, int c) {
	int m = a;
	if (b < m) m = b;
	if (c < m) m = c;
	return m;
}

void	free_map(t_map *map) {
	if (!map->grid) return;
	for (int i = 0; i < map->rows; i++) {
		if (map->grid[i]) free(map->grid[i]);
	}
	free(map->grid);
	map->grid = NULL;
}

void	print_map(t_map *map) {
	for (int i = 0; i < map->rows; i++) {
		fputs(map->grid[i], stdout);
		fputs("\n", stdout);
	}
}

int	parse_header(FILE *stream, t_map *map) {
	char *line = NULL;
	size_t cap = 0;
	ssize_t len = getline(&line, &cap, stream);

	if (len <= 0) {
		free(line);
		return 0;
	}

	// Strip trailing newline
	if (line[len - 1] == '\n') line[len - 1] = '\0';

	// Parse space-separated line: "9 . o x"
	int count = sscanf(line, "%d %c %c %c", &map->rows, &map->empty, &map->obstacle, &map->full);
	free(line);

	if (count != 4 || map->rows <= 0) return 0;

	// All chars must be unique
	if (map->empty == map->obstacle || map->empty == map->full || map->obstacle == map->full)
		return 0;
	if (map->empty == '\0' || map->obstacle == '\0'  || map->full == '\0')
		return 0;
	return 1;
}

int	read_grid(FILE *stream, t_map *map) {
	map->grid = calloc(map->rows, sizeof(char *));
	if (!map->grid) return (0);

	char *line = NULL;
	size_t cap = 0;
	map->cols = 0;

	for (int i = 0; i < map->rows; i++) {
		int len = (int)getline(&line, &cap, stream);
		if (len <= 0) {
			free(line);
			return 0;
		}

		// validate line break requirement
		if (line[len -1] != '\n') {
			free(line);
			return 0;
		}
		line[len - 1] = '\0';
		len--;

		// validate column dimensions/content
		if (i == 0) {
			map->cols = len;
			if (map->cols <= 0) {
				free(line);
				return 0;
			}
		} else if (len != map->cols) {
			free(line);
			return 0;
		}

		for (int j = 0; j < map->cols; j++) {
			if (line[j] != map->empty && line[j] != map->obstacle) {
				free(line);
				return 0;
			}
		}

		map->grid[i] = malloc((map->cols + 1) * sizeof(char));
		if (!map->grid[i]) {
			free(line);
			return 0;
		}

		for (int j = 0; j <= map->cols; j++)
			map->grid[i][j] = line[j];
	}

	ssize_t extra = getline(&line, &cap, stream);
	free(line);
	if (extra > 0) return 0;
	return 1;
}

void	solve_bsq(t_map *map) {
	// Alloc DP buffer
	int *prev = calloc(map->cols, sizeof(int));
	int *curr = calloc(map->cols, sizeof(int));
	if (!prev || !curr) {
		free(prev);
		free(curr);
		return;
	}

	t_bsq best = {0, -1, -1};
	for (int i = 0; i < map->rows; i++) {
		for (int j = 0; j < map->cols; j++) {
			if (map->grid[i][j] == map->obstacle) curr[j] = 0;
			else if (i == 0 || j == 0) curr[j] = 1;
			else curr[j] = 1 + min3(prev[j], curr[j - 1], prev[j - 1]);
			if (curr[j] > best.size) {
				best.size = curr[j];
				best.r = i;
				best.c = j;
			}
		}
		for (int j = 0; j < map->cols; j++) prev[j] = curr[j];
	}
	free(prev);
	free(curr);

	// Fill largest square
	if (best.size > 0) {
		int start_r = best.r - best.size + 1;
		int start_c = best.c - best.size + 1;
		for (int r = start_r; r <= best.r; r++) {
			for (int c = start_c; c <= best.c; c++)
				map->grid[r][c] = map->full;
		}
	}
}

void	process_stream(FILE *stream) {
	t_map	map;

	map.grid = NULL;
	if (!parse_header(stream, &map) || !read_grid(stream, &map)) {
		fprintf(stderr, "map error\n");
		free_map(&map);
		return;
	}

	solve_bsq(&map);
	print_map(&map);
	free_map(&map);
}

int main(int argc, char **argv)
{
	if (argc == 1) process_stream(stdin);
	else {
		for (int i = 1; i < argc; i++) {
			FILE *f = fopen(argv[i], "r");
			if (!f) fprintf(stderr, "map error\n");
			else {
				process_stream(f);
				fclose(f);
			}
		}
	}
}
