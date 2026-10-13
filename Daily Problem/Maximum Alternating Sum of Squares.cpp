# Maximum Alternating Sum of Squares

## Problem

Given an integer array `nums`, find the maximum alternating sum of squares after rearranging the squared elements.

The goal is to maximize an expression of the form:

\[
a_1^2+a_2^2-a_3^2-a_4^2+a_5^2+\cdots
\]

The exact alternating pattern depends on the problem's definition. The key idea is to assign larger squared values to positive positions and smaller squared values to negative positions.

## Intuition

Squaring every element makes it non-negative, regardless of whether the original number was positive or negative.

For example:

```text
nums = [-3, 2, 4]

Squares = [9, 4, 16]
```

Since larger squared values contribute more when added and less when subtracted, we should:

- Subtract the smallest squared values.
- Add the largest squared values.

This leads to a **sorting + greedy** approach.

## Approach

1. Square every element and store the result in a `long long` array.
2. Use `1LL` during multiplication to prevent integer overflow.
3. Sort the squared values in ascending order.
4. Let `k = n / 2`.
5. Subtract the first `k` smallest squares from the answer.
6. Add the remaining larger squares.
7. Return the final sum.

## Code

```cpp
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = 1LL * nums[i] * nums[i];
        }

        sort(arr.begin(), arr.end());

        int k = n / 2;
        long long sum = 0;

        for (int i = 0; i < k; i++) {
            sum -= arr[i];
        }

        for (int i = k; i < n; i++) {
            sum += arr[i];
        }

        return sum;
    }
};
```

## Dry Run

Consider the squared values:

```text
arr = [1, 4, 9, 16]
```

They are already sorted.

Since `n = 4`:

```text
k = n / 2 = 2
```

Subtract the two smallest values:

```text
sum = -1 - 4 = -5
```

Add the remaining values:

```text
sum = -5 + 9 + 16 = 20
```

The result is `20`.

## Complexity Analysis

- **Time Complexity:** `O(n log n)` — sorting the squared values dominates.
- **Space Complexity:** `O(n)` — storing the squared values in a separate array.

## Important Observations

- Use `1LL * nums[i] * nums[i]`, not `1LL * (nums[i] * nums[i])`. The latter can overflow before conversion to `long long`.
- Use `long long` for the accumulated sum because the sum of squares can exceed the 32-bit integer range.
- Sorting allows us to assign the smallest values to negative positions and the largest values to positive positions.

## Key Takeaway

**Greedy + Sorting:** Square the elements, sort them, subtract the smaller half, and add the larger half to maximize the alternating sum.
