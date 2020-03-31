#include <iostream>
#include <vector>
//Find n the fibonacci number
//fib = {1, 1, 2, 3, 5, 8, 13, 21, ...}

// 1. binary recursion
// O(2^n), call repeatedly same instances of the function. Precisely O(1.6^n), golden ratio = 1.618...
// not useful
int fib1(int n)
{
    if (n < 2)
    {
        return n;
    }
    return fib1(n - 1) + fib1(n - 2);
}

// 2.1 tabulation 制表的方式: O(n), linear recursion。这是 Bottle-Up 的方式
int fib21(int n)
{
    std::vector<int> tab(n+1);
    tab[0] = 0;
    tab[1] = 1;
    for (int i = 2; i <= n; ++i)
        tab[i] = tab[i-1] + tab[i-2];
    return tab[n];
}
// 2.2 memoization, 用数组记录 n > 1的项， 同样是O(n)。这是 Top-Down 的方式
int fib22(int n, int mem[])
{
    if (n <= 1)
        mem[n] = n;
    else
        mem[n] = fib22(n - 1, mem) + fib22(n - 2, mem);
    return mem[n];
}
// 2.3 Dynamic programming without using array. Interation method: O(n) time and space
int fib23(int n)
{
    int prev = 1;
    int ans = 0;
    while (n > 0)
    {
        ans += prev;
        prev = ans - prev;
        n--;
    }
    return ans;
}

int main()
{
    int const input = 8; // 1 1 2 3 5 8 13 21 34 55 89
    int output;
    int prev;
    int mem[input + 1];
    for (int i = 0; i < input + 1; ++i)
    {
        mem[i] = 0;
    }
    // output = fib22(input, mem);
    output = fib21(input);
    // output = fib31(7);
    std::cout << "The " << input << "th number of Fibonacci is " << output << std::endl;
    // std::cout << "The prev is " << prev << std::endl;
    return 0;
}