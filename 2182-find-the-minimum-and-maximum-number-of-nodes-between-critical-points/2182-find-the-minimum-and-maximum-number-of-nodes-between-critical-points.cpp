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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* tempi = head;
        vector<int> temp;
        while (tempi != NULL) {
            temp.push_back(tempi->val);
            tempi = tempi->next;
        }
        vector<int> ans;
        if (temp.size() <= 2) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        for (int i = 1; i < temp.size() - 1; i++) {
            if (temp[i] < temp[i - 1] && temp[i] < temp[i + 1]) {
                ans.push_back(i);
            }
            if (temp[i] > temp[i - 1] && temp[i] > temp[i + 1]) {
                ans.push_back(i);
            }
        }
        vector<int> ans2;
        if (ans.size() <2) {
            ans2.push_back(-1);
            ans2.push_back(-1);
            return ans2;
        }
        sort(ans.begin(), ans.end());
        int n = ans.size();
        int maximum = ans[n - 1] - ans[0];
        int minimum = abs(ans[0] - ans[1]);
        for (int i = 0; i < n - 1; i++) {
            int x = abs(ans[i] - ans[i + 1]);
            minimum = min(minimum, x);
        }
        ans2.push_back(minimum);
        ans2.push_back(maximum);
        return ans2;
    }
};