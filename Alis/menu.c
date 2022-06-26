#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include "moni.h"

void printTitle();
void printMenu(int position);
void menu(struct Node **questions, Question *currentQuestion);
void arrowhere(int realPosition, int arrowPosition);
void polovine(Question *currentQuestion);
void printOnlyTwoAnswers(Question *currentQuestion, int first, int second);
void helpFromFriend(Question *currentQuestion);
void helpFromPublic(Question *currentQuestion);
void helpingFunction(Question *currentQuestion, int first, int second, int third, int fourth);
void startGame(struct Node **questions,Question *currentQuestion);
struct Node **chose10Questions(struct Node **questions);
void checkAnswer(struct Node **questions, struct Node **choceQuestions, Question *currentQuestion, int choice, int i);


void printTitle(){
    FILE* title;
    char str[100];
    title = fopen("title.txt", "r");
 
    if(title == NULL){
        printf("Error with the title \n\n");
    }else{
        while(fgets(str, 100, title)){
            printf("%s", str);
        }
    }
    fclose(title);  
}

void printMenu(int position){
    system("cls");

    printTitle();

    printf("\n\n");
    arrowhere(1, position);  printf("|| START GAME\n");
    arrowhere(2, position);  printf("|| ADD QUESTION\n");
    arrowhere(3, position);  printf("|| CHANGE AN EXSISTING QUESTINO\n");
    arrowhere(4, position);  printf("|| EXIT\n");
}

void menu(struct Node **questions, Question *currentQuestion){
    int position = 1;
    char keyPressed = 0;
    do{
        printMenu(position);
        keyPressed = getch();
        if(keyPressed == 80 && position != 4){
            position++;
            printMenu(position);
        }else if(keyPressed == 72 && position != 1){
            position--;
            printMenu(position);
        }else{
            position == position;
        }
    }while(keyPressed != 13);

    if(position == 1){
        printf("the position is %d\n", position);
        system("cls");
        startGame(questions, currentQuestion);
    }else if(position == 2){
        printf("the position is %d\n", position);
        system("cls");
        addQuestion(questions, currentQuestion);
    }else if(position == 3){
        printf("the position is %d\n", position);
        system("cls");
        // changeQuestion(questions, currentQuestion);
    }else if(position == 4){
        printf("the position is %d\n", position);
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
    printTitle();
    printf("\n\n\n");

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
    printOnlyTwoAnswers(currentQuestion, firstQ, secondQ);
    printf("2.Ask a friend for help\n");
    printf("3.Ask the audience for help\n");
}

void printOnlyTwoAnswers(Question *currentQuestion, int first, int second){
    if(first == 0){
        if(second == 1){
            printf("C. %s\n", currentQuestion->answerC);
            printf("D. %s\n", currentQuestion->answerD);
        }else if(second == 2){
            printf("B. %s\n", currentQuestion->answerB);
            printf("D. %s\n", currentQuestion->answerD);
        }else{
            printf("B. %s\n", currentQuestion->answerB);
            printf("C. %s\n", currentQuestion->answerC);
        }
    }else if(first == 1){
        if(second == 0){
            printf("C. %s\n", currentQuestion->answerC);
            printf("D. %s\n", currentQuestion->answerD);
        }else if(second == 2){
            printf("A. %s\n", currentQuestion->answerA);
            printf("D. %s\n", currentQuestion->answerD);
        }else{
            printf("A. %s\n", currentQuestion->answerA);
            printf("C. %s\n", currentQuestion->answerC);
        }
    }else if(first == 2){
        if(second == 0){
            printf("B. %s\n", currentQuestion->answerB);
            printf("D. %s\n", currentQuestion->answerD);
        }else if(second == 1){
            printf("A. %s\n", currentQuestion->answerA);
            printf("D. %s\n", currentQuestion->answerD);
        }else{
            printf("A. %s\n", currentQuestion->answerA);
            printf("B. %s\n", currentQuestion->answerB);
        }
    }else{
        if(second == 0){
            printf("B. %s\n", currentQuestion->answerB);
            printf("C. %s\n", currentQuestion->answerC);
        }else if(second == 1){
            printf("A. %s\n", currentQuestion->answerA);
            printf("C. %s\n", currentQuestion->answerC);
        }else{
            printf("A. %s\n", currentQuestion->answerA);
            printf("B. %s\n", currentQuestion->answerB);
        }
    }
}

void helpFromFriend(Question *currentQuestion){
    srand(time(0));
    int chance = rand() % 100;
    int difficulty = currentQuestion->difficulty;

    if(chance < 80 && difficulty <= 3){
        printf("Your friend think the right answer is %c \n", currentQuestion->correctAnswer);
    }
    else if(chance < 60 && difficulty <= 6 && difficulty >= 4){
        printf("Your friend think the right answer is %c \n", currentQuestion->correctAnswer);
    }
    else if(chance < 30 && difficulty <= 10 && difficulty >= 7){
        printf("Your friend think the right answer is %c \n", currentQuestion->correctAnswer);
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
            printf("Your friend think the right answer is %c \n", result);
        }
    }
}

void helpFromPublic(Question *currentQuestion){
    srand(time(0));
    int first = rand() % 101;
    int second = rand() % (101 - first);
    int third = rand() % (101 - first - second);
    int fourth = 100 - first - second - third;
    int chance = rand() % 100;
    int difficulty = currentQuestion->difficulty;

    if(chance < 80 && difficulty <= 3){
        helpingFunction(currentQuestion, first, second, third, fourth);
    }
    else if(chance < 60 && difficulty <= 6 && difficulty >= 4){
        helpingFunction(currentQuestion, first, second, third, fourth);
    }
    else if(chance < 30 && difficulty <= 10 && difficulty >= 7){
        helpingFunction(currentQuestion, first, second, third, fourth);
    }
    else{
        if(first > second && first > third && first > fourth && currentQuestion->correctAnswer == 'A'){
            printf(" Precentage for the answer A: %d\n", second);
            printf(" Precentage for the answer B: %d\n", first);
            printf(" Precentage for the answer C: %d\n", third);
            printf(" Precentage for the answer D: %d\n", fourth);
        }
        else if(second > first && second > third && second > fourth && currentQuestion->correctAnswer == 'B'){
            printf(" Precentage for the answer A: %d\n", first);
            printf(" Precentage for the answer B: %d\n", third);
            printf(" Precentage for the answer C: %d\n", second);
            printf(" Precentage for the answer D: %d\n", fourth);
        }
        else if(third > first && third > second && third > fourth && currentQuestion->correctAnswer == 'C'){
            printf(" Precentage for the answer A: %d\n", first);
            printf(" Precentage for the answer B: %d\n", second);
            printf(" Precentage for the answer C: %d\n", fourth);
            printf(" Precentage for the answer D: %d\n", third);
        }
        else if(fourth > first && fourth > second && fourth > third && currentQuestion->correctAnswer == 'D'){
            printf(" Precentage for the answer A: %d\n", fourth);
            printf(" Precentage for the answer B: %d\n", second);
            printf(" Precentage for the answer C: %d\n", third);
            printf(" Precentage for the answer D: %d\n", first);
        }else{
            printf(" Precentage for the answer A: %d\n", first);
            printf(" Precentage for the answer B: %d\n", second);
            printf(" Precentage for the answer C: %d\n", third);
            printf(" Precentage for the answer D: %d\n", fourth);
        }
    } 
}

void helpingFunction(Question *currentQuestion, int first, int second, int third, int fourth){
    if(first > second && first > third && first > fourth){
        printf(" Precentage for the answer %c: %d\n", currentQuestion->correctAnswer, first);
        if(currentQuestion->correctAnswer == 'A'){
            printf(" Precentage for the answer B: %d\n", second);
            printf(" Precentage for the answer C: %d\n", third);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else if(currentQuestion->correctAnswer == 'B'){
            printf(" Precentage for the answer A: %d\n", second);
            printf(" Precentage for the answer C: %d\n", third);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else if(currentQuestion->correctAnswer == 'C'){
            printf(" Precentage for the answer A: %d\n", third);
            printf(" Precentage for the answer B: %d\n", second);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else{
            printf(" Precentage for the answer A: %d\n", fourth);
            printf(" Precentage for the answer B: %d\n", second);
            printf(" Precentage for the answer C: %d\n", third);
        }
    }else if(second > first && second > third && second > fourth){
        printf(" Precentage for the answer %c: %d\n", currentQuestion->correctAnswer, second);
        if(currentQuestion->correctAnswer == 'A'){
            printf(" Precentage for the answer B: %d\n", first);
            printf(" Precentage for the answer C: %d\n", third);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else if(currentQuestion->correctAnswer == 'B'){
            printf(" Precentage for the answer A: %d\n", first);
            printf(" Precentage for the answer C: %d\n", third);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else if(currentQuestion->correctAnswer == 'C'){
            printf(" Precentage for the answer A: %d\n", first);
            printf(" Precentage for the answer B: %d\n", third);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else{
            printf(" Precentage for the answer A: %d\n", first);
            printf(" Precentage for the answer B: %d\n", fourth);
            printf(" Precentage for the answer C: %d\n", third);
        }
    }else if(third > first && third > second && third > fourth){
        printf(" Precentage for the answer %c: %d\n", currentQuestion->correctAnswer, third);   
        if(currentQuestion->correctAnswer == 'A'){
            printf(" Precentage for the answer B: %d\n", first);
            printf(" Precentage for the answer C: %d\n", second);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else if(currentQuestion->correctAnswer == 'B'){
            printf(" Precentage for the answer A: %d\n", first);
            printf(" Precentage for the answer C: %d\n", second);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else if(currentQuestion->correctAnswer == 'C'){
            printf(" Precentage for the answer A: %d\n", first);
            printf(" Precentage for the answer B: %d\n", second);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else{
            printf(" Precentage for the answer A: %d\n", first);
            printf(" Precentage for the answer B: %d\n", second);
            printf(" Precentage for the answer C: %d\n", fourth);
        } 
    }else{
        printf(" Precentage for the answer %c: %d\n", currentQuestion->correctAnswer, fourth);
        if(currentQuestion->correctAnswer == 'A'){
            printf(" Precentage for the answer B: %d\n", second);
            printf(" Precentage for the answer C: %d\n", third);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else if(currentQuestion->correctAnswer == 'B'){
            printf(" Precentage for the answer A: %d\n", first);
            printf(" Precentage for the answer C: %d\n", third);
            printf(" Precentage for the answer D: %d\n", fourth);
        }else if(currentQuestion->correctAnswer == 'C'){
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

void startGame(struct Node **questions, Question *currentQuestion){
    struct Node **choceQuestions = chose10Questions(questions);
    int choice;
    for(int i = 0; i < 10; i++){
        system("cls");

        printf("%d. %s \n", i+1, choceQuestions[i]->question->question);
        printf("A. %s \n", choceQuestions[i]->question->answerA);
        printf("B. %s \n", choceQuestions[i]->question->answerB);
        printf("C. %s \n", choceQuestions[i]->question->answerC);
        printf("D. %s \n", choceQuestions[i]->question->answerD);

        if(choceQuestions[i]->joker1 == false){
            printf("1. 50/50 \n");
        }
        if(choceQuestions[i]->joker2 == false){
            printf("2. Ask a friend for help \n");
        }
        if(choceQuestions[i]->joker3 == false){
            printf("3. Ask the audience for help \n");
        }

        printf("Choose your answer only from the above options.\n And your answer is: ");
        scanf("%d", &choice);
        checkAnswer(questions, choceQuestions, currentQuestion, choice, i);
    }
    printf("Congratulations! You won the game!\n");
    menu(questions, currentQuestion);
    return;
}

void checkAnswer(struct Node **questions, struct Node **choceQuestions, Question *currentQuestion, int choice, int i){
    printf("Choose your answer only from the above options.\n And your answer is: ");
    scanf("%d", &choice);

    if(choceQuestions[i]->joker1 == false && choice == 1){
        polovin(choceQuestions[i]->question);
        for(int j = 0; j < 10; j++){
            choceQuestions[i]->joker1 = true;
        }

        int newchoice;
        printf("Choose your answer only from the above options.\n And your answer is: ");
        scanf("%d", &newchoice);
        checkAnswer(questions, choceQuestions,currentQuestion, newchoice, i);
    }
    else if(choceQuestions[i]->joker2 == false && choice == 2){
        helpFromFriend(choceQuestions[i]->question);
        for(int j = 0; j < 10; j++){
            choceQuestions[j]->joker2 = true;
        }

        int newchoice;
        printf("Choose your answer only from the above options.\n And your answer is: ");
        scanf("%d", &newchoice);
        checkAnswer(questions, choceQuestions, currentQuestion, newchoice, i);
    }
    else if(choceQuestions[i]->joker3 == false && choice == 3){
        helpFromPublic(choceQuestions[i]->question);
        for(int j = 0; j < 10; j++){
            choceQuestions[j]->joker3 = true;
        }
        
        int newchoice;
        printf("Choose your answer only from the above options.\n And your answer is: ");
        scanf("%d", &newchoice);
        checkAnswer(questions, choceQuestions, currentQuestion, newchoice, i);
    }
    else if(choice == atoi(&choceQuestions[i]->question->correctAnswer)){
            printf("Correct!\n");
    }else{
        printf("You lose!\n");
        for(int j = 0; j < 10; j++){
            choceQuestions[i]->joker1 = false;
            choceQuestions[i]->joker2 = false;
            choceQuestions[i]->joker3 = false;
        }
        menu(questions, currentQuestion);
        return;
    }
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
    char fileName[] = "questions.txt";

    struct Node **questions = initHashTable();
    questions = readQuestions(fileName);
    
    Question *currentQuestion = malloc(sizeof(Question));
    
    menu(questions, currentQuestion);
    
    return 0;
}
