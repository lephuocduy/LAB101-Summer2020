#include <math.h>
#include <stdio.h>
#include <string.h>

int isSpecialBin(char ch) {
    return (!(ch == '0') && !(ch == '1'));
}

int existBin(char s[]) {
    int i;
    for (i = 0; i < strlen(s); i++) {
        if (isSpecialBin(s[i])) {
            return 1;
        }
    }
    return 0;
}

int isSpecialOct(char ch) {
    return (!(ch == '0') && !(ch == '1') && !(ch == '2') && !(ch == '3') && !(ch == '4') && !(ch == '5') && !(ch == '6') && !(ch == '7'));
}

int existOct(char s[]) {
    int i;
    for (i = 0; i < strlen(s); i++) {
        if (isSpecialOct(s[i])) {
            return 1;
        }
    }
    return 0;
}

int isSpecialHex(char ch) {
    return (!(ch == '0') && !(ch == '1') && !(ch == '2') && !(ch == '3') && !(ch == '4') && !(ch == '5') && !(ch == '6') && !(ch == '7') && !(ch == '8')
            && !(ch == '9') && !(ch == 'A') && !(ch == 'B') && !(ch == 'C') && !(ch == 'D') && !(ch == 'E') && !(ch == 'F'));
}

int existHex(char s[]) {
    int i;
    for (i = 0; i < strlen(s); i++) {
        if (isSpecialHex(s[i])) {
            return 1;
        }
    }
    return 0;
}

void BinAndOct(char s[], int number) {
    int i, sum = 0;
    for (i = strlen(s) - 1; i >= 0; i--) {
        int x = (int) (s[i] - 48);
        sum += (x * pow(number, strlen(s) - i - 1));
    }
    printf("%d\n", sum);
}

void Hex(char s[]) {
    int i, sum = 0;
    int x;
    for (i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == 'A' || s[i] == 'B' || s[i] == 'C' || s[i] == 'D' || s[i] == 'E' || s[i] == 'F') {
            x = (int) (s[i] - 55);
        } else {
            x = (int) (s[i] - 48);
        }
        sum += (x * pow(16, strlen(s) - i - 1));
    }
    printf("%d\n", sum);
}

int main(int argc, const char * argv[]) {
    int choice;
    char esc = 100;
    char s[100];
    do {
        printf("1.Convert binary to decimal number\n");
        printf("2.Convert octal to decimal number\n");
        printf("3.Convert hexadecimal to decimal number\n");
        printf("4.Exit\n");
        printf("Please choose number (1 - 4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                do {
                    do {
                        printf("Enter binary number: ");
                        fflush(stdin);
                        scanf("%[^\n]", s);
                    } while (existBin(s));
                    printf("Decimal number is: ");
                    BinAndOct(s, 2);
                    fflush(stdin);
                    printf("Press enter to continue, e to return the main menu :\n");
                    fflush(stdin);
                    esc = getchar();

                } while (esc != 'e');
                break;
            case 2:
                do {
                    do {
                        printf("Enter octal number: ");
                        fflush(stdin);
                        scanf("%[^\n]", s);
                    } while (existOct(s));
                    printf("Decimal number is: ");
                    BinAndOct(s, 8);
                    fflush(stdin);
                    printf("Press enter to continue, e to return the main menu :\n");
                    fflush(stdin);
                    esc = getchar();

                } while (esc != 'e');
                break;
            case 3:
                do {
                    do {
                        printf("Enter hexa number: ");
                        fflush(stdin);
                        scanf("%[^\n]", s);
                    } while (existHex(s));
                    printf("Decimal number is: ");
                    Hex(s);
                    fflush(stdin);
                    printf("Press enter to continue, e to return the main menu :\n");
                    fflush(stdin);
                    esc = getchar();
                } while (esc != 'e');
                break;
        }

    } while (choice != 4);
    return 0;
}