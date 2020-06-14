#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#pragma pack(push)
#pragma pack(1)
typedef struct NodeSub
{
	int x, y, z, vx, vy, vz;
} NodeSub;
typedef struct Node
{
	int nodeSize;
	int nodeSubLen;
	NodeSub NodeS[0];
} Node;
#pragma pack(pop)
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
	int sublen = 3;
	NodeSub ns[3] = {{1, 2, 3, 4, 5, 6}, {11, 22, 33, 44, 55, 66}, {111, 222, 333, 444, 555, 666}};
	int SubStrLen = sizeof(NodeSub);
	Node *dataBuf = (Node *)malloc(sizeof(Node) + sublen * SubStrLen);
	dataBuf->nodeSize = sizeof(Node) + sublen * SubStrLen;
	dataBuf->nodeSubLen = sublen;
	memset(dataBuf->NodeS, 0, sublen * SubStrLen);
	memcpy(dataBuf->NodeS, ns, sublen * SubStrLen);
	printf("nodeSize = %d\n", dataBuf->nodeSize);
	printf("bufSize = %d\n", dataBuf->nodeSubLen);
	if (send(sockfd, (char *)dataBuf, dataBuf->nodeSize, 0) == -1)
	{
		printf("send error!\n");
		exit(1);
	}
	close(sockfd);
	free(dataBuf);
	return 0;
}