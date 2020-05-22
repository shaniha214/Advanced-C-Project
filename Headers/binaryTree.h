#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "boards.h"
#include "linkedList.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct _treeNode{
  boardPos position;
  treeNodeListCell *next_possible_positions; 
} treeNode;

typedef struct _treeNodeListCell {
  treeNode * node;
  struct _treeNodeListCell * next;
} treeNodeListCell;

typedef struct _treeNodeList {
  struct _treeNodeListCell * head;
  struct _treeNodeListCell * tail;
} treeNodeList;

typedef struct _pathTree {
  treeNode * head;
} pathTree;

pathTree findAllPossiblePaths(boardPos start, movesArray **moves, char **board);
treeNode * helper(boardPos start, boardPosArray ** moves, int matrix[N][M]);
treeNode * createNewTreeNode(boardPos pos);
treeNodeListCell * createNodeListCells(boardPosArray boardPosArr, int matrix[N][M]);
void makeEmptyTreeNodeList(treeNodeList * lst);
treeNodeListCell * createCell(boardPos pos);


#endif