/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
        {
            return "#,";
        }
        string serializeStr = to_string(root->val) + ",";
        serializeStr += serialize(root->left);
        serializeStr += serialize(root->right);

        return serializeStr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string temp;
        return deserialize1(data, temp);
    }
    TreeNode* deserialize1(string& data, string& temp)
    {
        if(data == "#," || data == "")
        {
            return NULL;
        }
        size_t pos = data.find(',');
        temp = data.substr(0, pos);
        TreeNode* root = NULL;
        if (temp != "#")
        {
            root = new TreeNode(atoi(temp.c_str()));
            data = data.substr(pos + 1);
            root->left = deserialize1(data, temp);
            root->right = deserialize1(data, temp);
        }
        else
        {
            data = data.substr(pos + 1);
            return NULL;
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));