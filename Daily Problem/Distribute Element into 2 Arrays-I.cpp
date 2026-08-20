Distribute Elements Into Two Arrays I
Problem Intuition

We are given an array nums and need to distribute its elements into two arrays, arr1 and arr2.

The first two elements are placed directly:

arr1 = [nums[0]]
arr2 = [nums[1]]

For every remaining element nums[i]:

Compare the last element of arr1 and arr2.
If arr1.back() > arr2.back(), put nums[i] into arr1.
Otherwise, put nums[i] into arr2.

Finally, concatenate arr1 and arr2.

Key Observation

The important part of this problem is understanding:

arr1.back()
arr2.back()

back() returns the last element of a vector.

So:

if(arr1.back() > arr2.back())

means:

Compare the most recently inserted elements of the two arrays.

We do not compare the sizes of the arrays or their first elements.

Step-by-Step Approach
1. Create two arrays
vector<int> arr1;
vector<int> arr2;
2. Place the first two elements
arr1.push_back(nums[0]);
arr2.push_back(nums[1]);

After this:

nums = [2, 1, 3, 4]


arr1 = [2]
arr2 = [1]
3. Process the remaining elements

Start from index 2 because indices 0 and 1 have already been handled.

for(int i=2; i<n; i++)

For every element:

if(arr1.back() > arr2.back())
    arr1.push_back(nums[i]);
else
    arr2.push_back(nums[i]);
4. Combine the arrays

The required result is:

arr1 followed by arr2

So we first insert all elements of arr1, then all elements of arr2.

Example

Consider:

nums = [2, 1, 3, 4, 5]

Initially:

arr1 = [2]
arr2 = [1]
i = 2
nums[2] = 3


arr1.back() = 2
arr2.back() = 1


2 > 1 → put 3 in arr1

Now:

arr1 = [2, 3]
arr2 = [1]
i = 3
nums[3] = 4


arr1.back() = 3
arr2.back() = 1


3 > 1 → put 4 in arr1

Now:

arr1 = [2, 3, 4]
arr2 = [1]
i = 4
nums[4] = 5


arr1.back() = 4
arr2.back() = 1


4 > 1 → put 5 in arr1

Final:

arr1 = [2, 3, 4, 5]
arr2 = [1]

Result:

[2, 3, 4, 5, 1]
Why else?

Notice the condition is strictly:

arr1.back() > arr2.back()

If both values are equal:

arr1.back() == arr2.back()

the condition is false, so the element goes into arr2.

Therefore:

if(arr1.back() > arr2.back())
    arr1.push_back(nums[i]);
else
    arr2.push_back(nums[i]);

is equivalent to:

if arr1's last element is greater → arr1
otherwise                         → arr2
Complexity

Let n = nums.size().

We process every element exactly once.

Time Complexity
O(n)

Creating the final result also takes O(n), so the overall complexity remains:

O(n)
Space Complexity

We store:

arr1
arr2
result

Therefore:

O(n)
Code Notes / Cleanup

Your code contains:

int n1 = 0, n2 = 0;
int k = 0;

These variables are never used, so they can be removed.

Also, the final result can be constructed more cleanly using insert():
    

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();


        vector<int> arr1;
        vector<int> arr2;


        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);


        for(int i = 2; i < n; i++) {
            if(arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            }
            else {
                arr2.push_back(nums[i]);
            }
        }


        vector<int> result;


        result.insert(result.end(), arr1.begin(), arr1.end());
        result.insert(result.end(), arr2.begin(), arr2.end());


        return result;
    }
};


Takeaway

The main thing to remember for this problem:

This is a simple simulation problem. Maintain two arrays, compare their current last elements using back(), place the next element accordingly, and concatenate the two arrays at the end.

No DP, greedy proof, or complex data structure is required here.
