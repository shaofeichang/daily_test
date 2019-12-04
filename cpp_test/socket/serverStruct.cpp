#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <unistd.h>
//使用不定长的结构体发送数据的关键在于：结构体变量必须分配到堆中，而不是栈中
//即只能用malloc或者new来给结构体分配空间
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
    struct sockaddr_in client_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("socket error!\n");
        exit(1);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5050);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_addr.sin_zero), 8);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("bind error!\n");
        exit(1);
    }
    if (listen(sockfd, 100) == -1)
    {
        printf("listen error!\n");
        exit(1);
    }
    printf("Server is listening:\n");
    while (1)
    {
        int sin_size = sizeof(struct sockaddr_in);
        if ((new_fd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&sin_size)) == -1)
        {
            printf("accept error!\n");
            exit(1);
        }
        int recvSize = 0; //data total length
        if (recv(new_fd, (char *)&recvSize, sizeof(recvSize), 0) == -1)
        {
            printf("recv error!\n");
            exit(1);
        }
        printf("recvsize %d\n", recvSize);
        int leftSize = sizeof(char) * (recvSize - sizeof(int));
        printf("leftsize %d\n", leftSize);
        char *dataBuf = (char *)malloc(leftSize);
        memset(dataBuf, 0, leftSize);
        if (recv(new_fd, dataBuf, leftSize, 0) == -1)
        {
            printf("recv error!\n");
            exit(1);
        }
        close(new_fd);
        Node *p = (Node *)malloc(sizeof(char) * recvSize);
        p->nodeSize = recvSize;
        memcpy((char *)(&p->nodeSubLen), dataBuf, leftSize);
        printf("nodeSize = %d\n", p->nodeSize);
        printf("bufSize = %d\n", p->nodeSubLen);
        for (size_t i = 0; i < p->nodeSubLen; i++)
        {
            printf("nodesub %d %d %d %d %d %d \n",p->NodeS[i].x,p->NodeS[i].y,p->NodeS[i].z,p->NodeS[i].vx,p->NodeS[i].vy,p->NodeS[i].vz);
        }
        free(p);
    }

    return 0;
}