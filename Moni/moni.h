#pragma once

#include <stdio.h>

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

void questionsToFile(Question questions[][100], FILE *fp, int numOfQuestions, int trudnost[]);
int enterQuestion(Question q[][100], int i[]);
