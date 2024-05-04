#include <iostream>
#include <random>
#include <locale.h>
#include <thread>
#include <chrono>
int main() {
    setlocale(LC_ALL, "Russian");
    /*
    Очистить консоль:
    system("cls"); // Для Windows
    system("clear"); // Для Linux/MacOS
    */
    std::cout << "Это будет игра в 'стаканчики'. " << "\n" << "Ваша задача - угадать, в каком стаканчике спрятан шарик. " << "\n"
        << "Сначала надо выбрать сколько стаканчиков будет. 2, 3 или 5?" << "\n" << "введите количество стаканчиков: ";
    int stakany;
    std::cin >> stakany;
    if (!std::cin.fail()) {
        std::cout << "Отлично. Теперь необходимо выбрать сложность от 1 до 3 (где 3 - самая сложная)" << "\n";
    }
    else {
        std::cout << "Ошибка ввода! Вы точно ввели правильное значение?";
    }
    std::cout << "Выберите сложность: ";
    int dif;
    std::cin >> dif; 
    if (!std::cin.fail()) {
        std::cout << "Отлично. Игра заключается в том, чтобы угадать, в каком стаканчике остался шарик на конец игры.";
        std::cout << "Сначала выведется в каком стаканчике изначально находится шарик. Потом будут выводится надписи куда девается шарик.";
        std::cout << "Ваша задача - угадать, в каком стаканчике остался шарик. С практикой легче понять игру. Вы готовы?";
        std::cout << "Для начала игры введите любую ЦИФРУ" << "\n";
    }else {
        std::cout << "Ошибка ввода! Вы точно ввели правильное значение?";
    }
    int startt; 
    std::cin >> startt;
    int n1 = 1;
    int n2 = 3;
    bool f1 = false;
    bool f2 = false;
    int res = (stakany / 2) + 1;
    if (!std::cin.fail()) {
        std::cout << "Изначально шарик в стакане № " << (stakany/2)+1 << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "А теперь он движется: " << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        system("cls"); 
        if (dif == 1) {
            for (int i = 0; i < 6; i++) {
                if (res == stakany) {
                    n2--;
                    f2 = true;
                }
                else if (res == 1) {
                    n1++;
                    f1 = true;
                }
                else if (f1 == true || f2 == true) {
                    if (f2 == true) {
                        n2++; 
                        f2 = false;
                    }
                    else {
                        n1--;
                        f1 = false;
                    }
                }
                std::random_device a;
                std::mt19937 gen(a());
                std::uniform_int_distribution<int> aboba(n1, n2);
                int act = aboba(gen);
                switch (act) {
                    case 1:
                        std::cout << "Влево.";
                        res--;
                        std::this_thread::sleep_for(std::chrono::milliseconds(1300));
                        system("cls"); 
                        break;
                    case 3:
                        std::cout << "Вправо.";
                        res++;
                        std::this_thread::sleep_for(std::chrono::milliseconds(1300));
                        system("cls"); 
                        break;
                    case 2:
                        std::cout << "На месте";
                        std::this_thread::sleep_for(std::chrono::milliseconds(1300));
                        system("cls");
                        break;
                }
            }
        }
        else if (dif == 2) {
            for (int i = 0; i < 11; i++) {
                if (res == stakany) {
                    n2--;
                    f2 = true;
                }
                else if (res == 1) {
                    n1++;
                    f1 = true;
                }
                else if (f1 == true || f2 == true) {
                    if (f2 == true) {
                        n2++;
                        f2 = false;
                    }
                    else {
                        n1--;
                        f1 = false;
                    }
                }
                std::random_device a;
                std::mt19937 gen(a());
                std::uniform_int_distribution<int> aboba(n1, n2);
                int act = aboba(gen);
                switch (act) {
                case 1:
                    std::cout << "Влево.";
                    res--;
                    std::this_thread::sleep_for(std::chrono::milliseconds(800));
                    system("cls");
                    break;
                case 3:
                    std::cout << "Вправо.";
                    res++;
                    std::this_thread::sleep_for(std::chrono::milliseconds(800));
                    system("cls");
                    break;
                case 2:
                    std::cout << "На месте";
                    std::this_thread::sleep_for(std::chrono::milliseconds(800));
                    system("cls");
                    break;
                }
            }
        }
        else if (dif == 3) {
            n1 = 1;
            n2 = 6;
            for (int i = 0; i < 15; i++) {
                if (res == stakany) {
                    n2--;
                    f2 = true;
                }
                else if (res == 1) {
                    n1++;
                    f1 = true;
                }
                else if (f1 == true || f2 == true) {
                    if (f2 == true) {
                        n2++;
                        f2 = false;
                    }
                    else {
                        n1--;
                        f1 = false;
                    }
                }
                std::random_device a;
                std::mt19937 gen(a());
                std::uniform_int_distribution<int> aboba(n1, n2);
                int act = aboba(gen);
                switch (act) {
                case 1:
                    std::cout << "Влево.";
                    res--;
                    std::this_thread::sleep_for(std::chrono::milliseconds(550));
                    system("cls");
                    break;
                case 6:
                    std::cout << "Вправо.";
                    res++;
                    std::this_thread::sleep_for(std::chrono::milliseconds(550));
                    system("cls");
                    break;
                case 2:
                    std::cout << "На месте";
                    std::this_thread::sleep_for(std::chrono::milliseconds(550));
                    system("cls");
                    break;
                case 3:
                    std::cout << "хлоп!";
                    std::this_thread::sleep_for(std::chrono::milliseconds(550));
                    system("cls");
                    break;
                case 4:
                    std::cout << "Влево. Нет, вправо!";
                    res++;
                    std::this_thread::sleep_for(std::chrono::milliseconds(550));
                    system("cls");
                    break;
                case 5:
                    std::cout << "Вправо. Нет, влево!";
                    res--;
                    std::this_thread::sleep_for(std::chrono::milliseconds(550));
                    system("cls");
                    break;
                }

            }
        }
        std::cout << "В каком стаканчике шарик?" << "\n";
        int r;
        std::cin >> r;
        if (r == res) {
            std::cout << "Вы угадали! Отличная работа!" << "\n";
        }
        else {
            std::cout << "К сожалению, вы не угадали. Попробуйте еще раз - обязательно получится!" << "\n";
        }
    }
    return 0;
}
