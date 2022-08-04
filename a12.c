/*  This is a program to play hangman!
    You will be able to read from an included text file
    to generate a random word and then you can guess what the word
    is within your allotted lives. I'll include CLI arguments to
    read the file into the program and it should replace the blanks
    with letters as you go.

    Written by Brennan St. John for CSC250 Final Assignment
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "a12.h"

int main(int argc, char *argv[]){

    srand(time(NULL));

    FILE *wordList;

    wordList = fopen(argv[1], "r");

    if(argc != 2){
        printf("\n\tUsage: '%s filename'\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if(wordList == NULL){
        printf("The file could not be opened.\n");
        exit(EXIT_FAILURE);
    }

    int numWords = 0;

    char garb;

    char arr[849][40];

    char word[] = "";
    char guessing[20];
    char guess;
    int *lives;
    int l = 6;
    lives = &l;

    fscanf(wordList, "%d", &numWords);

    printf("Welcome to Hangman!");

    puts("");

    getList(numWords, wordList, arr);

    puts("");
    
    pullWord(numWords, word, arr);

    printf("#############################\n");
    printf("Hint: The word is '%s'\n", word);
    printf("#############################\n\n");

    createBlank(guessing, word);

    while(*lives > 0 && strcmp(word, guessing) != 0){

        printMan(*lives);
        puts("");
        printf("%s\n\n", guessing);
        enterGuess(guessing, word, lives);
        puts("");
    }
    if(strcmp(word, guessing) == 0){
        printMan(*lives);
        puts("");
        printf("You win!");
    }
    if(*lives <= 0){
        puts("");
        printMan(*lives);
        puts("");
        printf("You lose!");
    }
}
