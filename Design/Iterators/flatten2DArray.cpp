#include <iostream>
#include <vector>
//#include <iterator>
using namespace std;

class Vector2D {
    vector<vector<int>> * v;
    int row;
    int col;
    int len;
 public:
    Vector2D(vector<vector<int>> & src) : row(0), col(0), len(src.size()) {
        v = &src;
    }

    void prepareNext() {
        while (row < len && col == (*v)[row].size()){
            ++row;
            col = 0;
        }
    }

    bool hasNext() {
        prepareNext();
        if (row == len) 
            return false;
        return true;
    }

    int next() {
        if (!hasNext()) 
            throw exception();
        return (*v)[row][col++]; //incrementing the 'col' here
    }
};