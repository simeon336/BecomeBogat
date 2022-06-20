#include "moni.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void questionsToFile(Question questions[][100], FILE *fp, int numOfQuestions, int trudnost[]){
    

    for(int i = 0; i < 10; i++){
        if(trudnost[i] != 0){
            for(int y = 0; y < trudnost[i]; y++){
            fprintf(fp, "%s\n", questions[i][y].difficulty);
            fprintf(fp, "%s\n", questions[i][y].question);
            fprintf(fp, "%s\n", questions[i][y].answerA);
            fprintf(fp, "%s\n", questions[i][y].answerB);
            fprintf(fp, "%s\n", questions[i][y].answerC);
            fprintf(fp, "%s\n", questions[i][y].answerD);
            fprintf(fp, "%c\n", questions[i][y].correctAnswer);

            }
        }
        
    }


}

int enterQuestion(Question q[][100], int i[]){

        //int key;

        char difficulty[MAX_LINE_LEN];
        printf("Enter difficulty of the question: ");
        scanf("%s", difficulty);
        getchar();
        //int key = atoi(difficulty.c_str());
        int key = atoi(difficulty)-1;
        strcpy(q[key][i[key]].difficulty, difficulty); //ne raboti



        char question[MAX_LINE_LEN] = {0};
        printf("Enter the question: ");
        // char *question = malloc(sizeof(char)*MAX_LINE_LEN);
        scanf("%[^\n]s", question);
        getchar();
        strcpy(q[key][i[key]].question, question);



        char answerA[MAX_LINE_LEN];
        printf("Enter answer A: ");
        scanf("%[^\n]s", answerA);
        getchar();
        strcpy(q[key][i[key]].answerA, answerA);

        char answerB[MAX_LINE_LEN];
        printf("Enter answer B: ");
        scanf("%[^\n]s", answerB);
        getchar();
        strcpy(q[key][i[key]].answerB, answerB);

        char answerC[MAX_LINE_LEN];
        printf("Enter answer C: ");
        scanf("%[^\n]s", answerC);
        getchar();
        strcpy(q[key][i[key]].answerC, answerC);

        char answerD[MAX_LINE_LEN];
        printf("Enter answer D: ");
        scanf("%[^\n]s", answerD);
        getchar();
        strcpy(q[key][i[key]].answerD, answerD);

        char correctAnswer[MAX_LINE_LEN];
        printf("Enter the letter of the correct answer: ");
        scanf("%s", correctAnswer);
        q[key][i[key]].correctAnswer = correctAnswer[0];

        i[key]++;
}