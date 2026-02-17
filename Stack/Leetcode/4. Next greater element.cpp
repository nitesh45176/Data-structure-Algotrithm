
// leetcode 496: Next greater element
//Approach: Using stack and map


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        vector<int> res(n1);
        unordered_map<int, int> map;
        stack<int> st;

        for(int i=0; i<nums2.size(); i++){
            while(!st.empty() && st.top() < nums2[i]){
                map[st.top()] =  nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        while(!st.empty()){
            map[st.top()] = -1;
            st.pop();
        }
        for(int i=0; i<nums1.size(); i++){
            res[i] = map[nums1[i]];
        }
        return res;
    }
};
