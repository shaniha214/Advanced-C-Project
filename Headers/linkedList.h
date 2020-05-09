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

void makeEmptyList(movesList *lst);
moveCell * createCell(char row, char col);
void printList(movesList *lst);
void freeList(movesList *lst);
void insert(movesList * lst, char row, char col);

#endif