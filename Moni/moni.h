#pragma once

#include <stdio.h>

#define MAX_LINE_LEN 256
#define MAX_NUM_QUESTIONS 100

typedef struct{
    int difficulty;
    char question[MAX_LINE_LEN];
    char answerA[MAX_LINE_LEN];
    char answerB[MAX_LINE_LEN];
    char answerC[MAX_LINE_LEN];
    char answerD[MAX_LINE_LEN];
    char correctAnswer;
} Question;

struct Node{
    Question *question;
    struct Node *next;
};

// void questionsToFile(Question questions[][100], FILE *fp, int numOfQuestions, int trudnost[]);
// int enterQuestion(Question q[][100], int i[]);
void removeNewLine(char* string);
struct Node **readQuestions(char *fileName);
void printQuestion(Question *question);
void printQuestions(struct Node **questions);
