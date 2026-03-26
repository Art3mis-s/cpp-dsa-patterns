/*
LeetCode 125 - Valid Palindrome
Pattern: Two Pointers

Idea:
Use two pointers, one starting from the left and one from the right.

Steps:
1. Move both pointers toward each other.
2. Skip characters that are not alphanumeric.
3. Compare characters in a case-insensitive way.
4. If any mismatch is found, return false.
5. If all valid characters match, return true.

Example:
s = "A man, a plan, a canal: Panama"

After ignoring non-alphanumeric and case:
"amanaplanacanalpanama" → palindrome

Time Complexity: O(n)
- Each character is processed at most once.

Space Complexity: O(1)
- No extra data structures are used.
*/

class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            // Skip non-alphanumeric characters from the left
            if (!isalnum(s[left]))
            {
                left++;
            }
            // Skip non-alphanumeric characters from the right
            else if (!isalnum(s[right]))
            {
                right--;
            }
            else 
            {
                // Compare characters ignoring case
                if (tolower(s[left]) != tolower(s[right]))
                {
                    return false;
                }

                // Move both pointers inward
                left++;
                right--;
            }
        }

        return true;
    }
};
