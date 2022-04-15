#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
class BST {
    int value;
    BST* left; 
    BST* right;


    public:
        BST();

        BST(int data);

        BST* Insert(BST* root ,int key);

        void Inorder(BST * root);

        BST* search( BST* root , int key);

        BST* minValueNode(BST* node);

        BST* del(BST* root, int key);

        

}; 


BST::BST(): value(0) , left(NULL) , right(NULL){};

BST::BST(int data) {
    value = data;
    left = right = NULL;
}


BST* BST::Insert(BST* root , int key){
    if(!root){
        return new BST(key);
    }
    if(key > root->value){
        root->right = Insert(root->right,key);
    }
    else {
        root->left = Insert(root->left,key);
    }
    return root;
}

void BST ::Inorder(BST* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->value << endl;
    Inorder(root->right);
}

 BST* BST::search( BST* root , int key){
    if(root == NULL || root->value == key){
        return root;
    }
    if (root->value < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}

BST* BST::minValueNode(BST* node)
{
    BST* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

BST* BST::del(BST* root , int key){
    if(root == NULL){
        return root;
    }
    if(key < root->value){
        root->left = del(root->left,key);
    }
    else if(root->value < key){
        root->right = del(root->right,key);
    }
    else {
        if(root->left == NULL & root->right == NULL){
            return NULL;
        }
        else if(root->left == NULL){
            BST* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            BST* temp = root->left;
            free(root);
            return temp;
        }

        BST* temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = del(root->right,temp->value);

    }
    return root;
}

int main(){
    return 0;
}
