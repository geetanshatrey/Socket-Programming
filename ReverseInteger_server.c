#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<string.h> 
#include<netinet/in.h>
#include <arpa/inet.h>
#include<unistd.h>
int main () {
    int fd, sfds;
    struct sockaddr_in server, client1;
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
    int l = sizeof(client1);
    sfds = accept(fd, (struct sockaddr*) &client1, &l);
    if(sfds != -1) {
        printf("\nConnection is success !");
    } 
    int x;
    recv(sfds, &x, sizeof(x), 0);
    int rev = 0, remainder;
    while (x != 0) {
        remainder = x % 10;
        rev = rev * 10 + remainder;
        x /= 10;
    }
    send(sfds, &rev, sizeof(rev), 0);
    close(fd);
    close(sfds);
}
