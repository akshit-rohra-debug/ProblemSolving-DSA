/*
* Given a singly linked list A, determine if its a palindrome.
* Return 1 or 0 denoting if its a palindrome or not, respectively. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseSubList(ListNode* root, ListNode* bRoot, int n) {
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
    tail->next = bRoot;
    return prev;
}

int Solution::lPalin(ListNode* A) {
    if (A==NULL) return 1;
    ListNode* slow_pointer = A;
    ListNode* fast_pointer = A;
    ListNode* prev = NULL;
    int mid_counter = 0;
    while(true) {
        if (fast_pointer==NULL) {
            break;
        }
        if (fast_pointer->next==NULL) {
            mid_counter++;
            break;
        }
        if (fast_pointer->next!=NULL) {
            fast_pointer = fast_pointer->next->next;
            prev = slow_pointer;
            slow_pointer = slow_pointer->next;
            mid_counter++;
            continue;
        }
    }
    ListNode* mid = slow_pointer;
    ListNode* end = reverseSubList(mid, prev, mid_counter);
    ListNode* start = A;
    while(start!=mid) {
        if (start->val!=end->val) return 0;
        start=start->next;
        end=end->next;
    }
    return 1;
}
