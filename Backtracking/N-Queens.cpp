
// Leetcode 51 : N-Queens
// Approach : R  Recursion & Backtracking
// TC, SC :-  o(n) , o(n)



class Solution {
public:

 bool isSafe(vector<string> &board, int row, int col, int n){

    for(int j=0; j<n; j++){
        if(board[row][j] == 'Q'){
            return false;
        }
    }

    for(int i=0; i<n; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }
    
    // left diagonal
    for(int i=row,j=col; j>=0 && i>=0; j-- ,i--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    // right diagonal
    for(int i=row,j=col; j<n && i>=0; j++ , i--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
 }

    void solve(vector<string> &board,int row, int n, vector<vector< string>> &ans){
       // baase case
       if(row == n){
        ans.push_back({board});
        return;
       }

       for(int j=0; j<n; j++){
            if(isSafe(board, row, j, n)){
            board[row][j] = 'Q';
            solve(board, row+1, n, ans);
            // backtrack
            board[row][j] = '.';
            }
        }

   
   }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector< string>> ans;

        solve(board, 0, n, ans);
        return ans;
    }
};
