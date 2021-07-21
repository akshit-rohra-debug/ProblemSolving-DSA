/*
* Given a singly linked list A and an integer B, reverse the nodes of
* the list B at a time and return modified linked list.
* 
* Input:	A = [1, 2, 3, 4, 5, 6]
* 		B = 3
* Output:	[3, 2, 1, 6, 5, 4]		
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverseSubList(ListNode* root, int n) {
    if (root==NULL) return NULL;
    ListNode* tail = root;
    ListNode* prev = NULL;
    ListNode* next = root->next;
    ListNode* curr = root;
    int i=0;
    while(i<n) {
        curr->next = prev;
        prev = curr;
        curr = next;
        if (curr!=NULL) {
            next = curr->next;
        } else {
            break;
        }
        i++;
    }
    tail->next = curr;
    return prev;
}

ListNode* Solution::reverseList(ListNode* A, int B) {
    int i=0;
    ListNode* temp = A;
    while(temp!=NULL) {
        if (i%B==0) {
            if (i==0) {
                A = reverseSubList(A,B);
                i++;
                temp = A;
                continue;
            } else {
                temp->next = reverseSubList(temp->next, B);    
            }
        }
        temp = temp->next;
        i++;
    }
    return A;
}
