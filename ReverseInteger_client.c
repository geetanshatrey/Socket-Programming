#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<string.h> 
#include<netinet/in.h>
#include <arpa/inet.h>
#include<unistd.h>
int main () {
    int fd;
    struct sockaddr_in client;
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd >= -1) {
        printf("\nSocket created successfully.");
    }
    //printf("%d", fd);
    client.sin_family = AF_INET;
    client.sin_port = htons(8000);
    client.sin_addr.s_addr = inet_addr("127.0.0.1");
    int b = connect(fd, (const struct sockaddr *)  &client, sizeof(client));
    if(b >= 0) {
        printf("\nConnection is successful.\n");
    } 
    else {
        printf("\nConnection is Not successful.\n");
    }
    int x;
    printf("\nEnter a number :");
    scanf("%d",&x);
    send(fd, &x, sizeof(x), 0);
    int y;
    recv(fd, &y, sizeof(y), 0);
    printf("Reversed : %d",y);
    close(fd);
}
