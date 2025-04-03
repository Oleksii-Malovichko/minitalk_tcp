#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

char *g_code = "345678\n";

int send_code(int sockfd)
{
	return (send(sockfd, g_code, strlen(g_code), 0));
}

int main()
{
	int sockfd;
	struct sockaddr_in server_addr;
	char buffer[BUFFER_SIZE];

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
}