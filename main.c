/*
This is the user interface
*/

#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include "SparseMatrix.h" 
#include "ReadFile.h" 

// Function to display menu and get user choice
int getUserChoice() {
	int choice;
	printf("\nSelect Matrix Operation:\n");
	printf("1. Addition\n");
	printf("2. Subtraction\n");
	printf("3. Multiplication\n");
	printf("Enter choice (1/2/3): ");
	scanf("%d", &choice);
	return choice;
}

int main() {
	char file1[100], file2[100];
	int choice; 
	
	// Get input file names from user
	printf("Enter first matrix file name: ");
	scanf("%s", file1);
	printf("Enter second matrix file name: ");
	scanf("%s", file2);
	
	// Load sparse matrices from files
	SparseMatrix *matA = readMatrixFromFile(file1);
	SparseMatrix *matB = readMatrixFromFile(file2);
	
	if (!matA || !matB) {
		printf("Error reading input files. Check format.\n");
		return 1;
	}
	
	// Get user choice for operation
	choice = getUserChoice();
	SparseMatrix *result = NULL;
	
	// Perform selected operation
	switch (choice) {
	case 1: 
	result = addMatrices(matA, matB);
	if (result) {
	writeMatrixToFile("result_addition.txt", result);
	printf("Addition result saved to 'result_addition.txt'\n");
	}
	break;
	case 2: 
	result = subtractMatrices(matA, matB);
	if (result) {
	writeMatrixToFile("result_subtraction.txt", result);
	printf("Subtraction result saved to 'result_subtraction.txt'\n");
	}
	break;
	case 3: 
	result = multiplyMatrices(matA, matB);
	if (result) {
	writeMatrixToFile("result_multiplication.txt", result);
	printf("Multiplication result saved to 'result_multiplication.txt'\n");
	}
	break;
	default:
		printf("Invalid choice. Exiting.\n");
		return 1;
	}
	
	// Free allocated memory
	freeMatrix(matA);
	freeMatrix(matB);
	if (result) freeMatrix(result);
	
	return 0;
}