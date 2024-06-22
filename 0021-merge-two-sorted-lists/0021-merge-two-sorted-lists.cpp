/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> temp;
        ListNode *temp1=list1;
        ListNode *temp2=list2;
        while(temp1!=nullptr){
            temp.push_back(temp1->val);
            temp1=temp1->next;
        }
        while(temp2!=nullptr){
            temp.push_back(temp2->val);
            temp2=temp2->next;
        }
        sort(temp.begin(),temp.end());
        ListNode *dummy=new ListNode();
        ListNode *ans=dummy;
        for(int i=0;i<temp.size();i++){
            ans->next=new ListNode(temp[i]);
            ans=ans->next;
        }
        return dummy->next;
    }
};