#include <iostream>
#include <cmath>
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
//S1 递归遍历，O(n)时间复杂度
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    //S2，时间复杂度O(nlogn)
    int countNodes(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int leftLevel = getLeftLevel(root->left) + 1;
        int rightLevel = getRightLevel(root->right) + 1;
        if (leftLevel == rightLevel)
        {
            return pow(2, leftLevel) - 1;
        }
        int sum = 0;
        sum += countNodes(root->left) + countNodes(root->right);
        return sum + 1;
        
    }
    int getLeftLevel(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return getLeftLevel(root->left) + 1;
    }
    int getRightLevel(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return getRightLevel(root->right) + 1;
    }
    //S3 时间复杂度(logn)^2
    int countNodes(TreeNode* root)
    {
        if (root ==NULL)
        {
            return 0;
        }
        int leftLevel = getLevel(root->left);
        int rightLevel = getLevel(root->right);
        if (leftLevel == rightLevel) //左边为满二叉树，右边不满(完全二叉树)
        {
            return ((1 << leftLevel) + countNodes(root->right));
        }
        //右边是满二叉树，左边可能不是满二叉树
        return ((1 << rightLevel) + countNodes(root->left));
        
    }
    int getLevel(TreeNode* root)
    {
        int level = 0;
        while (root)
        {
            level++;
            root = root->left;
        }
        return level;
    }
};