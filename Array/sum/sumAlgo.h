#ifndef SUM_ALGO
#define SUM_ALGO

#include <vector>
#include <iostream>

std::vector<int> twoSum (std::vector<int>& nums, int, int);

std::vector<int> towSumSortingBinary (std::vector<int>&, int, int);

std::vector<int> twoSumSortingWalkingInwards(std::vector<int>&, int, int);

std::vector<std::vector<int>> threeSum (std::vector<int>& nums, int);

int threeSumCloset (std::vector<int>& nums, int, int);

std::vector<std::vector<int>> fourSum (std::vector<int>& nums, int);

void lookUp(int);
void lookUp(const int);

void lookUp(float const &);
void lookUp(float &);

#endif