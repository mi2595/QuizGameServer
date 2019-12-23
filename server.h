//
// Created by Oreste Apa on 18/12/2019.
//

#ifndef QUIZGAMESERVER_SERVER_H
#define QUIZGAMESERVER_SERVER_H



/* ************************************************* */

//LIBRERIE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>
/* ************************************************* */

//COSTANTI
#define  MAX_LENGHT_QUESTION 100




/* ************************************************* */

//STRUTTURE
typedef struct infoQuiz{
    char question[MAX_LENGHT_QUESTION];
    char answer[4][100];
    unsigned short correct_answer;
}info;

int numberQuestion;
info **questions;

/* ************************************************* */

//FUNZIONI RELATIVE ALLA CREAZIONE E GESTIONE SERVER
bool saveInfo();

/* ************************************************* */













#endif //QUIZGAMESERVER_SERVER_H
