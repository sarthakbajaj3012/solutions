//merge two sorted linked list
#include <iostream>
#include <math.h>
using namespace std;


struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} 
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list = new ListNode;
        ListNode* temp = list;
        while(list1->next != NULL || list2->next != NULL){
           if(list1->val < list2->val){
                list->next = list1;
                list1 = list1->next;
           }
           else
           { 
               list->next = list2;
               list2 = list2->next;
           }
        }

        // if(list1->next == NULL) list->next = list2;
        // if(list2->next == NULL) list->next = list1;

        return temp->next;
    }
};
int main(){
    return 0;
}