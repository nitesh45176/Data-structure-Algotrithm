1658. Minimum Operations to Reduce X to Zero

You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.


1. Problem

We are given an array nums and an integer x.

In one operation, we can remove an element from either:

the left side, or
the right side.

We need to remove elements whose sum is exactly x.

The goal is to find the minimum number of operations.

2. Main Idea

Instead of thinking:

Which elements should I remove from the left and right?

Think the opposite:

Which subarray should I keep?

Suppose:

nums = [1, 1, 4, 2, 3]
x = 5

Total sum:

1 + 1 + 4 + 2 + 3 = 11

We need to remove elements having sum 5.

Therefore, the elements we keep must have:

11 - 5 = 6

So:

target = totalSum - x

Now the problem becomes:

Find the longest subarray whose sum is target.

Why longest?

If we keep the longest possible subarray, we remove the fewest elements.

minimum operations = n - longest subarray length
3. Example
nums = [1, 1, 4, 2, 3]
x = 5

Total:

11

Required subarray sum:

target = 11 - 5
       = 6

A longest subarray with sum 6 is:

[1, 1, 4]

Length:

3

So we remove:

5 - 3 = 2 elements

Indeed:

[1, 1, 4, 2, 3]
        ↑  ↑
        2  3

2 + 3 = 5.

Answer:

2
4. How Do We Find the Longest Subarray?

We use prefix sum + hashmap.

Suppose:

nums = [1, 1, 4, 2, 3]

Prefix sums are:

index:       -1   0   1   2   3   4
prefix sum:   0   1   2   6   8  11

We want a subarray whose sum is:

target = 6

For a subarray from j+1 to i:

subarray sum = prefix[i] - prefix[j]

We need:

prefix[i] - prefix[j] = target

Therefore:

prefix[j] = prefix[i] - target

This is why we calculate:

int findSum = sum - target;

and search for it in the hashmap.

5. Why mp[0] = -1?

This is an important line:

mp[0] = -1;

It means:

Before the array starts, the prefix sum is 0 at index -1.

Consider:

nums = [1, 1, 4]
target = 6

At index 2:

sum = 6

We calculate:

findSum = sum - target
        = 6 - 6
        = 0

We find:

mp[0] = -1

Therefore:

length = i - idx
       = 2 - (-1)
       = 3

So the entire subarray [1,1,4] is correctly counted.

Without:

mp[0] = -1;

we wouldn't be able to detect subarrays starting from index 0.

6. First Loop
unordered_map<int, int> mp;
int sum = 0;

mp[0] = -1;

for(int i = 0; i < n; i++){
    sum += nums[i];
    mp[sum] = i;
}

This stores:

prefix sum → index

For:

[1,1,4,2,3]

we get approximately:

0  → -1
1  → 0
2  → 1
6  → 2
8  → 3
11 → 4

We use this map to quickly find the prefix sum we need.

7. Why Check sum < x?
if(sum < x){
    return -1;
}

sum here is the total sum of the array.

If:

totalSum < x

then even removing all elements cannot reach x.

Example:

nums = [1,2,3]
x = 10

Total:

6 < 10

Impossible.

Therefore:

return -1
8. Calculate the Required Subarray Sum
int target = sum - x;

Remember:

total sum = removed sum + remaining sum

We need:

removed sum = x

Therefore:

remaining sum = total sum - x

So:

target = totalSum - x;
9. Second Loop

Now we find the longest subarray having sum target.

sum = 0;

for(int i = 0; i < n; i++){
    sum += nums[i];

    int findSum = sum - target;

    if(mp.find(findSum) != mp.end()){
        int idx = mp[findSum];

        longSubArray = max(longSubArray, i - idx);
    }
}

The important equation is:

prefix[i] - prefix[idx] = target

Therefore:

prefix[idx] = prefix[i] - target

That's exactly:

findSum = sum - target;
10. Dry Run

Consider:

nums = [1,1,4,2,3]
x = 5

Total:

11

Therefore:

target = 11 - 5 = 6

Prefix map:

sum → index

0  → -1
1  → 0
2  → 1
6  → 2
8  → 3
11 → 4

Now second loop.

i = 0
sum = 1
findSum = 1 - 6 = -5

-5 not found.

i = 1
sum = 2
findSum = 2 - 6 = -4

Not found.

i = 2
sum = 6
findSum = 6 - 6 = 0

We have:

mp[0] = -1

So:

length = 2 - (-1)
       = 3

Therefore:

longSubArray = 3
i = 3
sum = 8
findSum = 8 - 6 = 2

We have:

mp[2] = 1

So:

length = 3 - 1
       = 2

But 3 is already longer.

i = 4
sum = 11
findSum = 11 - 6 = 5

5 doesn't exist.

Final:

longSubArray = 3

Therefore:

operations = n - longSubArray
           = 5 - 3
           = 2
11. Complete Code
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        unordered_map<int, int> mp;
        int sum = 0;

        // prefix sum -> index
        mp[0] = -1;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            mp[sum] = i;
        }

        // Total sum is smaller than x
        if(sum < x){
            return -1;
        }

        // Sum of the subarray that we want to keep
        int target = sum - x;

        int longSubArray = INT_MIN;

        sum = 0;

        // Find longest subarray with sum = target
        for(int i = 0; i < n; i++){
            sum += nums[i];

            int findSum = sum - target;

            if(mp.find(findSum) != mp.end()){
                int idx = mp[findSum];

                longSubArray = max(
                    longSubArray,
                    i - idx
                );
            }
        }

        return longSubArray == INT_MIN
                   ? -1
                   : n - longSubArray;
    }
};
12. Complexity

We traverse the array twice.

Average hashmap operations are O(1).

Time Complexity:  O(n)
Space Complexity: O(n)
13. Key Takeaway

The most important transformation is:

Original problem:
Remove elements from left/right with sum = x

                ↓

Think about what remains

                ↓

Remaining sum = totalSum - x

                ↓

Find longest subarray with sum = totalSum - x

                ↓

Minimum operations = n - longestSubarray
Remember this pattern

Minimum removals from the two ends → Maximum subarray to keep.

And to find that maximum subarray:

Prefix Sum + HashMap.
