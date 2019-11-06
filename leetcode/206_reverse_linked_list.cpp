/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Iterative
        /*
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        
        ListNode* tail = head;
        ListNode* before = head;
        ListNode* after = head->next;
        
        while(after->next != NULL)
        {
            head->next = before;
            before = head;
            head = after;
            after = after->next;
        }
        
        // end case
        head->next = before;
        after->next = head;
        head = after;
        tail->next = NULL;
        
        tail = NULL;
        before = NULL;
        after = NULL;
        
        delete tail;
        delete before;
        delete after;
        
        return head;
        */
        
        //Recursive
        if (head == NULL || head->next == NULL) return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};