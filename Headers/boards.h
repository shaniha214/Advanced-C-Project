#ifndef BOARDS_H
#define BOARDS_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define N 2
#define M 2

typedef char boardPos[2];

// e.g: (rows: 1, cols: -3) --> move one row up, three columns left
typedef struct _move {
  char rows, cols;
} Move; 

// e.g: {{rows: 1. cols: -3}, {rows: -5, cols: 7}, ...}
typedef struct _movesArray {
  unsigned int size;
  Move *moves;
} movesArray;

// e.g: {"A4", "B8", "D6", "E1"}
typedef struct _boardPosArray {
  unsigned int size;
  boardPos *positions;
} boardPosArray;


boardPosArray ** validMoves(movesArray ** moves, char ** board);

#endif