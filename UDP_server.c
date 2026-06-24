#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    char buffer[100];
    struct sockaddr_in server, client;
    socklen_t len = sizeof(client);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    bind(sockfd, (struct sockaddr*)&server, sizeof(server));

    recvfrom(sockfd, buffer, sizeof(buffer), 0,
             (struct sockaddr*)&client, &len);

    printf("Server received: %s\n", buffer);

    return 0;
}
