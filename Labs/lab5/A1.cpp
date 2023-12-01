#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    // std::cout << "Введите размер массива: ";
    std::cin >> N;

    std::vector<int> originalArray(N);

    // std::cout << "Введите " << N << " элементов: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> originalArray[i];
    }

    std::vector<int> sumsArray; // Массив для хранения сумм

    while (originalArray.size() > 1) {
        // Находим два минимальных элемента
        int min1 = std::min_element(originalArray.begin(), originalArray.end()) - originalArray.begin();
        int min1_value = originalArray[min1];
        originalArray.erase(originalArray.begin() + min1);

        int min2 = std::min_element(originalArray.begin(), originalArray.end()) - originalArray.begin();
        int min2_value = originalArray[min2];
        originalArray.erase(originalArray.begin() + min2);

        // Суммируем минимальные элементы и добавляем сумму в исходный массив
        int sum = min1_value + min2_value;
        originalArray.push_back(sum);

        // Добавляем сумму в массив сумм
        sumsArray.push_back(sum);
    }

    std::cout << "Массив после обработки: ";
    for (int num : originalArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Массив сумм: ";
    for (int sum : sumsArray) {
        std::cout << sum << " ";
    }
    std::cout << std::endl;

    int sumOfSums = 0;
    for (int sum : sumsArray) {
        sumOfSums += sum;
    }

    std::cout << "Сумма всех элементов во втором массиве: " << sumOfSums << std::endl;

    return 0;
}
