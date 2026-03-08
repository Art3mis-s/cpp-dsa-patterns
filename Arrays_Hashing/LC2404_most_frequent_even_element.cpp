/*
LeetCode 2404 - Most Frequent Even Element
Pattern: Arrays & Hashing (Frequency Counting)

Idea:
Use an unordered_map to count the frequency of each even number
in the array.

Steps:
1. Iterate through nums and count frequencies of even numbers only.
2. If no even numbers exist, return -1.
3. Iterate through the frequency map and find the element with:
   - the highest frequency
   - if there is a tie, choose the smaller value.

Time Complexity: O(n)
- We iterate through the array once and through the map once.

Space Complexity: O(n)
- In the worst case, the map may store many distinct even numbers.
*/

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                freq[nums[i]]++;
            }
        }

        if (freq.empty())
        {
            return -1;
        }

        int bestVal = -1;
        int bestCount = 0;

        for (auto &p : freq)
        {
            int val = p.first;
            int count = p.second;

            if (count > bestCount)
            {
                bestCount = count;
                bestVal = val;
            }
            else if (count == bestCount && val < bestVal)
            {
                bestVal = val;
            }
        }

        return bestVal;
    }
};