function createMatrix(size) {
    return Array.from({ length: size }, () =>
        Array.from({ length: size }, () => Math.random() * 100)
    );
}

function multiplyMatrices(A, B) {
    const size = A.length;
    const C = Array.from({ length: size }, () => Array(size).fill(0));
    
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            for (let k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

const size = 2000;
const A = createMatrix(size);
const B = createMatrix(size);

console.time('Execution time');
const C = multiplyMatrices(A, B);
console.timeEnd('Execution time');