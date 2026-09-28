#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_game {
	int 	width;
	int	height;
	int	iterations;
	int	i;
	int	j;
	int	draw;
	char	alive;
	char	dead;
	char	**board;
} 	t_game;

void	free_board(t_game *game) {
	if (game->board) {
		for (int i = 0; i < game->height; i++) {
			if (game->board[i]) free(game->board[i]);
		}
		free(game->board);
		game->board = NULL;
	}
}

int	init_game(t_game *game, char **argv) {
	game->width = atoi(argv[1]);
	game->height = atoi(argv[2]);
	game->iterations = atoi(argv[3]);
	game->alive = 'O';
	game->dead = ' ';
	game->i = 0;
	game->j = 0;
	game->draw = 0;

	game->board = (char **)malloc(game->height * sizeof(char *));
	if (!game->board) return (-1);

	for (int i = 0; i < game->height; i++) {
		game->board[i] = (char *)malloc(game->width * sizeof(char));
		if (!game->board[i]) {
			free_board(game);
			return -1;
		}
		for (int j = 0; j < game->width; j++)
			game->board[i][j] = game->dead;
	}
	return 0;
}

void	fill_board(t_game *game) {
	char buffer;

	while (read(STDIN_FILENO, &buffer, 1) == 1) {
		if (buffer == 'w' && game->i > 0) 
			game->i--;
		else if (buffer == 's' && game->i < game->height - 1)
			game->i++;
		else if (buffer == 'a' && game->j > 0)
			game->j--;
		else if (buffer == 'd' && game->j < game->width - 1)
			game->j++;
		else if (buffer == 'x')
			game->draw = !(game->draw);

		if (game->draw)
			game->board[game->i][game->j] = game->alive;
	}
}

int	count_neighbors(t_game *game, int i, int j) {
	int count = 0;

	for (int di = -1; di <= 1; di++) {
		for (int dj = -1; dj <= 1; dj++) {
			if (di == 0 && dj == 0) continue;

			int ni = i + di;
			int nj = j + dj;

			if (ni >= 0 && ni < game->height && nj >= 0 && nj < game->width) {
				if (game->board[ni][nj] == game->alive) count++;
			}
		}
	}
	return count;
}

int	play(t_game *game) {
	char **temp = (char **)malloc(game->height * sizeof(char *));
	if (!temp) return -1;

	for (int i = 0; i < game->height; i ++) {
		temp[i] = (char *)malloc(game->width * sizeof(char));
		if (!temp[i]) {
			for (int k = 0; k < i; k++) free(temp[k]);
			free(temp);
			return (-1);
		}
	}

	for (int i = 0; i < game->height; i++) {
		for (int j = 0; j < game->width; j++) {
			int neighbors = count_neighbors(game, i, j);
			if (game->board[i][j] == game->alive) {
				if (neighbors == 2 || neighbors == 3)
					temp[i][j] = game->alive;
				else
					temp[i][j] = game->dead;
			} else {
				if (neighbors == 3)
					temp[i][j] = game->alive;
				else
					temp[i][j] = game->dead;
			}
		}
	}

	free_board(game);
	game->board = temp;
	return 0;
}

void	print_board(t_game *game) {
	for (int i = 0; i < game->height; i++) {
		for (int j = 0; j < game->width; j++)
			putchar(game->board[i][j]);
		putchar('\n');
	}
}

int main(int argc, char **argv) {
	if (argc != 4) return 1;

	t_game game;
	if (init_game(&game, argv) == -1) return 1;

	fill_board(&game);
	for (int i = 0; i < game.iterations; i++) {
		if (play(&game) == -1) {
			free_board(&game);
			return 1;
		}
	}
	print_board(&game);
	free_board(&game);
}
