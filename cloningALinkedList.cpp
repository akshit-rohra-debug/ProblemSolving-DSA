/*
* Given a doubly linked list of integers with one pointer of each node pointing
* to the next node (just like in a single link list) while the second pointer,
* however, can point to any node in the list and not just the previous node.
* 
* You have to create a copy of this list and return the head pointer of the duplicated list.
*/

/*
struct ListNode { 
    int val; 
    ListNode *next,*random; 
    ListNode(int x) { 
        val = x; 
        next = random = NULL; 
    } 
}; 
*/

ListNode* clonelist(ListNode *A) {
    unordered_map<ListNode*, ListNode*> hmap;
    // Create a list with just next variables
    if (A==NULL) return NULL;
    ListNode* myRoot=NULL;
    ListNode* org=A;
    ListNode* dup;
    while(org!=NULL) {
        ListNode* temp = new ListNode(org->val);
        if (myRoot==NULL) {
            myRoot=temp;
            dup=myRoot;
        } else {
            dup->next = temp;
            dup = dup->next;
        }
        hmap[org]=temp;
        org=org->next;
    }
    // Creating Random Nodes
    org = A;
    while(org!=NULL) {
        hmap[org]->random=hmap[org->random];
        org=org->next;
    }
    return myRoot;
}