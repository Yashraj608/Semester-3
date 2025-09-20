import numpy as np

# ----------- Gauss-Jordan Method -----------
def gauss_jordan_method(matrix, constants):
    n = len(constants)

    # create augmented matrix [A|B]
    augmented = np.hstack((matrix.astype(float), constants.reshape(-1, 1).astype(float)))

    for i in range(n):
        # make the diagonal element = 1
        augmented[i] = augmented[i] / augmented[i][i]

        # make other rows = 0 in the current column
        for j in range(n):
            if i != j:
                augmented[j] = augmented[j] - augmented[j][i] * augmented[i]

    # last column gives solution
    solution = augmented[:, -1]
    return solution


# ----------- Inverse Matrix Method -----------
def inverse_method(matrix, constants):
    inverse_matrix = np.linalg.inv(matrix)  # find inverse of A
    solution = np.dot(inverse_matrix, constants)  # X = A^-1 * B
    return solution


# ----------- Main Program -----------
if __name__ == "__main__":
    # Example system of equations:
    # 2x +  y -  z =  8
    #-3x -  y + 2z = -11
    #-2x +  y + 2z = -3

    A = np.array([[2, 1, -1],
                  [-3, -1, 2],
                  [-2, 1, 2]], dtype=float)

    B = np.array([8, -11, -3], dtype=float)

    print("System of Equations:")
    print("2x +  y - z =  8")
    print("-3x - y + 2z = -11")
    print("-2x + y + 2z = -3\n")

    # Solve using Gauss-Jordan Method
    answer_gj = gauss_jordan_method(A.copy(), B.copy())
    print("Solution using Gauss-Jordan Method:", answer_gj)

    # Solve using Inverse Matrix Method
    answer_inv = inverse_method(A.copy(), B.copy())
    print("Solution using Inverse Matrix Method:", answer_inv)
