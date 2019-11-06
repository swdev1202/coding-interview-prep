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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return NULL;
        
        if(l1 == NULL && l2 != NULL) return l2;
        if(l1 != NULL && l2 == NULL) return l1;
        
        // initial listnode construction
        bool leading_one = false;
        
        // add the value
        int digit_sum = l1->val + l2->val;
        if(digit_sum >= 10){
            leading_one = true;
            digit_sum -= 10;
        }
        else{
            leading_one = false;
        }
        
        ListNode* result = new ListNode(digit_sum);
        ListNode* result_head = result;
        
        l1 = l1->next;
        l2 = l2->next;
        
        while(l1 != NULL && l2 != NULL){
            // add the value
            int digit_sum = l1->val + l2->val;
            if(leading_one) digit_sum++;
            
            if(digit_sum >= 10){
                leading_one = true;
                digit_sum -= 10;
            }
            else{
                leading_one = false;
            }
            
            result->next = new ListNode(digit_sum);
            l1 = l1->next;
            l2 = l2->next;
            result = result->next;
        }
        
        if(l1 == NULL && l2 != NULL){
            while(l2 != NULL){
                int sum = l2->val;
                if(leading_one) sum++;
                
                if(sum >= 10){
                    leading_one=true;
                    sum -=10;
                }
                else{
                    leading_one = false;
                }
                
                result->next = new ListNode(sum);
                l2 = l2->next;
                result = result->next;
            }
        }
        else if(l1 != NULL && l2 == NULL){
            while(l1 != NULL){
                int sum = l1->val;
                if(leading_one) sum++;
                
                if(sum >=10){
                    leading_one=true;
                    sum -= 10;
                }
                else{
                    leading_one = false;
                }
                
                result->next = new ListNode(sum);
                l1 = l1->next;
                result = result->next;
            }
        }
        
        if(leading_one) result->next = new ListNode(1);
        
        return result_head;
    }
};