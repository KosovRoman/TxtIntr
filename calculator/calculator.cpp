#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

// Функция для вычисления среднего арифметического
double calculate_mean(const vector<double>& numbers) {
    double sum = 0;
    for (double num : numbers) {
        sum += num;
    }
    return sum / numbers.size();  // Правильное вычисление среднего
}

// Функция для вычисления медианы
double calculate_median(vector<double>& numbers) {
    sort(numbers.begin(), numbers.end());
    size_t size = numbers.size();
    if (size % 2 == 0) {
        // если четное количество чисел, медиана - это среднее из двух чисел
        return (numbers[size / 2 - 1] + numbers[size / 2]) / 2.0;
    } else {
        // если нечетное количество чисел, медиана - это среднее значение
        return numbers[size / 2];
    }
}

void print_usage() {
    cout << "Usage: calculator -o [operation] [operands...]\n";
    cout << "Operations:\n";
    cout << "  mean   : calculate the mean (average) of the operands\n";
    cout << "  median : calculate the median of the operands\n";
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        print_usage();
        return 1;
    }

    // Первым аргументом идет операция, например "mean"
    string operation = argv[1];
    vector<double> operands;

    // Обрабатываем параметры
    if (operation == "-o" || operation == "--operation") {
        if (argc < 4) {
            cout << "Error: You must provide at least 5 operands.\n";
            return 1;
        }

        string calc_type = argv[2]; // Это будет "mean" или "median"

        // Чтение операндов
        for (int i = 3; i < argc; i++) {
            operands.push_back(atof(argv[i])); // преобразуем строку в число
        }

        // Отладочный вывод: печатаем все операнды
        cout << "Operands: ";
        for (double num : operands) {
            cout << num << " ";
        }
        cout << endl;

        // Проверка на допустимое количество операндов
        if (operands.size() < 5 || operands.size() > 7) {
            cout << "Error: The number of operands must be between 5 and 7.\n";
            return 1;
        }

        if (calc_type == "mean") {
            double mean = calculate_mean(operands);
            cout << "Mean: " << mean << endl;
        } 
        else if (calc_type == "median") {
            double median = calculate_median(operands);
            cout << "Median: " << median << endl;
        } 
        else {
            cout << "Invalid operation!" << endl;
            print_usage();
        }
    } else {
        print_usage();
    }

    return 0;
}

