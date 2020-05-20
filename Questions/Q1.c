#include "../Headers/boards.h"
#include "../Headers/linkedList.h"

void printMoves(movesArray moves[N][M]) {
	Move curMove;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("Move with size %d \n", moves[i][j].size);
			for (int k = 0; k < moves[i][j].size; k++) {
				curMove = moves[i][j].moves[k];
				printf("(%d, %d) ", curMove.rows, curMove.cols);
			}
			printf("\n");
		}
	}
}

// TODO: moves[N][M] ==> ** moves
boardPosArray ** validMoves(movesArray moves[N][M], char board[N][M]) {
	boardPosArray ** res_array = (boardPosArray**)malloc(sizeof(boardPosArray*) * N);

	for (int i = 0; i < N; i++)
		res_array[i] = (boardPosArray*)malloc(sizeof(boardPosArray) * M);
	   
	int size;
	Move * moveArray;
	int rows, cols;
	int i, j, l ,write = 0, read = 0;
	int index = 0;
	char c;
	// TODO: delete this
	boardPosArray curPos;

	printMoves(moves);
	printf("\n\n\n");

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			size = moves[i][j].size;
			moveArray = moves[i][j].moves;

			while (read < size) {
				rows = moves[i][j].moves[read].rows;
				cols = moves[i][j].moves[read].cols;
				if (
					(i - rows) >= 0 && (i - rows) < N && 
					(j + cols) < M && (j + cols) >= 0 && 
					(board[i - rows][j + cols] != '*')
				) {
					swap(moveArray + read, moveArray + write);
					write++;
				}
				read++;
			}
			moves[i][j].size = write;

			while (write < size) {
				free(moveArray + write);
				write++;
			}
			read = 0;
			write = 0;
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			size = moves[i][j].size;
			res_array[i][j].positions = (boardPos*)malloc(sizeof(boardPos)*size);
			for (l = 0; l < size; l++) {
				rows = moves[i][j].moves[l].rows;
				cols = moves[i][j].moves[l].cols;
				res_array[i][j].positions[index][0] = 'A' + (i - rows);
				res_array[i][j].positions[index][1] = j + 1 + cols;
				index++;
			}
			res_array[i][j].size = index;
			index = 0;
		}
	}

	// TODO: delete this
	// for (int i = 0; i < N; i++) {
	// 	for (int j = 0; j < M; j++) {
	// 		curPos = res_array[i][j];
	// 		printf("Move with size %d \n", curPos.size);
	// 		for (int k = 0; k < curPos.size; k++) {

	// 			printf("(%c%d) ", curPos.positions[k][0], curPos.positions[k][1]);
	// 		}
	// 		printf("\n");
	// 	}
	// }
	return res_array;
}

void swap(Move * m1, Move * m2) {
	Move temp = *m1;
	*m1 = *m2;
	*m2 = temp;
}
