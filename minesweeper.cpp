#include <iostream>
#include <string>
#include <vector>

int main();
std::vector<std::vector<int>> solution(std::vector<std::vector<bool>> matrix);
void printBoard(int x, int y, int mine, std::vector<std::vector<char>> board);
void positionMine(int x, int y, int mine, std::vector<std::vector<char>> board);

int main() {
    std::vector<std::vector<bool>> input{};
    std::vector<std::vector<char>> display{};
    std::vector<char> displayRow{};
    int x, y, mine{};

    std::cout << "Welcome to minesweeper game! \nEnter the size of matrix: \nNumber of columns (x): ";
    std::cin >> x;
    std::cout << "Number of rows (y): ";
    std::cin >> y;

    for (int j{}; j < y; ++j) {
        for (int i{}; i < x; ++i) {
            displayRow.push_back('*');
        }
        display.push_back(displayRow);
    }

    printBoard(x, y, mine, display);
    
    std::cout << "Enter the number of mines to hide: ";
    std::cin >> mine;

    positionMine(x, y, mine, display);

    /*
    std::vector<std::vector<int>> soln{solution(input)};
    for (int i{}; i < soln.size(); ++i) {
        for (int j{}; i < soln[0].size(); ++j) {
            std::cout << soln[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i{}; i < input.size(); ++i) {
        for (int j{}; i < input[0].size(); ++j) {
            std::cout << input[i][j] << " ";
        }
        std::cout << std::endl;
    }
    */
    return 0;
}

void printBoard(int x, int y, int mine, std::vector<std::vector<char>> display) {
    
    for (int row{}; row < y + 1; ++row) {
        for (int col{}; col < x; ++col) {
            if (row == 0) std::cout << char('a' + col) << "\t";
            else std::cout << display[row - 1][col] << "\t";
        }
        if (row > 0) std::cout << (y + 1 - row) << "\t";
        std::cout << std::endl;
    }
}

void positionMine(int sizex, int sizey, int mine, std::vector<std::vector<char>> board) {
    std::vector<char> x;
    std::vector<int> y;
    for (int i{mine - 1}; i >= 0; --i) {
        char inputx;
        int inputy;

        // while loops to ensure the inputs are valid characters
        while (true) {
            std::cout << "Enter the x position of mine # " << mine - i;
            std::cin >> inputx;
            if (inputx >= 'a' && inputx <= ('a' + sizex)) break;
            std::cout << "Please enter a valid character.\n";
        }
        x.push_back(inputx);

        while (true) {
            std::cout << "Enter the y position of mine # " << mine - i;
            std::cin >> inputy;
            if (inputy >= 1 && inputy <= sizey) break;
            std::cout << "Please enter a valid character.\n"; 
        }
        y.push_back(inputy);
    }
    
}
std::vector<std::vector<int>> solution(std::vector<std::vector<bool>> matrix) {
    std::vector<std::vector<int>> s1;
    std::vector<int> s2;
    
    for (int i{0}; i < matrix.size(); ++i) {
        for (int j{0}; j < matrix[0].size(); ++j) {
            int cnt{};
            bool iplus{i + 1 < matrix.size()}, jplus{j + 1 < matrix[0].size()};
            bool imin{i - 1 >= 0}, jmin{j - 1 >= 0};
            
            if (jmin) {
                if (matrix[i][j-1] == true) ++cnt;
                if (iplus) if (matrix[i + 1][j - 1] == true) ++cnt;
                
                if (imin) if (matrix[i - 1][j -1] == true) ++cnt;

            }
            
            if (jplus) {
                if (matrix[i][j+1] == true) ++cnt;
                if (iplus) if (matrix[i + 1][j + 1] == true) ++cnt;
                
                if (imin) if (matrix[i - 1][j + 1] == true) ++cnt;
            }
            
            if (imin) if (matrix[i-1][j] == true) ++cnt;
            if (iplus) if (matrix[i+1][j] == true) ++cnt;
            s2.push_back(cnt);
        }
        s1.push_back(s2);
        s2.clear();
    }
    return s1;
}
