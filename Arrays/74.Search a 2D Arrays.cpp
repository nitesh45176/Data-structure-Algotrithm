// LeetCode 74 : Search a 2D matrix
// Approach: Two pointers
// Time complexity : O(nm), Space: O(1)


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        for(int i=0; i<row ; i++){
        int col = matrix[i].size();
            for(int j=0; j<col ; j++){
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }
        return false;
    }
};
