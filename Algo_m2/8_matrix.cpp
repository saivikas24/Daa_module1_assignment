#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;

    // Step 1: Input matrix dimensions
    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    // Step 2: Check if multiplication is possible
    if (c1 != r2) {
        cout << "Matrix multiplication not possible!" << endl;
        return 0;
    }

    int A[10][10], B[10][10], C[10][10] = {0};

    // Step 3: Input elements for Matrix A
    cout << "\nEnter elements of Matrix A:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];

    // Step 4: Input elements for Matrix B
    cout << "\nEnter elements of Matrix B:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];

    // Step 5: Matrix Multiplication Logic
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Step 6: Display Result
    cout << "\nResultant Matrix (A x B):\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
