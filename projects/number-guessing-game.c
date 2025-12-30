#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void game_funtion(int *win, int *lost);
void update_file(const char *user, int win, int lost);


int main() {
    srand(time(0));
    int win = 0, lost = 0, found = 0;
    char user[1024], name[1024];

    printf("Enter Your Name: ");
    scanf("%1023s", user);

    FILE *fptr = fopen("player.txt", "r");
    if (!fptr) {
        printf("Failed to open file\n");
        return 1;
    }

    // search user
    while (fscanf(fptr, "%1023s %d %d", name, &win, &lost) == 3) {
        if (strcmp(user, name) == 0) {
            found = 1;
            break;
        }
    }
    fclose(fptr);

    // new user
    if (!found) {
        win = 0, lost = 0;
        fptr = fopen("player.txt", "a");
        fprintf(fptr, "%s %d %d\n", user, win, lost);
        fclose(fptr);
        printf("New user added\n");
        game_funtion(&win, &lost);
        update_file(user, win, lost);

        return 0;
    }

    // existing user
    printf("Welcome back %s\n", user);
    printf("Wins: %d | Losses: %d\n", win, lost);
    game_funtion(&win, &lost);
    update_file(user, win, lost);

    printf("Stats updated\n");
    return 0;
}


void game_funtion(int *win, int *lost) {
    int input, limit = 3;
    int secretNum = rand() % 10 + 1;
    printf("\t Number Guessing Game \n");
    for (int i = 0; i < 10; i++)
    {
        printf("Chance : %d time \n", limit);
        printf("Enter number : ");
        scanf("%d", &input);
            if (input != secretNum)
                {
                   limit --;
                   if (limit == 0)
                   {
                    (*lost) ++;
                    printf("Out of limit\n");
                    break;
                   } else if (secretNum < input)
                   {
                    printf("%d is too high \n", input);
                   } else if (secretNum > input)
                   {
                    printf("%d is too low \n", input);
                   }
                } else {
                    (*win) ++;
                    printf("You win\n");
                    break;
                }
    }
}

void update_file(const char *user, int win, int lost) {
    FILE *read = fopen("player.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    char name[1024];
    int w, l;

    while (fscanf(read, "%1023s %d %d", name, &w, &l) == 3) {
        if (strcmp(name, user) == 0) {
            fprintf(temp, "%s %d %d\n", user, win, lost);
        } else {
            fprintf(temp, "%s %d %d\n", name, w, l);
        }
    }

    fclose(read);
    fclose(temp);

    remove("player.txt");
    rename("temp.txt", "player.txt");
}
