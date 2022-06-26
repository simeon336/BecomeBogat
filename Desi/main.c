#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_LINE_LEN 256
#define MAX_LINE 256
#define FILENAME_SIZE 256
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



int cmp(char *str1, char *str2){
    for(int i = 0; i < strlen(str1); i++){
        if(str1[i] != str2[i]){
            return 1;
        }
    }
    return 0;
}


struct Node **initHashTable();
bool writeToFile(struct Node **questions, char* fileName);
void writeQuestionToFile(Question *question, FILE *fp);
void addQuestion(struct Node **questions, Question *currentQuestion);
Question* enterQuestion();
void removeNewLine(char* string);
struct Node **readQuestions(char *fileName);
void printQuestion(Question *question);
void printQuestions(struct Node **questions);

void addQuestion(struct Node **questions, Question *currentQuestion){
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

struct Node **initHashTable(){
    struct Node **questions = malloc(sizeof(struct Node*)*10);

    for(int i = 0; i < 10; i++){
        questions[i] = NULL;
    }
    return questions;
}

void writeQuestionToFile(Question *question, FILE *fp){
    fprintf(fp, "%d\n", question->difficulty);
    fprintf(fp, "%s\n", question->question);
    fprintf(fp, "%s\n", question->answerA);
    fprintf(fp, "%s\n", question->answerB);
    fprintf(fp, "%s\n", question->answerC);
    fprintf(fp, "%s\n", question->answerD);
    fprintf(fp, "%c\n", question->correctAnswer);
}

bool writeToFile(struct Node **questions, char* fileName){
    FILE *fp = fopen(fileName, "w");

    if(fp == NULL){
        printf("Cannot open questions file.");
        return false;
    }

    for(int i = 0; i < 10; i++){
        struct Node *currentNode = questions[i];
        while(currentNode != NULL){
            writeQuestionToFile(currentNode->question, fp);
            currentNode = currentNode->next;
        }
    }
    fclose(fp);
    return true;
}

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
    struct Node **questions = initHashTable();

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

        addQuestion(questions, currentQuestion);
    }
    fclose(fp);
    return questions;

}

Question *enterQuestion(){
        Question *question = malloc(sizeof(Question));
        int difficulty;
        printf("Enter dificulty: ");
        scanf("%d", &difficulty);
        getchar();
        question->difficulty = difficulty;

        char *currentQuestion = malloc(sizeof(char)*MAX_LINE_LEN);
        printf("Enter the question: ");
        size_t size = MAX_LINE_LEN;
        getline(&currentQuestion, &size, stdin);
        removeNewLine(currentQuestion);
        strcpy(question->question, currentQuestion);

        char *answerA = malloc(sizeof(char)*MAX_LINE_LEN);
        printf("Enter answer A: ");
        getline(&answerA, &size, stdin);
        removeNewLine(answerA);
        strcpy(question->answerA, answerA);

        char *answerB = malloc(sizeof(char)*MAX_LINE_LEN);
        printf("Enter answer B: ");
        getline(&answerB, &size, stdin);
        removeNewLine(answerB);
        strcpy(question->answerB, answerB);

        char *answerC = malloc(sizeof(char)*MAX_LINE_LEN);
        printf("Enter answer C: ");
        getline(&answerC, &size, stdin);
        removeNewLine(answerC);
        strcpy(question->answerC, answerC);

        char *answerD = malloc(sizeof(char)*MAX_LINE_LEN);
        printf("Enter answer D: ");
        getline(&answerD, &size, stdin);
        removeNewLine(answerD);
        strcpy(question->answerD, answerD);

        char *correctAnswer = malloc(sizeof(char)*MAX_LINE_LEN);
        printf("Enter the letter of the correct answer: ");
        getline(&correctAnswer, &size, stdin);
        removeNewLine(correctAnswer);
        question->correctAnswer = correctAnswer[0];

        return question;
}

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


void change_question(struct Node **questions, char *textQ, int difficulty){
    struct Node *current = questions[difficulty-1];
    int count = 0;



    while(current != NULL){
        if(strcmp(textQ, current->question->question) == 0){
            break;
        }

        current = current->next;
        count++;
        printf("%d\n", count);
        printf("%d\n", current->question->difficulty);
    }

    int option;

    for(int i = 0; i < 7; i++){
        printf("What do you want to change?r");
        printf("1 - question");
        printf("2 - difficulty");
        printf("3 - answer A");
        printf("4 - answer B");
        printf("5 - answer C");
        printf("6 - answer D");
        printf("7 - correctAnswer");
        printf("8 - nothing");
        scanf("%d", &option);


        if(option == 2){
            int new;
            printf("Enter new difficultyf: ");
            scanf("%d", &new);
            questions[difficulty-1]->question->difficulty = new;

        }else if(option == 1){
            char new[50];
            printf("Enter new question: ");
            scanf("%s", new);
            strcpy(questions[difficulty-1]->question->difficulty, new);
        }else if(option == 7){
            char new[50];
            printf("Enter new correct answer: ");
            scanf("%s", new);
            strcpy(questions[difficulty-1]->question->correctAnswer, new);
        }else if(option == 3){
            char new[50];
            printf("Enter new answer A: ");
            scanf("%s", new);
            strcpy(questions[difficulty-1]->question->answerA, new);
        }
        else if(option == 4){
            char new[50];
            printf("Enter new answer B: ");
            scanf("%s", new);
            strcpy(questions[difficulty-1]->question->answerB, new);
        }
        else if(option == 5){
            char new[50];
            printf("Enter new answer C: ");
            scanf("%s", new);
            strcpy(questions[difficulty-1]->question->answerC, new);
        }
        else if(option == 6){
            char new[50];
            printf("Enter new answer D: ");
            scanf("%s", new);
            strcpy(questions[difficulty-1]->question->answerD, new);
        }else if(option == 8){
            break;
        }

    }
}



void replaceLine(char *fileName){
    FILE *file = fopen(fileName, "r");



    char currentLine[100];
    char oldquestion[] = {"trew"};

    fgets(currentLine, MAX_LINE_LEN-1, file);
    int len2 = strlen(currentLine);
    currentLine[len2-1] = '\0';

    printf("O: %s", oldquestion);
    printf("C: %s", currentLine);

    int count = 0;

    while(strcmp(currentLine, oldquestion) != 0){

        printf("O: %s", oldquestion);
        printf("C: %s", currentLine);
        printf(".");
        fgets(currentLine, MAX_LINE_LEN-1, file);
        len2 = strlen(currentLine);
        currentLine[len2-1] = '\0';
        count++;
    }


    printf("COUNT: %d", count);
    int option;
    int replace_line;

    for(int i = 0; i < 7; i++){
        printf("What do you want to change?r");
        printf("1 - question");
        printf("2 - difficulty");
        printf("3 - answer A");
        printf("4 - answer B");
        printf("5 - answer C");
        printf("6 - answer D");
        printf("7 - correctAnswer");
        printf("8 - nothing");
        scanf("%d", &option);


        if(option == 2){
            replace_line = count + 1;
            int new;
            printf("Enter new difficultyf: ");
            scanf("%d", &new);
            replaceLineinfile(file, replace_line, new);

        }else if(option == 1){
            replace_line = count + 2;
            char new[50];
            printf("Enter new question: ");
            scanf("%s", new);
            replaceLineinfile(file, replace_line, new);
        }else if(option == 7){
            replace_line = count + 7;
            char new[50];
            printf("Enter new correct answer: ");
            scanf("%s", new);
            replaceLineinfile(file, replace_line, new);
        }else if(option == 3){
            replace_line = count + 3;
            char new[50];
            printf("Enter new answer A: ");
            scanf("%s", new);
            replaceLineinfile(file, replace_line, new);
        }
        else if(option == 4){
            replace_line = count + 4;
            char new[50];
            printf("Enter new answer B: ");
            scanf("%s", new);
            replaceLineinfile(file, replace_line, new);
        }
        else if(option == 5){
            replace_line = count + 5;
            char new[50];
            printf("Enter new answer C: ");
            scanf("%s", new);
            replaceLineinfile(file, replace_line, new);
        }
        else if(option == 6){
            replace_line = count + 6;
            char new[50];
            printf("Enter new answer D: ");
            scanf("%s", new);
            replaceLineinfile(file, replace_line, new);
        }else if(option == 8){
            break;
        }

    }


}


void replaceLineinfile(char *fileName, int replace_line, char* replace){
    FILE *file = fopen(fileName, "r");
    FILE *temp;


    char temp_filename[FILENAME_SIZE];

    char buffer[MAX_LINE];


    strcpy(temp_filename, "temp");
    strcat(temp_filename, fileName);


    int len = strlen(replace);
    replace[len] = '\n';

    fflush(stdin);


    temp = fopen(temp_filename, "w");

    bool keep_reading = true;

    int current_line = 1;

    do{
        fgets(buffer, MAX_LINE, file);

        if (feof(file)) keep_reading = false;

        else if (current_line == replace_line)
        fputs(replace, temp);
        else fputs(buffer, temp);

        current_line++;

    }while (keep_reading);

      fclose(file);
      fclose(temp);

      remove(fileName);
      rename(temp_filename, fileName);
}


int main(){

    char fileName[] = "questions.txt";
    char *str = {"str"};
    int dif = 2;

    int numOfQuestions = 2;

    struct Node **questions = initHashTable();
    Question *q1 = enterQuestion();
    Question *q2 = enterQuestion();
    addQuestion(questions, q1);
    addQuestion(questions, q2);

    writeToFile(questions, fileName);



    change_question(questions, str, dif);


    replaceLine(fileName);



}
