/*
LeetCode 217 - Contains Duplicate
Pattern: Arrays & Hashing

Idea:
Use an unordered_set to track numbers we have already seen.
As we iterate through the array, we check if the current number
already exists in the set.

If it does, a duplicate exists → return true.
Otherwise insert the number into the set and continue.

Time Complexity: O(n)
- We iterate through the array once.

Space Complexity: O(n)
- In the worst case, all elements are unique and stored in the set.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        unordered_set<int> seen;

        for (int i = 0; i < size; i++)
        {
            if (seen.find(nums[i]) != seen.end())
            {
                return true;
            }

            seen.insert(nums[i]);
        }

        return false;
    }
};