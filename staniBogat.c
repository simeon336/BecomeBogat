#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LEN 256

typedef struct{
    int dificulty;
    char question[MAX_LINE_LEN];
    char answerA[MAX_LINE_LEN];
    char answerB[MAX_LINE_LEN];
    char answerC[MAX_LINE_LEN];
    char answerD[MAX_LINE_LEN];
    char correctAnswer;
} Question;

int main(){
    FILE *fp = fopen("questions.txt", "r");
    
    if(fp == NULL){
        printf("Cannot open questions file.");
        return 1;
    }
    char difficulty[MAX_LINE_LEN];
    
    while(fgets(difficulty, MAX_LINE_LEN-1, fp) != NULL){
        Question currentQuestion;
        currentQuestion.dificulty = atoi(difficulty);

        char question[MAX_LINE_LEN];
        fgets(question, MAX_LINE_LEN-1, fp);
        strcpy(currentQuestion.question, question);

        char answerA[MAX_LINE_LEN];
        fgets(answerA, MAX_LINE_LEN-1, fp);
        strcpy(currentQuestion.answerA, answerA);

        char answerB[MAX_LINE_LEN];
        fgets(answerB, MAX_LINE_LEN-1, fp);
        strcpy(currentQuestion.answerB, answerB);

        char answerC[MAX_LINE_LEN];
        fgets(answerC, MAX_LINE_LEN-1, fp);
        strcpy(currentQuestion.answerC, answerC);

        char answerD[MAX_LINE_LEN];
        fgets(answerD, MAX_LINE_LEN-1, fp);
        strcpy(currentQuestion.answerD, answerD);

        char correctAnswer[MAX_LINE_LEN];
        fgets(correctAnswer, MAX_LINE_LEN-1, fp);
        strcpy(currentQuestion.correctAnswer, correctAnswer[1]);
        
    }

    return 0;
}