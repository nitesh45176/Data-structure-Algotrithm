
// Leetcode  739: Daily temperatures
// Approach : Stack
// Tc and SC: O(n)  ,  S(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> days(n,0);
        stack<int> st;
        
        for(int i=0; i<n; i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                int idx = st.top();
                days[idx] = i - idx;
                st.pop();
            }
            st.push(i);
        }
        return days;
    }
};
