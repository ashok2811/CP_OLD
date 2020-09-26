/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.


*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1); //make a fake head node
        ListNode* ans_head = ans ; // pointer to this node
        int carry  =0 ;  // Initial Carry
        while(l1!=NULL || l2!=NULL || carry){ // Carry only case too
            int curr_sum = 0;
            
            if(l1!=NULL){ //If list 1 is not NULL
                curr_sum += l1->val;
                l1 = l1->next ;    // Move to next element
            }
              if(l2!=NULL){  //If list 2 is not NULL
                curr_sum += l2->val; 
                l2 = l2->next ;  // Move to next element
            }
            
            // Make a new node and store the value in it . 
            ans->next  = new ListNode( (carry + curr_sum)%10); // Next element in our fake node is the digit to be inserted
            carry = (carry + curr_sum)/10;  // update the carry
            
            ans = ans->next ; // move pointer to next
            
        }
        
        return ans_head->next; // Return address next to our fake head node
    }
};