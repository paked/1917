// tictactoe.c - for when you want to tic tac toe
// by Harrison Shoebridge on the 18/5/15

#include <stdlib.h>
#include <stdio.h>
#include "tictactoe.h"

typedef struct _game {
    int map[BOARD_SIZE][BOARD_SIZE];
    unsigned int roundCount;
} game;

// TODO make function names more specific to the "game"
// TODO allow symbol selection for characters
// TODO descriptions of game
// TODO write tests

Game newGame(void) {
    game *g = malloc(sizeof(game));
    int y = 0;

    while (y < BOARD_SIZE) {
        int x = 0;
        while (x < BOARD_SIZE) {
            g->map[y][x] = EMPTY;
            x += 1;
        }

        y += 1;
    }

    g->roundCount = 0;

    return g;
}

int getSpot(Game g, int x, int y) {
    return g->map[y][x];
}

unsigned int getRound(Game g) {
    return g->roundCount;
}

void printGame(Game g) {
    printf("Round #%d\n", getRound(g));

    int y = 0;
    
    // TODO make formatting prettier, code and normal wise

    printf("-------------\n");
    
    while (y < BOARD_SIZE) {
        int x = 0;
        printf("|");
        while (x < BOARD_SIZE) {
            printSpot(getSpot(g, x, y));
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

int validMove(Game g, pos m) {
    // boundary checks
    if (m.x < 0 || m.y < 0 || m.x > BOARD_SIZE || m.y > BOARD_SIZE) {
        return 0;
    }
    
    // move already made
    if (getSpot(g, m.x, m.y) != EMPTY) { 
        return 0;
    }

    return 1;
}

Game makeMove(Game g, int p, pos m) {
    g->map[m.y][m.x] = p;

    g->roundCount += 1;

    return g;
}

int end(Game g, int p) {
    if (getRound(g) == (BOARD_SIZE * BOARD_SIZE)) {
        return GAME_TIED;
    }

    int x;
    int y;
    y = 0;

    // horizontal check
    while (y < BOARD_SIZE) {
        x = 0;
        while (x < BOARD_SIZE) {
            if (getSpot(g, x, y) != p) {
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
            if (getSpot(g, y, x) != p) {
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
        if (getSpot(g, x, x) != p) {
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
        if (getSpot(g, i, BOARD_SIZE - i - 1) != p) {
            break;
        }

        i += 1;

        if (i == BOARD_SIZE) {
            return GAME_WON;
        }
    }

    return GAME_NOT_OVER;
}

int getCurrentPlayer(Game g) {
    int p;
    if (getRound(g) % 2 == 0) {
        p = PLAYER_ONE;
    } else {
        p = PLAYER_TWO;
    }

    return p;
}

// vim: sts=4 et cc=72
