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
    ListNode* mergeNodes(ListNode* head) {
        vector<int> arr1;
        ListNode *dummy=new ListNode();
        ListNode *temp=dummy;
        ListNode *temp2=head;
        while(temp2!=NULL){
            arr1.push_back(temp2->val);
            temp2=temp2->next;
        }
        vector<int> arr2;
        int sum=0;
        for(int i=1;i<arr1.size();i++){
            if(arr1[i]==0){
                if(sum!=0){
                    arr2.push_back(sum);
                    sum=0;
                }
            }
            sum+=arr1[i];
        }
        for(int i=0;i<arr2.size();i++){
            ListNode *node=new ListNode(arr2[i]);
            temp->next=node;
            temp=temp->next;
        }
        return dummy->next;
    }
};