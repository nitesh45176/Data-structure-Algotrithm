class Solution {
public:
    void f(int i, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds){
            int n = nums.size();
            if(i == n){
                ans.push_back(ds);
                return;
            }

       
            ds.push_back(nums[i]);
            f(i+1, nums, ans, ds);
            ds.pop_back();

            int j = i+1;
            while(j < n && nums[i] == nums[j]){
                j++;
            }
            f(j, nums, ans, ds);
        
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;

        f(0, nums, ans, ds);
        return ans;
    }
};
