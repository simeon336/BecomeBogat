#pragma once

#include <stdio.h>
#include <stdbool.h>

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
    bool joker1;
    bool joker2;
    bool joker3;
} Question;

struct Node{
    Question *question;
    struct Node *next;
};
struct Node **initHashTable();
bool writeToFile(struct Node **questions, char* fileName);
void writeQuestionToFile(Question *question, FILE *fp);
void addQuestion(struct Node **questions, Question *currentQuestion);
Question* enterQuestion();
void removeNewLine(char* string);
struct Node **readQuestions(char *fileName);
void printQuestion(Question *question);
void printQuestions(struct Node **questions);
