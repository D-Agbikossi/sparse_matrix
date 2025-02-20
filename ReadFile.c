/*
Given a file containing sampla data to load a sparse matrix, this program create a file
better organise. Data are stored in a linked list for a better output file.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "SparseMatrix.h"

// Function to read an input file
// Open the file
SparseMatrix* readMatrixFromFile(const char* filename) {
	FILE* file = fopen(filename, "r");
	if (!file) {
		printf("Error: Cannot open file %s\n", filename);
		return NULL;
	}
	
	// Read the file
	int rows, cols;
	if (fscanf(file, "rows=%d cols=%d", &rows, &cols) != 2) {
		printf("Error: Incorrect file format in %s\n", filename);
		fclose(file);
		return NULL;
	}
	
	SparseMatrix* matrix = createMatrix(rows, cols); int row, col, value; 
	
	// Read each (row, col, value) tuple 
	while (fscanf(file, " (%d, %d, %d)", &row, &col, &value) == 3) {
		setElement(matrix, row, col, value);
	} 
	
	fclose(file); 
	return matrix; 
} 

// Function to write a sparse matrix to a file 
void writeMatrixToFile(SparseMatrix *matrix, const char *filename) {
	FILE *file = fopen(filename, "w");
	if (!file) { printf("Error: Cannot open file %s for writing\n", filename);
	return;
	}
	
	fprintf(file, "rows=%d cols=%d\n", matrix->rows, matrix->cols);
	Node *current = matrix->head;
	while (current) {
		fprintf(file, "(%d, %d, %d)\n", current->row, current->col, current->value);
		current = current->next;
	}
	
	fclose(file);
}