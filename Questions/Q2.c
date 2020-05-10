#include "../Headers/linkedList.h"

int display(movesList *moves_list, boardPos start, char board[N][M]) {
	moveCell *p = moves_list->head;
  moveCell *temp;
  Location location = {start[0] - 'A', start[1] - '0' - 1};
  Location locationCheck;
	int deletedNodes = 0, n = 1; 

	board[location.row][location.col] = '#';

  while (p) {
    locationCheck.row = location.row - p->move.rows;
    locationCheck.col = p->move.cols + location.col; 

    if (
      (locationCheck.row) < 0 ||
      (locationCheck.row) >= N || 
      (locationCheck.col) >= M ||
      (locationCheck.col) < 0 ||
      board[locationCheck.row][locationCheck.col] != ' '
    ) {
      temp = p;
      deleteNode(moves_list, p);
      p = temp->next;
      deletedNodes++;
    } else {
      location = locationCheck;
      board[location.row][location.col] = '0' + n;
      n++;
      p = p->next;
    }
  } 
  printBoard(board);
	return deletedNodes;
}

void printBoard(char board[N][M]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) 
			printf("[%c]", board[i][j]);
		printf("\n");
	}
}
