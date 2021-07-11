/*
* Given a singly linked list A
* A: A0 → A1 → … → An-1 → An 
* reorder it to:
* A0 → An → A1 → An-1 → A2 → An-2 → … 
* You must do this in-place without altering the nodes' values. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    ListNode *tail, *mid;
    ListNode *temp, *ntemp, *prev;
    bool odd=false, even=false;
    temp = A;
    ntemp = A;
    while(true) {
        if (ntemp->next==NULL) {
            odd=true;
            mid=temp;
            //cout << "Mid: " << mid->val << endl;
            tail=ntemp;
            //cout << "Its odd" << endl;
            break;
        } else if (ntemp->next->next==NULL) {
            even=true;
            mid=temp;
            //cout << "Mid: " << mid->val << endl;
            tail=ntemp->next;
            //cout << "Its even" << endl;
            break;
        } else {
            temp = temp->next;
            ntemp=ntemp->next->next;
        }
    }
    if (tail==A) return A;
    temp = mid->next;
    prev = mid;
    while(temp!=NULL) {
        ntemp = temp->next;
        temp->next = prev;
        prev = temp;
        temp = ntemp;
    }
    ListNode *nst, *ne, *st, *e;
    st = A;
    e = tail;
    while(true) {
        nst = st->next;
        ne = e->next;
        //cout << "Start: " << st->val << endl;
        //cout << "End: " << e->val << endl;
        st->next = e;
        if (odd) {
            e->next = nst;
            if (nst==ne) {
                nst->next = NULL;
                break;
            }
        } else {
            if (st!=mid) {
                //cout << "Coming here" << endl;
                e->next = nst;
            } else {
                //cout << "Coming here to end" << endl;
                e->next = NULL;
                break;
            }
        }
        st = nst;
        e = ne;
    }
    return A;
}
