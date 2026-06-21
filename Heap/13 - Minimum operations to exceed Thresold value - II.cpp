// Leetcode 2530 : Minimum operations to exceed Thresold value - II
// Approach :- Heap
// TC, SC :- O(nlogn), O(n)


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long> , greater<long long>> pq(begin(nums), end(nums));

        int count = 0;

        while(!pq.empty() && pq.top() < k){
            long long smallest = pq.top();
            pq.pop();

            long long secSmallest = pq.top();
            pq.pop();

            pq.push(smallest * 2 + secSmallest);

            count ++;
        }

        return count;
    }
};
