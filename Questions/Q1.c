#include "./Headers/boards.h"

boardPosArray ** validMoves(movesArray moves[N][M], char board[N][M]) {
	boardPosArray ** res_array = (boardPosArray**)malloc(sizeof(boardPosArray*) * N);

	printf("%p\n", res_array);

	for (int i = 0; i < N; i++)
		res_array[N] = (boardPosArray*)malloc(sizeof(boardPosArray) * M);

	res_array[0][0].size = 1;
	printf("%d\n", res_array[0][0].size);

	int size;
	Move* moveArray;
	Move curMove;
	int rows, cols;
	int i, j, l;
	int index = 0;
	char c;
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			size = moves[i][j].size;
			for (l = 0; l < size; l++) {
				rows = moves[i][j].moves[l].rows;
				cols = moves[i][j].moves[l].cols;
				
				if (board[rows][cols] == '*')
					continue;

				if ((i - rows) >= 0 && (i - rows) < N && (j + cols) < M && (j + cols) >= 0) {
					res_array[i][j].positions[index][0] = 'A' - (i + abs(rows));
					res_array[i][j].positions[index][1] = j + abs(cols);
					index++;
				}
			}
			res_array[i][j].size = index;
		}
	}
	return res_array;
}
