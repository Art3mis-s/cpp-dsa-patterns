/*
LeetCode 561 - Array Partition
Pattern: Sorting + Greedy

Idea:
We want to maximize the sum of the minimum value from each pair.

Steps:
1. Sort the array.
2. Pair adjacent elements after sorting.
3. The smaller element in each pair will always be the element at the
   even index (0, 2, 4, ...).
4. Add those elements to the result.

Example:
nums = [1,4,3,2]

After sorting:
[1,2,3,4]

Pairs:
(1,2), (3,4)

Minimum values:
1 + 3 = 4

Time Complexity: O(n log n)
- Sorting dominates the runtime.

Space Complexity: O(1)
- No additional data structures are used (ignoring sorting internals).
*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // Step 1: sort the array
        sort(nums.begin(), nums.end());

        int maxNum = 0;

        // Step 2: add every element at even index
        // because it represents the smaller value in each pair
        for (int i = 0; i < nums.size(); i += 2)
        {
            maxNum += nums[i];
        }

        // Step 3: return the maximum possible sum of pair minimums
        return maxNum;
    }
};