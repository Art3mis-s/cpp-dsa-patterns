/*
LeetCode 88 - Merge Sorted Array
Pattern: Two Pointers (from the end)

Idea:
We are given two sorted arrays:
- nums1 has extra space at the end to hold nums2

Instead of merging from the front (which would overwrite values),
we merge from the back.

Steps:
1. Use three pointers:
   - m - 1 → last valid element in nums1
   - n - 1 → last element in nums2
   - last → last position in nums1 (m + n - 1)

2. Compare elements from the end of both arrays.
3. Place the larger element at the "last" position.
4. Move pointers accordingly.
5. If nums2 still has elements left, copy them.

Example:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6], n = 3

Result:
[1,2,2,3,5,6]

Time Complexity: O(m + n)
- Each element is processed once.

Space Complexity: O(1)
- In-place merge, no extra space used.
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // Pointer to the last position in nums1
        int last = m + n - 1;

        // Merge from the end of both arrays
        while (m > 0 && n > 0)
        {
            // Compare the last elements of nums1 and nums2
            if (nums1[m - 1] > nums2[n - 1])
            {
                nums1[last] = nums1[m - 1];
                m--;
            }
            else
            {
                nums1[last] = nums2[n - 1];
                n--;
            }

            last--;
        }

        // If nums2 still has elements, copy them
        // (No need to copy nums1 leftovers — they are already in place)
        while (n > 0)
        {
            nums1[last] = nums2[n - 1];
            n--;
            last--;
        }
    }
};