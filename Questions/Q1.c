#include "../Headers/boards.h"

boardPosArray ** validMoves(movesArray **moves, char** board) {
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

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			size = moves[i][j].size;
			res_array[i][j].positions= (boardPos*)malloc(sizeof(boardPos)*size);
			for (l = 0; l < size; l++) {
				rows = moves[i][j].moves[l].rows;
				cols = moves[i][j].moves[l].cols;
				
				if (
					(i - rows) >= 0 && (i - rows) < N && 
					(j + cols) < M && (j + cols) >= 0 && 
					(board['A' - (i + abs(rows))][j + abs(cols)] != '*')
				) {
					res_array[i][j].positions[index][0] = 'A' - (i + abs(rows));
					res_array[i][j].positions[index][1] = j + abs(cols);
					index++;
				}
			}
		}
		res_array[i][j].size = index;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("Move with size %d \n", res_array[i][j].size);
			for (int k = 0; k < res_array[i][j].size; k++) {

				printf("(%d, %d) ", res_array[i][j].positions[k][0], res_array[i][j].positions[k][1]);
			}
			printf("\n");
		}
	}
	return res_array;
}
