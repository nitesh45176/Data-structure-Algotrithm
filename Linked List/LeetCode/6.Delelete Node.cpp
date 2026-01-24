// Leetcode 237 : Delete  Node in Linked List
// Approach : Deleting node's next value and skip that node's next
// Time and sppace complexity:  O(1) , O(1)

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;

        }
    
};
