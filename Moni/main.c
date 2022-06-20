#include "moni.h"
#include <stdio.h>
int main(){
    int i[10];

    Question questions[10][100];


    FILE *fp = fopen("questions.txt", "w+");

    if(fp == NULL){
        printf("Cannot open questions file.");
        return 1;
    }
    int numOfQuestions = 2;
    //Question *questions = malloc(sizeof(Question)*numOfQuestions);
    enterQuestion(questions, i);
    enterQuestion(questions, i);

}