class Solution {
public:
    bool checkDivisibility(int n) {
        int s = 0;
        int p = 1;

        for(int x=n; x>0; x/=10){
            int r = x%10;
            s+=r;
            p*=r;
        }

    return n%(p+s) == 0;
    }
};
