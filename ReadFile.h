#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "SparseMatrix.h"

// Function prototypes
SparseMatrix* readMatrixFromFile(const char *filename);
void writeMatrixToFile(SparseMatrix *matrix, const char *filename);

#endif // FILE_HANDLER_H