//
// Created by Oreste Apa on 16/12/2019.
//

#ifndef QUIZGAMESERVER_UTILITYTHREAD_H
#define QUIZGAMESERVER_UTILITYTHREAD_H

/* ************************************************* */

//LIBRERIE
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>
#include "utilitySocket.h"
/* ************************************************* */

//COSTANTI
#define  QUEUE_SIZE 100



/* ************************************************* */

//STRUTTURE


typedef struct michela{

};


/* ************************************************* */

//FUNZIONI RELATIVE ALLA CREAZIONE E GESTIONE SOCKET
void *start_thread(void *argument);
void * thread_accept(void *arg);



/* ************************************************* */

#endif //QUIZGAMESERVER_UTILITYTHREAD_H
