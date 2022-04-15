#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

//  class  Project {
//      public:
//          string name;
//          int complete;
//          int best_before;
//          int score;
//          int roles;
//          map<string,int> skill;
// };


// class user_class {
//     public:
//         string name;
//         map<string, int> skill;
// };




// bool isavailable(map<string,int> skill_project ,map<string, int> skill_user)
// {
//     for(auto itr : skill_project){
//         if(skill_user.find(itr.first) != skill_user.end() && skill_user[itr.first] >= itr.second) break;
//         else return false;
//     }

//     return true;

// }

// int romanToInt(string s) {
    // int number = 0;
    // for(int i = 0; i< s.size(); i++){
    //     if(s.at(i) == 'I' ){
    //         if(s.size() - 1 != i){
    //             if(s.at(i+1) == 'V' ){
    //                 number += 4;
    //                 i++;
    //             } else if(s.at(i+1) == 'X'){
    //                 number+= 9;
    //                 i++;
    //             }        
    //         else number+= 1;
    //     } 
    //     else number += 1;
    // }
    //     else if(s.at(i) == 'X' ) {
    //         if(s.size() - 1 != i){
    //             if(s.at(i+1) == 'L'){
    //                 number += 40;
    //                 i++;
    //             } else if(s.at(i+1) == 'C' ){
    //                 number+= 90;
    //                 i++;
    //             }  else number += 10;
    //         }
    //         else number += 10;
    //     }
    //     else if(s.at(i) == 'C' ){
    //         if(s.size() - 1 != i){
    //             if(s.at(i+1) == 'D' ){
    //                 number += 400;
    //                 i++;
    //             } else if(s.at(i+1) == 'M'){
    //                 number+= 900;
    //                 i++;
    //             } 
    //             else number+= 100;
    //         }
    //         else number +=100;
    //     }
    //     else if(s.at(i) =='V') number += 5;
    //     else if(s.at(i) == 'L') number+= 50;
    //     else if(s.at(i) == 'D') number += 500;
    //     else if(s.at(i) == 'M') number += 1000;
    //     // else if(s.at(i) =='I') number += 1;
    //     // else if(s.at(i) =='C') number += 100;
    //     // else if(s.at(i) =='L') number += 50;
    // }
    //    return number; 
    // }

// int reverse(int x) {
//       std::int32_t reversed = 0;
//     const bool negative = i < 0;

//     while (negative ? i <= -base : i >= base) {
//         auto const digit = i % 10; // negative if i < 0
//         reversed = reversed * 10 + digit;
//         i /= 10;
//     }

//     // final digit may cause overflow
//     // const bool overflow =
//     //     negative
//     //     ? (reversed < (INT32_MIN - i) / 10)
//     //     : (reversed > (INT32_MAX - i) / 10);

//     const bool overflow = false;
//     if(negative){
//         if(reversed < (INT32_MIN - i) / 10) overflow = true;
//     }
//     else {
//         if(reversed > (INT32_MAX - i) / 10) overflow = true;
//     }
//     if (overflow) {
//         return 0;
//     }

//     return reversed * 10 + i;
        
//     }

// string longestCommonPrefix(vector<string>& strs) {
//         String s ="";
//         for(int i =0;  i< strs.at(0).size();i++){
//             char s1 = strs.at(0).at(i);
//             for(int j = 1; j < strs.size();j++){
//                 if(strs.at(j).size() == i -1) return s;
//                 if(s1 != strs.at(j).at(i)) return s;
//             }
//             s += s1;
//         }
//         return s;
//     }

// vector<vector<int>> permute(vector<int>& nums) {
//     vector<vector <int> > permu;

//     do {  
//         permu.push_back(nums);
//     } while(next_permutation(nums.begin(), nums.end()));

//     return permu;
// }


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

    BST b, *root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);
    b.del(root,30);
 
    b.Inorder(root);

    // vector<int> ve;
    // ve.push_back(1);
    // ve.push_back(7);
    // ve.push_back(8);
    //   do {  
    //       for(auto e: ve){
    //           cout << e << " ";
    //       }

    // } while(next_permutation(ve.begin(), ve.end()));  
      

    
    // int user , project;
    // cin >> user >> project;
    // vector<user_class> user_database;

    // for(int i =0; i < user; i++){
    //     string name;
    //     int temp ;
    //     user_class person;
    //     cin >> name >> temp;
    //     map<string,int> data;
    //     for(int i = 0; i < temp; i++) {
    //         string skill;
    //         int skill_level;
    //         cin >> skill;
    //         cin >> skill_level;
    //         data.insert(pair<string,int> (skill,skill_level));
    //     }
    //     person.name = name;
    //     person.skill = data;
    // }

    // vector<Project> database_project;

    // for(int i = 0; i < project;i++)
    // {
    //     string name_of;
    //     int complete;
    //     int best_before;
    //     int score;
    //     int roles;
    //     map<string,int> base;
    //     cin >> name_of >> complete >> score >> best_before >> roles;
    //     for( int i =0; i < roles; i++){
    //         string skill_name;
    //         int level;
    //         cin >> skill_name >> level;
    //         base.insert(pair<string,int> (skill_name,level));
    //     }
    //     Project user;
    //     user.name =  name_of;
    //     user.best_before = best_before;
    //     user.complete = complete;
    //     user.score = score;
    //     user.roles = roles;
    //     user.skill = base;
    //     database_project.push_back(user)  ;
    // }



    // // while(!database_project.empty())
    // // {
    //     for(int i = 0; i < database_project.size();i++){
    //         int z = 0;
    //         for(int y = 0; i < user_database.size(); y++){
    //             if(isavailable(database_project[i].skill,user_database[1].skill)){ 
    //                 z = 1;
    //             }
    //             else continue;
    //         }
    //         if(z == 1) cout<<"possible";
    //         else cout << "not possible";
    
    //     }
    // // }

    return 0;
}