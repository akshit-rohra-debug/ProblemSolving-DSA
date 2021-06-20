/*
* Given a binary tree, check whether it is a 
* mirror of itself (ie, symmetric around its center).
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool isMirror(TreeNode* root1, TreeNode* root2) {
    if (root1==NULL && root2==NULL) return true;
    if (root1==NULL || root2==NULL) return false;
    if (root1->val == root2->val) {
        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    } else {
        return false;
    }
}

int isSymmetric(TreeNode* A) {
    if (isMirror(A->left, A->right)) return 1;
    return 0;
}