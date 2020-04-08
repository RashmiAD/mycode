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
    ListNode* middleNode(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        if(head->next == NULL)
            return head;
        
        ListNode* slow_itr = head;
        ListNode* fast_itr = head;
        
        while(fast_itr->next != NULL)
        {
            slow_itr = slow_itr->next;
            if(fast_itr->next->next == NULL)
                fast_itr = fast_itr->next;
            else
                fast_itr = fast_itr->next->next;
        }
        
        return slow_itr;
    }
};


// Another solution
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        if(head->next == NULL)
            return head;
        
        ListNode* slow_itr = head;
        ListNode* fast_itr = head;
        
        while(fast_itr != NULL && fast_itr->next != NULL && fast_itr->next->next != NULL)
        {
            slow_itr = slow_itr->next;
            fast_itr = fast_itr->next->next;   
        }
        
        return fast_itr->next == NULL ? slow_itr : slow_itr->next;
    }
};
