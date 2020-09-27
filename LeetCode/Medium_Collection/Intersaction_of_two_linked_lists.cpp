/*
Intersection of Two Linked Lists
Easy
Write a program to find the node at which the intersection of two singly linked lists begins.
*/


// O(n+m) Time  , O(1) Space;

int len(ListNode *temp){ // A function to return length
    int count = 0;
    if(temp==NULL) return 0;    
    while(temp!=NULL){ temp = temp-> next ;
        count++;
    }
    return count;
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int lenA = len(headA);  // Getting Lengths
        int lenB = len(headB);
        
        if(lenB>lenA){  // Swap if B has greater length
            ListNode* temp1= headA;
            headA= headB;
            headB=temp1;
        }
        
        int diff = abs(lenA - lenB) ; // Store the difference
        
      // iterate over the bigger list untill they hay of equal length.
        for(int i = 0 ; i<diff ; i++) 
            headA = headA->next;
               
       while(headA !=NULL){ 
           if(headA == headB) return headA; //Return pointer to the node of intersaction
           headA=headA->next;
           headB=headB->next;
       }
        return NULL;
    }
};