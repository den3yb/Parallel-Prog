#include "alg.h"
#include <iostream>

using namespace std;
using namespace algoritms;

void oneCycle(int row_1, int colum_1, int row_2, int colum_2){
    //Функция делает прогон программы один раз, создавая рандомные значения для обеих матриц
    // и перемножая их

    createRandomMatrixFile(row_1, colum_1, constants::first_file);
    vector<vector<int>> matrix_1 = readMatrixFromFile(row_1, colum_1, constants::first_file);

    createRandomMatrixFile(row_2, colum_2, constants::second_file);
    vector<vector<int>> matrix_2 = readMatrixFromFile(row_2, colum_2, constants::second_file);

    vector<vector<int>> result = multiplySaveMatrixes(matrix_1, matrix_2);
}

void getMatrixStatistic(vector<int> cycyles){
    //функция замеряет время выполнения в зависимости от количества эллементов и записывает в файл
    //размеры пердаются в векторе
    ofstream file(constants::statistic_file);
    for (size_t i = 0; i < cycyles.size(); ++i) { 
        clock_t start = clock();
        oneCycle(cycyles[i], cycyles[i], cycyles[i], cycyles[i]);
        clock_t end = clock();
        double duration = double(end - start) / CLOCKS_PER_SEC;
        int count = cycyles[i];
        file << count << " " << duration << endl;
    }
    file.close();
}

int main() {
    vector<int> count = {2, 5, 10, 25, 50, 100, 150, 250, 350, 500, 750, 1000};
    getMatrixStatistic(count);
    oneCycle(2,3,3,3);
    return 0;
}
