#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<time.h>
#define MAX_LINE_LEN 256

typedef struct{
    int dificulty;
    char question[MAX_LINE_LEN];
    char answerA[MAX_LINE_LEN];
    char answerB[MAX_LINE_LEN];
    char answerC[MAX_LINE_LEN];
    char answerD[MAX_LINE_LEN];
    char correctAnswer;
} Question;

void arrowhere(int realPosition, int arrowPosition);

void menu(){
    system("cls");

    int position = 1;
    int keyPressed = 0;

    if(keyPressed = 13 && position == 1){
        system("cls");
    }else if(keyPressed = 13 && position == 2){
        system("cls");
    }else if(keyPressed = 13 && position == 3){
        system("cls");
    }else if(keyPressed = 13 && position == 4){
        return;
    }

    while (keyPressed != 13){
        FILE* title;
        char str[150];
        title = fopen("title.txt", "r");
 
        if(title == NULL){
            printf("Error with the title \n\n");
        }else{
            while(fgets(str, 150, title) != NULL){
                printf("%s", str);
            }
        }
 
        fclose(title);
    
        printf("\n\n\n");
        arrowhere(1, position);printf("|| START GAME\n");
        arrowhere(2, position);printf("|| ADD QUESTION\n");
        arrowhere(3, position);printf("|| CHANGE AN EXSISTING QUESTINO\n");
        arrowhere(4, position);printf("|| EXIT\n");

        keyPressed = getch();
        
        if(keyPressed == 40 && position != 4){
            position ++;
        }else if(keyPressed == 38 && position != 1){
            position--;
        }else{
            position == position;
        }

        printf("THE USER SELECT OPTION %d\n",position);
    }
}

void arrowhere(int realPosition, int arrowPosition){
    if(realPosition == arrowPosition){
        printf(" >> ");
    }else{
        printf("    ");
    }
}

void 50/50(Question currentQuestion){
    int firstQ = rand(1,3);
    int secondQ = rand(1,3);
    if(firstQ == secondQ){
        if(falseQ == 1){
            secondQ ++;
        }else{
            secondQ --;
        }
    }
    if(currentQuestion.correctAnswer == 'A'){
        srand(time(0));
        if(firstQ == 1){
            //mahni 4 otgovor or printiraneto
            //mahni secondQ otgovor ot printiraneto
        }
        if(firstQ == 1){
            //mahni 4 otgovor ot printiraneto
            //mahni firstQ otgovor ot printiraneto
        }else{
            //mahni firstQ otgovor ot printiraneto
            //mahni secondQ otgovor ot printiraneto
        }
    }else if(currentQuestion.correctAnswer == 'B'){
        srand(time(0));
        if(firstQ == 2){
            //mahni 4 otgovor or printiraneto
            //mahni secondQ otgovor ot printiraneto
        }
        if(firstQ == 2){
            //mahni 4 otgovor ot printiraneto
            //mahni firstQ otgovor ot printiraneto
        }else{
            //mahni firstQ otgovor ot printiraneto
            //mahni secondQ otgovor ot printiraneto
        }
    }else if(currentQuestion.correctAnswer == 'c'){
        srand(time(0));
        if(firstQ == 3){
            //mahni 4 otgovor or printiraneto
            //mahni secondQ otgovor ot printiraneto
        }
        if(firstQ == 3){
            //mahni 4 otgovor ot printiraneto
            //mahni firstQ otgovor ot printiraneto
        }else{
            //mahni firstQ otgovor ot printiraneto
            //mahni secondQ otgovor ot printiraneto
        }
    }else{
        srand(time(0));
        //mahni firstQ otgovor ot printiraneto
        //mahni secondQ otgovor ot printiraneto
    }
}

int helpFromFriend(Question currentQuestion){
    srand(time(0));
    int help = rand(1,4);

    return help;
}

void helpFromPublic(Question currentQuestion){
    srand(time(0));
    int first = rand(0,100);
    int second = rand(0,100 - first);
    int third = rand(0,100 - first - second);
    int fourth = 100 - first - second - third;
    printf(" Precentage for the first answer: %d\n", first);
    printf(" Precentage for the second answer: %d\n", second);
    printf(" Precentage for the third answer: %d\n", third);
    printf(" Precentage for the fourth answer: %d\n", fourth);
}

int main(){
    FILE *fp = fopen("questions.txt", "r");
    
    if(fp == NULL){
        printf("Cannot open questions file.");
        return 1;
    }
    char difficulty[MAX_LINE_LEN];
    
    while(fgets(difficulty, MAX_LINE_LEN-1, fp) != NULL){
        Question currentQuestion;
        currentQuestion.dificulty = atoi(difficulty);

        char question[MAX_LINE_LEN];
        fgets(question, MAX_LINE_LEN-1, fp);
        strcpy(currentQuestion.question, question);

        char answerA[MAX_LINE_LEN];
        fgets(answerA, MAX_LINE_LEN-1, fp);
        strcpy(currentQuestion.answerA, answerA);

        char answerB[MAX_LINE_LEN];
        fgets(answerB, MAX_LINE_LEN-1, fp);
        strcpy(currentQuestion.answerB, answerB);

        char answerC[MAX_LINE_LEN];
        fgets(answerC, MAX_LINE_LEN-1, fp);
        strcpy(currentQuestion.answerC, answerC);

        char answerD[MAX_LINE_LEN];
        fgets(answerD, MAX_LINE_LEN-1, fp);
        strcpy(currentQuestion.answerD, answerD);

        char correctAnswer[MAX_LINE_LEN];
        fgets(correctAnswer, MAX_LINE_LEN-1, fp);
        strcpy(currentQuestion.correctAnswer, correctAnswer[1]);
        
    }

    if(!kbhit){
        menu();
    }
    return 0;
}