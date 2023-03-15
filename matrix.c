// Harris Ransom
// C 2D Matrix
// Based on video by Jacob Sorber

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 4

typedef struct matrix {
	unsigned int rows;
	unsigned int cols;
	int **data;

} matrix;

// Initializes matrix with given dimensions
matrix *initMat(int rows, int cols) {
	matrix *mat = malloc(sizeof(matrix));
	mat->rows = rows;
	mat->cols = cols;

	// Dynamically allocates memory for matrix data
	mat->data = calloc(rows, sizeof(int*));
	if (mat->data == NULL) return NULL;
	for (int i = 0; i < rows; i++) {
		mat->data[i] = calloc(cols, sizeof(int));
		if (mat->data[i] == NULL) return NULL;
	}
	return mat;
}

// Deletes matrix
void deleteMat(matrix *mat) {
	for (int i = 0; i < mat->rows; i++) {
		free(mat->data[i]);
	}
	free(mat->data);
	free(mat);
	return;
}

// Prints out matrix
void printMat(matrix *mat) {
	for (int i = 0; i < mat->rows; i++) {
		printf("%d:\t", i);
		for (int j = 0; j < mat->cols; j++) {
			printf("%x ", mat->data[i][j]);
		}
		printf("\n");
	}
}

// MAIN
int main() { 
	matrix *mat = initMat(ROWS, COLS);

	if (mat == NULL) {
		printf("initMatrix failed!");
		return 1;
	}
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			mat->data[i][j] = (i << 16) | j;
		}
	}

	printMat(mat);

	printf("sizeof(mat) = %lu\n", sizeof(*mat));
	printf("sizeof(rows) = %lu\n", sizeof(mat->rows));
	printf("sizeof(cols) = %lu\n", sizeof(mat->cols));
	printf("sizeof(data) = %lu\n", sizeof(mat->data));

	deleteMat(mat);
	return 0;
}
