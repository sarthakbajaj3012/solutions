#include <iostream>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root->val < low) trimBST(root->left,low,high);
        if(root->val > high) trimBST(root->right,low ,high);
        TreeNode* newtree = root;
        trim(newtree,low,high);
        return newtree;
    }

    void trim(TreeNode* &root , int low , int high){
        if(root == NULL) return;
        trim(root->left,low,high);
        trim(root->right,low,high);
        if(root->left != NULL && root->left->val < low ) root->left = NULL;
        if(root->right != NULL && root->right->val > high) root->right = NULL;
    }


};

int main(){

}