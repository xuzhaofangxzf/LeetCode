/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <queue>
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    int treeDepth(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        std::queue<TreeNode*> NodeStack;
        NodeStack.push(root);
        int level = 0;
        while (!NodeStack.empty())
        {
            level++;
            int len = NodeStack.size();
            while(len--)
            {
                TreeNode* node = NodeStack.front();
                NodeStack.pop();
                if (node->left != NULL)
                {
                    NodeStack.push(node->left);
                }
                if (node->right != NULL)
                {
                    NodeStack.push(node->right);
                }
            }
        }
        return level;
        
    }
    int treeDepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int nLeft=treeDepth(root->left);
        int nRight=treeDepth(root->right);

        return nLeft>nRight?nLeft+1:nRight+1;
        
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
        {
            return true;
        }
        if(abs(treeDepth(root->left) - treeDepth(root->right)) > 1)
        {
            return false;
        }
        if(isBalanced(root->left) && isBalanced(root->right))
        {
            return true;
        }
        return false;
        
    }




    //S2
    int treeDepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int nLeft=treeDepth(root->left);
        int nRight=treeDepth(root->right);
        if (nLeft >= 0 && nRight >= 0 && abs(nLeft - nRight) <= 1)
        {
            return nLeft>nRight?nLeft+1:nRight+1;
        }
        else
        {
            return -1;
        }
    }
    bool isBalanced(TreeNode* root)
    {
        return treeDepth(root) >= 0;
    }
};