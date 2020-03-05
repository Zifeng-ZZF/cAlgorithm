#include "sumAlgo.h"
#include <iostream>

void bitMapSort(std::vector<int>&, int);
void bitMapSort2(std::vector<int>&, int);
void bitMapSort3(std::vector<int>&, int);

int main()
{
    std::vector<int> input{ 10, 3, 4 , 2, 5, 6, 0, 7};
    std::vector<int> output;
    std::vector<std::vector<int>> threeSumOutput;
    int threeSumClosetOutput;
    int target = 0;

    // output = twoSum(input, input.size(), target);
    // threeSumOutput = threeSum(input, input.size());
    // threeSumClosetOutput = threeSumCloset(input, input.size(), 20);

    // for(int i = 0; i < output.size(); i++)
    // {
    //     std::cout << output[i] << std::endl;
    // }

    // for (int i = 0; i < threeSumOutput.size(); i++)
    // {
    //     for (int j = 0; j < threeSumOutput[0].size(); j++)
    //     {
    //         std::cout << threeSumOutput[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }

    // std::cout << "closet three sum to 20: " << threeSumClosetOutput << std::endl;

    for (int i = 0; i < input.size(); i++)
    {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
    // bitMapSort(input, 11);
    // bitMapSort2(input, 11);
    bitMapSort2(input, 11);
    for (int i = 0; i < input.size(); i++)
    {
        std::cout << input[i] << " ";
    }
}