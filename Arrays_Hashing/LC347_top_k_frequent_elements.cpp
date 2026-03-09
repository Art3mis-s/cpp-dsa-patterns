/*
LeetCode 347 - Top K Frequent Elements
Pattern: Arrays & Hashing (Frequency Map + Sorting)

Idea:
1. Count the frequency of each number using an unordered_map.
2. Store the (number, frequency) pairs in a vector.
3. Sort the vector by frequency in descending order.
4. Take the first k elements from the sorted vector.

Example:
nums = [1,1,1,2,2,3], k = 2

Frequency Map:
1 -> 3
2 -> 2
3 -> 1

After sorting by frequency:
[(1,3), (2,2), (3,1)]

Take first k numbers → [1,2]

Time Complexity: O(n log n)
- Counting frequencies takes O(n)
- Sorting the vector takes O(n log n)

Space Complexity: O(n)
- The map and vector store up to n elements.
*/

class Solution {
public:
    static bool compare(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        vector<pair<int, int>> arr;

        for (const auto& pair : freq)
        {
            arr.push_back(pair);
        }

        sort(arr.begin(), arr.end(), compare);

        vector<int> result;

        for (int i = 0; i < k; i++)
        {
            result.push_back(arr[i].first);
        }

        return result;
    }
};