#include "sumAlgo.h"
#include <iostream>

int main()
{
    std::vector<int> input{ 1, 3, 4 ,8, 5};
    std::vector<int> output;
    int target = 0;
    output = twoSum(input, input.size(), target);

    for(int i = 0; i < output.size(); i++)
    {
        std::cout << output[i] << std::endl;
    }
}