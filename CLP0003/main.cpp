#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *f;
double money;

void readMoney() {
    f = fopen("saveMoney.txt", "r");
    if (f == NULL) {
        money = 10.00;
    } else {
        fscanf(f, "%.2lf", &money);
    }
    fclose(f);
}

void saveMoney() {
    f = fopen("saveMoney.txt", "w");
    fprintf(f, "%.2lf", money);
    fclose(f);
}

void game() {
    int s1 = rand() % 10;
    int s2 = rand() % 10;
    int s3 = rand() % 10;
    int s4 = rand() % 10;
    printf("The slot machine show %d%d%d%d\n", s1, s2, s3, s4);
    money -= 0.25;
    int soSanh = (s1 == s2) + (s1 == s3) + (s1 == s4) + (s2 == s3) + (s2 == s4) + (s3 == s4); 
    if (soSanh == 0) {
        printf("Sorry you don't win anything\n");
    } else if (soSanh == 1) {
        printf("You win 50 cents!\n");
        money += 0.5;        
    } else if (soSanh == 2){
        printf("You win 100 cents!\n");
        money += 1;        
    } else if (soSanh == 3){
        printf("You win the big prize, $10.00!\n");
        money += 10;
    } else if (soSanh == 6){
        printf("You win the bigger prize, $25.00!\n");
        money += 25;
    }
}

int main() {
    srand(time(NULL));
    int choice;
    readMoney();
    do {
        if (money == 0) {
            printf("You run out of money. Better luck next time. Good bye!\n");
            break;
        }
        printf("You have $%.2lf\n", money);
        printf("\nChoose one of the following menu options:\n");
        printf("1) Play the slot machine.\n");
        printf("2) Save game.\n");
        printf("3) Cash out.\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                game();
                break;
            case 2:
                saveMoney();
                printf("Your money had saved!\n");
                break;
            case 3:
                printf("Thank you for playing! You end with $%.2lf!", money);
                break;
        }

    } while (choice != 3);
}
