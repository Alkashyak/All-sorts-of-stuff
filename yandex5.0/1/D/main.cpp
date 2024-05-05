#include <iostream>
#include <vector>

bool GorizVert(std::vector<std::string>& doska, int row, int col) {
    for (int i = row - 1; i >= 0; --i) {
        if (doska[i][col] != '*') {
            if (doska[i][col] == 'R') {
                return true;
            }
            break;
        }
    }
    for (int i = row + 1; i < 8; ++i) {
        if (doska[i][col] != '*') {
            if (doska[i][col] == 'R') {
                return true;
            }
            break;
        }
    }
    for (int j = col - 1; j >= 0; --j) {
        if (doska[row][j] != '*') {
            if (doska[row][j] == 'R') {
                return true;
            }
            break;
        }
    }
    for (int j = col + 1; j < 8; ++j) {
        if (doska[row][j] != '*') {
            if (doska[row][j] == 'R') {
                return true;
            }
            break;
        }
    }
    return false;
}

bool Diogn(std::vector<std::string>& doska, int row, int col) {
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
        if (doska[i][j] != '*') {
            if (doska[i][j] == 'B') {
                return true;
            }
            break;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < 8; --i, ++j) {
        if (doska[i][j] != '*') {
            if (doska[i][j] == 'B') {
                return true;
            }
            break;
        }
    }
    for (int i = row + 1, j = col - 1; i < 8 && j >= 0; ++i, --j) {
        if (doska[i][j] != '*') {
            if (doska[i][j] == 'B') {
                return true;
            }
            break;
        }
    }
    for (int i = row + 1, j = col + 1; i < 8 && j < 8; ++i, ++j) {
        if (doska[i][j] != '*') {
            if (doska[i][j] == 'B') {
                return true;
            }
            break;
        }
    }
    return false;
}

int TotalPopa(std::vector<std::string>& doska) {
    int neBit = 0;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (doska[i][j] == '*' && !GorizVert(doska, i, j) && !Diogn(doska, i, j)) {
                neBit++;
            }
        }
    }

    return neBit;
}

int main() {
    std::vector<std::string> DoskaDoska(8);

    for (int i = 0; i < 8; ++i) {
        std::getline(std::cin, DoskaDoska[i]);
    }

    int result = TotalPopa(DoskaDoska);

    std::cout << result << std::endl;

    return 0;
}
