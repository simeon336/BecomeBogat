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
} Question;

struct Node{
    Question *question;
    struct Node *next;
};
void tablePrinter(char table[26][26]);
void TableMaker(char table[26][26]);
char* cypher(char table[26][26], char* text, char* key);
char *decypher(char table[26][26], char *cypher, char *key);
struct Node **initHashTable();
bool writeToFile(struct Node **questions, char* fileName);
void writeQuestionToFile(Question *question, FILE *fp);
void addQuestion(struct Node **questions, Question *currentQuestion);
Question* enterQuestion();
void removeNewLine(char* string);
struct Node **readQuestions(char *fileName);
void printQuestion(Question *question);
void printQuestions(struct Node **questions);
Question *cryptoQuestion(Question *question);
char shiftChar(char c);
Question *decypherQuestion(Question *question);
char unshiftChar(char c);