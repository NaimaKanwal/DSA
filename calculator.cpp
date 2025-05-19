#include <iostream>
using namespace std;

const int MATRIX_SIZE = 4;

enum MatrixType {
    MATRIX,
    VECTOR
};

struct Matrix {
    int data[MATRIX_SIZE][MATRIX_SIZE];
    MatrixType type;
};

Matrix addMatrices(const Matrix& A, const Matrix& B) {
    Matrix result;
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            result.data[i][j] = A.data[i][j] + B.data[i][j];
        }
    }
    result.type = A.type;
    return result;
}

Matrix subtractMatrices(const Matrix& A, const Matrix& B) {
    Matrix result;
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            result.data[i][j] = A.data[i][j] - B.data[i][j];
        }
    }
    result.type = A.type;
    return result;
}

Matrix multiplyMatrices(const Matrix& A, const Matrix& B) {
    Matrix result;
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; ++k) {
                result.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }
    result.type = A.type;
    return result;
}

Matrix multiplyMatrixByScalar(const Matrix& matrix, int scalar) {
    Matrix result;
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            result.data[i][j] = matrix.data[i][j] * scalar;
        }
    }
    result.type = matrix.type;
    return result;
}

Matrix multiplyMatrixByVector(const Matrix& matrix, const int vector[]) {
    Matrix result;
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        result.data[i][0] = 0;
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            result.data[i][0] += matrix.data[i][j] * vector[j];
        }
    }
    result.type = VECTOR;
    return result;
}

void displayMatrix(const Matrix& matrix) {
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            cout << matrix.data[i][j] << " ";
        }
        cout << endl;
    }
}

void displayVector(const Matrix& matrix) {
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        cout << matrix.data[i][0] << " ";
    }
    cout << endl;
}

void inputMatrix(Matrix& matrix, const string& matrixName) {
    cout << "Enter elements of " << matrixName << " matrix (4x4):\n";
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            cout << "position enter : (" << i + 1 << "," << j + 1 << "): ";
            cin >> matrix.data[i][j];
        }
    }
}

void inputVector(int vector[], const string& vectorName) {
    cout << "Enter elements of " << vectorName << " vector (4 elements):\n";
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        cout << "posiion enter : " << i + 1 << ": ";
        cin >> vector[i];
    }
}

int main() {
    Matrix matrixA, matrixB, resultMatrix;
    int scalar;
    int vector[MATRIX_SIZE];

    matrixA.type = MATRIX;
    matrixB.type = MATRIX;

    inputMatrix(matrixA, "first");
    inputMatrix(matrixB, "second");

    int choice;
    do {
        cout << "\n::::::::::::::::::::::Matrix Calculator Menu:::::::::::::::::::::::::::\n";
        cout << "1. ::::::Addition::::::\n";
        cout << "2. ::::::Subtraction::::::\n";
        cout << "3. ::::::Multiplication::::::\n";
        cout << "4. :::::::::Scalar Multiplication:::::::\n";
        cout << "5. :::::::::Vector Multiplication::::::::\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                resultMatrix = addMatrices(matrixA, matrixB);
                cout << "\nResult of addition:\n";
                displayMatrix(resultMatrix);
                break;
            case 2:
                resultMatrix = subtractMatrices(matrixA, matrixB);
                cout << "\nResult of subtraction:\n";
                displayMatrix(resultMatrix);
                break;
            case 3:
                resultMatrix = multiplyMatrices(matrixA, matrixB);
                cout << "\nResult of multiplication:\n";
                displayMatrix(resultMatrix);
                break;
            case 4:
                cout << "Enter scalar value: ";
                cin >> scalar;
                resultMatrix = multiplyMatrixByScalar(matrixA, scalar);
                cout << "\nResult of scalar multiplication:\n";
                displayMatrix(resultMatrix);
                break;
            case 5:
                inputVector(vector, "vector");
                resultMatrix = multiplyMatrixByVector(matrixA, vector);
                cout << "\nResult of vector multiplication:\n";
                displayVector(resultMatrix);
                break;
            case 6:
                cout << "EXIT PROGRAM.\n";
                break;
            default:
                cout << "U HAVE ENTER WRONG NUMBER PLEASE ENTER BETWEEN 1 TO 6 :) :\n";
        }
    } while (choice != 6);

    return 0;
}

