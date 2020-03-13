#include <iostream>
#include <string>
#include <initializer_list>
#include <vector>

bool isEmpty(const std::string &str)
{
    return str.empty();
}

bool hasCapital(const std::string &str)
{
    for (auto c : str)
    {
        if (isupper(c))
        {
            return true;
        }
    }
    return false;
}

void toLowercase(std::string &str)
{
    for (auto &c : str)
    {
        if (isupper(c))
        {
            c = tolower(c);
        }
    }
}

void printArr(const int *arr, const int *end)
{
    while (arr != end)
    {
        std::cout << *arr << std::endl;
        arr++;
    }
}

void printArr(const int *arr, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

template<class T> void compareTest(const T val, const T *pt)
{
    return val > *pt ? val : *pt;
}

template<class T> void swapPointers(T *&pt1, T *&pt2)
{
    T *temp = pt1;
    pt1 = pt2;
    pt2 = temp;
}

void printError(std::initializer_list<std::string> errMsg)
{
    for (std::string msg : errMsg)
    {
        std::cout << "error message: " << msg << std::endl;
    }
}

int sumCalc(std::initializer_list<int> nums)
{
    int sum = 0;
    for (int num : nums)
    {
        sum += num;
    }
    return sum;
}

std::string &shorterString(std::string &s1, std::string &s2)
{
    return s1.size() > s2.size() ? s2 : s1;
}

void print2(std::vector<int> vec, int index)
{
    if (vec.empty() || index >= vec.size())
    {
        return;
    }
    std::cout << vec[index] << std::endl;
    print2(vec, index + 1);
}

// function that returns a pointer to an array
int (*func(int val))[10]
{

}

// trailing return type
auto func2(int val) -> int(*)[10]
{

}

int (&func3(int val))[10]
{
    // return the reference of an array with 10 elements
}

//use decltype to use known type to define return type
int odd[]{1, 3, 5, 7, 9};
int even[]{0, 2, 4, 6, 8};
decltype(odd) &func4(int val)
{
    return (val % 2) ? odd : even;
}

int main()
{
    // std::cout << hasCapital("David") << std::endl;

    // std::string s = "ZZF";
    // toLowercase(s);
    // std::cout << s << std::endl;

    // int arr[]{1, 2, 3, 4, 5, 6};
    // printArr(arr, arr+6);
    // printArr(arr, sizeof(arr) / sizeof(int));

    int a = 1;
    int b = 2;
    int *pt1 = &a;
    int *pt2 = &b;
    std::cout << "(pt1, pt2) : (" << *pt1 << ", " << *pt2 << ")" << std::endl; 
    swapPointers(pt1, pt2);
    std::cout << "(pt1, pt2) : (" << *pt1 << ", " << *pt2 << ")" << std::endl; 

    int sum = sumCalc({1, 2, 3, 4, 5, 6});
    std::cout << "sum calc: " << sum << std::endl; 

    std::string str1 = "abc";
    std::string str2 = "abcd";
    // shorterString(str1, str2) = "short"; // lvalue reference
    std::string &sr = shorterString(str1, str2);
    sr = "short";
    std::cout << "str1 " << str1 << std::endl;
    std::cout << "str2 " << str2 << std::endl;

    std::vector<int> vec{1, 12, 123, 1234, 12345};
    print2(vec, 0);
}