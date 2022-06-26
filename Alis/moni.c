#include "moni.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void tablePrinter(char table[26][26]){
       for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
           if(j < 25){
               printf("%c", table[i][j]);
           }else{
               printf("%c\n", table[i][j]);
           }
        }
    } 
}


void TableMaker(char table[26][26]){
    char start = 'a';
    for(int i = 0; i < 26; ++i){
        for(int j = 0; j < 26; j++){
            table[i][j] = (i + j + 1) % 26 + start;
        }
    }

}

char* cypher(char table[26][26], char* text, char* key){
    int len = strlen(text);
    char* cyphered = malloc(sizeof(char)*len);

    for(int i = 0; i < len; i++){
        int key_index = i % strlen(key);
        int column = text[i] - 'a';
        int row = key[key_index] - 'a';
        cyphered[i] = table[row][column];

    }

    return cyphered;
}

char *decypher(char table[26][26], char *cypher, char *key){
    int len = strlen(cypher);
    char *decyphered = malloc(sizeof(char)*len);

    for(int i = 0; i < len; i++){
        int key_index = i % strlen(key);
        int offset = key[key_index] - 'a' + 1;
        int AsciiChar = cypher[i] - 'a';
        decyphered[i] = (AsciiChar - offset + 26) % 26 + 'a';
    }

    return decyphered;
}


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

char shiftChar(char c){
    c += 6;
    return c;
}

char unshiftChar(char c){
    c -= 6;
    return c;
}

Question *cryptoQuestion(Question *question){
    Question *currentQuestion = malloc(sizeof(Question));
    char table[26][26] = {0};
    TableMaker(table);
    char key[] = "grec";
    currentQuestion->difficulty = question->difficulty;
    strcpy(currentQuestion->question, cypher(table, question->question, key));
    strcpy(currentQuestion->answerA, cypher(table, question->answerA, key));
    strcpy(currentQuestion->answerB, cypher(table, question->answerB, key));
    strcpy(currentQuestion->answerC, cypher(table, question->answerC, key));
    strcpy(currentQuestion->answerD, cypher(table, question->answerD, key));
    currentQuestion->correctAnswer = shiftChar(question->correctAnswer);

    return currentQuestion;
}

Question *decypherQuestion(Question *question){
    Question *currentQuestion = malloc(sizeof(Question));
    char table[26][26] = {0};
    TableMaker(table);
    char key[] = "grec";
    currentQuestion->difficulty = question->difficulty;
    strcpy(currentQuestion->question, decypher(table, question->question, key));
    strcpy(currentQuestion->answerA, decypher(table, question->answerA, key));
    strcpy(currentQuestion->answerB, decypher(table, question->answerB, key));
    strcpy(currentQuestion->answerC, decypher(table, question->answerC, key));
    strcpy(currentQuestion->answerD, decypher(table, question->answerD, key));
    currentQuestion->correctAnswer = unshiftChar(question->correctAnswer);
    
    return currentQuestion;
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
            writeQuestionToFile(cryptoQuestion(currentNode->question), fp);
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

        addQuestion(questions, decypherQuestion(currentQuestion));
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
