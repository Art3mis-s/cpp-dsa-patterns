/*
LeetCode 1 - Two Sum
Pattern: Arrays & Hashing

Idea:
Use two nested loops to check every pair of numbers in the array.
For each pair, check if their sum equals the target value.
If a valid pair is found, return their indices.

This is the brute-force approach. It works but is not optimal.

Time Complexity: O(n^2)
- We compare each element with every other element.

Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }

        return {};
    }
};