#include <stdio.h>
#include <stdlib.h>//pt functia rand
#include <unistd.h>// pt functia sleep
#include <time.h>//pt declarerea seed-ului in functia throw_dice

int n;
char names[11][16];
int scoreboard[11];
int gender[11];

void rules()
{
    //present the rules of the game
    printf("Maximum admitted number of players = 10\n"
           "Minimum admitted number of players = 3\n"
           "This is a simulation game, that involves drinking and a playing die(un zar)\n"
           "you can drink whatever you want, it is just your RESPOSABILITY\n"
           "the rules are fairly simple:\n"
           "    all players form a circle(the first player stands near the last player)\n"
           "    you must introduce the names in the order of your positions in the circle\n"
           "    every round a player has to roll a die, going in a trigonometric order\n"
           "    if it lands on 1 -> nothing happens\n"
           "    if it lands on 2 -> the one who threw the die drinks\n"
           "    if it lands on 3 -> the one sitting on the left of the one who threw the die drinks\n"
           "    if it lands on 4 -> the one sitting on the right of the one who threw the die drinks\n"
           "    if it lands on 5 -> all boys drink \n"
           "    if it lands on 6 -> all girls drink\n"
           "    JUST FOLLOW THE INSTRUCTIONS THAT COME UP\n\n");
}

void det_gender(int i)
{
    char gend;
    int ok=0;
    //read the gender of person i with the predifined letters
    printf("%s enter you gender\n (it must be M/m or F/f): ",names[i]);
    scanf("%s" ,&gend);
    while(ok==0)
        switch (gend)
        {
            //if the person is a male in gender[] we mark it as 1
            case 'M':
                gender[i] = 1;
                ok = 1;
                break;
            case 'm':
                gender[i] = 1;
                ok = 1;
                break;
            //if the person is a female in gender[] we mark it as 2
            case 'F':
                gender[i] = 2;
                ok = 1;
                break;
            case 'f':
                gender[i] = 2;
                ok = 1;
                break;
            //if character is not correct, then we redo the reading until it is correct
            default :
                ok = 0;
                printf("INCORRECT (it must be M/m or F/f): ", names[i]);
                scanf("%s", &gend);
        }
}

void players()
{
    char trash[30];
    //read the number of players until it is between >=3 and <=10
    //i haven't use a "stupid proof" reading because in case of a mistake i want the print a different mesaje
    printf("Introduce the number of players:");
    scanf("%d",&n);
    while( n<3 || n>10 )
    {
        printf("this game can be played by 3 to 10 people, intoduce a viable number");
        scanf("%d", &n);

    }
    gets(trash);

    //read the names of all players
    for (int i=1;i<=n;i++)
    {
        printf("Name %d:",i);
        gets(names[i]);

    }
    //read the genders of all players
    for (int i=1;i<=n;i++)
        det_gender(i);

}

//generate a random number from 1 to 6
int throw_dice()   //adapted after https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm
{
    /* time() only changes once per second.
     * If you seed from time(),for each call to rand(), then you will get the same
     * value for every call during a single second." - reinterpreted from Knuth Vol 2 Chapter 3   */
    printf(" rolling dice\n");
    sleep(1);   //https://stackoverflow.com/questions/10922900/is-it-possible-to-wait-a-few-seconds-before-printing-a-new-line-in-c
    srand(time(NULL));

    int z;
    z = rand() % 6+1;
    return z;
}

void afis_dice(int z)
{
    //for each possible number (1 to 6) I made a drawing of the die
    if(z==1)
    {
        printf(" ___________________ \n");
        printf("|                   |\n");
        printf("|                   |\n");
        printf("|                   |\n");
        printf("|        ###        |\n");
        printf("|        ###        |\n");
        printf("|                   |\n");
        printf("|                   |\n");
        printf("|___________________|\n");
    }
    else
    if(z==2)
    {
        printf(" ___________________ \n");
        printf("|                   |\n");
        printf("|             ###   |\n");
        printf("|             ###   |\n");
        printf("|                   |\n");
        printf("|                   |\n");
        printf("|  ###              |\n");
        printf("|  ###              |\n");
        printf("|___________________|\n");
    }
    else
    if(z==3)
    {
        printf(" ___________________ \n");
        printf("|                   |\n");
        printf("|              ###  |\n");
        printf("|              ###  |\n");
        printf("|        ###        |\n");
        printf("|        ###        |\n");
        printf("|  ###              |\n");
        printf("|  ###              |\n");
        printf("|___________________|\n");
    }
    else
    if(z==4)
    {
        printf(" ___________________ \n");
        printf("|                   |\n");
        printf("|  ###         ###  |\n");
        printf("|  ###         ###  |\n");
        printf("|                   |\n");
        printf("|                   |\n");
        printf("|  ###         ###  |\n");
        printf("|  ###         ###  |\n");
        printf("|___________________|\n");
    }
    else
    if(z==5)
    {
        printf(" ___________________ \n");
        printf("|                   |\n");
        printf("|  ###         ###  |\n");
        printf("|  ###         ###  |\n");
        printf("|        ###        |\n");
        printf("|        ###        |\n");
        printf("|  ###         ###  |\n");
        printf("|  ###         ###  |\n");
        printf("|___________________|\n");
    }
    else
    {
        printf(" ___________________ \n");
        printf("|                   |\n");
        printf("|  ###   ###   ###  |\n");
        printf("|  ###   ###   ###  |\n");
        printf("|                   |\n");
        printf("|                   |\n");
        printf("|  ###   ###   ###  |\n");
        printf("|  ###   ###   ###  |\n");
        printf("|___________________|\n");
    }
    //tell concretly the number in a specific on the page
    printf("                      you rolled: %d\n",z);
}

void game()
{
    int continuation=1,z;
    char trash[30];
    do //the condition to do another turn of "drinks<3"
    {
        for (int i=1;i<=n;i++)
        {
            //for all n players we
            printf("\n%s's turn \n",names[i]);
            printf("%s press anything to roll the dice, then press enter: ",names[i]);
            scanf(" %s",trash);

            //generate a random number between >0 and <=6
            z = throw_dice();
            //display its corresponding drawing
            afis_dice(z);

            //for each possibile number, show the instruction as presented in the rules function and count who had to "drink"/do smth
            if(z==1)
                printf("!!! noone drinks, nothing happens\n");
            else
                if(z==2)
                {
                    printf("%s has to drink\n",names[i]);
                    scoreboard[i]++;
                }
            else
                if(z==3)
                {
                    if (i == 1)
                    {
                       printf("!!! %s has to drink\n",names[n]);
                        scoreboard[n]++;
                    }
                    else
                    {
                        printf("!!! %s has to drink\n",names[i-1]);
                        scoreboard[i-1]++;
                    }
                }
            else
                if(z==4)
                {
                    if (i == n)
                    {
                        printf("%s has to drink one\n",names[1]);
                        scoreboard[1]++;
                    }
                    else
                    {
                        printf("!!! %s has to drink \n",names[i+1]);
                        scoreboard[i+1]++;
                    }
                }
            else
                if(z==5)
                {
                    printf("!!! all boys have to drink\n");
                    for (int j=1;j<=n;j++)
                        if(gender[j]==1)
                            scoreboard[j]++;
            }
            else
                if(z==6)
                {
                    printf("!!! all girls have to drink\n");
                    for (int j = 1; j <= n; j++)
                        if (gender[j] == 2)
                            scoreboard[j]++;
                }
            sleep(1);//for a good flow in the game// not to give too many info to players so fast

        }
        //at the end of each turn (every player has rolled the die) there are 3 options as shown
        printf("\n\n what happens now? _PLAY ANOTHER ROUND (press any key,except E/e and S/s, then press enter)\n"
               "                   _show how many drinks each player had had AND PLAY ANOTHER ROUND (press  S/s, then press enter)\n"
               "                   _END GAME HERE (press E/e, then press enter)\n\n"
               "your choice: ");

        char verif;
        scanf("%s" ,&verif);
        switch (verif)
        {
            //if you want to end the game a nice message appears and the score for each player
            case 'E':
                continuation=0;//equivalent to "don't continue"
                printf("\n");
                printf("##### #   # #####    ###   ###   #   #  #####   #   #  ###  ####      ##### #  # ####  ##### ####  \n");
                printf("  #   #   # #       #     #   #  ## ##  #       #   # #   #  #        #     ## # #   # #     #   # \n");
                printf("  #   ##### ###     #   # #####  # # #  ###     ##### #####    #      ###   # ## #   # ###   #   # \n");
                printf("  #   #   # #####    ###  #   #  #   #  #####   #   # #   # ####      ##### #  # ####  ##### ####  \n\n");
                for (int i = 1; i <= n; i++)
                    printf("%s drank %d \n",names[i], scoreboard[i]);
                break;
            case 'e':
                continuation=0;//equivalent to "don't continue"
                printf("\n");
                printf("##### #   # #####    ###   ###   #   #  #####   #   #  ###  ####      ##### #  # ####  ##### ####  \n");
                printf("  #   #   # #       #     #   #  ## ##  #       #   # #   #  #        #     ## # #   # #     #   # \n");
                printf("  #   ##### ###     #   # #####  # # #  ###     ##### #####    #      ###   # ## #   # ###   #   # \n");
                printf("  #   #   # #####    ###  #   #  #   #  #####   #   # #   # ####      ##### #  # ####  ##### ####  \n\n");
                printf("GAME HAS ENDED...\n");
                for (int i = 1; i <= n; i++)
                    printf("%s drank %d \n",names[i], scoreboard[i]);
                break;
            //if can also see the score for each player and play another round
            case 'S':
                for (int i = 1; i <= n; i++)
                    printf("%s drank %d \n",names[i], scoreboard[i]);
                break;
            case 's':
                for (int i = 1; i <= n; i++)
                    printf("%s drank %d \n",names[i], scoreboard[i]);
                break;
            //or simply you can just play another round(
            default :
                printf("\n!!! THE GAME GOES ON !!!\n");
        }
    }while(continuation==1);
}

int main()
{
    rules();
    players();
    game();
    return 0;
}