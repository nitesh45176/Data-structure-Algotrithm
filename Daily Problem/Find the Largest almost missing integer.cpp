Largest Integer That Occurs Only Once in the Chosen Subarrays
Problem Intuition

We are given an array nums and an integer k.

We consider every contiguous subarray of length k and want to find the largest integer that appears in exactly one of those subarrays.

The important part is that we're not simply looking for an element whose frequency in nums is 1.

The answer depends on how many length-k subarrays contain that element.

Key Observation

The behavior changes depending on the value of k.

There are three important cases:

1. k == 1
2. k == n
3. 1 < k < n

This is the main insight behind the solution.

Case 1: k == 1

If:

k = 1

then every subarray contains exactly one element.

For example:

nums = [4, 2, 7, 2]
k = 1

The subarrays are:

[4]
[2]
[7]
[2]

An element appears in exactly one subarray if and only if it occurs exactly once in nums.

Frequencies:

4 → 1
2 → 2
7 → 1

Therefore candidates are:

4, 7

Largest:

7

That's why we do:

if(k == 1){
    int ans = -1;


    for(auto [x, freq]: mp){
        if(freq == 1){
            ans = max(ans, x);
        }
    }


    return ans;
}
Why do we need the frequency map?

We create:

unordered_map<int, int> mp;

and count every element:

for(auto x: nums){
    mp[x]++;
}

For example:

nums = [1, 2, 2, 4, 5, 5]

The map becomes:

1 → 1
2 → 2
4 → 1
5 → 2

This allows us to quickly determine whether an element occurs once in the entire array.

Case 2: k == n

If:

k == n

there is only one subarray:

nums

For example:

nums = [4, 7, 2, 9]
k = 4

Only subarray:

[4, 7, 2, 9]

Every element in the array belongs to this one subarray.

Therefore the largest valid integer is simply the maximum element:

return *max_element(nums.begin(), nums.end());
Case 3: 1 < k < n

This is the most interesting case.

Your solution checks only:

nums[0]
nums[n-1]

Why?

Because an element appearing somewhere in the middle of the array will necessarily belong to at least two different subarrays of length k.

The elements at the boundaries are special.

Why only the first and last elements?

Consider:

nums = [1, 2, 3, 4, 5]
k = 3

The length-3 subarrays are:

[1, 2, 3]
[2, 3, 4]
[3, 4, 5]

Look at 1.

It appears only in:

[1, 2, 3]

So 1 belongs to exactly one subarray.

Look at 5.

It appears only in:

[3, 4, 5]

So 5 also belongs to exactly one subarray.

But 3 appears in:

[1, 2, 3]
[2, 3, 4]
[3, 4, 5]

So it belongs to three subarrays.

Similarly, 2 belongs to two subarrays and 4 belongs to two.

Therefore, when:

1 < k < n

only the first and last positions can potentially belong to exactly one length-k subarray.

But there's another condition

Just being at the first or last position isn't enough.

The value itself must occur only once in the entire array.

For example:

nums = [5, 2, 3, 5]
k = 2

nums[0] = 5.

Although the first 5 belongs to only one length-2 subarray:

[5, 2]

there is another 5 at the end:

[3, 5]

So the value 5 appears in two different subarrays.

Therefore, 5 cannot be the answer.

That's why your code checks:

if(mp[nums[0]] == 1)

and:

if(mp[nums[n-1]] == 1)
Main logic for 1 < k < n

Your code:

int ans = -1;


if(mp[nums[0]] == 1){
    ans = max(ans, nums[0]);
}


if(mp[nums[n-1]] == 1){
    ans = max(ans, nums[n-1]);
}


return ans;

In plain English:

Check whether the first element occurs exactly once. If yes, it is a candidate.

Check whether the last element occurs exactly once. If yes, it is also a candidate.

Return the larger candidate.

Example

Consider:

nums = [3, 5, 2, 4, 6]
k = 2

Frequency:

3 → 1
5 → 1
2 → 1
4 → 1
6 → 1

First element:

3

It occurs once → candidate.

Last element:

6

It occurs once → candidate.

Therefore:

answer = max(3, 6)
       = 6
Example where answer is -1

Consider:

nums = [5, 2, 3, 5]
k = 2

Frequency:

5 → 2
2 → 1
3 → 1

First:

nums[0] = 5

but:

mp[5] = 2

so it isn't valid.

Last:

nums[3] = 5

also isn't valid.

Therefore:

answer = -1
Why the middle elements don't work

This is the most important reasoning to remember.

For:

1 < k < n

there are multiple overlapping windows.

An interior position has enough room for the window to start/end around it, meaning it belongs to at least two length-k subarrays.

The boundary positions are different:

index 0       → only windows starting at 0 can contain it
index n-1     → only windows ending at n-1 can contain it

Thus:

Only nums[0] and nums[n-1]

can potentially satisfy the condition.

Then the frequency check ensures that their value doesn't appear elsewhere.

Complexity

Building the frequency map:

for(auto x: nums)
    mp[x]++;

takes:

O(n)

Checking the map takes:

O(n)

in the k == 1 case.

max_element() takes:

O(n)

in the k == n case.

Therefore overall:

Time
O(n)
Space

The frequency map can contain up to n distinct values:

O(n)
Code cleanup

Your solution contains:

int n = nums.size();

which is necessary.

But there isn't much to remove otherwise. Your implementation is already fairly concise.

You could make the three cases visually clearer:

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();


        unordered_map<int, int> mp;


        for(int x : nums) {
            mp[x]++;
        }


        // Every subarray contains exactly one element.
        if(k == 1) {
            int ans = -1;


            for(auto [x, freq] : mp) {
                if(freq == 1) {
                    ans = max(ans, x);
                }
            }


            return ans;
        }


        // There is only one subarray: the entire array.
        if(k == n) {
            return *max_element(nums.begin(), nums.end());
        }


        // For 1 < k < n, only boundary positions
        // can belong to exactly one subarray.
        int ans = -1;


        if(mp[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }


        if(mp[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }


        return ans;
    }
};
The takeaway for future you

The key isn't the unordered_map. The real insight is the position of an element with respect to the length-k windows:

k == 1
→ every position is its own window
→ value must occur once


k == n
→ only one window exists
→ maximum element is the answer


1 < k < n
→ only the first and last positions can belong to exactly one window
→ their values must occur exactly once

So the pattern to remember is:

Don't brute-force all subarrays. Analyze how many windows can contain each position. The boundary positions are the only special positions when 1 < k < n.
