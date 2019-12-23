//
// Created by Oreste Apa on 12/12/2019.
//

#ifndef QUIZGAMESERVER_UTILITYSOCKET_H
#define QUIZGAMESERVER_UTILITYSOCKET_H

/* ************************************************* */

//LIBRERIE
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>
/* ************************************************* */

//COSTANTI
#define  QUEUE_SIZE 100



/* ************************************************* */

//STRUTTURE
typedef struct preconditions{
    int number_client;
    pthread_mutex_t lock;
    pthread_cond_t isTwo;

} preconditions;

preconditions precondition;



/* ************************************************* */

//FUNZIONI RELATIVE ALLA CREAZIONE E GESTIONE SOCKET
void createServerSocket();
void signal_handler(int signo);
void init_preconditions();
void run_socket();


/* ************************************************* */

#endif //QUIZGAMESERVER_UTILITYSOCKET_H
