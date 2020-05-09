#include "../Headers/linkedList.h"

void printList(movesList *lst) {
  while (lst->head) {
    printf("(%d, %d)\n", lst->head->move.rows, lst->head->move.cols);
    lst->head = lst->head->next; 
  } 
}

void insert(movesList * lst, char row, char col) 
{ 
  moveCell * newNode = createCell(row, col);
  moveCell * p = lst->head;
	if (!lst->head) {
		lst->head = newNode; 
    lst->tail = newNode;
    return;
  }
  lst->tail->next = newNode;
  lst->tail = newNode;
} 

void deleteNode(movesList * lst, moveCell * p) {
  if (!lst->head)
    return;
  else if (!p->prev) {
    if (lst->head->next) 
      lst->tail = p->next;

    lst->head = p->next;
    lst->head->prev = NULL;
    free(p);
  } else if (!p->next) {
    lst->tail = p->prev;
    p->prev->next = NULL;
    free(p);
  } else {
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
  }
}

void makeEmptyList(movesList *lst)
{
  lst->head = NULL;
  lst->tail = NULL;
}

moveCell * createCell(char row, char col) {
  moveCell *newNode = (moveCell*)malloc(sizeof(moveCell));
  assert(newNode);
  newNode->move.cols = col;
  newNode->move.rows = row;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

void freeList(movesList *lst) {
  moveCell * temp;
  while (lst->head) {
    temp = lst->head;
    lst->head = temp->next;
    free(temp);
  }
}