#include <iostream> 
#include <cmath> 
int main()
{
    int V1, V2, M1, M2;
    std::cin >> V1 >> V2 >> M1 >> M2;
    if (V1 == M1) {
        if (V2 >= M2) {
            std::cout << V2 * 2 + 1;
        }
        else {
            std::cout << M2 * 2 + 1;
        }
    }
    else if ((((V1 + V2) >= (M1 + M2)) && ((V1 - V2) <= (M1 - M2))) || (((M1 + M2) >= (V1 + V2)) && ((M1 - M2) <= (V1 - V2)))) {
        if (((V1 + V2) >= (M1 + M2)) && ((V1 - V2) <= (M1 - M2))) {
            std::cout << V2 * 2 + 1;
        }
        else {
            std::cout << M2 * 2 + 1;
        }
    }
    else {
        if (V1 > M1) {
            if ((V1 - V2) <= (M1 + M2)) {
                if (M1 + M2 != V1 - V2) {
                    if (M1 < 0) {
                        std::cout << V2 + M2 + std::abs(V1 - M1) + 1;
                    }
                    else {
                        if (((V1 + V2) >= M1) || ((M1 - M2) <= V1)) {
                            std::cout << V2 + M2 + std::abs(V1 - M1) + 1;
                        }
                        else {
                            std::cout << V2 + M2 + std::abs(V1 - M1) + 2 - (std::abs(std::min(M1 + M2, V1) - std::max(M1, V1 - M2)));
                        }
                    }
                }
                else {
                    std::cout << V2 * 2 + M2 * 2 + 1;
                }
            }
            else {
                std::cout << V2 * 2 + M2 * 2 + 2;
            }
        }
        else {
            if ((M1 - M2) <= (V1 + V2)) {
                if (V1 + V2 != M1 - M2) {
                    if (V1 < 0) {
                        std::cout << M2 + V2 + std::abs(M1 - V1) + 1;
                    }
                    else {
                        if (((V1 + V2) >= M1) || ((M1 - M2) <= V1)) {
                            std::cout << M2 + V2 + std::abs(M1 - V1) + 1;
                        }
                        else {
                            std::cout << M2 + V2 + std::abs(M1 - V1) + 2 - (std::abs(std::min(V1 + V2, M1) - std::max(V1, std::abs(M1 - V2))));
                        }
                    }
                }
                else {
                    std::cout << M2 * 2 + V2 * 2 + 1;
                }
            }
            else {
                std::cout << M2 * 2 + V2 * 2 + 2;
            }
        }
    }

    return 0;
} // если это кто смотрит и думает, что же я за дурак - я поставил себе цель это сделать без циклов и сделал это. Попа болит(
