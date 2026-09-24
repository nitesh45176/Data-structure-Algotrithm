Spiral Matrix — LeetCode 54
1. Problem

Given a matrix, return all its elements in spiral order.

Example:

1  2  3
4  5  6
7  8  9

Spiral order:

1 → 2 → 3 → 6 → 9 → 8 → 7 → 4 → 5
2. Main Idea

Instead of visiting elements randomly, maintain 4 boundaries:

int rowBegin = 0;
int rowEnd = matrix.size() - 1;

int colBegin = 0;
int colEnd = matrix[0].size() - 1;

These represent the current unvisited rectangle:

rowBegin
   ↓
1  2  3  4  ← colEnd
5  6  7  8
9 10 11 12
   ↑
 rowEnd

We repeatedly traverse:

Right → Down → Left → Up

After each traversal, we shrink the corresponding boundary.

3. Four Boundaries
rowBegin

Topmost unvisited row.

rowBegin++;

After traversing the top row, move it down.

rowEnd

Bottommost unvisited row.

rowEnd--;

After traversing the bottom row, move it up.

colBegin

Leftmost unvisited column.

colBegin++;

After traversing the left column, move it right.

colEnd

Rightmost unvisited column.

colEnd--;

After traversing the right column, move it left.

4. Step 1 — Traverse Right
for(int i = colBegin; i <= colEnd; i++){
    res.push_back(matrix[rowBegin][i]);
}
rowBegin++;

We move across the top row:

→ → →

Example:

1  2  3
4  5  6
7  8  9

Take:

1 2 3

Then:

rowBegin++;

because that row has been completely processed.

5. Step 2 — Traverse Down
for(int i = rowBegin; i <= rowEnd; i++){
    res.push_back(matrix[i][colEnd]);
}
colEnd--;

Now move down the rightmost column:

1  2  3
      ↓
4  5  6
      ↓
7  8  9
      ↓

We add:

6 9

Then:

colEnd--;

because the rightmost column is processed.

6. Step 3 — Traverse Left
if(rowBegin <= rowEnd){
    for(int i = colEnd; i >= colBegin; i--){
        res.push_back(matrix[rowEnd][i]);
    }
}
rowEnd--;

Now move from right to left across the bottom row:

7 ← 8 ←

For the example:

1 2 3
4 5 6
7 8 9

we add:

8 7

Notice the indexing:

matrix[rowEnd][i]

because:

rowEnd is fixed
i changes across columns

Then:

rowEnd--;
7. Step 4 — Traverse Up
if(colBegin <= colEnd){
    for(int i = rowEnd; i >= rowBegin; i--){
        res.push_back(matrix[i][colBegin]);
    }
}
colBegin++;

Now move up along the leftmost column:

↑
4

For our example, we add:

4

Then:

colBegin++;

because that column has been processed.

8. Why Do We Need the if Conditions?

These are important:

if(rowBegin <= rowEnd)

and

if(colBegin <= colEnd)

Consider a matrix with only one row:

1 2 3 4

After traversing right:

1 2 3 4

we have:

rowBegin > rowEnd

So we should not try to traverse left again.

Otherwise, we could add elements twice.

Similarly, for a single-column matrix, we don't want to traverse up after the column has already been processed.

9. Why Does the while Loop Stop?
while(rowBegin <= rowEnd && colBegin <= colEnd)

We continue only while there are still unvisited rows and columns.

Eventually:

rowBegin > rowEnd

or:

colBegin > colEnd

which means there is nothing left to process.

10. Complete Code
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> res;

        if(matrix.empty()){
            return res;
        }

        int rowBegin = 0;
        int rowEnd = matrix.size() - 1;

        int colBegin = 0;
        int colEnd = matrix[0].size() - 1;

        while(rowBegin <= rowEnd && colBegin <= colEnd){

            // Traverse Right
            for(int i = colBegin; i <= colEnd; i++){
                res.push_back(matrix[rowBegin][i]);
            }
            rowBegin++;

            // Traverse Down
            for(int i = rowBegin; i <= rowEnd; i++){
                res.push_back(matrix[i][colEnd]);
            }
            colEnd--;

            // Traverse Left
            if(rowBegin <= rowEnd){
                for(int i = colEnd; i >= colBegin; i--){
                    res.push_back(matrix[rowEnd][i]);
                }
            }
            rowEnd--;

            // Traverse Up
            if(colBegin <= colEnd){
                for(int i = rowEnd; i >= rowBegin; i--){
                    res.push_back(matrix[i][colBegin]);
                }
            }
            colBegin++;
        }

        return res;
    }
};
11. The Most Important Part to Remember

Memorize these 4 traversals:

// Right
matrix[rowBegin][i]

// Down
matrix[i][colEnd]

// Left
matrix[rowEnd][i]

// Up
matrix[i][colBegin]

And the boundaries move like this:

Right → rowBegin++
Down  → colEnd--
Left  → rowEnd--
Up    → colBegin++

So the complete pattern is:

        RIGHT →
   ┌─────────────┐
   │             ↓
   │             DOWN
   ↑             │
   │             │
   └─────────────┘
        ← LEFT
12. Complexity

For an m × n matrix:

Time Complexity:  O(m × n)
Space Complexity: O(m × n)

The O(m × n) space is for the returned res vector.

The algorithm itself uses only:

O(1)

extra working space.

Key Takeaway

Spiral Matrix = Maintain 4 boundaries and repeatedly traverse Right → Down → Left → Up, shrinking one boundary after each traversal.

This is the main pattern you should remember for spiral matrix problems.
