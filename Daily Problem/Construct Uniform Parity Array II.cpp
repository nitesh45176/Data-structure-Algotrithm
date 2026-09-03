Uniform Array II
Problem

Given an array nums1, for every index i, we can choose either:

nums1[i]
nums1[i] - nums1[j] where j != i and the result is positive.

We need to determine whether it is possible to construct an array where all elements have the same parity (all even or all odd).

Intuition

The key observation is the smallest element.

Why is the smallest element important?

The smallest element cannot subtract any other element because every other element is greater than or equal to it.

For example:

[2, 5, 8]

2 - 5 < 0
2 - 8 < 0

So 2 is forced to remain 2.

Therefore, the parity of the smallest element determines the parity that the entire final array must have.

Case 1: Minimum is Odd

Suppose:

[1, 4, 6, 9]

The minimum is 1, which is odd.

We can make every even number odd by subtracting 1:

4 - 1 = 3
6 - 1 = 5

Odd numbers can simply remain unchanged.

So:

Minimum is odd → Answer is always TRUE
Case 2: Minimum is Even

Suppose:

[2, 4, 6, 8]

The minimum is even, so the final array must be even.

All numbers are already even, so the answer is:

TRUE

But consider:

[2, 5, 8]

The minimum 2 is even, so the final array must be even.

But 5 cannot become even:

5
5 - 2 = 3

Both are odd.

Therefore, it is impossible.

Minimum is even + any odd number exists → FALSE
Algorithm
Find the minimum element.
If the minimum is odd, return true.
Otherwise, the minimum is even.
Check whether every element is even.
If any odd element exists, return false.
Otherwise return true.
Code
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min = *min_element(nums1.begin(), nums1.end());

        // If minimum is odd, we can make every element odd.
        if(min % 2)
            return true;

        // Minimum is even, so every element must be even.
        for(auto &num : nums1) {
            if(num % 2)
                return false;
        }

        return true;
    }
};
Example
Example 1
nums1 = [1, 4, 6, 9]

Minimum:

1 → odd

Therefore answer:

true

Possible result:

[1, 3, 5, 9]

All elements are odd.

Example 2
nums1 = [2, 4, 6, 8]

Minimum:

2 → even

All elements are even.

Therefore:

true
Example 3
nums1 = [2, 5, 8]

Minimum:

2 → even

But 5 is odd.

Therefore:

false
Key Observation

The entire problem can be reduced to this:

Minimum is odd
       ↓
Everyone can become odd
       ↓
TRUE
Minimum is even
       ↓
Everyone must be even
       ↓
If any odd exists → FALSE
Otherwise → TRUE
One-line takeaway

The smallest element cannot be changed, so its parity determines the required final parity.

Complexity
Time: O(n)
Space: O(1)

The min_element() takes O(n) and the second loop takes O(n), so overall complexity remains O(n).
