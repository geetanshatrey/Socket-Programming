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
    float n1, n2;
    printf("\nEnter 2 numbers :");
    scanf("%f %f",&n1,&n2);
    send(fd, &n1, sizeof(n1), 0);
    send(fd, &n2, sizeof(n2), 0);
    float x;
    recv(fd, &x, sizeof(x), 0);
    printf("Sum : %f",x);
    close(fd);
}
