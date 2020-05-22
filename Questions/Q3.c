#include "../headers/binaryTree.h"
#include "../headers/boards.h"

pathTree findAllPossiblePaths(boardPos start, movesArray **moves, char **board) {
  boardPosArray ** boardPosArr = validMoves(moves, board);
  pathTree tr;
  int matrix[N][M] = {0};

  matrix[start[0] - 'A'][start[1] - '0' - 1] = 1;
  tr.head = helper(start, boardPosArr, matrix);
  return tr;
}

treeNode * helper(boardPos start, boardPosArray ** moves, int matrix[N][M]) {
  treeNode * newNode = createNewTreeNode(start);

  // newNode->next_possible_positions = createNodeListCells(boardPosArray[...row][...col], size, matrix);

  // for (position in next_possible_positions)
  //   helper(position, boardPosArray, matrix)

  return newNode;
}

treeNode * createNewTreeNode(boardPos pos) {
  treeNode *newNode = (treeNode*)malloc(sizeof(treeNode));
  assert(newNode);
  strcpy(newNode->position, pos);
  newNode->next_possible_positions = NULL;
  return newNode;
}

treeNodeListCell * createNodeListCells(boardPosArray boardPosArr, int matrix[N][M]) {
  int i;
  treeNodeList lst;
  boardPos pos;
  makeEmptyTreeNodeList(&lst);
  for (i = 0; i < boardPosArr.size; i++) {
    strcpy(pos, boardPosArr.positions[i]);
    if (!matrix[boardPosArr.positions[i][0] - 'A'][pos[1] - '0' - 1]) {
      matrix[boardPosArr.positions[i][0] - 'A'][boardPosArr.positions[i][1] - '0' - 1] = 1;
      insertListCell(&lst, boardPosArr.positions[i]);
    }
  }
  return lst.head;
}

void insertListCell(treeNodeList * lst, boardPos pos) 
{ 
  treeNodeListCell * newListCell = createCell(pos);
  moveCell * p = lst->head;
	if (!lst->head) {
		lst->head = newListCell; 
    lst->tail = newListCell;
    return;
  } 
  lst->tail->next = newListCell;
  lst->tail = newListCell;
} 

treeNodeListCell * createCell(boardPos pos) {
  treeNodeListCell * newListCell = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
  newListCell->node = createNewTreeNode(pos);
  newListCell->next = NULL;
  return newListCell;
}

void makeEmptyTreeNodeList(treeNodeList * lst) {
  lst->head = NULL;
  lst->tail = NULL;
}
