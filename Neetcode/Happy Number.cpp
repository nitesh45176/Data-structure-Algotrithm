Happy Number — LeetCode 202
1. Problem

A number is called a Happy Number if we repeatedly replace the number with the sum of the squares of its digits and eventually reach 1.

If the process enters a cycle and never reaches 1, the number is not happy.

Example

For:

37

Calculate the square of each digit:

3² + 7²
= 9 + 49
= 58

Then repeat:

58 → 5² + 8²
   → 25 + 64
   → 89

Continue until either:

1 → Happy

or a number repeats:

... → 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4 → ...

A repeated number means we are stuck in a cycle.

2. Main Idea

We need two things:

1. Calculate the sum of squares of digits

For every digit:

digit = n % 10;

gets the last digit.

Then:

digit * digit

calculates its square.

Finally:

n = n / 10;

removes the last digit.

2. Detect a cycle

Use:

unordered_set<int> usedIntegers;

to store numbers we have already seen.

If we encounter the same number again, we know that we are in a cycle.

3. How Do We Extract Digits?

Suppose:

n = 37
Get last digit
int digit = n % 10;
37 % 10 = 7

So:

digit = 7
Calculate square
digit * digit
7 × 7 = 49
Remove last digit
n = n / 10;
37 / 10 = 3

Now:

n = 3

Repeat:

3 % 10 = 3
3 × 3 = 9
3 / 10 = 0

Therefore:

37 → 7² + 3²
   → 49 + 9
   → 58
4. Code
class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> usedIntegers;

        while(true) {

            // Find the sum of squares of digits
            int sum = 0;

            while(n != 0) {

                // Get the last digit
                int digit = n % 10;

                // Add square of digit
                sum += digit * digit;

                // Remove the last digit
                n = n / 10;
            }

            // If sum becomes 1, it is a Happy Number
            if(sum == 1)
                return true;

            // The new number becomes n
            n = sum;

            // If we have already seen this number,
            // a cycle exists
            if(usedIntegers.count(n))
                return false;

            usedIntegers.insert(n);
        }
    }
};
5. Code Explanation
Create a Set
unordered_set<int> usedIntegers;

This stores all numbers that we have already encountered.

For example:

4
16
37
58
89
...

If we see one of them again, we know that the process is repeating.

Outer while
while(true)

We keep calculating new numbers until:

sum == 1 → return true
a number repeats → return false
Inner while
while(n != 0)

This loop processes every digit of n.

For example:

n = 123

It processes:

3 → 2 → 1
Get the Last Digit
int digit = n % 10;

% 10 gives the last digit.

123 % 10 = 3
12  % 10 = 2
1   % 10 = 1
Square the Digit
sum += digit * digit;

For example:

digit = 3

3 × 3 = 9

So:

sum = sum + 9
Remove the Last Digit
n = n / 10;

Because C++ integer division removes the decimal part:

123 / 10 = 12
12 / 10  = 1
1 / 10   = 0
6. Why sum == 1?

After calculating all digit squares:

if(sum == 1)
    return true;

If we reach 1, the number is happy.

For example:

19
↓
1² + 9²
↓
1 + 81
↓
82
↓
8² + 2²
↓
64 + 4
↓
68
↓
...
↓
1

Therefore 19 is a Happy Number.

7. Why Use a Set?

Some numbers don't reach 1.

Instead, they eventually repeat.

For example:

4 → 16 → 37 → 58 → 89
              ↓
...
              ↓
4

Once we get:

4

again, we know the same sequence will repeat forever.

So:

if(usedIntegers.count(n))
    return false;

means:

"Have I seen this number before?"

If yes → cycle → not happy.

Otherwise:

usedIntegers.insert(n);

stores the number.

8. Complete Flow
              Start with n
                   ↓
          Extract every digit
                   ↓
        Square each digit
                   ↓
       Add all the squares
                   ↓
              sum == 1?
             /        \
           YES         NO
            ↓           ↓
          true      Have we seen
                     this number?
                    /          \
                  YES           NO
                   ↓             ↓
                 false       n = sum
                                ↓
                             Repeat
9. Important Pattern

Whenever you see a problem involving digits of a number, remember:

int digit = n % 10;  // Get last digit
n = n / 10;          // Remove last digit

For digit squares:

sum += digit * digit;

So:

Number → Extract digits → Process digits → Remove digits → Repeat
10. Complexity

Let d be the number of digits processed.

The set stores previously seen numbers.

Time Complexity:  O(d)*
Space Complexity: O(d)*

* More precisely, the number of iterations is bounded because the digit-square transformation quickly reaches a small range of values; the set stores the values encountered during the process.

Key Takeaway

Happy Number = repeatedly calculate the sum of squared digits. Return true if it reaches 1; return false if a number repeats.

Remember these 3 lines:
int digit = n % 10;
sum += digit * digit;
n = n / 10;

They mean:

Get digit → Square digit → Remove digit
