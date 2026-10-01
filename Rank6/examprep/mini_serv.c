#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>


int clients[1024];
fd_set current, read_set, write_set;
int sockfd, max_fd, g_id = 0;
char msg[200000], buff[200040];

void	fatal(void) {
	write(2, "Fatal error\n", 12);
	close(sockfd);
	exit(1);
}

void	send_to_all(int sender_fd) {
	for (int fd = 0; fd <= max_fd; fd++) {
		if (fd != sender_fd && FD_ISSET(fd, &write_set)) {
			if (send(fd, buff, strlen(buff), 0) < 0)
				fatal();
		}
	}
}

void	add_client(void) {
	struct sockaddr_in clientaddr;
	socklen_t len = sizeof(clientaddr);

	int client_fd = accept(sockfd, (struct sockaddr *)&clientaddr, &len);
	if (client_fd < 0)
		return;

	if (client_fd > max_fd)
		max_fd = client_fd;

	clients[client_fd] = g_id++;
	FD_SET(client_fd, &current);

	bzero(&buff, sizeof(buff));
	sprintf(buff, "server: client %d just arrived\n", clients[client_fd]);
	send_to_all(client_fd);
}

void	rm_client(int fd) {
	bzero(&buff, sizeof(buff));
	sprintf(buff, "server: client %d just left\n", clients[fd]);
	send_to_all(fd);

	FD_CLR(fd, &current);
	close(fd);
}

void	extract_msg(int fd) {
	/*
	char	line_tmp[200000];
	int		i = -1;

	bzero(&line_tmp, sizeof(line_tmp));
	while (msg[++i] != 0) {
		line_tmp[i] = msg[i];
		if (msg[i] == '\n') {
			bzero(&buff, sizeof(buff));
			sprintf(buff, "client %d: %s", clients[fd], line_tmp);
			send_to_all(fd);
			break;
		}
	}
	bzero(&msg, sizeof(msg));
	*/
	bzero(&buff, sizeof(buff));
	sprintf(buff, "client %d: %s", clients[fd], msg);
	send_to_all(fd);
	bzero(&msg, sizeof(msg));
}

int	main(int argc, char **argv) {
	if (argc != 2) {
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}

	struct sockaddr_in	servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // 127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1]));

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		fatal();

	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
		fatal();

	if (listen(sockfd, 128) < 0)
		fatal();

	FD_ZERO(&current);
	FD_SET(sockfd, &current);
	max_fd = sockfd;
	bzero(&msg, sizeof(msg));

	while (1) {
		read_set = write_set = current;
		if (select(max_fd + 1, &read_set, &write_set, NULL, NULL) < 0)
			continue;

		for (int fd = 0; fd <= max_fd; ++fd) {
			if (FD_ISSET(fd, &read_set)) {
				if (fd == sockfd) {
					add_client();
					break;
				}

				int ret = 1;
				while (ret == 1 && msg[strlen(msg) - 1] != '\n') {
					ret = recv(fd, msg + strlen(msg), 1, 0);
				}

				if (ret <= 0) {
					rm_client(fd);
					break;
				}

				extract_msg(fd);
			}
		}
	}
	return (0);
}
