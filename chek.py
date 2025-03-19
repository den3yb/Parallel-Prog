import numpy as np

def load_matrix_from_file(filename):
    """
    Считывает матрицы из файла
    """
    matrix = np.loadtxt(filename)
    return matrix


def check_matrix_multiplication(file1, file2, file3):
   
    """
    Принимает три файла с матрицами и проверяет их произведение
    """
    matrix1 = load_matrix_from_file(file1)
    matrix2 = load_matrix_from_file(file2)
    matrix3 = load_matrix_from_file(file3)

    if matrix1 is None or matrix2 is None or matrix3 is None:
        return None  

    product = np.dot(matrix1, matrix2)
    return np.allclose(product, matrix3)  


if __name__ == '__main__':
    file1 = "matrix_in\\first_matrix.txt"
    file2 = "matrix_in\\second_matrix.txt"
    file3 = "matrix_out\\result_matrix.txt"

    result = check_matrix_multiplication(file1, file2, file3)

    if result is None:
        print("Проверка не была выполнена из-за ошибок при чтении файлов.")
    elif result:
        print("Произведение первой и второй матриц равно третьей.")
    else:
        print("Произведение первой и второй матриц НЕ равно третьей.")