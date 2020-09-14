#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<string.h> 
#include<netinet/in.h>
#include <arpa/inet.h>
#include<unistd.h>
int main () {
    int fd;
    struct sockaddr_in client1;
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd >= -1) {
        printf("\nSocket created successfully.");
    }
    //printf("%d", fd);
    client1.sin_family = AF_INET;
    client1.sin_port = htons(8000);
    client1.sin_addr.s_addr = inet_addr("127.0.0.1");
    int b = connect(fd, (const struct sockaddr *)  &client1, sizeof(client1));
    if(b >= 0) {
        printf("\nConnection is successful.\n");
    } 
    else {
        printf("\nConnection is Not successful.\n");
    }
    char arr[100], recArr[100];

    while(1) {
        printf("\nEnter the message :");
        scanf("%s",arr);
        send(fd, arr, 100, 0);
        recv(fd, arr, 100, 0);
        printf("\nMessage Received : %s",arr);
        if(arr[0] == 'e') {
            break;
        }
    }
    close(fd);
}
