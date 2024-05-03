#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    // 1. Чтение из файла целочисленного одномерного вектора
    std::ifstream inputFile("input.txt");
    std::vector<int> vec;
    int num;
    while (inputFile >> num) {
        vec.push_back(num);
    }
    inputFile.close();

    // 2. Реверсируем последовательность элементов вектора
    std::reverse(vec.begin(), vec.end());

    // 3. Находим минимальный элемент
    int minElement = *std::min_element(vec.begin(), vec.end());

    // 4. Удаляем четные элементы
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }), vec.end());

    // 5. Сортируем вектор в убывающей последовательности
    std::sort(vec.rbegin(), vec.rend());

    // 6. Вставляем произвольный элемент, не нарушая сортировку
    int newElement = 100;
    vec.insert(std::upper_bound(vec.begin(), vec.end(), newElement, std::greater<int>()), newElement);

    // 7. Определяем индекс заданного элемента
    int elementToFind = 50;
    auto it = std::find(vec.begin(), vec.end(), elementToFind);
    int index = std::distance(vec.begin(), it);

    // 8. Удаляем дублированные элементы
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

    // Выводим результаты
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\nМинимальный элемент: " << minElement << "\n";
    std::cout << "Индекс элемента " << elementToFind << ": " << index << "\n";

    return 0;
}
