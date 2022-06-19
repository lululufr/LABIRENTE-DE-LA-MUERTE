#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#define HAUTEUR1 14 // definition des valeurs de la taille de nos labyrinthes
#define LARGEUR1 50 // definition des valeurs de la taille de nos labyrinthes
#define HAUTEUR2 14 // definition des valeurs de la taille de nos labyrinthes
#define LARGEUR2 66 // definition des valeurs de la taille de nos labyrinthes
#define HAUTEUR3 14 // definition des valeurs de la taille de nos labyrinthes
#define LARGEUR3 86 // definition des valeurs de la taille de nos labyrinthes


void clearTerminal(); //permet de nettoyer le terminal
int is_valid(); // Defini si la case sur laquel se trouve le personnage est VALIDE
int is_finish();// défini quand est ce que la labyrinth est fini
void createLaby();// permet a l'utilisateur de creer son propre labyrinth
void levelChoice();// Pemet de choisir son niveau
void playAgain();// permet de rejouer
void play3();// niveau 3
void play2();// niveau 2
void play1();// niveau 1
void playYours(); // Permet de jouer le labyrinth que l'utilisateur a cree
int is_validcreation();
int is_finishcreation();
char yourLabyrinth[HAUTEUR1][LARGEUR1]; // labyrinthe global, utilisé pour la création
int yoursSet=0;// pour savoir si on a déjà créé un labyrinthe, c'est plus simple d'en faire une globale
void movement();
char menutxt[] = {"1 ->jouer 2 -> creer un labyrinthe 3 ->regles 4 ->quitter \n>>>"};
void clearTerminal() { // un focntion qui permet de nettoyer la console.
    printf("\033[2J");
}

int menu(){
    int menuChoice;
    clearTerminal();
    printf("Bonjour bienvenue sur EL LABYRENTO DE LA MUERTE !!!\n\nMENU >>>\n\n"); //notre thème est "l'espagnol mais en mauvais" 
// donc une partie du text est en espagnol mal écrit
    printf("%s", menutxt);
        
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
            printf("Merci de choisir l'un des choix du menu : \n %s>>>", menutxt);
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
    printf("3 -> Aie Aie Aie CARAMBA Buena suerte, chico !!\n ");
    printf("4 -> puedes juegar a tu labyrente \n>>>");
    scanf("%d",&difficulty);
    
    switch(difficulty) {
        
        case 1:
            playAgain(difficulty); // ici la fonction Play again permet de rejouer les niveaux
            break;
        case 2:
            playAgain(difficulty);
            break;
         case 3:
            playAgain(difficulty);
            break;
        case 4 :
            if(yoursSet==1){
                playYours();
            }else{
                printf("veuillez creer d'abord un labyrinthe");// si l'utilisateur n'a pas créer de labyrinth alors il est renvoyé ici
            }
            break;
        default :
            printf("Merci de choisir l'un des choix du menu : \n%s", menutxt);
            levelChoice();
        break;
    };
}

// vérifie si le movement de l'user est valide
int is_valid(int x, int y, int hauteur, int largeur, char grille[hauteur][largeur]) {
    if(grille[y][x]=='#'||y>hauteur||x>largeur||x<0||y<0){
        return 0;
    }
    return 1;
}
//vérifie si le labyrnthe est fini en fonction de la position de l'user
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
    
     //lance le chono
    chronoDebut = time(NULL); //debut du chronometre
   

    //définis le labyrinthe
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

    movement(HAUTEUR3,LARGEUR3,grille);
    
    chronoFin = time(NULL);
     
    clearTerminal();
    
    printf("BRAVOOOOO !!!!! Vous avez réussi ce niveau \n");
    printf("Vous avez mis  %ld", chronoFin - chronoDebut);
    printf(" secondes a finir le Labyrinthe \n ");
 
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

    movement(HAUTEUR2,LARGEUR2,grille);

    chronoFin = time(NULL);
     
    clearTerminal();
    printf("BRAVOOOOO !!!!! Vous avez réussi ce niveau \n");
    printf("Vous avez mis  %ld", chronoFin - chronoDebut);
    printf(" secondes a finir le Labyrinthe \n ");
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

    movement(HAUTEUR1,LARGEUR1,grille);

    chronoFin = time(NULL);
     
    clearTerminal();

    printf("BRAVOOOOO !!!!! Vous avez réussi ce niveau !! \n");
    printf("Vous avez mis  %ld", chronoFin - chronoDebut);
    printf(" secondes a finir le Labyrinthe \n ");
    
}


int is_validcreation(int x, int y, int hauteur, int largeur, char grille[hauteur][largeur]) {
    if(y>=hauteur-1&&grille[y][x]=='#'||x>=largeur-2||x<=0||y<=0){ //les limites du tableau et je veux quand 
        return 0;                                               //meme pouvoir aller au '.' donc je fais un check pour'#'
    }
    return 1;
}

int is_finishcreation(int x, int y, int hauteur, int largeur, char grille[hauteur][largeur]) {
    if (y==hauteur-1){ // 
        return 1;
    }
    return 0;
}


void createLaby() { // permet de creer son labyrinthe
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
    yoursSet=1;
    menu();
}


void playYours(){

    time_t chronoDebut;
    time_t chronoFin;
    char test;
    
    
    chronoDebut = time(NULL);


    movement(HAUTEUR1,LARGEUR1,yourLabyrinth);

    chronoFin = time(NULL);
     
    clearTerminal();
    
    printf("Vous avez mis  %ld", chronoFin - chronoDebut);
    printf(" secondes a finir le Labyrinthe");
    levelChoice();
}



void playAgain(int difficulty){
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

        printf("Voulez vous rejouez ? o / n \n >>>>");
        
        scanf(" %c",&choice);
        
        if(choice == 'o' ||choice == 'O'){
            levelChoice();
            
        }else{
            menu();
        }
}

void movement(int hauteur, int largeur ,char labyrinth[hauteur][largeur]) {
    
    int x = 1, y = 0;
    int move_x, move_y;
    int i;
    initscr();
    noecho();
    cbreak();
    do {
        clear();
        for(i = 0; i < hauteur; ++i) {
            mvprintw(i, 0, "%s", labyrinth[i]);
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
        if(is_valid(move_x, move_y, hauteur, largeur, labyrinth)) {
            x = move_x; y = move_y;
        }
    } while(! is_finish(x, y, hauteur, largeur, labyrinth));
    refresh();
    clrtoeol();
    refresh();
    endwin();
}


int main(){
    menu();
}
