#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // std::sort
#include <chrono>    // Pomiar czasu

int main() {
    // Rozpoczęcie mierzenia czasu
    auto start = std::chrono::high_resolution_clock::now();

    std::ifstream inputFile("array.txt"); // Plik wejściowy z liczbami
    std::ofstream outputFile("sorted_cpp.txt"); // Plik wyjściowy na posortowane liczby
    std::ofstream timeFile("stats_cpp.txt", std::ios::app); // Plik na czas wykonania (tryb dopisania)

    // Sprawdzenie, czy plik wejściowy został poprawnie otwarty
    if (!inputFile) {
        std::cerr << "Nie można otworzyć pliku wejściowego!" << std::endl;
        return 1;
    }

    std::vector<double> numbers; // Wektor do przechowywania liczb
    double number;

    // Wczytywanie liczb z pliku wejściowego
    while (inputFile >> number) {
        numbers.push_back(number);
    }

    // Zamknięcie pliku wejściowego
    inputFile.close();

    // Sortowanie liczb za pomocą std::sort
    std::sort(numbers.begin(), numbers.end());

    // Zapis posortowanych liczb do pliku wyjściowego
    if (outputFile) {
        for (const auto& num : numbers) {
            outputFile << num << std::endl;
        }
        outputFile.close();
        std::cout << "Posortowane liczby zapisano w pliku sorted_cpp.txt" << std::endl;
    } else {
        std::cerr << "Nie można otworzyć pliku wyjściowego!" << std::endl;
        return 1;
    }

    // Zakończenie mierzenia czasu
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Dopisanie czasu wykonania do pliku (w milisekundach)
    if (timeFile) {
        timeFile << elapsed_ms.count() << std::endl; // Dopisuje tylko liczbę w ms
        timeFile.close();
        std::cout << "Czas wykonania zapisano w pliku execution_time.txt" << std::endl;
    } else {
        std::cerr << "Nie można otworzyć pliku na czas wykonania!" << std::endl;
        return 1;
    }

    return 0;
}
