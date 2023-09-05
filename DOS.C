#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(void) {
    int meusocket;
    int conecta;
    struct sockaddr_in alvo;

    alvo.sin_family = AF_INET;
    alvo.sin_port = htons(PORTA); //Alterar para Porta Alvo
    alvo.sin_addr.s_addr = inet_addr("IP"); //Alterar para IP Alvo

    while (1) { // Loop infinito
        meusocket = socket(AF_INET, SOCK_STREAM, 0);
        if (meusocket < 0) {
            perror("Erro ao criar soquete");
            return 1;
        }

        conecta = connect(meusocket, (struct sockaddr *)&alvo, sizeof alvo);

        if (conecta == 0) {
            printf("Porta Aberta \n");
        } else {
            printf("Porta Fechada \n");
        }

        // Não feche a conexão aqui

        sleep(0.1); // Espere por um milisegundo antes de tentar novamente
    }

    return 0;
}
