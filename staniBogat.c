#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LINE_LEN 256
#define MAX_NUM_QUESTIONS 100

typedef struct{
    int dificulty;
    char question[MAX_LINE_LEN];
    char answerA[MAX_LINE_LEN];
    char answerB[MAX_LINE_LEN];
    char answerC[MAX_LINE_LEN];
    char answerD[MAX_LINE_LEN];
    char correctAnswer;
} Question;

int questionsToFile(Question *questions, FILE *fp){
    int len = 0;
    while(len < MAX_NUM_QUESTIONS){
        fprintf(fp, "%d\n", questions[len].dificulty);
        fprintf(fp, "%s\n", questions[len].question);
        fprintf(fp, "%s\n", questions[len].answerA);
        fprintf(fp, "%s\n", questions[len].answerB);
        fprintf(fp, "%s\n", questions[len].answerC);
        fprintf(fp, "%s\n", questions[len].answerD);
        fprintf(fp, "%c\n", questions[len].correctAnswer);
        len++;
        
        if(strcmp(questions[len].answerA, "")){
            break;
        }
    }
}

int enterQuestion(Question q){

    char dificulty[MAX_LINE_LEN];
    printf("Enter the difficulty of the question: \n");
    scanf("%s", dificulty);
    if(isdigit(dificulty[0])){
        printf("\n");
    }
    else{
        printf("Value of difficulty must be a number!");
        return 1;
    }
    // printf("%d", isdigit(dificulty));
    // if(isdigit(dificulty)){}
    // else{
    //     printf("Value of difficulty must be a number!");
    //     return 1;
    // }
    q.dificulty = atoi(dificulty);

    char question[MAX_LINE_LEN];
    printf("Enter the question: ");
    scanf("%s", question);
    strcpy(q.question, question);

    char answerA[MAX_LINE_LEN];
    printf("Enter answer A: ");
    scanf("%s", answerA);
    strcpy(q.answerA, answerA);

    char answerB[MAX_LINE_LEN];
    printf("Enter answer B: ");
    scanf("%s", answerB);
    strcpy(q.answerB, answerB);

    char answerC[MAX_LINE_LEN];
    printf("Enter answer C: ");
    scanf("%s", answerC);
    strcpy(q.answerC, answerC);

    char answerD[MAX_LINE_LEN];
    printf("Enter answer D: ");
    scanf("%s", answerD);
    strcpy(q.answerD, answerD);

    char correctAnswer[MAX_LINE_LEN];
    printf("Enter the letter of the correct answer: ");
    scanf("%s", correctAnswer);
    q.correctAnswer = correctAnswer[0];    
    
}

int main(){
    FILE *fp = fopen("questions.txt", "a"); 
    
    if(fp == NULL){
        printf("Cannot open questions file.");
        return 1;
    }
    Question questions[MAX_NUM_QUESTIONS];

    Question q1;
    enterQuestion(q1);
    questions[0] = q1;

    // Question q2;
    // enterQuestion(q2);
    // questions[1] = q2;
    printf("%s", questions[0].answerA);
    questionsToFile(questions, fp);

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
