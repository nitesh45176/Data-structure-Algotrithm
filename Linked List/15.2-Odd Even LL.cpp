

// Leetcode 328 : Odd Even LL
// Approach: Two pointers
// TC and SC : O(n),  O(1)



class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;

        while(even != NULL && even->next != NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
