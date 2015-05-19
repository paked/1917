// tictactoe.h
// by Harrison Shoebridge

#define BOARD_SIZE 3

#define EMPTY -1 
#define PLAYER_ONE 0
#define PLAYER_TWO 1

#define GAME_WON 1
#define GAME_TIED 2
#define GAME_NOT_OVER 0


typedef struct _pos {
    int x;
    int y;
} pos;

typedef struct _game * Game;

void printSpot(int s);
void printGame(Game g);
Game newGame(void);
int validMove(Game g, pos m);
Game makeMove(Game g, int p, pos m);
int end(Game g, int p);
int getSpotPos(Game g, pos m);
int getSpot(Game g, int x, int y);
unsigned int getRound(Game g);

// vim: sts=4 et cc=72
