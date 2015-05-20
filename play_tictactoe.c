// play_tictactoe.c - An interface for tictactoe
// by Harrison Shoebridge

#include <stdlib.h>
#include <stdio.h>
#include "tictactoe.h"

int main(int argc, char *argv[]) {
    Game g = newGame();

    while(1) {
        printGame(g);

        int p = getCurrentPlayer(g);

        while (1) {
            printf("Where would you like to place your player?\n");

            pos m;
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

// vim: sts=4 et cc=72
