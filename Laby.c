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
void levelChoice();
int getHeight(int difficulty);
int getLenght(int difficulty);
int playAgain();
void play3();
void play2();
void play1();



void clearTerminal() {
    printf("\033[2J");
}


void levelChoice(){
    clearTerminal();
    int difficulty;

    printf("Le menu : \n");
    printf("1 -> Niveau FACILE = Esto MUI FASSIL \n");
    printf("2 -> Niveau MOYEN = te respeto mucho !!! \n");
    printf("3 -> Aie Aie Aie CARAMBA Buena suerte, chico !!\n>>> ");
    scanf("%d",&difficulty);
    
    switch(difficulty) {
        
        case 1:
            playAgain();
            break;
        case 2:
           playAgain();
           break;
         case 3:
          
             playAgain();
          
            break;
        default :
            printf("Merci de choisir l'un des choix du menu : \n 1 ->jouer 2 ->regles 3 ->quitter\n");
            levelChoice();
        break;
    };
}

int menu(){
    int menuChoice;
    clearTerminal();
    printf("Bonjour bienvenue sur EL LABYRENTO DE LA MUERTE !!!\n\nMENU >>>\n\n");

    printf("1 ->jouer 2 ->regles 3 ->quitter>>>");
        
    scanf(" %d",&menuChoice);
    switch( menuChoice ) {
            
        case 1:
            printf("Let's GO ! \n");
            levelChoice();
            
        break;

        case 2:
            printf("Les regles sont simple : il faut que vous sortiez du Labyrinthe indemne. \nPour cela frayez vous un chemin a travers les murs de cet endroit malfaisant.\n");
        break;
            
        case 3:
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



// is_valid vérifie que les coordonnées (x, y) sont valides pour un déplacement /
int is_valid(int x, int y, int hauteur, int largeur, char grille[hauteur][largeur]) {
    if(grille[y][x]=='#'||y>hauteur||x>largeur||x<0||y<0){
        return 0;
    }
    return 1;
}
// is_finish vérifie que l'emplacement sur lequel se trouve les coordonnées (x, y) est une sortie */
int is_finish(int x, int y, int hauteur, int largeur, char grille[hauteur][largeur]) {
    if (grille[y][x]=='.'){
        return 1;
    }
    return 0;
}



void play3() {
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
 
}


void play2() {
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

}
void play1() {
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
    
}


int playAgain(){
    char choice;
    
        play2();

        printf("voulez vous rejouez ? o / n \n >>>> ");
        
        scanf(" %c",&choice);
        
        if(choice == 'o' ||choice == 'O'){
            playAgain();
            
        }else{
            menu();
        }
    }

int main(){
    menu();
}


