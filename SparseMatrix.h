#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H 

// Structure to store a single non-zero matrix element
typedef struct Node {
	int row, col, value;
	struct Node *next;
}
Node;

// Structure to represent the sparse matrix
typedef struct SparseMatrix {
	int rows, cols;
	Node *head; // Linked list to store non-zero elements
} SparseMatrix;

// Function prototypes
SparseMatrix* createMatrix(int rows, int cols);
void setElement(SparseMatrix *matrix, int row, int col, int value);
int getElement(SparseMatrix *matrix, int row, int col);
SparseMatrix* addMatrices(SparseMatrix *A, SparseMatrix *B);
SparseMatrix* subtractMatrices(SparseMatrix *A, SparseMatrix *B);
SparseMatrix* multiplyMatrices(SparseMatrix *A, SparseMatrix *B);
void printMatrix(SparseMatrix *matrix);
void freeMatrix(SparseMatrix *matrix);

#endif // SPARSE_MATRIX_H