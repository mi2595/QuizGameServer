//
// Created by Oreste Apa on 18/12/2019.
//


#include "server.h"






bool saveInfo(){


    //DICHIARAZIONE VARIABILI
    short unsigned int index=0;
    int fd;
    char buffer[1];
    int index_question=0;
    int index_answer=0;
    int index_answerChar=0;
    int dim=40;


    //APERTURA FILE DI TESTO
    if ( (fd=open("domande.txt",O_RDONLY)) < 0){
        perror("errore file");
        return false;
    }


    //ALLOCAZIONE MEMORIA PER DOMANDE
    questions=(info**)malloc(dim*sizeof(info*));
    while (1){
        if(index>dim){
            dim=dim*2;
            questions=(info**)realloc(questions,dim*sizeof(info*));
        }



        //SALVATAGGIO DOMANDE
        questions[index]=(info*)malloc(sizeof(info));
        index_question=0;
        do {
            read(fd,buffer,1);
            questions[index]->question[index_question]=buffer[0];
            index_question ++;
        }while(buffer[0] != '\n' && buffer[0] != '\0');
        questions[index]->question[index_question]='\0';

        if (buffer[0] == '\0'){
            return false;
        }


        //SALVATAGGIO RISPOSTE
        index_answer=0;
        while(index_answer<4){
            index_answerChar=0;
            do {
                read(fd,buffer,1);
                questions[index]->answer[index_answer][index_answerChar]=buffer[0];
                index_answerChar++;
            }while(buffer[0] != '\n' && buffer[0] != '\0');
            questions[index]->answer[index_answer][index_answerChar]='\0';
            if (buffer[0] == '\0' ){
                return false;
            }
            index_answer++;
        }

        //SALVATAGGIO RISPOSTE CORRETTE
        do {
            if ( (read(fd,buffer,1)) < 0){
                return false;
            }
            questions[index]->correct_answer=atoi(buffer);

        }while( buffer[0] !='\n' && buffer[0] != '.');
        if(buffer[0] == '.'){
            break;
        }
        index++;
    }

    numberQuestion=index;
    /*for (int i = 0; i <= index; i++) {
        printf("\ndomanda: %s",questions[i]->question);

        for (int j = 0; j < 4; j++) {
            printf("\nrisposta %d): %s",j+1,questions[i]->answer[j]);
        }
        printf("\nrisposta corretta è : %hu\n",questions[i]->correct_answer);

    }*/

    close(fd);
    return true;
}
