/*
LeetCode 242 - Valid Anagram
Pattern: Arrays & Hashing

Idea:
Use a frequency array of size 26.
Increment counts for characters in string s
and decrement counts for characters in string t.
If all counts end up zero, the strings are anagrams.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length() != t.length())
        {
            return false;
        }

        int count[26] = {0};

        for (int i = 0; i < s.length(); i++)
        {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};