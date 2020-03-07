#include <iostream>
//Find n the fibonacci number
//fib = {1, 1, 2, 3, 5, 8, 13, 21, ...}

// 1. binary recursion
// O(2^n), call repeatedly same instances of the function
// not useful
int fib1(int n)
{
    if (n < 2)
    {
        return n;
    }
    return fib1(n - 1) + fib1(n - 2);
}

// 2.1 tabulation 制表的方式: O(n), linear recursion
int fib2(int n, int& prev)
{
    if (n == 0)
    {
        prev = 1; // 前2项
        return 0; // 前1项
    }
    // 计算前两项
    int prevPrev;
    prev = fib2(n - 1, prevPrev);
    return prevPrev + prev;
}
// 2.2 memoization, 用数组记录 n > 1的项， 同样是O(n)
int fib22(int n, int mem[])
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (!mem[n]) 
        mem[n] = fib22(n - 1, mem) + fib22(n - 2, mem);
    return mem[n];
}

// 3. Dynamic programming. Interation method: O(n) time and space
int fib3(int n)
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

// 3.1 Dynamic programming & memoization
int fib31(int n)
{
    int dp[n];
    dp[0] = 0;
    dp[1] = 1;
    int k = 2;
    while (k <= n)
    {
        dp[k] = dp[k - 1] + dp[k - 2];
        k++;
    }
    return dp[n];
}

int main()
{
    int const input = 7;
    int output;
    int prev;
    // output = fib1(7);
    // output = fib2(input, prev);
    // output = fib3(input);
    int mem[input + 1];
    // output = fib22(input, mem);
    output = fib31(7);
    std::cout << "The " << input << "th number of Fibonacci is " << output << std::endl;
    std::cout << "The prev is " << prev << std::endl;
    return 0;
}