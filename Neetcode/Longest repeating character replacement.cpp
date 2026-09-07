Longest Repeating Character Replacement — Sliding Window

Given a string s containing uppercase English letters and an integer k.

You can replace at most k characters with any other uppercase letter.

Find the length of the longest substring that can be made to contain only one distinct character.

Example
s = "AABABBA"
k = 1

We can change:

A A B A B B A
      ↑

For example, change one B to A:

A A B A B B A
    ↓
A A A A B B A

The longest valid substring is "AABA" → change B to A → "AAAA".

Answer:

4
2. Main Idea

This is a sliding window problem.

We maintain a window:

[left ........ right]

Inside this window, we count the frequency of every character.

The important thing is:

We want to make the entire window consist of the same character.

So naturally, we should keep the character that occurs most frequently and replace all other characters.

3. Key Formula ⭐

Suppose our current window is:

A A B A B

Window length:

5

Frequencies:

A = 3
B = 2

The most frequent character is A, appearing 3 times.

If we want the whole window to become A:

A A B A B
    ↑   ↑

We need to change the two Bs.

Therefore:

characters to replace
= window length - maximum frequency

So:

5 - 3 = 2
Formula
charactersToChange = windowLen - maxFreq;
4. When is the Window Valid?

We are allowed to replace at most k characters.

Therefore:

windowLen - maxFreq <= k

means the window is valid.

If:

windowLen - maxFreq > k

then we need more than k replacements.

So the window is invalid.

We shrink it from the left.

5. Sliding Window Process

We use:

int left = 0;

and:

for(int right = 0; right < n; right++)

So right continuously expands the window.

For every new character:

Step 1 — Add character
freq[s[right] - 'A']++;
Step 2 — Update maximum frequency
maxFreq = max(maxFreq, freq[s[right] - 'A']);
Step 3 — Calculate window length
int windowLen = right - left + 1;
Step 4 — Calculate required replacements
int char_need_tobe_changed = windowLen - maxFreq;
Step 5 — If too many replacements are needed
if(char_need_tobe_changed > k) {
    freq[s[left] - 'A']--;
    left++;
}

We remove the character at left because that character is leaving the window.

Step 6 — Update answer
maxWindow = max(maxWindow, windowLen);
6. Dry Run

Consider:

s = "AABABBA"
k = 1

We can change at most 1 character.

Initially:

left = 0
right = 0

Window:

A

Frequency:

A = 1
windowLen = 1
maxFreq = 1
changes = 1 - 1 = 0

Valid.

maxWindow = 1
right = 1

Window:

AA
A = 2
windowLen = 2
maxFreq = 2
changes = 2 - 2 = 0

Valid.

maxWindow = 2
right = 2

Window:

AAB

Frequency:

A = 2
B = 1
windowLen = 3
maxFreq = 2
changes = 3 - 2 = 1

We can make:

AAB → AAA

using 1 replacement.

Valid.

maxWindow = 3
right = 3

Window:

AABA

Frequency:

A = 3
B = 1
windowLen = 4
maxFreq = 3
changes = 4 - 3 = 1

Valid.

maxWindow = 4
right = 4

Window:

AABAB

Frequency:

A = 3
B = 2
windowLen = 5
maxFreq = 3
changes = 5 - 3 = 2

But:

2 > k
2 > 1

So this window is invalid.

We remove the character at left.

Current:

A A B A B
↑
left

Remove A:

  A B A B
  ↑
 left

Then:

left++;

Now the window becomes:

ABAB

Length:

4
7. Why Do We Keep maxFreq?

You may notice that we don't decrease maxFreq when removing a character.

For example:

freq[s[left] - 'A']--;

but we don't do:

maxFreq--;

This is intentional.

maxFreq represents the maximum frequency we have seen while expanding the window.

Keeping it this way still gives the correct maximum window length and allows the algorithm to remain O(n).

This is a common optimization in this problem.

8. Code
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int left = 0;

        vector<int> freq(26, 0);

        int maxFreq = 0;
        int maxWindow = 0;

        for(int right = 0; right < n; right++) {

            // Add current character
            freq[s[right] - 'A']++;

            // Maximum frequency in current/seen window
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // Current window length
            int windowLen = right - left + 1;

            // Characters that need to be replaced
            int char_need_tobe_changed = windowLen - maxFreq;

            // Window is invalid
            if(char_need_tobe_changed > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            // Update answer
            windowLen = right - left + 1;
            maxWindow = max(maxWindow, windowLen);
        }

        return maxWindow;
    }
};
9. Why freq(26, 0)?

The string contains uppercase English letters:

A B C ... Z

There are only 26 possible characters.

So:

vector<int> freq(26, 0);

stores their frequencies.

For example:

s[right] - 'A'

converts:

'A' → 0
'B' → 1
'C' → 2
...
'Z' → 25
10. Most Important Intuition ⭐

Whenever you see:

"You can change at most k characters and need the longest substring satisfying some condition"

think:

Sliding Window
      ↓
Maintain frequency
      ↓
Keep the most frequent character
      ↓
Everything else needs replacement
      ↓
changes = window length - max frequency
      ↓
if changes > k → shrink window
One-line formula to remember
windowLen - maxFreq <= k

This is the heart of Character Replacement.

11. Complexity
Time

Each character enters the window once and leaves the window at most once.

O(n)
Space

Only 26 frequencies are stored:

O(26) = O(1)

So:

Time:  O(n)
Space: O(1)
