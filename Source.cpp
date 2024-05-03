#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    // 1. ������ �� ����� �������������� ����������� �������
    std::ifstream inputFile("input.txt");
    std::vector<int> vec;
    int num;
    while (inputFile >> num) {
        vec.push_back(num);
    }
    inputFile.close();

    // 2. ����������� ������������������ ��������� �������
    std::reverse(vec.begin(), vec.end());

    // 3. ������� ����������� �������
    int minElement = *std::min_element(vec.begin(), vec.end());

    // 4. ������� ������ ��������
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }), vec.end());

    // 5. ��������� ������ � ��������� ������������������
    std::sort(vec.rbegin(), vec.rend());

    // 6. ��������� ������������ �������, �� ������� ����������
    int newElement = 100;
    vec.insert(std::upper_bound(vec.begin(), vec.end(), newElement, std::greater<int>()), newElement);

    // 7. ���������� ������ ��������� ��������
    int elementToFind = 50;
    auto it = std::find(vec.begin(), vec.end(), elementToFind);
    int index = std::distance(vec.begin(), it);

    // 8. ������� ������������� ��������
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

    // ������� ����������
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\n����������� �������: " << minElement << "\n";
    std::cout << "������ �������� " << elementToFind << ": " << index << "\n";

    return 0;
}
