#include "moni.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// void questionsToFile(Question questions[][100], FILE *fp, int numOfQuestions, int trudnost[]){
    

//     for(int i = 0; i < 10; i++){
//         if(trudnost[i] != 0){
//             for(int y = 0; y < trudnost[i]; y++){
//             fprintf(fp, "%s\n", questions[i][y].difficulty);
//             fprintf(fp, "%s\n", questions[i][y].question);
//             fprintf(fp, "%s\n", questions[i][y].answerA);
//             fprintf(fp, "%s\n", questions[i][y].answerB);
//             fprintf(fp, "%s\n", questions[i][y].answerC);
//             fprintf(fp, "%s\n", questions[i][y].answerD);
//             fprintf(fp, "%c\n", questions[i][y].correctAnswer);

//             }
//         }
        
//     }


// }
void removeNewLine(char* string){
    char *p = strchr(string, '\n');
    if(p != NULL){
        *p = '\0';
    }
}
struct Node **readQuestions(char *fileName){
   FILE *fp = fopen(fileName, "r");

    if(fp == NULL){
        printf("Cannot open questions file.");
        return NULL;
    }

    char difficulty[MAX_LINE_LEN];
    struct Node **questions = malloc(sizeof(struct Node*)*10);

    for(int i = 0; i < 10; i++){
        questions[i] = NULL;
    }
    
    while(fgets(difficulty, MAX_LINE_LEN-1, fp) != NULL){
        Question *currentQuestion = malloc(sizeof(Question));
        removeNewLine(difficulty);
        currentQuestion->difficulty = atoi(difficulty);

        char question[MAX_LINE_LEN];
        fgets(question, MAX_LINE_LEN-1, fp);
        removeNewLine(question);
        strcpy(currentQuestion->question, question);

        char answerA[MAX_LINE_LEN];
        fgets(answerA, MAX_LINE_LEN-1, fp);
        removeNewLine(answerA);
        strcpy(currentQuestion->answerA, answerA);

        char answerB[MAX_LINE_LEN];
        fgets(answerB, MAX_LINE_LEN-1, fp);
        removeNewLine(answerB);
        strcpy(currentQuestion->answerB, answerB);

        char answerC[MAX_LINE_LEN];
        fgets(answerC, MAX_LINE_LEN-1, fp);
        removeNewLine(answerC);
        strcpy(currentQuestion->answerC, answerC);

        char answerD[MAX_LINE_LEN];
        fgets(answerD, MAX_LINE_LEN-1, fp);
        removeNewLine(answerD);
        strcpy(currentQuestion->answerD, answerD);

        char correctAnswer[MAX_LINE_LEN];
        fgets(correctAnswer, MAX_LINE_LEN-1, fp);
        removeNewLine(correctAnswer);
        currentQuestion->correctAnswer = correctAnswer[0];

        struct Node *node = malloc(sizeof(struct Node));
        node->next = NULL;
        node->question = currentQuestion;
        if(questions[currentQuestion->difficulty-1] == NULL){
            questions[currentQuestion->difficulty-1] = node;
        } else{
            struct Node *lastNode = questions[currentQuestion->difficulty-1];
            while(lastNode->next != NULL){
                lastNode = lastNode->next;
            }
            lastNode->next = node;
        }
    }

    return questions;

}

// int enterQuestion(Question q[][100], int i[]){

//         //int key;

//         char difficulty[MAX_LINE_LEN];
//         printf("Enter difficulty of the question: ");
//         scanf("%s", difficulty);
//         getchar();
//         //int key = atoi(difficulty.c_str());
//         int key = atoi(difficulty)-1;
//         strcpy(q[key][i[key]].difficulty, difficulty); //ne raboti



//         char question[MAX_LINE_LEN] = {0};
//         printf("Enter the question: ");
//         // char *question = malloc(sizeof(char)*MAX_LINE_LEN);
//         scanf("%[^\n]s", question);
//         getchar();
//         strcpy(q[key][i[key]].question, question);



//         char answerA[MAX_LINE_LEN];
//         printf("Enter answer A: ");
//         scanf("%[^\n]s", answerA);
//         getchar();
//         strcpy(q[key][i[key]].answerA, answerA);

//         char answerB[MAX_LINE_LEN];
//         printf("Enter answer B: ");
//         scanf("%[^\n]s", answerB);
//         getchar();
//         strcpy(q[key][i[key]].answerB, answerB);

//         char answerC[MAX_LINE_LEN];
//         printf("Enter answer C: ");
//         scanf("%[^\n]s", answerC);
//         getchar();
//         strcpy(q[key][i[key]].answerC, answerC);

//         char answerD[MAX_LINE_LEN];
//         printf("Enter answer D: ");
//         scanf("%[^\n]s", answerD);
//         getchar();
//         strcpy(q[key][i[key]].answerD, answerD);

//         char correctAnswer[MAX_LINE_LEN];
//         printf("Enter the letter of the correct answer: ");
//         scanf("%s", correctAnswer);
//         q[key][i[key]].correctAnswer = correctAnswer[0];

//         i[key]++;
// }
void printQuestion(Question *question){
    printf("%d\n", question->difficulty);
    printf("%s\n", question->question);
    printf("%s\n", question->answerA);
    printf("%s\n", question->answerB);
    printf("%s\n", question->answerC);
    printf("%s\n", question->answerD);
    printf("%c\n", question->correctAnswer);

}
void printQuestions(struct Node **questions){

    for(int i = 0; i < 10; i++){
        struct Node *currentNode = questions[i];
        while(currentNode != NULL){
            printQuestion(currentNode->question);
            currentNode = currentNode->next;
        }
    }

}

