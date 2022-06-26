#include "moni.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){


    
    char fileName[] = "questions.txt";

 

    struct Node **questions = readQuestions(fileName);
    
    printQuestions(questions);
}