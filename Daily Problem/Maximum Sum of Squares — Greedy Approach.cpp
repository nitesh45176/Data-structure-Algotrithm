
3723. Maximize Sum of Squares of Digits

You are given two positive integers num and sum.

A positive integer n is good if it satisfies both of the following:

The number of digits in n is exactly num.
The sum of digits in n is exactly sum.
The score of a good integer n is the sum of the squares of digits in n.

Return a string denoting the good integer n that achieves the maximum score. If there are multiple possible integers, return the maximum ​​​​​​​one. If no such integer exists, return an empty string.

 

Example 1:

Input: num = 2, sum = 3

Output: "30"

Explanation:

There are 3 good integers: 12, 21, and 30.

The score of 12 is 12 + 22 = 5.
The score of 21 is 22 + 12 = 5.
The score of 30 is 32 + 02 = 9.
The maximum score is 9, which is achieved by the good integer 30. Therefore, the answer is "30".

Example 2:

Input: num = 2, sum = 17

Output: "98"

Explanation:

There are 2 good integers: 89 and 98.

The score of 89 is 82 + 92 = 145.
The score of 98 is 92 + 82 = 145.
The maximum score is 145. The maximum good integer that achieves this score is 98. Therefore, the answer is "98".

Example 3:

Input: num = 1, sum = 10

Output: ""

Explanation:

There are no integers that have exactly 1 digit and whose digits sum to 10. Therefore, the answer is "".

 

Constraints:

1 <= num <= 2 * 105
1 <= sum <= 2 * 106

## Approach
1. Check whether `sum > num * 9`. If true, return an empty string because the maximum possible digit sum is `num * 9`.
2. Calculate `nines = sum / 9` to determine the maximum number of complete 9s.
3. Calculate `rem = sum % 9` to find the remaining sum.
4. Create a string containing `nines` copies of the character `'9'`.
5. If `rem > 0`, append the remaining digit using `push_back(rem + '0')`.
6. Append zeros until the string length becomes exactly `num`.
7. Return the resulting string.

## Code

```cpp
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > num * 9) return "";

        int nines = sum / 9;
        int rem = sum % 9;

        string result(nines, '9');

        if (rem > 0)
            result.push_back(rem + '0');

        result.append(num - result.length(), '0');

        return result;
    }
};
```

## Dry Run

Input: `num = 5, sum = 23`

Step 1: Check feasibility.

The maximum possible digit sum is `5 * 9 = 45`. Since `23 <= 45`, a valid number can be constructed.

Step 2: Calculate the number of 9s and the remainder.

```text
nines = 23 / 9 = 2
rem = 23 % 9 = 5
```

Step 3: Create a string containing two 9s.

```text
result = "99"
```

Step 4: Append the remaining digit, 5.

```text
result = "995"
```

Step 5: The string currently contains 3 digits, but we need 5 digits. Append two zeros.

```text
result = "99500"
```

The digit sum is `9 + 9 + 5 + 0 + 0 = 23`.

The sum of squares is:

`9² + 9² + 5² + 0² + 0² = 81 + 81 + 25 = 187`

Therefore, the resulting number is `"99500"`, and its sum of squares is 187.

## Complexity Analysis

- Time Complexity: O(num), because constructing the resulting string takes linear time.
- Space Complexity: O(num), because the resulting string stores `num` digits.

## Key Takeaway

This problem uses a greedy strategy. Since larger digits contribute more to the sum of squares, we maximize the number of 9s, append the remaining digit if necessary, and fill the unused positions with zeros.

The important operations are:
- `sum / 9`: calculates the number of complete 9s.
- `sum % 9`: calculates the remaining digit.
- `string(nines, '9')`: creates a string containing multiple 9s.
- `push_back()`: appends one character.
- `append()`: appends multiple copies of a character.
