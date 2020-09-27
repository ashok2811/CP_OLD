/*
Odd Even Linked List

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==NULL || head->next == NULL) return head;  // Atleast 2 elements
        
        ListNode* odd = head; // Start Odd
        ListNode* even = head->next; // Start Even
        ListNode* temp = even;
        
        while(odd->next!=NULL && even->next!=NULL){   
            
            if(odd->next==NULL) {odd->next = temp ; break;}
            odd->next = even->next;          
            odd = odd->next;
           
            even->next = odd-> next ; 
            even = even->next; 
            if(even==NULL || even->next==NULL) {odd->next= temp ; break;}
            
        }       
        
        
        return head;
    }
};