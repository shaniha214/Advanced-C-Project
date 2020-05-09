#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "boards.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct _moveCell {
  Move move;
  struct _moveCell *next, *prev;
} moveCell;

typedef struct _movesList {
  moveCell * head;
  moveCell * tail;
} movesList;

typedef struct _location {
  int row, col;
} Location;

void makeEmptyList(movesList *lst);
moveCell * createCell(char row, char col);
void printList(movesList *lst);
void freeList(movesList *lst);
void insert(movesList * lst, char row, char col);
void deleteNode(movesList * lst, moveCell * p);
int display(movesList *moves_list, boardPos start, char board[N][M]);
void printBoard(char board[N][M]);

#endif