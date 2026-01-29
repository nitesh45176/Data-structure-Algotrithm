
// Leetcode 160 : Intersection of Two Linked List
// Approach: Two pointers
// TC and SC : O(n + m),  O(1)


class Solution {
public:
    ListNode* collisionPoint(ListNode* t1, ListNode* t2, int d) {
        while (d--) {
            t2 = t2->next;
        }
        while (t1 != t2) {
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL) return NULL;  
        
        ListNode* temp1 = headA;
        int N1 = 0;
        ListNode* temp2 = headB;
        int N2 = 0;

        while (temp1 != NULL) {
            N1++;
            temp1 = temp1->next;
        }
        while (temp2 != NULL) {
            N2++;
            temp2 = temp2->next;
        }

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        if (N1 < N2) {
           return collisionPoint(t1, t2, N2 - N1);
        } else {
           return collisionPoint(t2, t1, N1 - N2);
        }
     
    }
};
