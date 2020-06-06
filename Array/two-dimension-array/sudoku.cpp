/*
    Validate a soduku
    such that the matrix columns, rows and boxes have unique number
    if not return false
*/
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/* three hash set to record col, row and box, if repeated element exists return false */
/* use row, col to count the index of box : boxIndex = row / 3 * 3 + col / 3; */
bool isValidSudoku_one(vector<vector<char>> board) {
    vector<unordered_set<char>> rows(9); // needs initialization
    vector<unordered_set<char>> cols(9);
    vector<unordered_set<char>> boxes(9);
    int boxIdx;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 0; ++j) {
            if (board[i][j] == '.') {
                continue; //skip '.'
            }
            //rows
            if (rows[i].find(board[i][j]) != rows[i].end()) {
                return false;
            }
            rows[i].insert(board[i][j]);

            //cols
            if (cols[j].find(board[i][j]) != cols[j].end()) {
                return false;
            }
            cols[j].insert(board[i][j]);

            //boxes
            boxIdx = i / 3 * 3 + j / 3;
            if (boxes[boxIdx].find(board[i][j]) != boxes[boxIdx].end()) {
                return false;
            }
            boxes[boxIdx].insert(board[i][j]);
        }
    }
    return true;
}

/* use hash map to count the time */
bool isValidSudoku_two(vector<vector<char>> board) {
    vector<unordered_map<char, int>> rows;
    vector<unordered_map<char, int>> cols;
    vector<unordered_map<char, int>> boxes;
    int bIdx;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                bIdx = i / 3 * 3 + j / 3;
                if (++rows[i][board[i][j]] > 1 || ++cols[j][board[i][j]] > 1 || ++boxes[bIdx][board[i][j]] > 1) {
                    return false;
                }
            }
        }
    }
    return true;
}

/* bit manipulation : faster than last two */
/* make use of 9 bits to record a single row & column & box; set a bit of corresponding position; */
/* use & operator to check if the same bit of the some row/col/box has been set, if so there is repeated number ,return false */
/* if no repeated, use |= operation to set the corresponding bit to 1 */
bool isValidSudoku_three(vector<vector<char>>& board) {
    vector<int> row(9, 0), col(9, 0), block(9, 0);
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.')
                continue;
            int mask = 1 << (board[r][c] - '0');
            if (row[r] & mask || col[c] & mask || block[r / 3 * 3 + c / 3] & mask)
                return false;
            row[r] |= mask;
            col[c] |= mask;
            block[r / 3 * 3 + c / 3] |= mask;
        }
    }
    return true;
}