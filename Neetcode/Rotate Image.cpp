Rotate Image — LeetCode 48
    
1. Problem
Given an n × n matrix, rotate it 90° clockwise.

Example:
1 2 3
4 5 6
7 8 9

After rotating 90° clockwise:

7 4 1
8 5 2
9 6 3

We need to do this in-place, meaning we should modify the original matrix without creating another matrix.

2. Main Idea

A 90° clockwise rotation can be done in 2 simple steps:

Step 1 → Transpose the matrix
Step 2 → Reverse every row

So remember:

90° Clockwise Rotation = Transpose + Reverse Each Row

3. Step 1 — Transpose the Matrix

Transpose means:

Convert rows into columns.

For example:

1 2 3
4 5 6
7 8 9

After transpose:

1 4 7
2 5 8
3 6 9

Notice:

matrix[i][j] ↔ matrix[j][i]

So we swap:

swap(matrix[i][j], matrix[j][i]);
4. Why Do We Start j From i?

Your code:

for(int i = 0; i < m; i++){
    for(int j = i; j < n; j++){
        swap(matrix[i][j], matrix[j][i]);
    }
}

The important part is:

j = i

We only need to swap the upper triangle of the matrix.

For example:

X  X  X
   X  X
      X

Why?

Because swapping both sides would undo the transpose.

For example, if we first do:

swap(matrix[0][1], matrix[1][0]);

and later do:

swap(matrix[1][0], matrix[0][1]);

we would simply get the original matrix back.

Therefore, each pair is swapped only once.

5. Dry Run of Transpose

Original:

1 2 3
4 5 6
7 8 9
i = 0

j = 0

swap(0,0)

No change.

j = 1

swap(matrix[0][1], matrix[1][0])
2 ↔ 4

Matrix:

1 4 3
2 5 6
7 8 9

j = 2

3 ↔ 7

Matrix:

1 4 7
2 5 6
3 8 9
i = 1

j = 1

Diagonal element, no change.

j = 2

6 ↔ 8

Matrix becomes:

1 4 7
2 5 8
3 6 9

Now we have the transpose.

6. Step 2 — Reverse Every Row

Now:

1 4 7
2 5 8
3 6 9

We reverse each row:

for(int i = 0; i < n; i++){
    reverse(matrix[i].begin(), matrix[i].end());
}

Row 1:

1 4 7
↓
7 4 1

Row 2:

2 5 8
↓
8 5 2

Row 3:

3 6 9
↓
9 6 3

Final:

7 4 1
8 5 2
9 6 3

This is the required 90° clockwise rotation.

7. Complete Code
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = m;

        // Step 1: Transpose the matrix
        for(int i = 0; i < m; i++){
            for(int j = i; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse every row
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
8. Why Does Transpose + Reverse Work?

Let's look at one element.

Suppose:

1

is at:

row = 0, column = 0

After transpose:

(row, column) → (column, row)

Then reversing the row moves it to its final position for a 90° clockwise rotation.

The combination:

Transpose
   ↓
Reverse rows
   ↓
90° clockwise rotation

is a standard matrix rotation technique.

9. Complexity
Time

Transpose:

O(n²)

Reverse every row:

O(n²)

Total:

O(n²)
Space

We don't create another matrix.

O(1) extra space
10. Key Takeaway

For 90° clockwise rotation, remember:

        Matrix
          ↓
      Transpose
          ↓
    Reverse each row
          ↓
    90° Clockwise
One-line interview answer

To rotate a matrix 90° clockwise in-place, first transpose it by swapping matrix[i][j] with matrix[j][i], then reverse every row.

Pattern to memorize:

Clockwise 90°  → Transpose + Reverse Rows
Anti-clockwise 90° → Transpose + Reverse Columns
