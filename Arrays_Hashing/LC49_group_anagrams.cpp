/*
LeetCode 49 - Group Anagrams
Pattern: Arrays & Hashing

Idea:
Two strings are anagrams if they contain the same characters with the same
frequencies. If we sort the characters of each string, all anagrams will
produce the same sorted string.

Example:
"eat" -> "aet"
"tea" -> "aet"
"ate" -> "aet"

We use the sorted string as a key in a hash map, and store the original
strings in the value (a vector).

After processing all words, we extract the grouped anagrams from the map.

Time Complexity: O(n * k log k)
- n = number of strings
- k = maximum length of a string
- Sorting each string takes k log k

Space Complexity: O(n * k)
- We store all strings in the hash map.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> groups;

        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());

            groups[temp].push_back(strs[i]);
        }

        vector<vector<string>> result;

        for (const auto& pair : groups)
        {
            result.push_back(pair.second);
        }

        return result;
    }
};