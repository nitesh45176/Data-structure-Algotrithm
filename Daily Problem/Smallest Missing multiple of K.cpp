============================================================
Problem: Missing Multiple
============================================================

Approach:
- Use an unordered_set to store all elements of nums.
- Start with the first positive multiple of k, i.e. k.
- Check whether the current multiple exists in the set.
- If it exists, move to the next multiple by adding k.
- The first multiple that is not present in the set is the answer.

Why unordered_set?
- We repeatedly need to check whether a particular multiple exists in nums.
- unordered_set provides O(1) average-time existence lookup.
- Sorting is not required.
- nums.begin() and nums.end() are iterators used to pass the entire range of nums
  into the unordered_set constructor. They do NOT perform sorting.

Example:
nums = [2, 4, 6, 8]
k = 2

Multiples:
2  -> present
4  -> present
6  -> present
8  -> present
10 -> missing

Answer = 10

Key Pattern:
- If a problem requires repeated existence checks, think about using
  unordered_set for fast lookup.
- Do not automatically use a set just because something is being
  checked continuously.
- The important clue is repeated existence checking.

Alternative Approach:
- Sorting the array and checking the multiples is possible.
- However, sorting takes O(n log n), so it is less efficient than
  the unordered_set approach.
- Therefore, unordered_set is the preferred approach for this problem.

Time Complexity:
- O(n) average
  O(n) to build the unordered_set.
  Each lookup is O(1) average.
  The number of multiples checked is bounded by the input range.

Space Complexity:
- O(n)
  The unordered_set stores the elements of nums.

Code:

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> seen(nums.begin(), nums.end());

        int cur = k;

        while (seen.count(cur)) {
            cur += k;
        }

        return cur;
    }
};
