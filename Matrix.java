import java.util.Random;

public class Matrix {
    private static final int SIZE = 2000;

    public static void main(String[] args) {
        double[][] A = new double[SIZE][SIZE];
        double[][] B = new double[SIZE][SIZE];
        double[][] C = new double[SIZE][SIZE];

        // Initialize matrices A and B with random values
        Random rand = new Random();
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++) {
                A[i][j] = rand.nextDouble() * 100;
                B[i][j] = rand.nextDouble() * 100;
            }

        long startTime = System.nanoTime();
        multiplyMatrices(A, B, C);
        long endTime = System.nanoTime();

        long duration = endTime - startTime;
        System.out.printf("Execution time: %.6f seconds%n", duration / 1e9);
    }

    private static void multiplyMatrices(double[][] A, double[][] B, double[][] C) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                C[i][j] = 0;
                for (int k = 0; k < SIZE; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }
}