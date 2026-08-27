Lexicographically Smallest Permutation Greater Than Target
Problem

Given two strings s and target, rearrange the characters of s to create the lexicographically smallest permutation that is strictly greater than target.

If no such permutation exists, return an empty string.

Example
s = "aabc"
target = "aacb"

Possible permutations greater than "aacb" include:

"abac"
"abca"
"acab"
...

The smallest valid answer is:

"abac"
Core Idea

We construct the answer character by character using:

Backtracking
Frequency array
Greedy ordering
A greater flag to track whether the current prefix is already greater than target
1. Frequency Array

Since only lowercase English letters are present, we store the frequency of each character:

vector<int> count(26, 0);

for(char ch : s) {
    count[ch - 'a']++;
}

For:

s = "aabc"

we have:

a → 2
b → 1
c → 1

This allows us to know which characters are still available.

2. greater Variable

We maintain:

bool greater

It tells us whether the prefix we have constructed is already greater than the corresponding prefix of target.

Initially:

greater = false;

because nothing has been constructed yet.

When greater == false

We are still equal to target.

Suppose:

target[i] = 'c'

Then:

ch < 'c'   → ❌ Not allowed
ch == 'c'  → ✅ Allowed
ch > 'c'   → ✅ Allowed

Why can't we choose a smaller character?

Because once our prefix becomes smaller, the complete string can never become greater later.

So:

if(!greater && ch < target[i])
    continue;
When greater == true

The prefix is already greater than target.

For example:

current = "abd"
target  = "abc"

Since:

"d" > "c"

the entire string is already greater.

Therefore, from this point:

Any remaining character is allowed.

But we still try characters from 'a' to 'z' so that the final answer remains as small as possible.

3. Updating greater

After choosing a character:

bool isGreater = greater || ch > target[i];
Case 1: Already greater
greater = true

Then:

isGreater = true
Case 2: Equal
greater = false
ch == target[i]

Then:

isGreater = false

We are still equal.

Case 3: Become greater
greater = false
ch > target[i]

Then:

isGreater = true

From this point onward, the permutation is guaranteed to be greater.

4. Why Backtracking?

We don't know which character choice will lead to a valid answer.

For example:

s = "aab"
target = "aba"

Suppose we construct:

"aab"

But:

"aab" < "aba"

So this choice/path fails.

We need to undo the choice and try another possibility.

The pattern is:

Choose
  ↓
Explore
  ↓
Fails?
  ↓
Undo choice
  ↓
Try another choice

In code:

curr.push_back(ch);
count[ch - 'a']--;

solve(...);

curr.pop_back();
count[ch - 'a']++;

The pop_back() and frequency restoration are the backtracking step.

5. Why Try Characters From 'a' to 'z'?

We want the smallest valid permutation.

Therefore, at every position we try:

a → b → c → d → ... → z

The first valid solution we find is the lexicographically smallest one.

This combines:

Greedy ordering + Backtracking
6. Base Case
if(i == target.size())

means we have constructed the complete string.

Now we check:

if(greater)

If greater == true:

current > target

so we found a valid answer.

result = curr;
return true;

If greater == false, the constructed string is equal to target, so it is not valid.

7. Complete Code
class Solution {
public:
    string result = "";

    bool solve(string& curr,
               vector<int>& count,
               string& target,
               int i,
               bool greater) {

        // Complete permutation constructed
        if(i == target.size()) {

            // We need strictly greater permutation
            if(greater) {
                result = curr;
                return true;
            }

            return false;
        }

        // Try characters from smallest to largest
        for(char ch = 'a'; ch <= 'z'; ch++) {

            // Character is not available
            if(count[ch - 'a'] == 0)
                continue;

            // If still equal to target,
            // we cannot choose a smaller character
            if(!greater && ch < target[i])
                continue;

            // Choose character
            curr.push_back(ch);
            count[ch - 'a']--;

            // Check whether current prefix is now greater
            bool isGreater = greater || ch > target[i];

            // Explore this choice
            if(solve(curr, count, target, i + 1, isGreater))
                return true;

            // Backtrack
            curr.pop_back();
            count[ch - 'a']++;
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {

        // Store frequency of each character
        vector<int> count(26, 0);

        for(char ch : s)
            count[ch - 'a']++;

        string curr;

        solve(curr, count, target, 0, false);

        return result;
    }
};
8. Algorithm
1. Count frequency of every character in s.

2. Start constructing the answer from index 0.

3. At every index:
   - Try characters from 'a' to 'z'.
   - Skip characters that are unavailable.
   - If we are still equal to target:
       - Skip characters smaller than target[i].
   - Choose the character.
   - Update the greater state.
   - Recursively continue.

4. If a complete string is greater than target:
   - Store it.
   - Return true.

5. If the choice fails:
   - Remove the character.
   - Restore its frequency.
   - Try the next character.

6. Return the first valid answer.
9. Important Condition

This line is the most important part:

if(!greater && ch < target[i])
    continue;

Remember:

Still equal:
    smaller → ❌
    equal   → ✅
    greater → ✅

Already greater:
    anything → ✅
10. Example
s      = "aabc"
target = "aacb"

We start:

curr = ""
greater = false

Try smallest available characters.

'a' == 'a'

So:

curr = "a"
greater = false

Next:

'a' == 'a'

So:

curr = "aa"
greater = false

Next target character is:

'c'

Available characters are:

b, c

b < c, so:

'b' → ❌

Try:

'c' == 'c'

Now:

curr = "aac"

Last target character:

target[3] = 'b'

Remaining character:

'b'

So:

"b" == "b"

Complete string:

"aacb"

But:

"aacb" == target

Therefore it is not valid.

Backtracking occurs and we try another path.

Eventually:

"abac"

is found:

"abac" > "aacb"

Therefore:

answer = "abac"
11. Why Is the First Valid Answer the Smallest?

Because we always try:

'a' → 'b' → 'c' → ... → 'z'

At every position.

Therefore, we explore lexicographically smaller possibilities before larger ones.

So when the first valid complete permutation is found:

first valid answer = lexicographically smallest valid answer
12. Complexity

Let n = s.length().

At each position we can try up to 26 characters, with backtracking over possible arrangements.

Time

Worst case:

O(26^n)

Since 26 is constant, this is often described as:

O(C^n)

for the branching factor C.

The frequency array reduces duplicate-character branches compared with generating all n! permutations.

Space

Recursion depth:

O(n)

Frequency array:

O(26) = O(1)

Current string:

O(n)

Therefore:

Space = O(n)

excluding the returned result.

13. Pattern to Remember

This problem combines three ideas:

Frequency Array
       +
Backtracking
       +
Greedy Character Ordering
Mental model
                 Start
                   |
             greater = false
                   |
          Try smallest char
                   |
          ┌────────┴────────┐
          |                 |
       smaller            >= target
          |                 |
         ❌          ┌──────┴──────┐
                    ==             >
                    |              |
              remain equal    greater = true
                    |              |
                    └──────┬───────┘
                           |
                    Continue recursion
                           |
                       Complete?
                       /      \
                     NO        YES
                     |          |
                 Backtrack    greater?
                                |
                              YES → Answer
One-line interview explanation

We use backtracking to construct the permutation character by character, always trying the smallest available character first, while tracking whether our prefix has already become greater than the target.
