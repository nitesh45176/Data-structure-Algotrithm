
//leetCode 61 :  Rotate LL
//Approach : Traversing the list
//Time and Space Complexity: O(N)  , O(1)



class Solution {
public:
    ListNode* findNthNode(ListNode* temp, int k) {
        int cnt = 1;
        while (cnt < k && temp != NULL) {
            temp = temp->next;
            cnt++;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tail = head;
        int len = 1;

        if (head == NULL || head->next == NULL || k == 0)
            return head;

        while (tail->next != NULL) {
            tail = tail->next;
            len += 1;
        }

        k = k % len;
        if (k == 0)
            return head;

        tail->next = head;
        ListNode* newLastNode = findNthNode(head, len - k);
        head = newLastNode->next;
        newLastNode->next = NULL;

        return head;
    }
};
