#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream file("input.txt");  // Открываем файл для чтения
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::vector<int> vec;
    int num;

    // Читаем целочисленный одномерный вектор из файла
    while (file >> num) {
        vec.push_back(num);
    }

   // Реверсируем последовательность элементов вектора
    std::reverse(vec.begin(), vec.end());

    // Находим минимальный элемент
    int min_element = *std::min_element(vec.begin(), vec.end());

    // Удаляем все четные элементы из вектора
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }), vec.end());

     // Сортируем вектор в возрастающей последовательности
    std::sort(vec.begin(), vec.end());

     // Вставляем произвольный элемент (например, 42) в вектор, не нарушая сортировку
    vec.insert(std::upper_bound(vec.begin(), vec.end(), 42), 42);

    // Определяем индекс заданного элемента (например, элемента со значением 42)
    auto it = std::find(vec.begin(), vec.end(), 42);
    int index = it != vec.end() ? std::distance(vec.begin(), it) : -1;

    // Удаляем дублированные элементы из вектора
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

    // Выводим результаты
    std::cout << "Reversed vector:";
    for (int num : vec) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    std::cout << "Minimum element: " << min_element << std::endl;

    std::cout << "Sorted vector:";
    for (int num : vec) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    if (index != -1) {
        std::cout << "Index of the element 42: " << index << std::endl;
    }
    else {
        std::cout << "Element 42 not found in the vector." << std::endl;
    }

    file.close(); // Закрываем файл
    return 0;
}
