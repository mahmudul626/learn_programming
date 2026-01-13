#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Function Prototypes

void game_funtion(int *win, int *lost);
void update_file(const char *user, int win, int lost);
void leaderboard(const char *user, int win, int lost);


int main() {
    srand(time(0));
    int win = 0, lost = 0, found = 0;
    char user[1024], name[1024];

    printf("Enter Your Name: ");
    scanf("%1023s", user);

    FILE *fptr = fopen("player.txt", "r");
    if (!fptr) {
        fptr = fopen("player.txt", "w");
        if (!fptr) {
            printf("Failed to open file\n");
            return 1;
        }
        fclose(fptr);
        fptr = fopen("player.txt", "r");
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

        printf("Wins: %d | Losses: %d\n", win, lost);
        if (win > lost)
            {
                printf("Unstoppable!\n");
            } else if (win < lost) {
                printf("Keep-trying!\n");
            } else {
                printf("Balanced!\n");
            }

        update_file(user, win, lost);
        leaderboard(user, win, lost);

        return 0;
    }

    // existing user
    printf("Welcome back %s\n", user);
    printf("Wins: %d | Losses: %d\n", win, lost);
    game_funtion(&win, &lost);
    update_file(user, win, lost);
    leaderboard(user, win, lost);

    printf("Wins: %d | Losses: %d\n", win, lost);
    if (win > lost)
            {
                printf("Unstoppable!\n");
            } else if (win < lost) {
                printf("Keep-trying!\n");
            } else {
                printf("Balanced!\n");
            }
    return 0;
}


//Game Logic
void game_funtion(int *win, int *lost) {
    char choice;
    do
    {
        int input, limit = 3, prev = 0;
        int secretNum = rand() % 10 + 1;
        printf("\t Number Guessing Game \n");
        while(limit > 0)
        {
            printf("Chance : %d time \n", limit);
            printf("Enter number : ");

            while (scanf("%d", &input) != 1) {
            printf("Error! Invalid input\n");
            printf("Enter number : ");
            while (getchar() != '\n'); 
            }

            if (input != secretNum)
                {
                limit --;
                if (limit == 0)  {
                                (*lost) ++;
                                printf("Out of limit\n");
                                break;
                    } else if (secretNum < input)   {
                                if(prev != 0) {

                                    if(abs(secretNum-input) < abs(secretNum-prev))
                                    {
                                        printf("You're getting closer!\n");
                                    } else {
                                        printf("You're getting farther!\n");
                                    }
                                    
                                } else {
                                    printf("%d is too high \n", input);
                                }

                    } else if (secretNum > input)   {
                                if(prev != 0) {

                                    if(abs(secretNum-input) < abs(secretNum-prev))
                                    {
                                        printf("You're getting closer!\n");
                                    } else {
                                        printf("You're getting farther!\n");
                                    }
                                    
                                } else {
                                    printf("%d is too low \n", input);
                                }
                    }
            } else {
                    (*win) ++;
                    if(limit == 3) {
                        printf("Perfect Guess!\n");
                    } else {
                        printf("You win\n");
                    }
                    break;
            }
        prev = input;
        }

    printf("Do you want to play more (y/n) :");
    scanf(" %c", &choice);

    while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
        printf("Error! Invalid input\n");
        printf("Do you want to play more (y/n) :");
        while (getchar() != '\n');
        scanf(" %c", &choice);
    }
    
    } while (choice == 'y' || choice == 'Y');
}


//Updating Scores in the Score Sheet
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


void leaderboard(const char *user, int win, int lost)
{
    FILE *fptr = fopen("player.txt", "r");
    if (!fptr) {
        printf("Failed to open leaderboard file\n");
        return;
    }

    char name[1024];
    int w, l;

    // temporary storage
    char names[100][1024];
    int wins[100], losses[100];
    int count = 0;

    // read all players
    while (fscanf(fptr, "%1023s %d %d", name, &w, &l) == 3) {
        strcpy(names[count], name);
        wins[count] = w;
        losses[count] = l;
        count++;
    }
    fclose(fptr);

    // sort by wins (descending)
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (wins[j] > wins[i]) {
                int tw = wins[i], tl = losses[i];
                char tn[1024];

                wins[i] = wins[j];
                losses[i] = losses[j];
                strcpy(tn, names[i]);

                wins[j] = tw;
                losses[j] = tl;
                strcpy(names[i], names[j]);
                strcpy(names[j], tn);
            }
        }
    }

    // print leaderboard
    printf("\n=========== LEADERBOARD ===========\n");
    printf("%-5s %-15s %-6s %-6s\n", "Rank", "Name", "Win", "Lost");
    printf("----------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d %-15s %-6d %-6d",
               i + 1, names[i], wins[i], losses[i]);

        if (strcmp(names[i], user) == 0)
            printf("  <-- YOU");

        printf("\n");
    }

    printf("==================================\n");
}
