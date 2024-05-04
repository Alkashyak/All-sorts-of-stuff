#include <iostream>
#include <random>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "Russian");
    std::random_device a;  
    std::mt19937 gen(a()); 
    int n1;
    int n2;
    std::cout << "Введите от какого числа загадываем: " << "\n";
    std::cin >> n1;
    std::cout << "Введите до какого числа загадываем: " << "\n";
    std::cin >> n2; 
    int n3;
    int c = 0;
    std::uniform_int_distribution<int> aboba(n1, n2);
    int res = aboba(gen);
    std::cout << "Ну, пробуйте угадать. Удачи)" << "\n";
    std::cout << "Введите любое не-число если хотите досрочно прекратить. Уже можно пробовать угадать. " << "\n";
    while (true) {
        std::cin >> n3;
        if (std::cin.fail()) {
            std::cout << "сессия прекращена досрочно";
            break;
        }
        if (n3 != res) {
            if (n3 > n2 || n3 < n1) {
                std::cout << "Да ладно, это число даже не в диапазоне искомых." << "\n";
            }
            else {
                std::cout << "Мимо. Может еще разок?" << "\n";
            }
            c++;
        }
        else {
            std::cout << "Поздравляю! Вы попали. Количество попыток: " << c << "\n";
            break;
        }
    }
    return 0;
}

