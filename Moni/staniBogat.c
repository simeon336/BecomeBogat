#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LINE_LEN 256
#define MAX_NUM_QUESTIONS 100

typedef struct{
    char difficulty[MAX_LINE_LEN];
    char question[MAX_LINE_LEN];
    char answerA[MAX_LINE_LEN];
    char answerB[MAX_LINE_LEN];
    char answerC[MAX_LINE_LEN];
    char answerD[MAX_LINE_LEN];
    char correctAnswer;
} Question;



void questionsToFile(Question *questions, FILE *fp, int numOfQuestions){
   
    for(int i = 0; i < numOfQuestions; i++){
        fprintf(fp, "%s\n", questions[i].difficulty);
        fprintf(fp, "%s\n", questions[i].question);
        fprintf(fp, "%s\n", questions[i].answerA);
        fprintf(fp, "%s\n", questions[i].answerB);
        fprintf(fp, "%s\n", questions[i].answerC);
        fprintf(fp, "%s\n", questions[i].answerD);
        fprintf(fp, "%c\n", questions[i].correctAnswer);

    }
    
}

int enterQuestion(Question *q, int numOfQuestions){

    
    for(int i = 0; i < numOfQuestions; i++){
        char difficulty[MAX_LINE_LEN];
        printf("Enter difficulty of the question: ");
        scanf("%s", difficulty);
        getchar();
        strcpy(q[i].difficulty, difficulty);

        char question[MAX_LINE_LEN] = {0};
        printf("Enter the question: ");
        // char *question = malloc(sizeof(char)*MAX_LINE_LEN);
        scanf("%[^\n]s", question);
        getchar();
        strcpy(q[i].question, question);

      

        char answerA[MAX_LINE_LEN];
        printf("Enter answer A: ");
        scanf("%[^\n]s", answerA);
        getchar();
        strcpy(q[i].answerA, answerA);

        char answerB[MAX_LINE_LEN];
        printf("Enter answer B: ");
        scanf("%[^\n]s", answerB);
        getchar();
        strcpy(q[i].answerB, answerB);

        char answerC[MAX_LINE_LEN];
        printf("Enter answer C: ");
        scanf("%[^\n]s", answerC);
        getchar();
        strcpy(q[i].answerC, answerC);

        char answerD[MAX_LINE_LEN];
        printf("Enter answer D: ");
        scanf("%[^\n]s", answerD);
        getchar();
        strcpy(q[i].answerD, answerD);

        char correctAnswer[MAX_LINE_LEN];
        printf("Enter the letter of the correct answer: ");
        scanf("%s", correctAnswer);
        q[i].correctAnswer = correctAnswer[0];    
        }
    
}

int main(){
    FILE *fp = fopen("questions.txt", "w+"); 
    
    if(fp == NULL){
        printf("Cannot open questions file.");
        return 1;
    }
    int numOfQuestions = 1;
    Question *questions = malloc(sizeof(Question)*numOfQuestions);
    enterQuestion(questions, numOfQuestions);


    // Question q2;
    // enterQuestion(q2);
    // questions[1] = q2;
    //printf("\n %d \n", questions[0].dificulty);

    questionsToFile(questions, fp, numOfQuestions);

    // char difficulty[MAX_LINE_LEN];
    // int numOfQuestons = 1;
    // Question *questions = malloc(sizeof(Question)*numOfQuestons);

    // while(fgets(difficulty, MAX_LINE_LEN-1, fp) != NULL){
    //     Question currentQuestion;
    //     currentQuestion.dificulty = atoi(difficulty);

    //     char question[MAX_LINE_LEN];
    //     fgets(question, MAX_LINE_LEN-1, fp);
    //     strcpy(currentQuestion.question, question);

    //     char answerA[MAX_LINE_LEN];
    //     fgets(answerA, MAX_LINE_LEN-1, fp);
    //     strcpy(currentQuestion.answerA, answerA);

    //     char answerB[MAX_LINE_LEN];
    //     fgets(answerB, MAX_LINE_LEN-1, fp);
    //     strcpy(currentQuestion.answerB, answerB);

    //     char answerC[MAX_LINE_LEN];
    //     fgets(answerC, MAX_LINE_LEN-1, fp);
    //     strcpy(currentQuestion.answerC, answerC);

    //     char answerD[MAX_LINE_LEN];
    //     fgets(answerD, MAX_LINE_LEN-1, fp);
    //     strcpy(currentQuestion.answerD, answerD);

    //     char correctAnswer[MAX_LINE_LEN];
    //     fgets(correctAnswer, MAX_LINE_LEN-1, fp);
    //     strcpy(currentQuestion.correctAnswer, correctAnswer[1]);
        
    // }

    fclose(fp);
    return 0;
}