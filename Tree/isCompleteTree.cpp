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
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }
        std::queue<TreeNode*> NodeQ;
        NodeQ.push(root);
        bool flag = false; //代表出现过NULL节点
        while (!NodeQ.empty())
        {
            int len = NodeQ.size();
            while (len--)
            {
                TreeNode* curNode = NodeQ.front();
                NodeQ.pop();
                if(curNode != NULL)
                {
                    if (flag)
                    {
                        return false;
                    }
                    NodeQ.push(curNode->left);
                    NodeQ.push(curNode->right);
                }
                else
                {
                    flag = true;
                }
            }
        }
        return true;
    }
};