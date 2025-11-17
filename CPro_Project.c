#include <stdio.h>
#include <string.h>

char Board[24][24];

int Check_Square(int i, int j) {
    if (i < 1 || i > 22 || j < 1 || j > 22) {
        return 0;
    }

    if (Board[i][j] != '.') {
        return 0;
    }

    return 1;
}

void Print_Board() {
    const char* red = "\033[1;31m";
    const char* blue = "\033[1;34m";
    const char* reset = "\033[0m";
    
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 24; j++) {
            if ((i == 0 && j == 0) || (i == 0 && j == 23) || (i == 23 && j == 0) || (i == 23 && j == 23)){
                printf("  ");
                continue;
            }

            if (i == 0 && j > 0 && j < 23) {
                printf("%s- %s", red, reset);
                continue;
            }

            if (i == 23 && j > 0 && j < 23) {
                printf("%s- %s", red, reset);
                continue;
            }

            if (j == 0 && i > 0 && i < 23) {
                printf("%s| %s", blue, reset);
                continue;
            }

            if (j == 23 && i > 0 && i < 23) {
                printf("%s| %s", blue, reset);
                continue;
            }

            if (Board[i][j] == 'R') {
                printf("%sR %s", red, reset);
            }
            else if (Board[i][j] == 'B') {
                printf("%sB %s", blue, reset);
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    const char* red = "\033[1;31m";
    const char* blue = "\033[1;34m";
    const char* reset = "\033[0m";
    
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 24; j++) {
            Board[i][j] = '.';
        }
    }

    int x, y;
    char User_1[101], User_2[101];
    
    fgets(User_1, sizeof(User_1), stdin);
    User_1[strcspn(User_1, "\n")] = '\0';

    fgets(User_2, sizeof(User_2), stdin);
    User_2[strcspn(User_2, "\n")] = '\0';

    Print_Board();

    while(1) {
        while(1) {
            printf("%s%s%s, enter row and column: ", red, User_1, reset);
            scanf("%d %d", &x, &y);
            if (Check_Square(x, y) == 1) break;
            printf("Invalid. Try again.\n");
        }

        Board[x][y] = 'R';
        Print_Board();

        while(1) {
            printf("%s%s%s, enter row and column: ", blue, User_2, reset);
            scanf("%d %d", &x, &y);
            if (Check_Square(x, y) == 1) break;
            printf("Invalid. Try again.\n");
        }

        Board[x][y] = 'B';
        Print_Board();
    }

    return 0;
}