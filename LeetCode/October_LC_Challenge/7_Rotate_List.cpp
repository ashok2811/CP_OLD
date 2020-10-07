// Rotate List
// Given a linked list, rotate the list to the right by k places, where k is non-negative.

// Example 1:
// Input: 1->2->3->4->5->NULL, k = 2
// Output: 4->5->1->2->3->NULL
// Explanation:
// rotate 1 steps to the right: 5->1->2->3->4->NULL
// rotate 2 steps to the right: 4->5->1->2->3->NULL

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

// Key : Convert int a circular LL and then break at desired position.
class Solution {

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            //Corner case
            return NULL;
        }
        
        int n = 1 ; // To count no of elements in the list;
        ListNode* temp = head;
        while(temp!= NULL &&  temp->next!=NULL) {
            temp=temp-> next;
            n++;
        }
              
        k%=n;
       
        temp->next = head;
        for(int i= 0 ; i<n - k ; i++){
            temp=temp-> next; 
        }
        
         ListNode* newHead = temp-> next ;
         temp-> next = NULL;
        
        return newHead;
    }
};