
// Leetcode 160 : Intersection of Two Linked List
// Approach: Hashing
// TC and SC : O(n + m),  O(n)


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

       if(!headA || !headB)  return NULL;
        
       map<ListNode*, int> mpp;
       ListNode* temp1 = headA;

       while(temp1 != NULL){
        mpp[temp1] = 1;
        temp1 = temp1->next;
       }

       ListNode* temp2 = headB;
       while(temp2 != NULL){
         if(mpp.find(temp2) != mpp.end(){
            return temp2;
         }
         temp2 = temp2->next;
       }
       return NULL;
    }
};
