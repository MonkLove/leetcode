/* Rotate List
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(k <= 0 || head == NULL)
        return head;
        
    int len = 1;
    struct ListNode *curNode = head;
    
    /* Get length of list; */
    while(curNode->next != NULL){
        ++len;
        curNode = curNode->next;
    }
    
    if(k > len)
        k = k % len;
    
    curNode->next = head;
    int i;
    for(i = 0; i < len - k; ++i){
        curNode = curNode->next;
    }
    head = curNode->next;
    curNode->next = NULL;
    
    return head;
}