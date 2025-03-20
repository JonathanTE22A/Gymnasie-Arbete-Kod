#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

// Function to multiply two matrices
void multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    int n = A.size();
    int m = A[0].size();
    int p = B[0].size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            C[i][j] = 0; // Initialize the result cell
            for (int k = 0; k < m; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to create a matrix with random values
vector<vector<int>> createRandomMatrix(int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 10; // Random values between 0 and 9
        }
    }
    return matrix;
}

int main() {
    // Seed for random number generation
    srand(static_cast<unsigned>(time(0)));

    // Fixed dimensions for matrices
    const int n = 2000; // Rows for matrix A and C
    const int m = 2000; // Columns for matrix A and rows for matrix B
    const int p = 2000; // Columns for matrix B and C

    // Initialize matrices A and B with random values
    vector<vector<int>> A = createRandomMatrix(n, m);
    vector<vector<int>> B = createRandomMatrix(m, p);
    
    // Resultant matrix C
    vector<vector<int>> C(n, vector<int>(p, 0));

    // Start the timer
    auto start = chrono::high_resolution_clock::now();

    // Multiply matrices A and B
    multiplyMatrices(A, B, C);

    // Stop the timer
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    // Output the time taken
    cout << "Time taken for multiplication: " << duration.count() << " seconds" << endl;

    return 0;
}






