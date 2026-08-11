class Solution {
public:
    void f(int i, int target, vector<int> &arr, vector<vector<int>>& ans, vector<int>& ds){
    if(i == arr.size()){
        if(target == 0){
            ans.push_back(ds);
        }
        return;
    }


    if(arr[i] <= target){   // take
        ds.push_back(arr[i]);
        f(i, target-arr[i], arr , ans, ds);
        ds.pop_back();
    }  
    f(i+1,target, arr, ans, ds);      // not take
    
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        f(0, target, candidates, ans, ds);
        return ans;
    }
};
