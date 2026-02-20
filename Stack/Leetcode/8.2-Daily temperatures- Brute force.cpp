
// Leetcode  739: Daily temperatures
// Approach : Arrays
// Tc and SC: O(n*n)  ,  S(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> days(temperatures.size(),0);

        for(int i=0; i<temperatures.size(); i++){
            for(int j=i+1; j<temperatures.size(); j++){
                int currTemp = temperatures[i];

                if(currTemp < temperatures[j]){
                    days[i] = j - i;
                    break;
                }
            }
        }
        return days;
    }
};
