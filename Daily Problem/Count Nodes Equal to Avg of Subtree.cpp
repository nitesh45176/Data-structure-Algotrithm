Average of Subtree — Brute Force & Optimized Approach
1. Problem

Given a binary tree, for every node we need to check whether:

average of all nodes in its subtree == value of the node

If yes, count that node.

Return the total number of such nodes.

What is a subtree?

For any node, its subtree consists of:

The node itself
All nodes in its left subtree
All nodes in its right subtree

For example:

        4
       / \
      8   5
     / \   \
    0   1   6

The subtree of 8 is:

      8
     / \
    0   1

The subtree of 5 is:

    5
     \
      6

The subtree of 4 is the entire tree.

2. What Do We Need to Calculate?

For every node, we need two things:

1. Sum of all nodes in its subtree
2. Number of nodes in its subtree

Then:

average = sum / count

If:

average == node->val

then increase the answer.

3. Brute Force Approach

The brute-force idea is:

For every node, independently calculate the sum and count of its entire subtree.

We use two recursive functions.

solve()

Visits every node one by one.

sum()

For a given node, calculates:

sum of subtree
+
number of nodes in subtree

So the flow is:

solve(node)
     ↓
sum(node)
     ↓
calculate sum + count
     ↓
calculate average
     ↓
check node
     ↓
solve(left)
solve(right)
4. Understanding sum()

Your function:

int sum(TreeNode* root, int& count)

returns the sum of the subtree.

But it also updates count.

So it actually gives us two pieces of information:

return value → subtree sum
count        → number of nodes
Base Case
if(root == NULL){
    return 0;
}

If there is no node:

sum = 0

There is also no need to increase count.

Count Current Node
count++;

Whenever sum() reaches a real node, we count it.

For example:

      8
     / \
    0   1

When sum(8) finishes:

count = 3
Calculate Left and Right Sums
int l = sum(root->left, count);
int r = sum(root->right, count);

l contains:

sum of left subtree

r contains:

sum of right subtree
Return Total Sum
return l + r + root->val;

So:

total sum =
left subtree sum
+
right subtree sum
+
current node
5. Example of sum()

Consider:

        8
       / \
      0   1

Call:

sum(8, count)

Initially:

count = 0

At node 8:

count = 1

Go left:

0
count = 2

Return:

sum = 0

Go right:

1
count = 3

Return:

sum = 1

Now at node 8:

l = 0
r = 1
root->val = 8

Therefore:

total sum = 0 + 1 + 8
          = 9

count = 3

So:

sum(8) → 9
count  → 3

Average:

9 / 3 = 3

Since:

3 != 8

node 8 is not counted.

6. Understanding solve()

Now look at:

void solve(TreeNode* root){
    if(root == NULL){
        return;
    }

    int count = 0;
    int totSum = sum(root, count);

    if(totSum / count == root->val){
        result += 1;
    }

    solve(root->left);
    solve(root->right);
}

This function is responsible for checking every node.

Step 1 — Base Case
if(root == NULL){
    return;
}

If there is no node, there is nothing to check.

Step 2 — Create Count
int count = 0;

For the current node, we start counting its subtree from zero.

This is important because every node gets its own fresh count.

Step 3 — Calculate Subtree Sum
int totSum = sum(root, count);

After this line:

totSum = sum of current subtree
count  = number of nodes in current subtree
Step 4 — Calculate Average
if(totSum / count == root->val)

We calculate:

average = total sum / total count

Then compare it with the current node.

If equal:

result += 1;
Step 5 — Process Children
solve(root->left);
solve(root->right);

After checking the current node, we recursively check:

left subtree
right subtree

Therefore, every node is eventually processed.

7. Understanding the Whole Code
class Solution {
public:
    int result;

    int sum(TreeNode* root, int& count) {
        if(root == NULL) {
            return 0;
        }

        count++;

        int l = sum(root->left, count);
        int r = sum(root->right, count);

        return l + r + root->val;
    }

    void solve(TreeNode* root) {
        if(root == NULL) {
            return;
        }

        int count = 0;

        int totSum = sum(root, count);

        if(totSum / count == root->val) {
            result += 1;
        }

        solve(root->left);
        solve(root->right);
    }

    int averageOfSubtree(TreeNode* root) {
        result = 0;

        solve(root);

        return result;
    }
};
8. Complete Dry Run

Consider:

        4
       / \
      8   5
     / \   \
    0   1   6

We start:

result = 0
Node 4

solve(4) calls:

sum(4, count)

The entire tree is traversed.

sum = 4 + 8 + 5 + 0 + 1 + 6
    = 24

count = 6

Average:

24 / 6 = 4

Current node:

4

Therefore:

4 == 4

Count it.

result = 1
Node 8

Now:

solve(8)

sum(8) traverses:

      8
     / \
    0   1

Therefore:

sum = 9
count = 3

average = 9 / 3
        = 3

But:

3 != 8

So:

result = 1
Node 0

Subtree:

0

Therefore:

sum = 0
count = 1

average = 0 / 1
        = 0

So:

0 == 0

Count it.

result = 2
Node 1
sum = 1
count = 1

average = 1

So:

1 == 1

Count it.

result = 3
Node 5

Subtree:

    5
     \
      6
sum = 11
count = 2

average = 11 / 2
        = 5

Because C++ integer division gives 5.

So:

5 == 5

Count it.

result = 4
Node 6
sum = 6
count = 1

average = 6

So:

6 == 6

Count it.

result = 5

Final answer:

5
9. Why Is This Brute Force?

Look at what happens with node 4.

To calculate its sum, we visit:

4, 8, 0, 1, 5, 6

Then when we process node 8, we again visit:

8, 0, 1

Then for node 0:

0

And so on.

So we repeatedly calculate information about the same subtrees.

For example:

For node 4 → calculate subtree of 8
For node 8 → calculate subtree of 8 again

That repeated work makes this approach inefficient.

10. Optimized Approach

We can avoid recalculating the subtree.

Instead of:

For every node
      ↓
Traverse its entire subtree

we use:

Children calculate their information
              ↓
         Give it to parent
              ↓
Parent combines the information

For every node, return:

{sum, count}

For example:

        8
       / \
      0   1

Node 0 returns:

{0, 1}

Node 1 returns:

{1, 1}

Then node 8 calculates:

sum = 0 + 1 + 8 = 9
count = 1 + 1 + 1 = 3

and returns:

{9, 3}

The parent can directly use {9,3} without traversing 8's subtree again.

11. Optimized Code
class Solution {
public:
    int result;

    pair<int,int> solve(TreeNode* root) {
        if(root == NULL) {
            return {0, 0};
        }

        auto left = solve(root->left);
        auto right = solve(root->right);

        int totSum = left.first + right.first + root->val;
        int totCnt = left.second + right.second + 1;

        int avg = totSum / totCnt;

        if(avg == root->val) {
            result++;
        }

        return {totSum, totCnt};
    }

    int averageOfSubtree(TreeNode* root) {
        result = 0;

        solve(root);

        return result;
    }
};
12. Why Is Optimized Code Faster?
Brute Force
Node 4
 ↓
Traverse entire subtree

Node 8
 ↓
Traverse subtree again

Node 0
 ↓
Traverse subtree again

Same nodes may be visited many times.

Optimized
Node 0 → {0,1}
Node 1 → {1,1}
       ↓
Node 8 → {9,3}
       ↓
Node 4 uses {9,3}

Every node calculates its information once.

13. Complexity

Let n = number of nodes.

Brute Force

In the worst case:

Time: O(n²)
Space: O(h)

where h is the height of the tree.

Optimized

Every node is processed once:

Time: O(n)
Space: O(h)

For a balanced tree:

h = O(log n)

For a skewed tree:

h = O(n)
14. Brute Force vs Optimized
	Brute Force	Optimized
Main idea	Recalculate each subtree	Calculate once and pass upward
Sum calculation	Repeated	Once
Count calculation	Repeated	Once
Traversal	Repeated subtree traversals	Postorder
Time	O(n²) worst case	O(n)
Space	O(h)	O(h)
Technique	DFS + repeated calculation	Postorder / Tree DP
15. Key Pattern to Remember ⭐

The brute-force pattern is:

For every node:
    calculate its complete subtree
    check condition

The optimized pattern is:

Go to children
    ↓
Get information from children
    ↓
Calculate current node's information
    ↓
Return information to parent

For this problem, the information is:

{sum, count}

So the most important idea is:

If every node needs information about its subtree, try calculating that information bottom-up and returning it to the parent instead of recalculating the subtree for every node.
