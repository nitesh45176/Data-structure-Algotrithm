Container With Most Water
Problem

You are given an integer array height where:

height[i]

represents the height of a vertical line at index i.

Choose two lines that together with the x-axis form a container that holds the maximum amount of water.

Example
Input:
[1,8,6,2,5,4,8,3,7]

Output:
49
Intuition

A container is formed using two vertical lines.

The amount of water it can hold depends on:

Area = Width × Height

Where:

Width = distance between the two lines

and:

Height = shorter of the two lines

Therefore:

Area = (right - left) × min(height[left], height[right])
Why Not Brute Force?

The brute-force approach would try every pair:

i = 0 → n-1
j = i+1 → n-1

This gives:

O(n²)

We can do better using two pointers.

Two Pointer Approach

Start with the widest possible container:

left = 0
right = n - 1

For every pair:

int w = j - i;
int h = min(height[i], height[j]);

int area = w * h;

Update the maximum:

maxWater = max(maxWater, area);
The Most Important Part: Which Pointer to Move?

Suppose:

height[left] = 8
height[right] = 3

The height of the container is:

min(8, 3) = 3

So the right line is limiting the amount of water.

We move the smaller-height pointer:

if(height[i] > height[j]){
    j--;
}
else{
    i++;
}
Why?

Suppose we move the taller line instead.

The width definitely decreases:

new width < old width

But the height is still limited by the shorter line.

So we cannot get a better area by moving the taller line while keeping the shorter line.

Instead, we move the shorter line, hoping to find a taller line that can increase the container height.

Key rule

Always move the pointer pointing to the shorter line.

Why Is This Greedy Movement Safe?

Suppose:

height[left] < height[right]

Current area:

(left, right)

The height is limited by:

height[left]

Now if we keep left and move right:

new width < old width

The height can never exceed height[left], because:

min(height[left], height[newRight]) <= height[left]

Therefore:

new area < old area

So keeping left cannot produce a better answer.

We can safely discard it and do:

left++;

The same logic applies when the right line is shorter.

Code Explanation
class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();

        int maxWater = 0;

        int i = 0;
        int j = n - 1;

        while(i < j) {

            // Distance between the two lines
            int w = j - i;

            // Water level is limited by the shorter line
            int h = min(height[i], height[j]);

            // Calculate current container area
            int area = w * h;

            // Store maximum area found so far
            maxWater = max(maxWater, area);

            // Move the shorter line
            if(height[i] > height[j]) {
                j--;
            }
            else {
                i++;
            }
        }

        return maxWater;
    }
};
Dry Run

Consider:

height = [1,8,6,2,5,4,8,3,7]

Initially:

i = 0
j = 8

Heights:

1                 7
↑                 ↑
i                 j
Step 1
width = 8
height = min(1,7) = 1

area = 8 × 1 = 8

Maximum:

maxWater = 8

Since 1 is smaller:

i++
Step 2
i = 1
j = 8

height[i] = 8
height[j] = 7
width = 7
height = 7

area = 7 × 7 = 49

So:

maxWater = 49

Since 7 is smaller:

j--

The algorithm continues until:

i >= j

Final answer:

49
Visual Idea

Think of the array as vertical lines:

8 |                       | 7
  |                       |
  |                       |
  |                       |
  |                       |
  |_______________________|
        width = 7

The water level is determined by the shorter line.

So:

Area = width × shorter height
Complexity
Time Complexity

Each pointer only moves from one end toward the other.

Therefore, each element is visited at most once:

O(n)
Space Complexity

Only a few variables are used:

O(1)
Brute Force vs Two Pointers
Approach	Time	Space
Brute Force — every pair	O(n²)	O(1)
Two Pointers	O(n)	O(1)
Key Pattern to Remember

For Container With Most Water:

Start with maximum width
        ↓
left = 0, right = n-1
        ↓
Calculate area
        ↓
Move the shorter line
        ↓
Repeat
Most important formula
Area = (right - left) × min(height[left], height[right])
Most important rule

The shorter line limits the water, so always move the shorter pointer.

Interview Explanation

“I use two pointers at both ends to start with the maximum possible width. For each pair, I calculate the area using the shorter height. Then I move the pointer corresponding to the shorter line because keeping that line while reducing the width cannot produce a better area. This allows both pointers to move only once across the array, giving O(n) time and O(1) space.”
