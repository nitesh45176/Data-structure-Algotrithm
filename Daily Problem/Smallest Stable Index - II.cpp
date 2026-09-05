Smallest Stable Index - II (Its optimised version for Ist part)

Problem

Given an array nums and an integer k, an index i is called stable if its instability score is less than or equal to k.

The instability score of index i is:

maximum element in nums[0 ... i]
-
minimum element in nums[i ... n-1]

We need to return the smallest stable index.

If no stable index exists, return -1.

Example
nums = [5, 0, 1, 4]
k = 3

For each index:

i = 0
left  = [5]       → max = 5
right = [5,0,1,4] → min = 0

score = 5 - 0 = 5

Not stable because:

5 > 3
i = 1
left  = [5,0]     → max = 5
right = [0,1,4]   → min = 0

score = 5 - 0 = 5

Not stable.

i = 2
left  = [5,0,1]   → max = 5
right = [1,4]     → min = 1

score = 5 - 1 = 4

Not stable.

i = 3
left  = [5,0,1,4] → max = 5
right = [4]       → min = 4

score = 5 - 4 = 1

1 <= 3, so index 3 is stable.

Answer:

3
Approach

The straightforward approach would calculate:

max(nums.begin(), nums.begin() + i + 1)
min(nums.begin() + i, nums.end())

for every index.

But each max_element() and min_element() takes O(n), resulting in:

O(n²)

We can optimize this to O(n) by precomputing suffix minimums.

Step 1: Build minFromIdx
vector<int> minFromIdx(n);

minFromIdx[i] stores:

The minimum element from index i to the end of the array.

For:

nums = [5, 0, 1, 4]

We calculate from right to left.

Start:
minEl = INT_MAX

At index 3:

minEl = min(INT_MAX, 4) = 4
minFromIdx[3] = 4

At index 2:

minEl = min(4, 1) = 1
minFromIdx[2] = 1

At index 1:

minEl = min(1, 0) = 0
minFromIdx[1] = 0

At index 0:

minEl = min(0, 5) = 0
minFromIdx[0] = 0

So:

nums:         [5, 0, 1, 4]
minFromIdx:   [0, 0, 1, 4]

Now we can get the right-side minimum in O(1).

Step 2: Calculate prefix maximum

Now traverse from left to right:

maxEl = max(maxEl, nums[i]);

maxEl represents:

Maximum element from nums[0] to nums[i].

For:

nums = [5, 0, 1, 4]

we get:

i = 0 → maxEl = 5
i = 1 → maxEl = 5
i = 2 → maxEl = 5
i = 3 → maxEl = 5
Step 3: Calculate instability score

At every index:

score = maxEl - minFromIdx[i];

So:

i = 0 → 5 - 0 = 5
i = 1 → 5 - 0 = 5
i = 2 → 5 - 1 = 4
i = 3 → 5 - 4 = 1

The first score satisfying:

score <= k

is our answer.

Therefore:

if((maxEl - minEl) <= k)
    return i;
Code
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxEl = 0;

        // minFromIdx[i] = minimum element from i to n-1
        vector<int> minFromIdx(n);

        int minEl = INT_MAX;

        // Build suffix minimum array
        for(int i = n - 1; i >= 0; i--) {
            minEl = min(minEl, nums[i]);
            minFromIdx[i] = minEl;
        }

        // Find the first stable index
        for(int i = 0; i < n; i++) {
            maxEl = max(maxEl, nums[i]);

            minEl = minFromIdx[i];

            if((maxEl - minEl) <= k)
                return i;
        }

        return -1;
    }
};
Key Idea

The main trick is to avoid recalculating the minimum for every index.

We precompute:

minFromIdx[i]

which gives us the minimum from i to the end in O(1).

At the same time, while traversing left to right, we maintain:

maxEl

which gives us the maximum from 0 to i.

Therefore:

Instability Score
        =
max(0 ... i)
        -
min(i ... n-1)
Why Two Passes?
Right → Left
     ↓
Suffix Minimum
     ↓
minFromIdx[]

Left → Right
     ↓
Prefix Maximum
     ↓
maxEl
     ↓
Check score
Complexity
Time

First loop:

O(n)

Second loop:

O(n)

Total:

O(n)
Space

We store the suffix minimum array:

vector<int> minFromIdx(n);

Therefore:

Space = O(n)
Key Takeaway

When you repeatedly need the minimum of every suffix, precompute suffix minimums. When you repeatedly need the maximum of every prefix, maintain a running maximum.

This changes the original O(n²) approach into an O(n) solution.
