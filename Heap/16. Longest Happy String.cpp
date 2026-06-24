// Leetcdoe 1405 : Longest Happy String
// Approach :  Using Heap
// TC & SC  :  O(1) , O(1)

class Solution {
public:
    typedef pair<int, char> P;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P, vector<P>> pq;

        if(a > 0){
            pq.push({a, 'a'});
        }
        if(b > 0){
            pq.push({b, 'b'});
        }
        if(c > 0){
            pq.push({c, 'c'});
        }

        string result = "" ;

        while(!pq.empty()){
            int currChar = pq.top().second;
            int currCount = pq.top().first;
            pq.pop();

            if(result.length() >= 2 && result[result.length() - 1] ==  currChar && result[result.length() - 2] ==  currChar){
                // we can't push currChar

                if(pq.empty()){
                    break;
                }
                
                int nextChar = pq.top().second;
                int nextCount = pq.top().first;
                pq.pop();

                result.push_back(nextChar);
                nextCount--;

                if(nextCount > 0){
                    pq.push({nextCount, nextChar});
                }

                pq.push({currCount, currChar});
            }else{
                currCount--;
                result.push_back(currChar);

                if(currCount > 0){
                    pq.push({currCount, currChar});
                }
            }
        }
        return result;
        
    }
};
