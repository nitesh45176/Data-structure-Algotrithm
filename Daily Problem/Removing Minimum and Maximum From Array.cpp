# LeetCode 2091 — Removing Minimum and Maximum From Array

## Approach

The goal is to remove both the **minimum** and **maximum** elements from the array using the minimum number of deletions.

Since we can only delete elements from the **beginning or the end** of the array, there are only **three possible strategies**.

### 1. Find the positions of minimum and maximum

```cpp
int minIdx = min_element(begin(nums), end(nums)) - begin(nums);
int maxIdx = max_element(begin(nums), end(nums)) - begin(nums);
```

`min_element()` returns an iterator pointing to the minimum element, and subtracting `begin(nums)` gives its index.

Similarly, `max_element()` gives the index of the maximum element.

---

### 2. Arrange the indices

```cpp
int leftIdx = min(minIdx, maxIdx);
int rightIdx = max(minIdx, maxIdx);
```

We store the smaller index in `leftIdx` and the larger index in `rightIdx`.

For example, if:

```text
minIdx = 6
maxIdx = 2
```

then:

```text
leftIdx = 2
rightIdx = 6
```

This makes it easier to calculate the number of deletions.

---

## Three possible ways

Suppose:

```text
leftIdx = position of the first target
rightIdx = position of the second target
```

### Option 1: Delete from both ends

Remove everything from the beginning through `leftIdx`, and everything from `rightIdx` through the end.

```cpp
int first = (leftIdx + 1) + (n - rightIdx);
```

Why?

* `leftIdx + 1` elements must be removed from the left.
* `n - rightIdx` elements must be removed from the right.

So:

```text
first = (leftIdx + 1) + (n - rightIdx)
```

---

### Option 2: Delete everything from the left

We can remove elements from the beginning until we have removed the element at `rightIdx`.

```cpp
int sec = rightIdx + 1;
```

Because the array is zero-indexed, removing through index `rightIdx` requires:

```text
rightIdx + 1
```

deletions.

This removes both the minimum and maximum because both indices are at or before `rightIdx`.

---

### Option 3: Delete everything from the right

Alternatively, we can remove elements from the end until we have removed the element at `leftIdx`.

```cpp
int third = n - leftIdx;
```

There are `n - leftIdx` elements from `leftIdx` to the end.

---

## Take the minimum

We calculate all three possibilities:

```cpp
return min({first, sec, third});
```

and return the smallest number of deletions.

---

## Example

Consider:

```text
nums = [2, 10, 7, 5, 4, 1, 8, 6]
```

Minimum:

```text
1 → index 5
```

Maximum:

```text
10 → index 1
```

Therefore:

```text
leftIdx = 1
rightIdx = 5
```

### Option 1 — Both ends

```text
(leftIdx + 1) + (n - rightIdx)

= (1 + 1) + (8 - 5)
= 2 + 3
= 5
```

### Option 2 — From left

```text
rightIdx + 1
= 5 + 1
= 6
```

### Option 3 — From right

```text
n - leftIdx
= 8 - 1
= 7
```

Therefore:

```text
answer = min(5, 6, 7)
       = 5
```

---

## Complexity

Finding the minimum and maximum takes `O(n)` time.

The remaining calculations take `O(1)` time.

Therefore:

```text
Time Complexity:  O(n)
Space Complexity: O(1)
```

## C++ Code

```cpp
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        // Find indices of minimum and maximum elements
        int minIdx = min_element(begin(nums), end(nums)) - begin(nums);
        int maxIdx = max_element(begin(nums), end(nums)) - begin(nums);

        // Arrange them so leftIdx <= rightIdx
        int leftIdx = min(minIdx, maxIdx);
        int rightIdx = max(minIdx, maxIdx);

        // 1. Remove from both left and right
        int first = (leftIdx + 1) + (n - rightIdx);

        // 2. Remove everything from the left
        int sec = rightIdx + 1;

        // 3. Remove everything from the right
        int third = n - leftIdx;

        return min({first, sec, third});
    }
};
```

### Key Insight

There are only **three meaningful possibilities**:

1. Remove the two elements using **both ends**.
2. Remove both elements using **only the left side**.
3. Remove both elements using **only the right side**.

Checking these three cases is sufficient because deletions can only happen from the two ends of the array.
