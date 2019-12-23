//
// Created by Oreste Apa on 12/12/2019.
//
#include <signal.h>
#include "utilitySocket.h"
#include "utilityThread.h"

//INIZIALIZZAZIONE PRECONDIZIONI
void init_preconditions(){
    precondition.number_client=0;
    pthread_mutex_init(&precondition.lock,NULL);
    pthread_cond_init(&precondition.isTwo,NULL);

}



//DICHIARAZIONI VARIABILI GLOBALI
int sd1;




//CREAZIONE STRUTTURA SERVER
void createServerSocket() {

    //GESTIONE SEGNALI
    signal(15, signal_handler);



    //INIZIALIZZAZIONE STRUTTURA
    init_preconditions();



    //CREAZIONE INDIRIZZO DA ASSEGNARE ALLA SOCKET
    struct sockaddr_in indirizzo;
    indirizzo.sin_family = AF_INET;
    indirizzo.sin_port = htons(5201);
    indirizzo.sin_addr.s_addr = htonl(INADDR_ANY);



    //CREAZIONE SOCKET, LO IMPOSTO DI RETE (INET) E CON CONNESSIONE (STREAM)
    sd1 = socket(PF_INET, SOCK_STREAM, 0);
    if (sd1 < 0) {
        exit(1);
    }



    //ASSEGNAZIONE INDIRIZZO ALLA SOCKET
    int flag = 1;
    setsockopt(sd1, SOL_SOCKET, SO_REUSEPORT, &flag, sizeof(int));
    if (bind(sd1, (struct sockaddr *) &indirizzo, sizeof(indirizzo)) < 0) {
        exit(1);
    }



    //IMPOSTO LA SOCKET IN ASCOLTO
    if (listen(sd1, QUEUE_SIZE) < 0) {
        exit(1);
    }
}




//CREAZIONE THREAD PER GESTIRE
void run_socket(){
    pthread_t tid;
    int* arg_thread=malloc(sizeof(int));
    *arg_thread=sd1;
    pthread_create(&tid,NULL,thread_accept,(void*)arg_thread);
    pthread_detach(tid);
}




//GESTIONE SEGNALI
void signal_handler(int signo){
    close(sd1);
    exit(0);
}
