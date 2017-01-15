#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

struct packet_s {
    uint8_t cmd;
    uint8_t len;
    uint8_t data[0];
};

static int server_sock = -1;
static int port_number = 3333;

void tcp_server(void)
{
    int reuse = 1;
    int client_socket;
    socklen_t client_len;
    struct sockaddr_in serv_addr;
    struct sockaddr_in client_addr;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock  < 0){
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port_number);
    if(setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1){
        perror("SO_REUSEADDR");
        exit(1);
    }

    if (bind(server_sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        perror("bind");
        exit(1);
    }

    listen(server_sock, 100);
    client_len = sizeof(client_addr);


    uint8_t buff[1024];
    struct packet_s *pkt = (struct packet_s*)buff;

    while(true) {
        client_socket = accept(server_sock, (struct sockaddr *) &client_addr, &client_len);
        if (client_socket < 0){
            perror("ERROR on accepting incoming connection.");
            continue;
        }

        printf("CONNECTED FROM %s:%d", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        read(client_socket, pkt, sizeof(struct packet_s));
        read(client_socket, pkt->data, pkt->len);

        printf("CMD[%d] LEN [%d] DATA0[%d]\n", pkt->cmd, pkt->len, pkt->data[0]);
        close(client_socket);
    }
}
