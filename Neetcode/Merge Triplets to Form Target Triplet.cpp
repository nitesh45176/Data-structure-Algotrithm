Merge Triplets to Form Target Triplet
1. Problem

We are given some triplets and a target triplet.

We can merge two triplets by taking the maximum value at each position.

For example:

[1, 5, 3]
[2, 3, 4]
---------
[2, 5, 4]

Because:

max(1,2) = 2
max(5,3) = 5
max(3,4) = 4

We need to determine whether we can merge some triplets to get exactly the target.

2. Most Important Observation

Suppose target is:

[2, 7, 5]

Consider:

[3, 6, 4]

This triplet has 3 > 2.

Can we use it?

No.

Why?

Because merging only uses max().

max(3, anything) >= 3

So the first value can never come back down to 2.

Therefore:

If any value of a triplet is greater than the corresponding target value, we cannot use that triplet.

3. Which Triplets Are Useful?

Target:

[2, 7, 5]

Suppose we have:

[2, 5, 3]   ✅
[1, 7, 4]   ✅
[1, 6, 5]   ✅
[3, 4, 5]   ❌

Why is the last one invalid?

3 > 2

So if we merge it, the first position becomes at least 3.

We only want 2.

4. What Do We Actually Need?

For target:

[2, 7, 5]

We need to somehow get:

first position  = 2
second position = 7
third position  = 5

So we maintain three boolean variables:

bool a = false; // Can we get target[0]?
bool b = false; // Can we get target[1]?
bool c = false; // Can we get target[2]?
5. Check Every Triplet

For every triplet:

[t[0], t[1], t[2]]

First check:

if(t[0] > target[0] ||
   t[1] > target[1] ||
   t[2] > target[2])

If this is true, ignore the triplet.

Because it would make some value too large.

Otherwise

Check whether this triplet can provide any target value.

if(t[0] == target[0])
    a = true;

if(t[1] == target[1])
    b = true;

if(t[2] == target[2])
    c = true;
6. Dry Run

Suppose:

triplets = [
    [2,5,3],
    [1,8,4],
    [1,7,5]
]

target = [2,7,5]
Triplet 1
[2,5,3]

Compare with target:

2 <= 2
5 <= 7
3 <= 5

Valid.

It gives:

2 → first position

So:

a = true
b = false
c = false
Triplet 2
[1,8,4]

Check:

1 <= 2
8 > 7  ❌
4 <= 5

Ignore it.

Because 8 can never be reduced to 7.

Triplet 3
[1,7,5]

Valid:

1 <= 2
7 <= 7
5 <= 5

It gives:

7 → second position
5 → third position

Now:

a = true
b = true
c = true

Therefore:

return true
7. But How Does Merging Actually Work?

We have useful triplets:

[2,5,3]
[1,7,5]

Merge them:

[2,5,3]
[1,7,5]
---------
[2,7,5]

Exactly our target!

8. Code
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets,
                       vector<int>& target) {

        bool a = false;
        bool b = false;
        bool c = false;

        for(auto &t : triplets) {

            // This triplet can make some value too large
            if(t[0] > target[0] ||
               t[1] > target[1] ||
               t[2] > target[2]) {
                continue;
            }

            // Check which target values this triplet can provide
            if(t[0] == target[0])
                a = true;

            if(t[1] == target[1])
                b = true;

            if(t[2] == target[2])
                c = true;
        }

        return a && b && c;
    }
};
9. Why Don't We Actually Merge the Triplets?

This is the important trick.

We don't need to perform the merge.

We only need to know:

Can some valid triplet give target[0]?
Can some valid triplet give target[1]?
Can some valid triplet give target[2]?

If all three are possible, then merging those triplets will produce the target.

So instead of actually merging:

[2,5,3]
[1,7,5]
...

we simply track:

a = true
b = true
c = true
10. Why This Works

Remember:

merge = maximum

Maximum can only increase values.

Therefore:

Rule 1

If:

triplet[i] > target[i]

the triplet is useless.

Because we can never decrease that value.

Rule 2

If:

triplet[i] <= target[i]

the triplet is safe.

It won't make that position too large.

Rule 3

If every target position can be reached by some safe triplet, then merging those triplets gives the target.

11. Complexity

Let n = number of triplets.

We check every triplet once.

Time Complexity:  O(n)
Space Complexity: O(1)
12. The Pattern to Remember

When you see:

Merge using maximum + need to reach exact target

Think:

Can never decrease
       ↓
Reject anything > target
       ↓
Find which triplets can provide each target position
       ↓
If all 3 positions are possible → true
Interview one-liner

Since merging uses max, any value greater than the target is permanently too large, so we ignore those triplets and simply check whether the three target values can each be obtained from the remaining valid triplets.
