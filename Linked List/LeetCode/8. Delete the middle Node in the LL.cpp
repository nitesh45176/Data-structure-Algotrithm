
//leetCode 2095 : Delete the middle Node in the LL
//Approach : skipping the duplicate part
//Time and Space Complexity: O(N)  , O(1)


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next==NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* previousOfSlow = head;

        while(fast != NULL && fast->next != NULL){
            previousOfSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        previousOfSlow->next = slow->next;
    
    return head;
    }
};
