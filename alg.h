#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

namespace constants{
    string first_file = "matrix_in\\first_matrix.txt";
    string second_file = "matrix_in\\second_matrix.txt";
    string result_file = "matrix_out\\result_matrix.txt";
    string statistic_file = "matrix_out\\matrix_statistic.txt";
}

namespace algoritms {

    bool createRandomMatrixFile(int row, int colum, string file_name) {
        // Функция создаёт файл с матрицой рандомного содержания, по заданным размерам
        srand(time(0)); 
        ofstream file(file_name);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < colum; ++j) {file << rand() << " "; }
            file << std::endl; 
        }
        file.close();
        return true;
    }

    std::vector<std::vector<int>> readMatrixFromFile(int row, int colum, string file_name) {
        // Функция считывает из файла матрицу рандомного содержания, по заданным размерам
        std::vector<std::vector<int>> matrix(row, std::vector<int>(colum));
        std::ifstream file(file_name);
        int number;
    
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < colum; ++j) {
                if (file >> number) {
                    matrix[i][j] = number;
                } else {
                    matrix[i][j] = 0;
                }
            }
        }
    
        file.close();
        return matrix;
    }

    vector<vector<int>> multiplySaveMatrixes(vector<vector<int>>& matrix1,vector<vector<int>>& matrix2) {
        // выполняет произведение матриц и записывает результат в файл
        if (matrix1[0].size() != matrix2.size()) {
            cerr << "Матрицы не могут быть умноженны" << endl;
            return {}; 
        }
    
        int row = matrix1.size();
        int colum = matrix2[0].size();
    
        vector<vector<int>> result(row, vector<int>(colum, 0));

        ofstream file(constants::result_file);
    
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < colum; ++j) {
                for (int k = 0; k < matrix1[0].size(); ++k) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
                file << result[i][j] << " ";
            }
            file << endl;
        }

        file.close();

        return result;
    }
    
    void printMatrix(const vector<vector<int>>& matrix) {
        // функция вывода матрицы в консоль
        for (const auto& row : matrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }

}