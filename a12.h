void getList(int n, FILE *wordList, char arr[849][40]);
void pullWord(int n, char word[], char arr[849][40]);
void createBlank(char array[], char arr2[]);
void enterGuess(char arr2[], char word[], int *lives);
void printMan(int lives);

void getList(int n, FILE *wordList, char arr[849][40]){

    int i;
    int j;

    for(i = 0; i <= n ; i++){
        fscanf(wordList,"%d", &arr[i]);
        for(j = 0; j < n ; j++){
            fscanf(wordList,"%s", &arr[j]);
        }
    }
}

void pullWord(int n, char arr1[], char arr[849][40]){
    int i;
    int r = rand() % n;
    int length = strlen(arr[r]);

    for(i = 0; i <= length; i++){
        arr1[i] = arr[r][i];
    }
}

void createBlank(char arr1[], char arr2[]){

    int i;
    char under = 95;
    int n = strlen(arr2);

    for(i = 0; i < n; i++){
        arr1[i] = under;
    }
}

void enterGuess(char arr1[], char arr2[], int *lives){
    int i;
    char guess;
    char garb;
    char under = 95;
    int n = strlen(arr2);
    int check = 1;
    printf("Guess a character: ");
    scanf("%c", &guess);
    scanf("%c", &garb);
    for(i = 0; i <= n; i++){
        if(guess == arr2[i]){
            arr1[i] = guess;
            check = 0;
        }
    }
    if(check == 1){
        --*lives;
        }
}

void printMan(int lives){
    switch(lives){
        case 0:
        puts(" _______");
        puts(" |/     |");
        puts(" |     (_)");
        puts(" |     \\|/");
        puts(" |      |");
        puts(" |     / \\");
        puts(" |");
        puts("_|___");
        
        break;

        case 1:
        puts(" _______");
        puts(" |/    |");
        puts(" |    (_)");
        puts(" |    \\|/");
        puts(" |     |");
        puts(" |    /");
        puts(" |");
        puts("_|___");

        break;

        case 2:
        puts(" _______");
        puts(" |/    |");
        puts(" |    (_)");
        puts(" |    \\|/");
        puts(" |     |");
        puts(" |");
        puts(" |");
        puts("_|___");

        break;

        case 3:

        puts(" _______");
        puts(" |/    |");
        puts(" |    (_)");
        puts(" |    \\|/");
        puts(" |");
        puts(" |");
        puts(" |");
        puts("_|___");

        break;

        case 4:

        puts(" _______");
        puts(" |/    |");
        puts(" |    (_)");
        puts(" |    \\|");
        puts(" |");
        puts(" |");
        puts(" |");
        puts("_|___");

        break;

        case 5:

        puts(" _______");
        puts(" |/    |");
        puts(" |    (_)");
        puts(" |");
        puts(" |");
        puts(" |");
        puts(" |");
        puts("_|___");

        break;

        case 6:

        puts(" _______");
        puts(" |/    |");
        puts(" |");
        puts(" |");
        puts(" |");
        puts(" |");
        puts(" |");
        puts("_|___");

    }
}