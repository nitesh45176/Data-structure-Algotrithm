
// Leetcdoe 3170 : Lexicographically Minimum String After Removing Stars
// Approach :  Using Heap
// TC & SC  :  O(nlogn) , O(n)


class Solution {
public:
    typedef pair<char, int> P;

    struct comp {
        bool operator()(P& p1, P& p2) {
            if (p1.first == p2.first) {
                return p1.second < p2.second;
            } else {
                return p1.first > p2.first;
            }
        }
    };
     string clearStars(string s) {
        priority_queue<P, vector<P>, comp> pq;

        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                pq.push({s[i], i});
            } else {
                int idx = pq.top().second;
                pq.pop();
                s[idx] = '*';
            }
        }
        string result = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                result.push_back(s[i]);
            }
        }

        return result;
    }
};
