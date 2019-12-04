#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <ctime>
#include <unistd.h>
//使用不定长的结构体发送数据的关键在于：结构体变量必须分配到堆中，而不是栈中
//即只能用malloc或者new来给结构体分配空间
#include "radar_struct.h"
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
	TrackRadarOutput track;

	int sin_size = sizeof(struct sockaddr_in);
	if ((new_fd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&sin_size)) == -1)
	{
		printf("accept error!\n");
		exit(1);
	}
	int i = 0;
	timeval tv;
	tv.tv_sec = 1;
	tv.tv_usec = 0;
	if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) == -1)
	{
		printf("set error\n");
		exit(1);
	}
	
	while (1)
	{
		int recvSize = 0; //data total length

		if ((recvSize = recv(new_fd, &track.megHead, sizeof(track.megHead), 0)) == -1)
		{
			printf("recv error!\n");
			exit(1);
		}
		if (recvSize == sizeof(track.megHead) && track.megHead.nodeID == TRACKRADARNODEONE)
		{
			if ((recvSize = recv(new_fd, &track.traRadInfo, sizeof(track.traRadInfo), 0)) == -1)
			{
				printf("recv error!\n");
				exit(1);
			}
		}
		printf("%d\n", i++);
		printf("%f %f %f \n", track.traRadInfo.x, track.traRadInfo.y, track.traRadInfo.z);
	}

	return 0;
}