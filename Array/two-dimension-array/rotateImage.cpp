#include <vector>
using namespace std;

/* Rotate the given two-dimensional array 90 degree clock-wise */

/* make use of an extra 2D matrix: take first col as new first row, and so on */
void rotateImg_one(vector<vector<int>>& matrix) {
    vector<vector<int>> original = matrix;
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = original[n - 1 - j][i];
        }
    }
}

/* no extra space, flip the matrix upside down first, then flip it diagonally */
/* faster */
void rotateImg_two(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n; ++j) {
            swap(matrix[i][j], matrix[n - 1 - i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > j) { //important: in case we swap the same two elements twice
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
}