import random
import time

# Function to multiply two matrices
def matrix_multiply(A, B):
    result = [[0 for _ in range(len(B[0]))] for _ in range(len(A))]
    
    # Iterating through rows of A
    for i in range(len(A)):
        # Iterating through columns of B
        for j in range(len(B[0])):
            # Iterating through rows of B
            for k in range(len(B)):
                result[i][j] += A[i][k] * B[k][j]
    
    return result

# Function to generate a random matrix with given dimensions
def generate_matrix(rows, cols):
    return [[random.random() for _ in range(cols)] for _ in range(rows)]

# Matrix size (2000x2000)
n = 2000

# Generating two random matrices A and B
A = generate_matrix(n, n)
B = generate_matrix(n, n)

# Measuring the time taken for matrix multiplication
start_time = time.time()
C = matrix_multiply(A, B)
end_time = time.time()

# Printing the execution time
print("Execution time:", end_time - start_time)
