class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0;
        long right = sqrt(c);

        while(left <= right){
            long sum = left*left + right*right;

            if(c == sum) return true;

            if(c < sum) right--;

            if(c > sum) left ++;
        }
    return false;
    }
};
