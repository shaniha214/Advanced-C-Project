#include "../Headers/boards.h"
#include "../Headers/linkedList.h"

// TODO: moves[N][M] ==> ** moves
boardPosArray ** validMoves(movesArray moves[N][M], char board[N][M]) {
	boardPosArray ** res_array = (boardPosArray**)malloc(sizeof(boardPosArray*) * N);

	for (int i = 0; i < N; i++)
		res_array[i] = (boardPosArray*)malloc(sizeof(boardPosArray) * M);
	   
	int size;
	Move* moveArray;
	Move curMove;
	int rows, cols;
	int i, j, l;
	int index = 0;
	char c;
	// TODO: delete this
	boardPosArray curPos;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			size = moves[i][j].size;
			res_array[i][j].positions = (boardPos*)malloc(sizeof(boardPos)*size);
			for (l = 0; l < size; l++) {
				rows = moves[i][j].moves[l].rows;
				cols = moves[i][j].moves[l].cols;
				
				if (
					(i - rows) >= 0 && (i - rows) < N && 
					(j + cols) < M && (j + cols) >= 0 && 
					(board[i - rows][j + cols] != '*')
				) {
					res_array[i][j].positions[index][0] = 'A' + (i - rows);
					res_array[i][j].positions[index][1] = j + 1 + cols;
					index++;
				}
			}
			res_array[i][j].size = index;
			index = 0;
		}
	}

	// TODO: delete this
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			curPos = res_array[i][j];
			printf("Move with size %d \n", curPos.size);
			for (int k = 0; k < curPos.size; k++) {

				printf("(%c%d) ", curPos.positions[k][0], curPos.positions[k][1]);
			}
			printf("\n");
		}
	}
	return res_array;
}
