#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    Solution(void);
public:
    static vector<int> _result;

    static vector<int> spiralOrder(vector<vector<int>>& matrix) {
        _result.clear();
        solve(matrix);
        return _result;
    }

    static void solve(vector<vector<int>> matrix) {
        addResult(matrix[0]);
        if(matrix.size() == 1) return;

        matrix.erase(matrix.begin());
        vector<vector<int>> newMatrix = makeNewMatrix(matrix);
        solve(newMatrix);
    }

    static void addResult(vector<int> &vec) {
        for(int i = 0; i < vec.size(); i++) {
            _result.push_back(vec[i]);
        }
    }

    static vector<vector<int>> makeNewMatrix(vector<vector<int>>& oldMatrix) {
        int row = oldMatrix[0].size();
        int col = oldMatrix.size();
        vector<vector<int>> newMatrix(row, vector<int>(col));

        for(int i = 0; i < col; i++) {
            for(int j = 0; j < row; j++) {
                newMatrix[row - 1 - j][i] = oldMatrix[i][j];
            }
        }
        return newMatrix;
    }
};

vector<int> Solution::_result;

int main() {
    cout << "----- example 1 -----" << endl;
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> output1 = Solution::spiralOrder(matrix1);
    cout << "Output = [ ";
    for (size_t i = 0; i < output1.size(); i++) {
        cout << output1[i];
        if(i < output1.size() - 1)
            cout << ", ";
    }
    cout << " ]" << endl;

    cout << endl  << "----- example 2 -----" << endl;
    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    vector<int> output2 = Solution::spiralOrder(matrix2);
    cout << "Output = [ ";
    for (size_t i = 0; i < output2.size(); i++) {
        cout << output2[i];
        if(i < output2.size() - 1)
            cout << ", ";
    }
    cout << " ]" << endl << endl;
    return 0;
}
