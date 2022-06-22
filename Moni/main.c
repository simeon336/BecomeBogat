#include "moni.h"
#include <stdio.h>
int main(){

    // FILE *fp = fopen("questions.txt", "w+");

    // if(fp == NULL){
    //     printf("Cannot open questions file.");
    //     return 1;
    // }
    
    char fileName[] = "questions.txt";

    int numOfQuestions = 2;
    // Question *questions = malloc(sizeof(Question)*numOfQuestions);
    // enterQuestion(questions, i);
    // enterQuestion(questions, i);
    // questionsToFile(questions, fp, numOfQuestions, i); 
    // struct Node **questions = readQuestions(fileName);
    // printQuestions(questions);
    struct Node **questions = initHashTable();
    Question *q1 = enterQuestion();
    Question *q2 = enterQuestion();
    addQuestion(questions, q1);
    addQuestion(questions, q2);
    printQuestions(questions);
    writeToFile(questions, fileName);

}