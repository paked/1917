// tictactoe.c - for when you want to tic tac toe
// by Harrison Shoebridge on the 18/5/15

#include <stdlib.h>
#include <stdio.h>

#define BOARD_SIZE 3

#define EMPTY -1 
#define PLAYER_ONE 0
#define PLAYER_TWO 1

#define GAME_WON 1
#define GAME_TIED 2
#define GAME_NOT_OVER 0

typedef struct _move {
    int x;
    int y;
} Move;

typedef struct _game {
    int map[BOARD_SIZE][BOARD_SIZE];
    unsigned int roundCount;
} Game;

// TODO split logic out of this main file

// TODO make function names more specific to the "game"

// TODO move contents of main into a seperate "run game" function

// TODO allow symbol selection for characters

// TODO create ADT

void printSpot(int s);
void printGame(Game g);
Game newGame(void);
int validMove(Game g, Move m);
Game makeMove(Game g, int p, Move m);
int end(Game g, int p);

Game newGame(void) {
    Game g;
    int y = 0;

    while (y < BOARD_SIZE) {
        int x = 0;
        while (x < BOARD_SIZE) {
            g.map[y][x] = EMPTY;
            x += 1;
        }

        y += 1;
    }

    g.roundCount = 0;

    return g;
}

void printGame(Game g) {
    printf("Round #%d\n", g.roundCount);

    int y = 0;
    
    // TODO make formatting prettier, code and normal wise

    printf("-------------\n");
    
    while (y < BOARD_SIZE) {
        int x = 0;
        printf("|");
        while (x < BOARD_SIZE) {
            printSpot(g.map[y][x]);
            printf("|");
            x += 1;
        }

        printf("\n");
        printf("-------------\n");

        y += 1;
    }
}

void printSpot(int s) {
    printf(" ");

    if (s == EMPTY) {
        printf(" ");
    } else if (s == PLAYER_ONE) {
        printf("x");
    } else if (s == PLAYER_TWO) {
        printf("o");
    }

    printf(" ");
}

int validMove(Game g, Move m) {
    // boundary checks
    if (m.x < 0 || m.y < 0 || m.x > BOARD_SIZE || m.y > BOARD_SIZE) {
        return 0;
    }
    
    // move already made
    if (g.map[m.y][m.x] != EMPTY) {
        return 0;
    }

    return 1;
}

Game makeMove(Game g, int p, Move m) {
    g.map[m.y][m.x] = p;

    g.roundCount += 1;

    return g;
}

int end(Game g, int p) {
    if (g.roundCount == (BOARD_SIZE * BOARD_SIZE)) {
        return GAME_TIED;
    }

    int x;
    int y;
    y = 0;

    // horizontal check
    while (y < BOARD_SIZE) {
        x = 0;
        while (x < BOARD_SIZE) {
            if (g.map[y][x] != p) {
                break;
            }

            x += 1;

            if (x == BOARD_SIZE) {
                return GAME_WON;
            }
        }

        y += 1;
    }
    
    // vertical check
    y = 0;
    x = 0;
    while (x < BOARD_SIZE) {
        y = 0;
        while (y < BOARD_SIZE) {
            if (g.map[y][x] != p) {
                break;
            }

            y += 1;

            if (y == BOARD_SIZE) {
                return GAME_WON;
            }
        }
        x += 1;
    }

    // left-top -> right-bottom diag check
    // TODO neaten this up
    y = 0;
    x = 0;
    while (x < BOARD_SIZE) {
        if (g.map[x][x] != p) {
            break;
        }

        x += 1;

        if (x == BOARD_SIZE) {
            return GAME_WON;
        }
    }

    // right-top -> left-bottom diag check
    // TODO neaten this up
    int i = 0;
    while (i < BOARD_SIZE) {
        if (g.map[i][BOARD_SIZE- i - 1] != p) {
            break;
        }

        i += 1;

        if (i == BOARD_SIZE) {
            return GAME_WON;
        }
    }

    return GAME_NOT_OVER;
}

int main(int argc, char *argv[]) {
    Game g = newGame();

    while(1) {
        printGame(g);

        int p;
        if (g.roundCount % 2 == 0) {
            p = PLAYER_ONE;
        } else {
            p = PLAYER_TWO;
        }


        while (1) {
            printf("Where would you like to place your player?\n");

            Move m;
            scanf("%d %d", &m.x, &m.y);
            
            m.x -= 1;
            m.y -= 1;

            printf("placing at grid cooords (%d %d)\n", m.x, m.y);
            if (validMove(g, m)) {
                g = makeMove(g, p, m);
                break;
            } 

            printf("that is not a valid move, try again\n"); 
        }

        printf("\n");
        
        int result = end(g, p);

        if (result != GAME_NOT_OVER) {
            printGame(g);

            if (result == GAME_WON) {
                printf("\n\nplayer %d won!\n", p);
            }else if (result == GAME_TIED) {
                printf("\n\ngame over, tied!\n");
            }

            break;
        }
    }

    return EXIT_SUCCESS;
}
