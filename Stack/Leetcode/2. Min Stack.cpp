
// Leetcode 155 :  Min Stack
// Approach :  Stack
//  Tc and SC :  O(1)  ,  O(n*n)


class MinStack {
private:
      stack<pair<int, int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) st.push({val,val});
        else{
            st.push({val, min(val, st.top().second)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
       return st.top().first;
    }
    
    int getMin() {
      return  st.top().second ;
    }
};
