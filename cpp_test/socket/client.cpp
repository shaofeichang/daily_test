#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

typedef struct Node
{
	int nodeSize;
	int bufSize;
	char buf[0];
} Node;

int main()
{
	int sockfd, new_fd;
	struct sockaddr_in server_addr;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		printf("socket error!\n");
		exit(1);
	}
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5050);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	bzero(&(server_addr.sin_zero), 8);

	if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
	{
		printf("connect error!\n");
		exit(1);
	}
	printf("Client is connecting\n");
	const char *tmp = "this is a test!";
	int tmpLen = strlen(tmp);
	Node *dataBuf = (Node *)malloc(sizeof(Node) + tmpLen + 1);
	dataBuf->nodeSize = sizeof(Node) + tmpLen + 1;
	dataBuf->bufSize = tmpLen;
	memset(dataBuf->buf, 0, tmpLen + 1);
	memcpy(dataBuf->buf, tmp, tmpLen + 1);
	printf("nodeSize = %d\n", dataBuf->nodeSize);
	printf("bufSize = %d\n", dataBuf->bufSize);
	printf("buf = %s\n", dataBuf->buf);
	if (send(sockfd, (char *)dataBuf, dataBuf->nodeSize, 0) == -1)
	{
		printf("send error!\n");
		exit(1);
	}
	close(sockfd);
	return 0;
}