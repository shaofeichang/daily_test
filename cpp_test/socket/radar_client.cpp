#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include "radar_struct.h"
#include "targetTrace.h"
#include <ctime>
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
    time_t now_time;
    now_time = time(NULL);
    TrackRadarOutput trackRadar;
    trackRadar.megHead = {3, TRACKRADARNODEONE, TRACKRADARNODEONE, TRACKRADARMSG, sizeof(TrackRadarInfo), 1, now_time, 1};
    //trackRadar.traRadInfo = {11.111,22.222,1, 1, 11.11, 22.22, 33.33, 44.44, 55.55, 66.66, 77.77, 88.88};
    targetTrace target1;
    while (1)
    {

        target1.targetGenerate();
        double *currPos = target1.getCurrentPos();
        trackRadar.traRadInfo.x = currPos[0];
        trackRadar.traRadInfo.y = currPos[1];
        trackRadar.traRadInfo.z = currPos[2];

        if (send(sockfd, &trackRadar, sizeof(trackRadar), 0) == -1)
        {
            printf("send error!\n");
            exit(1);
        }
        time_t tt;
        tt = time(NULL);
        printf("time %f\n", abs((tt - now_time))*1000000);
        now_time = time(NULL);
        sleep(3);
    }

    close(sockfd);
    return 0;
}