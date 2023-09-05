#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
int main (void){

        int meusocket;
        int conecta;

        char ip[16];
        struct sockaddr_in alvo;

        printf("Digite o endereço que vocÊ quer escanear:");
        scanf("%15s", ip);

        for (int porta = 1; porta <= 65535; porta++) {
        meusocket = socket(AF_INET,SOCK_STREAM,0);

        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = 500000;
        setsockopt(meusocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
        setsockopt(meusocket, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));


        alvo.sin_family = AF_INET;
        alvo.sin_port = htons(porta);
        alvo.sin_addr.s_addr = inet_addr(ip);

        conecta = connect(meusocket, (struct sockaddr *)&alvo, sizeof alvo);

        if(conecta == 0){

        printf("Porta %d  Aberta \n", porta);
        close(meusocket);
        close(conecta);
        }       else {
        close(meusocket);
        }
}
}
