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
    int pairSum(ListNode* head) {
        int cnt=0, ans=0;
        unordered_map<int,int> mp;
        for(auto *temp=head; temp!=NULL; temp= temp->next){
            mp[cnt]=temp->val;
            cnt++;
        }
        for(int i=0; i<= (cnt/2)-1; i++){
            ans= max(ans, mp[cnt-i-1]+mp[i]);
        }
        return ans;
    }
};