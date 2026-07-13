
class Solution {
public:
    void right_side(TreeNode* node, vector<int> &res, int &level){
        if (res.size() < level)
            res.push_back(node->val);
        if (node->right){
            level++;
            right_side(node->right, res, level);
            level--;
        }
        if (node->left){
            level++;
            right_side(node->left, res, level);
            level--;
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int level = 1;
        if (root){
            right_side(root, res, level);
        }
        return res;
        
    }
};