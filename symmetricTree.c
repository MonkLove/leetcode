/* Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3    */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
bool isSymmetric(struct TreeNode* root) {
    if(root == NULL)
        return 1;
    
    return cmpNode(root->left, root->right);
}

int cmpNode(struct TreeNode *lroot, struct TreeNode *rroot){
    if(lroot == NULL && rroot == NULL)
        return 1;
    if(lroot->val != rroot->val)
        return 0;
        
    cmpNode(lroot->left, rroot->right);
    cmpNode(lroot->right, rroot->left);
    return 1 && cmpNode(lroot->left, rroot->right) && cmpNode(lroot->right, rroot->left);
}
