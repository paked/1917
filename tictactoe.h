// tictactoe.h - define the tictactoe ADT
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

// TODO add descriptions of functions
// TODO add more getters and setters

// end checks if the game is in a state where the current player has
// won. This could be caused by one or more of these events:
// * The game has reached 9 rounds, therefore are no more spots
//   on the board. => results in a tie.
// * The current player has placed a mark in a spot that completes
//   a horizontal row. => results in a win for current player
// * The current player has placed a mark in a spot that completes
//   a vertical row of length BOARD_SIZE. => results in a
//   win for the current player
// * The current player has placed a mark in a spot that completes
//   a diagonal row of length BOARD_SIZE. => results in a win for
//   the current player
int end(Game g, int p);

// getSpotPos retrieves a spots value on the board. The position is
// supplied through a pos struct.
int getSpotPos(Game g, pos m);

// getSpot retrieves the value of a spot using traditional x and y
// integers.
int getSpot(Game g, int x, int y);

// valid move detects if the move supplied in pos m is valid. A move
// is valid if:
// * It is within the confines of the board. ie. m > {0,0}, 
//   m < {BOARD_SIZE,BOARD_SIZE}
// * The current player has not already placed a mark there
// * Another player has not placed a mark there.
int validMove(Game g, pos m);

// getCurrentPlayer gets the player whoes turn it currently is. It
// uses modulation based upon the getRound value.
int getCurrentPlayer(Game g);

// getRound retrieves the current round of the game.
unsigned int getRound(Game g);

// printSpot prints out the ASCII representation of spot's value.
void printSpot(int s);

// printGame prints out the entire state of the game. This includes:
// * Round number
// * Which players turn it is
// * The board
void printGame(Game g);

// newGame creates a new game and sets the roundCount and map to 
// default values.
Game newGame(void);

// makeMove makes a move for a player. It assumes that the move has
// been validated by validMove prior.
Game makeMove(Game g, int p, pos m);

// vim: sts=4 et cc=72
