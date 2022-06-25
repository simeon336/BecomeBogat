#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include "moni.h"

void printMenu(int position);
void menu();
void arrowhere(int realPosition, int arrowPosition);
void polovine(Question *currentQuestion);
char helpFromFriend(Question *currentQuestion);
char helpFromPublic(Question *currentQuestion);
void helpingFunction(Question currentQuestion, int first, int second, int third, int fourth);
void startGame();
struct Node **chose10Questions(struct Node **questions);


void printMenu(int position){
    system("cls");

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
    arrowhere(1, position);  printf("|| START GAME\n");
    arrowhere(2, position);  printf("|| ADD QUESTION\n");
    arrowhere(3, position);  printf("|| CHANGE AN EXSISTING QUESTINO\n");
    arrowhere(4, position);  printf("|| EXIT\n");
}

void menu(){
    int position = 1;
    int keyPressed = 0;
    do{
        keyPressed = getch();
        printMenu(position);
        if(keyPressed == 80 && position != 4){
            position ++;
            printMenu(position);
        }else if(keyPressed == 72 && position != 1){
            position--;
            printMenu(position);
        }else{
            position == position;
        }
    }while(keyPressed != 13);

    if(position == 1){
        //statrt game
    }else if(position == 2){
        //  addQuestion();
    }else if(position == 3){
        // changeQuestion();
    }else if(position == 4){
        return;
    }        
}

void arrowhere(int realPosition, int arrowPosition){
    if(realPosition == arrowPosition){
        printf(" >> ");
    }else{
        printf("    ");
    }
}

void polovin(Question *currentQuestion){
    srand(time(0));
    int firstQ = rand() % 3;
    int secondQ = rand() % 3;
    if(firstQ == secondQ){
        if(firstQ == 0){
            secondQ ++;
        }else{
            secondQ --;
        }
    }
    if(currentQuestion->correctAnswer == 'A'){
        if(firstQ == 0){
            //mahni 4 otgovor ot printiraneto
            //mahni firstQ otgovor ot printiraneto
        }else{
            //mahni firstQ otgovor ot printiraneto
            //mahni secondQ otgovor ot printiraneto
        }
    }else if(currentQuestion->correctAnswer == 'B'){
        if(firstQ == 1){
            //mahni 4 otgovor ot printiraneto
            //mahni firstQ otgovor ot printiraneto
        }else{
            //mahni firstQ otgovor ot printiraneto
            //mahni secondQ otgovor ot printiraneto
        }
    }else if(currentQuestion->correctAnswer == 'c'){
        if(firstQ == 2){
            //mahni 4 otgovor ot printiraneto
            //mahni firstQ otgovor ot printiraneto
        }else{
            //mahni firstQ otgovor ot printiraneto
            //mahni secondQ otgovor ot printiraneto
        }
    }else{
        //mahni firstQ otgovor ot printiraneto
        //mahni secondQ otgovor ot printiraneto
    }
}

char helpFromFriend(Question *currentQuestion){
    srand(time(0));
    int chance = rand() % 100;
    int difficulty = currentQuestion->difficulty;

    if(chance < 80 && difficulty <= 3){
        return currentQuestion->correctAnswer;
    }
    else if(chance < 60 && difficulty <= 6 && difficulty >= 4){
        return currentQuestion->correctAnswer;
    }
    else if(chance < 30 && difficulty <= 10 && difficulty >= 7){
        return currentQuestion->correctAnswer;
    }
    else{
        int intResult = rand() % 3;
        char result;
        if(intResult == atoi(&currentQuestion->correctAnswer)){
            if(intResult == 0){
                intResult++;
                result = intResult + '0';
            }else{
                intResult--;
                result = intResult + '0';
            }
            return result;
        }
    }
}

char helpFromPublic(Question *currentQuestion){
    srand(time(0));
    int first = rand() % 101;
    int second = rand() % (101 - first);
    int third = rand() % (101 - first - second);
    int fourth = 100 - first - second - third;
    int chance = rand() % 100;
    int difficulty = currentQuestion->difficulty;

    if(chance < 80 && difficulty <= 3){
        return currentQuestion->correctAnswer;
    }
    else if(chance < 60 && difficulty <= 6 && difficulty >= 4){
        return currentQuestion->correctAnswer;
    }
    else if(chance < 30 && difficulty <= 10 && difficulty >= 7){
        return currentQuestion->correctAnswer;
    }
    else{
        int intResult = rand() % 3;
        char result;
        if(intResult == atoi(&currentQuestion->correctAnswer)){
            if(intResult == 0){
                intResult++;
                result = intResult + '0';
            }else{
                intResult--;
                result = intResult + '0';
            }
            return result;
        }
    }


    
}

void helpingFunction(Question currentQuestion, int first, int second, int third, int fourth){
    if(first > second && first > third && first > fourth){
        printf(" Precentage for the answer %c: %d\n", currentQuestion.correctAnswer, first);
        if(currentQuestion.correctAnswer == 'A'){
            printf(" Precentage for the answer B: %d\n", second);
            printf(" Precentage for the answer C: %d\n", third);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else if(currentQuestion.correctAnswer == 'B'){
            printf(" Precentage for the answer A: %d\n", second);
            printf(" Precentage for the answer C: %d\n", third);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else if(currentQuestion.correctAnswer == 'C'){
            printf(" Precentage for the answer A: %d\n", third);
            printf(" Precentage for the answer B: %d\n", second);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else{
            printf(" Precentage for the answer A: %d\n", fourth);
            printf(" Precentage for the answer B: %d\n", second);
            printf(" Precentage for the answer C: %d\n", third);
        }
    }else if(second > first && second > third && second > fourth){
        printf(" Precentage for the answer %c: %d\n", currentQuestion.correctAnswer, second);
        if(currentQuestion.correctAnswer == 'A'){
            printf(" Precentage for the answer B: %d\n", first);
            printf(" Precentage for the answer C: %d\n", third);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else if(currentQuestion.correctAnswer == 'B'){
            printf(" Precentage for the answer A: %d\n", first);
            printf(" Precentage for the answer C: %d\n", third);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else if(currentQuestion.correctAnswer == 'C'){
            printf(" Precentage for the answer A: %d\n", first);
            printf(" Precentage for the answer B: %d\n", third);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else{
            printf(" Precentage for the answer A: %d\n", first);
            printf(" Precentage for the answer B: %d\n", fourth);
            printf(" Precentage for the answer C: %d\n", third);
        }
    }else if(third > first && third > second && third > fourth){
        printf(" Precentage for the answer %c: %d\n", currentQuestion.correctAnswer, third);   
        if(currentQuestion.correctAnswer == 'A'){
            printf(" Precentage for the answer B: %d\n", first);
            printf(" Precentage for the answer C: %d\n", second);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else if(currentQuestion.correctAnswer == 'B'){
            printf(" Precentage for the answer A: %d\n", first);
            printf(" Precentage for the answer C: %d\n", second);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else if(currentQuestion.correctAnswer == 'C'){
            printf(" Precentage for the answer A: %d\n", first);
            printf(" Precentage for the answer B: %d\n", second);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else{
            printf(" Precentage for the answer A: %d\n", first);
            printf(" Precentage for the answer B: %d\n", second);
            printf(" Precentage for the answer C: %d\n", fourth);
        } 
    }else{
        printf(" Precentage for the answer %c: %d\n", currentQuestion.correctAnswer, fourth);
        if(currentQuestion.correctAnswer == 'A'){
            printf(" Precentage for the answer B: %d\n", second);
            printf(" Precentage for the answer C: %d\n", third);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else if(currentQuestion.correctAnswer == 'B'){
            printf(" Precentage for the answer A: %d\n", first);
            printf(" Precentage for the answer C: %d\n", third);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else if(currentQuestion.correctAnswer == 'C'){
            printf(" Precentage for the answer A: %d\n", first);
            printf(" Precentage for the answer B: %d\n", second);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else{
            printf(" Precentage for the answer A: %d\n", first);
            printf(" Precentage for the answer B: %d\n", second);
            printf(" Precentage for the answer C: %d\n", third);
        }
    }
}

void startGame(struct Node **questions){
    struct Node **choceQuestions = chose10Questions(questions);
    int choice;
    for(int i = 0; i < 10; i++){
        printf("%d. %s \n", i, choceQuestions[i]->question->question);
        printf("A. %s \n", choceQuestions[i]->question->answerA);
        printf("B. %s \n", choceQuestions[i]->question->answerB);
        printf("C. %s \n", choceQuestions[i]->question->answerC);
        printf("D. %s \n", choceQuestions[i]->question->answerD);

        if(choceQuestions[i]->question->joker1 == false){
            printf("1. 50/50 \n");
        }
        if(choceQuestions[i]->question->joker2 == false){
            printf("2. Ask a friend for help \n");
        }
        if(choceQuestions[i]->question->joker3 == false){
            printf("3. Ask the audience for help \n");
        }

        scanf("%d", &choice);

        if(choceQuestions[i]->question->joker2 == false && choice == 1){
            polovin(choceQuestions[i]->question);
        }
        else if(choceQuestions[i]->question->joker2 == false && choice == 2){
            helpFromFriend(choceQuestions[i]->question);
        }
        else if(choceQuestions[i]->question->joker3 == false && choice == 3){
            helpFromPublic(choceQuestions[i]->question);
        }
        else if(choice == 65 || choice == 97){
            if(choceQuestions[i]->question->correctAnswer == 'A'){
                printf("Correct!\n");
            }
        }
        else if(choice == 66 || choice == 98){
            if(choceQuestions[i]->question->correctAnswer == 'B'){
                printf("Correct!\n");
            }
        }
        else if(choice == 67 || choice == 99){
            if(choceQuestions[i]->question->correctAnswer == 'C'){
                printf("Correct!\n");
            }
        }
        else if(choice == 68 || choice == 100){
            if(choceQuestions[i]->question->correctAnswer == 'D'){
                printf("Correct!\n");
            }
        }else{
            printf("Wrong answer!\n");
            menu();
            return;
        }
    }
    printf("Congratulations! You won the game!\n");
    menu();
    return;
}

struct Node **chose10Questions(struct Node **questions){
    int randNum;
    struct Node **chosenQuestions = malloc(sizeof(struct Node*) * 10);
    srand(time(0));
    for(int j = 0; j <10; j++){
        randNum = rand() % 5;
        struct Node **temp = questions;
        for(int i = 0; i <randNum ; i++){
            temp[j] = temp[j]->next;
        }
        chosenQuestions[j] = temp[j];   
    }
    return chosenQuestions;
}

int main(){
    menu();
   
    return 0;
}