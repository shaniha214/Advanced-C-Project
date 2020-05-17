
#include "./Headers/boards.h"
#include "./Headers/linkedList.h"

int main() {
	boardPosArray **res_array;
	int i, j, k, size;
	int row, col;
	char board[N][M];
	movesArray moves[N][M];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%c", &board[i][j]);

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			printf("enter number of moves for %c%d:\n", 'A' + i, j +1);
			scanf("%d", &size);
			moves[i][j].size = size;
			moves[i][j].moves = (Move*)malloc(sizeof(Move));
		
			printf("Now enter the moves:\n");
			for (k = 0; k < size; k++) {
				scanf("%d%d", &row, &col);
				moves[i][j].moves[k].rows = row;
				moves[i][j].moves[k].cols = col;
			}
		}
	}
	// printBoard(board);
	// printMoves(moves);
	res_array = validMoves(moves, board);
	return 0;
}
