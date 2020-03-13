#include <iostream>
#include <stack>
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Solution {
public:
    bool isValidBST(TreeNode* root, int* min, int* max)
    {
        if(root == NULL)
        {
            return true;
        }
        int *TmpVal = &root->val;
        if(min != NULL && *TmpVal <= *min)
        {
            return false;
        }
        if(max != NULL && *TmpVal >= *max)
        {
            return false;
        }
        return (isValidBST(root->left, min, TmpVal) && isValidBST(root->right, TmpVal, max));
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }



    //S2 二叉树中序遍历，
    bool isValidBST(TreeNode* root)
    {
        if (root == NULL)
        {
            return true;
        }
        std::stack<TreeNode*> NodeQ;
        TreeNode* PreNode = NULL;
        while (!NodeQ.empty() || root != NULL)
        {
            if (root != NULL)
            {
                NodeQ.push(root);
                root = root->left;
            }
            else
            {
                root = NodeQ.top();
                NodeQ.pop();
                if (PreNode != NULL && root->val <= PreNode->val)
                {
                    return false;
                }
                PreNode = root;
                root = PreNode->right;
            }
            
        }
        return true;
    }
    //S3 该方法错误，保留用于对比，这种情况不能保证柚子树所有节点都比根节点大
    bool isValidBST(TreeNode* root)
    {
        if (root == NULL)
        {
            return true;
        }
        std::stack<TreeNode*> NodeQ;
        while (!NodeQ.empty() || root != NULL)
        {
            if (root != NULL)
            {
                NodeQ.push(root);
                root = root->left;
            }
            else
            {
                root = NodeQ.top();
                NodeQ.pop();
                if (root->left != NULL && root->left->val >= root->val)
                {
                    return false;
                }
                if (root->right != NULL && root->val >= root->right->val)
                {
                    return false;
                }
                root = root->right;
            }
            
        }
        return true;
    }
};