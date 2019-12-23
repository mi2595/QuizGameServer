//
// Created by Oreste Apa on 16/12/2019.
//

#include "utilityThread.h"
#include "utilitySocket.h"
#include "server.h"



//DICHIARAZIONE VARIABILI GLOBALI
    pthread_t th1;



//SCAMBIO DATI
void* start_thread(void *arguments){

    //PRECONDIZIONI SCAMBIO DATI
    pthread_mutex_lock(&precondition.lock);
    precondition.number_client++;
    while(precondition.number_client < 2){
        printf("ATTENDERE IL COLLEGAMENTO DI UN ALTRO CLIENT PER INZIARE IL QUIZ\n\n");
        pthread_cond_wait(&precondition.isTwo,&precondition.lock);

    }
    pthread_cond_signal(&precondition.isTwo);
    pthread_mutex_unlock(&precondition.lock);
    char risposta[1];


    //INVIO DOMANDE E RISPOSTE AL CLIENT
    for(int i=0; i<=numberQuestion;i++) {


        write(*(int *) arguments, questions[i]->question, strlen(questions[i]->question));
        sleep(2);
        for (int j = 0; j < 4; j++) {
            write(*(int *) arguments, questions[i]->answer[j], strlen(questions[i]->answer[j]));
            sleep(2);
        }
        read(*(int *) arguments, risposta, 1);
        write(STDOUT_FILENO,risposta,1);
        sleep(2);
        //leggo la risposta, se è uguale a quella presente in question[i]->risposte,
        //aggiorno la classifica di quel client collegato altrimenti risposta errata.
        //il server attende con la read massimo un minuto, scaduto quel time, la risposta è errata
    }
    pthread_exit(NULL);
}



//INIZIO COMUNICAZIONE
void * thread_accept(void *arg){
    pthread_t tid;
    int * sd2;
    while(1){
        sd2=malloc(sizeof(int*));
        if((*sd2=accept(*(int*)arg,NULL,NULL) ) <0){
            perror("Errore");
            exit(1);
        }
        pthread_create(&tid,NULL,start_thread,(void*)sd2);
        pthread_detach(tid);
    }
}