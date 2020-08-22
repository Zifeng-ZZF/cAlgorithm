#include <iostream>
//#include <iterator>
using namespace std;

/* self-defined Iterator class */
class Iterator {
    struct Data;
    Data *data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    int next();
    bool hasNext();
};

/* solution */
class PeekIterator : public Iterator {
    int peekVal;
    bool hNext; 
public:
    PeekIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        hNext = Iterator::hasNext();
        peekVal = Iterator::next();
    }

    int peek() {
        return peekVal;
    }

    int next() {
        int ans = peekVal;
        hNext = Iterator::hasNext();
        if (hNext)
            peekVal = Iterator::next();
        return ans;
    }

    bool hasNext() {
        return hNext;
    }
};