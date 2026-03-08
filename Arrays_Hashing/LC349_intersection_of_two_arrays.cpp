/*
LeetCode 349 - Intersection of Two Arrays
Pattern: Arrays & Hashing

Idea:
Use an unordered_set to store elements from the smaller array.
Then iterate through the second array and check whether each
element exists in the lookup set.

If it does, insert it into a result set to ensure the output
contains only unique elements.

Finally convert the result set into a vector and return it.

Time Complexity: O(n + m)
- n = size of nums1
- m = size of nums2

Space Complexity: O(n)
- We store elements of the first array in a hash set.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size())
        {
            swap(nums1, nums2);
        }

        unordered_set<int> lookupSet;
        unordered_set<int> resultSet;

        for(int i = 0; i < nums1.size(); i++)
        {
            lookupSet.insert(nums1[i]);
        }

        for (int j = 0; j < nums2.size(); j++)
        {
            if(lookupSet.count(nums2[j]) > 0)
            {
                resultSet.insert(nums2[j]);
            }
        }

        vector<int> answer(resultSet.begin(), resultSet.end());
        return answer;
    }
};