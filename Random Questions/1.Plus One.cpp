66. Plus One

Problem
Given an array digits representing a non-negative integer, add 1 to the number and return the resulting array.

Example:

digits = [1,2,3]
Output = [1,2,4]
digits = [9,9,9]
Output = [1,0,0,0]
Approach

We start from the last digit because adding 1 affects the number from right to left.

int i = n - 1;
Case 1: Digit is less than 9

If:

digits[i] < 9

we can simply add 1 and return.

digits[i] += 1;
return digits;

Example:

[1,2,3]

3 + 1 = 4

[1,2,4]

No carry is generated.

Case 2: Digit is 9

If:

digits[i] == 9

then adding 1 makes it 10.

So:

9 + 1 = 10

We put 0 at that position and carry 1 to the previous digit.

digits[i] = 0;
i--;

Example:

[1,2,9]

9 → 0
carry → previous digit

[1,2,0]

Then we process 2.

All Digits Are 9

Consider:

[9,9,9]

Processing from right to left:

[9,9,9]
     ↓
[9,9,0]
     ↓
[9,0,0]
     ↓
[0,0,0]

Now i < 0, meaning every digit was 9.

We need to add 1 at the beginning:

digits.insert(digits.begin(), 1);

Result:

[1,0,0,0]
Code
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();

        // Start from the last digit
        int i = n - 1;

        while(i >= 0) {

            // No carry is generated
            if(digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }

            // 9 + 1 = 10
            // Put 0 and carry 1 to the previous digit
            if(digits[i] == 9) {
                digits[i] = 0;
                i--;
            }
        }

        // All digits were 9
        // Example: [9,9,9] -> [1,0,0,0]
        digits.insert(digits.begin(), 1);

        return digits;
    }
};
Dry Run

For:

digits = [1,9,9]

Start:

i = 2
Step 1
digits[2] = 9

Set it to 0:

[1,9,0]

Move left:

i = 1
Step 2

Again 9:

[1,0,0]

Move left:

i = 0
Step 3

Now:

digits[0] = 1

Since it is less than 9:

1 + 1 = 2

Final:

[2,0,0]
Complexity
Time Complexity
O(n)

In the worst case, all digits are 9, so we traverse the entire array.

Space Complexity
O(1)

We modify the input array in-place. The returned array itself is not counted as auxiliary space.
