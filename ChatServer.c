#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<string.h> 
#include<netinet/in.h>
#include <arpa/inet.h>
#include<unistd.h>
int main () {
    int fd, sfds1, sfds2;
    struct sockaddr_in server, client1, client2;
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd >= -1) {
        printf("\nSocket created successfully.");
    }
    //printf("%d", fd);
    server.sin_family = AF_INET;
    server.sin_port = htons(8000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    int b = bind(fd, (const struct sockaddr *) &server, sizeof(server));
    if(b >= 0) {
        printf("\nBind is successful.\n");
    } else {
        printf("\nBind is Not successful.\n");
    }
    int k = listen(fd, 5);
    if(k == -1 ) {
        printf("\nListen Success !");
    }

    int l1 = sizeof(client1);
    sfds1 = accept(fd, (struct sockaddr*) &client1, &l1);
    if(sfds1 != -1) {
        printf("\nConnection 1 is success !");
    } 

    int l2 = sizeof(client2);
    sfds2 = accept(fd, (struct sockaddr*) &client2, &l2);
    if(sfds2 != -1) {
        printf("\nConnection 2 is success !");
    } 

    char arr[100], recArr[100];
   
    while(1) {
        recv(sfds1, arr, 100, 0);
        send(sfds2, arr, 100, 0);
        recv(sfds2, recArr, 100, 0);
        send(sfds1, recArr, 100, 0);
    }
    
    close(fd);
    close(sfds1);
    close(sfds2);
}    
