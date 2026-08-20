class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1;
        vector<int> arr2;

        int n1=0, n2=0;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int i=2; i<n; i++){
            if(arr1.back() > arr2.back()){
                arr1.push_back(nums[i]);
            }
            else{
                arr2.push_back(nums[i]);
            }
        }
    vector<int> result(n);
    int k=0;
    for(auto x: arr1){
        result.push_back(arr1[n1]);
    }
    for(auto x: arr2){
        result.push_back(arr2[n2]);
    }
    return result;
    }
};
