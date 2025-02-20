/*
This program allocate 
- memory for a sparse matirx structure, 
- retrieve the value at a specific position,
- inserts and updates value in the matrix
- process operations (add, substract, multiply) and free 
memory used by matrix.
*/


#include <stdio.h>
#include <stdlib.h>
#include "SparseMatrix.h"

// Function to create a new sparse matrix
SparseMatrix* createMatrix(int rows, int cols) {
	SparseMatrix *matrix = (SparseMatrix*)malloc(sizeof(SparseMatrix));
	matrix->rows = rows;
	matrix->cols = cols;
	matrix->head = NULL;
	return matrix;
} 

// Function to get an element from the sparse matrix
int getElement(SparseMatrix *matrix, int row, int col) {
	Node *current = matrix->head;
	while (current) {
		if (current->row == row && current->col == col) {
			return current->value; 
		} 
		current = current->next;
	}
	return 0;  // Default value for empty positions
} 

// Function to set an element in the sparse matrix
void setElement(SparseMatrix *matrix, int row, int col, int value) {
	if (value == 0) return; // Do not store zero values

	// Check if the element already exists
	Node* current = matrix->head;
	while (current) {
		if (current->row == row && current->col == col) {
			current->value = value;  // Update the value if the element exists
			return;
		}
		current = current->next;
	}

	// Create a new node it does not exist
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->row = row;
	newNode->col = col;
	newNode->value = value;
	newNode->next = matrix->head;
	matrix->head = newNode;
} 

// Function to add two sparse matrices
SparseMatrix* addMatrices(SparseMatrix* A, SparseMatrix* B) {
	if (A->rows != B->rows || A->cols != B->cols) {
		printf("Error: Matrices must have the same dimensions for addition.\n");
		return NULL;
	}

	SparseMatrix* result = createMatrix(A->rows, A->cols);
	Node* currentA = A->head;
	Node* currentB = B->head;

	// Copy elements from A to result
	while (currentA) {
		setElement(result, currentA->row, currentA->col, currentA->value);
		currentA = currentA->next;
	}

	// Add elements from B to result
	while (currentB) {
		int existingValue = getElement(result, currentB->row, currentB->col);
		setElement(result, currentB->row, currentB->col, existingValue + currentB->value);
		currentB = currentB->next;
	}