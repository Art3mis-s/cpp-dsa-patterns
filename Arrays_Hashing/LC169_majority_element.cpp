/*
LeetCode 169 - Majority Element
Pattern: Voting / Cancellation (Boyer-Moore Voting Algorithm)

Idea:
Maintain a candidate and a count.

- If count becomes 0, choose the current number as the new candidate.
- If the current number matches the candidate, increase count.
- Otherwise, decrease count.

Because the majority element appears more than n/2 times,
it cannot be completely canceled out by the other elements.

Time Complexity: O(n)
- We iterate through the array once.

Space Complexity: O(1)
- Only two extra variables are used.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        int size = nums.size();

        for (int i = 0; i < size; i++)
        {
            if (count == 0)
            {
                candidate = nums[i];
                count += 1;
            }
            else if (nums[i] == candidate)
            {
                count += 1;
            }
            else
            {
                count -= 1;
            }
        }

        return candidate;
    }
};
