/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if (root == NULL)
            return NULL;

        // Step 1: Search for the node
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // Node found

            // Case 1: No child
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // Case 2: One child
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            // Find maximum in left subtree (inorder predecessor)
            TreeNode* temp = root->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }

            // Replace value
            root->val = temp->val;

            // Delete the duplicate node
            root->left = deleteNode(root->left, temp->val);
        }

        return root;
    }
};