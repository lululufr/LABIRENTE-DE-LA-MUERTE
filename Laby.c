#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#define HAUTEUR1 15
#define LARGEUR1 50
#define HAUTEUR2 14
#define LARGEUR2 66
#define HAUTEUR3 14
#define LARGEUR3 124


void clearTerminal();
int is_valid();
int is_finish();
void playYours();
void createLaby();
void levelChoice();
int playAgain();
void play3();
void play2();
void play1();
int is_validcreation();
int is_finishcreation();
char yourLabyrinth[HAUTEUR1][LARGEUR1];
int yoursSet=0;

void clearTerminal() {
    printf("\033[2J");
}

int menu(){
    int menuChoice;
    clearTerminal();
    printf("Bonjour bienvenue sur EL LABYRENTO DE LA MUERTE !!!\n\nMENU >>>\n\n");

    printf("1 ->jouer 2 -> creer un labyrinthe 3 ->regles 4 ->quitter >>>");
        
    scanf(" %d",&menuChoice);
    switch( menuChoice ) {
            
        case 1:
            printf("Let's GO ! \n");
            levelChoice();
            
        break;
        
        case 2:
            createLaby();
        break;
        
        case 3:
            printf("Les regles sont simple : il faut que vous sortiez du Labyrinthe indemne. \nPour cela frayez vous un chemin a travers les murs de cet endroit malfaisant.\n");
        break;
        case 4:
            printf("Au revoir !!\n");
            return 0;
        break;
                
        default :
            printf("Merci de choisir l'un des choix du menu : \n 1 ->jouer 2 ->regles 3 ->quitter\n");
            menu();
        break;
    }
    return 0;
}


void levelChoice(){
    clearTerminal();
    int difficulty;

    printf("Le menu : \n");
    printf("1 -> Niveau FACILE = Esto MUI FASSIL \n");
    printf("2 -> Niveau MOYEN = te respeto mucho !!! \n");
    printf("3 -> Aie Aie Aie CARAMBA Buena suerte, chico !!\n>>> ");
    printf("4 -> puedes juegar a tu labyrente \n>>>");
    scanf("%d",&difficulty);
    
    switch(difficulty) {
        
        case 1:
            playAgain(difficulty);
            break;
        case 2:
            playAgain(difficulty);
            break;
         case 3:
            playAgain(difficulty);
            break;
        case 4 :
            playYours();
            break;
        default :
            printf("Merci de choisir l'un des choix du menu : \n 1 ->jouer 2-creer 3 ->regles 4 ->quitter\n");
            levelChoice();
        break;
    };
}


int is_valid(int x, int y, int hauteur, int largeur, char grille[hauteur][largeur]) {
    if(grille[y][x]=='#'||y>hauteur||x>largeur||x<0||y<0){
        return 0;
    }
    return 1;
}
int is_finish(int x, int y, int hauteur, int largeur, char grille[hauteur][largeur]) {
    if (grille[y][x]=='.'){
        return 1;
    }
    return 0;
}

void play3() {

    time_t chronoDebut;
    time_t chronoFin;
    char test;
    
     
    chronoDebut = time(NULL);
   


    char grille[HAUTEUR3][LARGEUR3] = {
"# ####################################################################################",
"#   #    ######       ########     # ## # ##############   #####       ## ##  ## #####",
"## ## ## # ######## #    #     ### ####      ###           ###  ## ### # # # # #  ####",
"##    ##  ##      # ####   ###     #####  ###### #######       #####   # ##         ##",
"## ######    #### # ######### # ##### ###        ############ ##   ##### ### ###    ##",
"##      #### #####     ## ### # ##### ### #######     ####  #                     # ##",
"#  ## #### # # ###### ##    ##    ###     ########### ###  # ####### ########### #  ##",
"#  ## #### #########  ## ##  #### ####### ## ############# ##     ### ####    # ##  ##",
"# ##  ##      ####         # ####     ##     ####     # # ##  ###      ### ## # ##   #",
"# #### ##### ###### ## ## #  ########  ## ### ##  ##  # # ## ##### # # ##  #   # ### #",
"#     ######        ## ##  # ###### ##    ###    ####      # ##### ### ## # ##       #",
"## ############### ### ## ##  ###   ####  ## # ##### #####    ###  ###    #  # #  ## #",
"##                 ## #### ##     ###   ##   #           ####      ####   ###  #######",
"#####################################################.################################"};

    int x = 1, y = 0;
    int move_x, move_y;
    int i;
    initscr();
    noecho();
    cbreak();
    do {
        clear();
        for(i = 0; i < HAUTEUR3; ++i) {
            mvprintw(i, 0, "%s", grille[i]);
        }
        mvprintw(y, x, "@");
        mvprintw(y, x, "");
        refresh();
        move_x = x; move_y = y;
        switch(getch()) {
            case 'z': move_y = y - 1; break;
            case 's': move_y = y + 1; break;
            case 'q': move_x = x - 1; break;
            case 'd': move_x = x + 1; break;
        }
        if(is_valid(move_x, move_y, HAUTEUR3, LARGEUR3, grille)) {
            x = move_x; y = move_y;
        }
    } while(! is_finish(x, y, HAUTEUR3, LARGEUR3, grille));
    refresh();
    clrtoeol();
    refresh();
    endwin();
    refresh();

    chronoFin = time(NULL);
     
    clearTerminal();
    
    printf("Vous avez mis  %ld", chronoFin - chronoDebut);
    printf(" secondes a finir le Labyrinthe");
 
}


void play2() {

    time_t chronoDebut;
    time_t chronoFin;
    char test;
    
     
    chronoDebut = time(NULL);

    char grille[HAUTEUR2][LARGEUR2] = {
"# ##########################################",
"#   #    ######       ########     # ## # ##",
"## ## ## # ######## #    #     ### ####   ##",
"##    ##  ##      # ####   ###     #####  ##",
"## ######    #### # ######### # ##### ### ##",
"##      #### #####     ## ### # ##### ### ##",
"#  ## #### # # ###### ##    ##    ###     ##",
"#  ## #### #########  ## ##  #### ####### ##",
"# ##  ##      ####         # ####     ##   #",
"# #### ##### ###### ## ## #  ########  ##  #",
"#     ######        ## ##  # ###### ##     #",
"## ############### ### ## ##  ###   ####   #",
"##                 ## #### ##     ###   ####",
"########.###################################"};

    int x = 1, y = 0;
    int move_x, move_y;
    int i;
    initscr();
    noecho();
    cbreak();
    do {
        clear();
        for(i = 0; i < HAUTEUR2; ++i) {
            mvprintw(i, 0, "%s", grille[i]);
        }
        mvprintw(y, x, "@");
        mvprintw(y, x, "");
        refresh();
        move_x = x; move_y = y;
        switch(getch()) {
            case 'z': move_y = y - 1; break;
            case 's': move_y = y + 1; break;
            case 'q': move_x = x - 1; break;
            case 'd': move_x = x + 1; break;
        }
        if(is_valid(move_x, move_y, HAUTEUR2, LARGEUR2, grille)) {
            x = move_x; y = move_y;
        }
    } while(! is_finish(x, y, HAUTEUR2, LARGEUR2, grille));
    refresh();
    clrtoeol();
    refresh();
    endwin();

    chronoFin = time(NULL);
     
    clearTerminal();
    
    printf("Vous avez mis  %ld", chronoFin - chronoDebut);
    printf(" secondes a finir le Labyrinthe");

}
void play1() {

    time_t chronoDebut;
    time_t chronoFin;
    char test;
    
    
    chronoDebut = time(NULL);
   

    char grille[HAUTEUR1][LARGEUR1] = {
"# ###############################################",
"#   #  ####   ####    ##   ##  ########       # #",
"# #    #    # #    ##    #        ### # ## #### #",
"# ####   ####   ## ######### #####      ##    # #",
"#    #####  #######         # ##  ##### ##### # #",
"# ## #           #### ##### #           #     # #",
"#  ###### ###### # ## # ### ##### ##### ### # # #",
"##  #     #    # #    #         ###   # # ###   #",
"#     ########   # ####  ######     # # # ### ###",
"#  ####    ##### #    #####   ####### # #      ##",
"#  #       #     #  #       ###       # ###### ##",
"#  ###### ## ###### ########### #######   #### ##",
"#          #                 #     #    #       #",
"##############################.##################"};

    int x = 1, y = 0;
    int move_x, move_y;
    int i;
    initscr();
    noecho();
    cbreak();
    do {
        clear();
        for(i = 0; i < HAUTEUR1; ++i) {
            mvprintw(i, 0, "%s", grille[i]);
        }
        mvprintw(y, x, "@");
        mvprintw(y, x, "");
        refresh();
        move_x = x; move_y = y;
        switch(getch()) {
            case 'z': move_y = y - 1; break;
            case 's': move_y = y + 1; break;
            case 'q': move_x = x - 1; break;
            case 'd': move_x = x + 1; break;
        }
        if(is_valid(move_x, move_y, HAUTEUR1, LARGEUR1, grille)) {
            x = move_x; y = move_y;
        }
    } while(! is_finish(x, y, HAUTEUR1, LARGEUR1, grille));
    refresh();
    clrtoeol();
    refresh();
    endwin();

    chronoFin = time(NULL);
     
    clearTerminal();
    
    printf("Vous avez mis  %ld", chronoFin - chronoDebut);
    printf(" secondes a finir le Labyrinthe");
    
}


int is_validcreation(int x, int y, int hauteur, int largeur, char grille[hauteur][largeur]) {
    if(y>=hauteur-2&&grille[y][x]=='#'||x>=largeur-2||x<=0||y<=0){ //les limites du tableau et je veux quand 
        return 0;                                               //meme pouvoir aller au '.' donc je fais un check pour'#'
    }
    return 1;
}

int is_finishcreation(int x, int y, int hauteur, int largeur, char grille[hauteur][largeur]) {
    if (y==hauteur-2){ // 
        return 1;
    }
    return 0;
}


void createLaby() {
    char grille[HAUTEUR1][LARGEUR1] = {
"# ###############################################",
"# ###############################################",
"#################################################",
"#################################################",
"#################################################",
"#################################################",
"#################################################",
"#################################################",
"#################################################",
"#################################################",
"#################################################",
"#################################################",
"#################################################",
"#############################################.###"};

    int x = 1, y = 0;
    int move_x, move_y;
    int i;
    initscr();
    noecho();
    cbreak();
    do {
        clear();
        for(i = 0; i < HAUTEUR1; ++i) {
            mvprintw(i, 0, "%s", grille[i]);
        }
        mvprintw(y, x, "@");
        mvprintw(y, x, "");
        refresh();
        move_x = x; move_y = y;
        switch(getch()) {
            case 'z': move_y = y - 1; break;
            case 's': move_y = y + 1; break;
            case 'q': move_x = x - 1; break;
            case 'd': move_x = x + 1; break;
        }
        if(is_validcreation(move_x, move_y, HAUTEUR1, LARGEUR1, grille)) {
            x = move_x; y = move_y;
            if(grille[y][x]!='.'){
                grille[y][x] = ' ';
            }
        }
    } while(! is_finishcreation(x, y, HAUTEUR1, LARGEUR1, grille));
    refresh();
    clrtoeol();
    refresh();
    endwin();
    int a,b;
    for(a=0;a<=HAUTEUR1-1;++a){
        for(b=0; b<=LARGEUR1-1;++b){
            printf("%c",grille[a][b]);
            yourLabyrinth[a][b]= grille[a][b];
        }
        printf("\n");
    }
    printf("confirmez vous votre labyrinthe ?\n");
    for(a=0;a<=HAUTEUR1-1;++a){
        for(b=0; b<=LARGEUR1-1;++b){
            printf("%c",yourLabyrinth[a][b]);
        }
        printf("\n");
    }
    menu();
}


void playYours(){

    time_t chronoDebut;
    time_t chronoFin;
    char test;
    
    
    chronoDebut = time(NULL);


    int x = 1, y = 0;
    int move_x, move_y;
    int i;
    initscr();
    noecho();
    cbreak();
    do {
        clear();
        for(i = 0; i < HAUTEUR1; ++i) {
            mvprintw(i, 0, "%s", yourLabyrinth[i]);
        }
        mvprintw(y, x, "@");
        mvprintw(y, x, "");
        refresh();
        move_x = x; move_y = y;
        switch(getch()) {
            case 'z': move_y = y - 1; break;
            case 's': move_y = y + 1; break;
            case 'q': move_x = x - 1; break;
            case 'd': move_x = x + 1; break;
        }
        if(is_valid(move_x, move_y, HAUTEUR1, LARGEUR1, yourLabyrinth)) {
            x = move_x; y = move_y;
        }
    } while(! is_finish(x, y, HAUTEUR1, LARGEUR1, yourLabyrinth));
    refresh();
    clrtoeol();
    refresh();
    endwin();

    chronoFin = time(NULL);
     
    clearTerminal();
    
    printf("Vous avez mis  %ld", chronoFin - chronoDebut);
    printf(" secondes a finir le Labyrinthe");
    levelChoice();
}



int playAgain(int difficulty){
    char choice;
        switch (difficulty) {
        case 1:
            play1();
            break;
        case 2:
            play2();
            break;
        case 3:
            play3();
            break;
        default:
            levelChoice();
            break;
        }

        printf("voulez vous rejouez ? o / n \n >>>> ");
        
        scanf(" %c",&choice);
        
        if(choice == 'o' ||choice == 'O'){
            levelChoice();
            
        }else{
            menu();
        }
    }

int main(){
    menu();
}


int chrono(int truc){
    time_t chronoDebut;
    char test;
    
     
    chronoDebut = time(NULL);
    printf("Debut du chrono = %ld\n ", chronoDebut);
    
    //laby a la place
        //truc;
    //laby a la place
     
    time_t chronoFin;
    
    chronoFin = time(NULL);
    
    printf("Fin du chrono :  %ld\n ", chronoFin);
    
    printf("Temps total en seconde :  %ld\n ", chronoFin - chronoDebut);
    
    return(0);
}
