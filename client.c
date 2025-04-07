#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

char *g_code = "124567\n";

int send_code(int sockfd)
{
	return (send(sockfd, g_code, strlen(g_code), 0));
}

void	*receive_msg(void *arg)
{
	int sockfd = *(int *)arg;
	char buffer[BUFFER_SIZE];
	while (1)
	{
		int len = recv(sockfd, buffer, sizeof(buffer - 1), 0);
		if (len <= 0)
		{
			printf("Connection closed or error ocurred\n");
			break;
		}
		buffer[len] = '\0';
		printf("Server: %s\n", buffer);
	}
	return (NULL);
}

int main()
{
	int sockfd;
	struct sockaddr_in server_addr;
	char buffer[BUFFER_SIZE];
	char *info;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");//лок адрес
	connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	printf("Connected to server. You can start typing messages...\n");

	usleep(1000);

	if (send_code(sockfd) == -1)
	{
		perror("Send code failed");
		close(sockfd);
		return 1;
	}
	printf("The code was sent\n");
	
	pthread_t recv_thread;

	if (pthread_create(&recv_thread, NULL, receive_msg, (void *)&sockfd) != 0)
	{
		perror("pthread");
		close(sockfd);
		return 1;
	}

	while (1)
	{
		printf("You: ");
		fgets(buffer, sizeof(buffer), stdin);
		buffer[strcspn(buffer, "\n")] == 0;
		if (send(sockfd, buffer, strlen(buffer), 0) == -1)
		break ;
		if (strcmp(buffer, "exit") == 0)
		break ;
	}
	close(sockfd);
	pthread_join(recv_thread, NULL);
	close(sockfd);
}

// printf("Write the ip:port from client, you want to connect to [FORMAT: 0.0.0.0:12345]: ");