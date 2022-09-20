#include <iostream>
#include <string>
#include <vector>

int main();
int main() {
    
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
