3Sum — Brute Force to Optimized Approach
Problem

Given an integer array nums, find all unique triplets [a, b, c] such that:

a + b + c = 0

The solution should not contain duplicate triplets.

Example
Input:
[-1, 0, 1, 2, -1, -4]

Output:
[[-1, -1, 2],
 [-1, 0, 1]]
Approach 1: Brute Force — 3 For Loops + Set
Intuition

The most direct way is to try every possible combination of 3 elements.

We use three loops:

i → first element
j → second element
k → third element

For every combination:

nums[i] + nums[j] + nums[k]

If the sum is 0, we found a valid triplet.

Problem: Duplicate Triplets

Consider:

[-1, 0, 1, 2, -1, -4]

We may find:

[-1, 0, 1]
[0, -1, 1]
[1, -1, 0]

These are actually the same triplet, just in different orders.

So we:

Put the three elements into a temporary vector.
Sort the temporary vector.
Insert it into a set.

Since a set only stores unique values, duplicates are automatically removed.

Brute Force Code
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        set<vector<int>> st;

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                for(int k = j + 1; k < n; k++) {

                    if(nums[i] + nums[j] + nums[k] == 0) {

                        vector<int> temp = {
                            nums[i],
                            nums[j],
                            nums[k]
                        };

                        sort(temp.begin(), temp.end());

                        st.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> result(
            st.begin(),
            st.end()
        );

        return result;
    }
};
Why j = i + 1 and k = j + 1?

We want three different indices.

i < j < k

Therefore:

j = i + 1;
k = j + 1;

This prevents:

nums[i] with nums[i]
nums[j] with nums[j]

and avoids checking the same combination repeatedly.

Brute Force Dry Run

For:

[-1, 0, 1, 2, -1, -4]

Suppose:

i = 0 → -1
j = 1 → 0
k = 2 → 1

Then:

-1 + 0 + 1 = 0

So:

temp = [-1, 0, 1]

After sorting:

[-1, 0, 1]

Insert into:

set

Later, if another ordering produces:

[0, -1, 1]

sorting gives:

[-1, 0, 1]

The set already contains it, so it is ignored.

Complexity

Three nested loops:

O(n³)

For every valid triplet, we sort 3 elements:

O(3 log 3) ≈ O(1)

So the overall time complexity is:

O(n³)

Extra space:

O(number of unique triplets)

because of the set.

Approach 2: Optimized — Sorting + Two Pointers

The brute-force approach checks every possible combination.

Can we reduce:

3 loops

to:

1 loop + 2 pointers

Yes.

The key observation is:

3Sum can be converted into 2Sum by fixing one element.

Step 1: Sort the Array
sort(nums.begin(), nums.end());

Example:

[-1, 0, 1, 2, -1, -4]

        ↓

[-4, -1, -1, 0, 1, 2]

Sorting allows us to use the two-pointer technique.

Step 2: Fix One Element

Suppose:

nums[i] = -1

We need:

-1 + x + y = 0

Therefore:

x + y = 1

So the remaining problem is simply:

Find two numbers whose sum is 1.

That's 2Sum.

Step 3: Use Two Pointers

Set:

left = i + 1;
right = n - 1;

For example:

[-4, -1, -1, 0, 1, 2]
      ↑           ↑
    left        right

Calculate:

sum = nums[left] + nums[right];
If sum is too small
if(sum < target)
    left++;

We need a larger value.

Because the array is sorted, moving left right increases the sum.

If sum is too large
if(sum > target)
    right--;

Moving right left decreases the sum.

If sum equals target

We found a valid triplet.

Duplicate Handling

There are two types of duplicates.

Duplicate fixed element
if(i > 0 && nums[i] == nums[i-1])
    continue;

Example:

[-4, -1, -1, 0, 1, 2]
      ↑   ↑

We don't process the second -1 because it would generate the same triplets.

Duplicate left/right elements

After finding a valid pair:

while(i < j && nums[i] == nums[i+1])
    i++;

while(i < j && nums[j] == nums[j-1])
    j--;

Then:

i++;
j--;

This ensures the same triplet isn't added again.

Optimized Code
class Solution {
public:

    vector<vector<int>> result;

    void twoSum(vector<int>& nums, int target, int i, int j) {

        while(i < j) {

            int sum = nums[i] + nums[j];

            if(sum < target) {
                i++;
            }
            else if(sum > target) {
                j--;
            }
            else {

                result.push_back({
                    -target,
                    nums[i],
                    nums[j]
                });

                // Skip duplicate left values
                while(i < j && nums[i] == nums[i + 1])
                    i++;

                // Skip duplicate right values
                while(i < j && nums[j] == nums[j - 1])
                    j--;

                i++;
                j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        if(n < 3)
            return {};

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {

            // Skip duplicate fixed elements
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            int n1 = nums[i];

            // Need two numbers whose sum is -n1
            int target = -n1;

            twoSum(nums, target, i + 1, n - 1);
        }

        return result;
    }
};
Optimized Dry Run

Input:

[-1, 0, 1, 2, -1, -4]

After sorting:

[-4, -1, -1, 0, 1, 2]
i = 0
nums[i] = -4
target = 4

Search for two numbers whose sum is 4.

No valid pair.

i = 1
nums[i] = -1
target = 1

Now:

[-4, -1, -1, 0, 1, 2]
      ↑              ↑
    left           right

Try:

-1 + 2 = 1

Found:

[-1, -1, 2]

Then continue searching.

Eventually:

0 + 1 = 1

Found:

[-1, 0, 1]
i = 2
nums[i] = -1

But:

nums[2] == nums[1]

Therefore:

continue;

This prevents duplicate triplets.

Brute Force vs Optimized
Feature	Brute Force	Optimized
Technique	3 loops + Set	Sort + Two Pointers
Fixed element	No	Yes
Number of loops	3	1 + 2 pointers
Duplicate handling	set	Skip duplicates
Time	O(n³)	O(n²)
Extra space	O(unique triplets)	O(1) excluding output
Main idea	Try everything	Fix one + solve 2Sum
How We Improved the Brute Force

The evolution is important for interviews:

Brute Force
   ↓
Try every i, j, k
   ↓
O(n³)

Then ask:

Do I really need to try every k?

After sorting, for a fixed i and j, we can intelligently move the third pointer based on the current sum.

But an even cleaner way is:

Fix i
  ↓
Remaining problem becomes 2Sum
  ↓
Use left + right pointers

So:

3 nested loops
      ↓
1 loop + 2 pointers
      ↓
O(n³) → O(n²)
Important Pattern

This is the main thing to remember for interviews:

Brute Force
3Sum
→ try all triples
→ 3 loops
→ Set for duplicates
→ O(n³)
Optimized
3Sum
→ sort
→ fix one element
→ remaining = 2Sum
→ two pointers
→ skip duplicates
→ O(n²)
One-line interview explanation

I first solve 3Sum using three nested loops and a set to understand the brute-force solution. Then I optimize it by sorting the array, fixing one element, and converting the remaining problem into 2Sum using two pointers, reducing the time complexity from O(n³) to O(n²).
