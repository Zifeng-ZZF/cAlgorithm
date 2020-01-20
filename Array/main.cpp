#include "sumAlgo.h"
#include <iostream>

int main()
{
    std::vector<int> input{ 1, 3, 4 ,8, 5, -1, 0, -7};
    std::vector<int> output;
    std::vector<std::vector<int>> threeSumOutput;
    int target = 0;

    output = twoSum(input, input.size(), target);
    threeSumOutput = threeSum(input, input.size());

    // for(int i = 0; i < output.size(); i++)
    // {
    //     std::cout << output[i] << std::endl;
    // }

    for (int i = 0; i < threeSumOutput.size(); i++)
    {
        for (int j = 0; j < threeSumOutput[0].size(); j++)
        {
            std::cout << threeSumOutput[i][j] << " ";
        }
        std::cout << "\n";
    }
}