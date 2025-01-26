/*
Rock Paper Sissors Game
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// for cross platforms
#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
    char getch() {
        struct termios oldt, newt;
        char ch;
        tcgetattr(STDIN_FILENO, &oldt); // Get current terminal settings
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old settings
        return ch;
    }
#endif

void output(int o);

int main() {
    srand(time(0));
    int com_in,us_in;          //com-->computer     us-->user 
    int us_res=0,com_res=0;    // in-->input        res-->result  
    int status;
    game :
        system("cls");
        printf("Enter\n0-->Rock\n1-->paper\n2-->scissors:\n9-->exit\n");
        // scanf(" %d", &us_in);
        status = 1;
        us_in = getch()-'0';
        com_in = rand() % 3;
        
        printf("%d\n",us_in);
        if(!(us_in==1 || us_in==2 || us_in==9 || us_in==0)){    //to print error
            fprintf(stderr, "An error occurred: %s\n", "Invalid input");
            status--;
        }
        if (us_in == 9){
            goto end;
        }

        if(status){
            printf("You choosed:\t");
            output(us_in);
            printf("Computer input:\t");
            output(com_in);

            if(com_in==us_in){
                printf("Game is Draw\n");
            } else if ((us_in==0 && com_in==2) || (us_in==1 && com_in==0) || (us_in==2 && com_in==1)){
                printf("Game is won by you\n");
                us_res++;
            } else {
                printf("You lost the Game\n");
                com_res++;
            }
        }

        printf("Press any key to continue...");
        _getch();
        goto game;

    end :
    printf("You scored: %d\nOpponet Scored: %d\n",us_res,com_res);
    us_res >= com_res ? (us_res == com_res ? printf("Tie") : printf("You Won")) : printf("You lost\n");
    return 0;
}

void output(int o){
    if(o==0){
        printf("ROCK\n");
    } else if(o==1){
        printf("PAPER\n");
    } else if(o==2){
        printf("SICSSORS\n");
    }
}