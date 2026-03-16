/*
LeetCode 268 - Missing Number
Pattern: Brute Force Search

Idea:
The array contains n distinct numbers taken from the range [0, n].
Exactly one number is missing.

Approach:
1. Iterate through every number from 0 to n. (outer loop) *its the number we are looking for.*
2. For each number, scan the array to check if it exists.
3. If a number is not found in the array, that number is the missing value.

Example:
nums = [3,0,1]

Check:
0 -> found
1 -> found
2 -> not found → return 2

Time Complexity: O(n^2)
- For every number from 0 to n we scan the array.

Space Complexity: O(1)
- No extra data structures are used.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        // Try every number from 0 to n
        for(int i = 0; i <= nums.size(); i++)
        {
            bool found = false;

            // Check if the number exists in the array
            for (int j = 0; j < nums.size(); j++)
            {
                if(nums[j] == i)
                {
                    found = true;
                    break;
                }
            }

            // If not found, this is the missing number
            if (found == false)
            {
                return i;
            }
        }

        return -1;
    }
};
