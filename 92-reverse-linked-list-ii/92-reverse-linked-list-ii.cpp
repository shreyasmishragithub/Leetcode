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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* p1=head,*p2;
        stack<int>s;
        int cnt=1;
        while(cnt!=left){
            head=head->next;
            cnt++;
        }
        p2=head;
        while(cnt!=right+1){
    s.push(head->val);
            head=head->next;
            cnt++;
        }
        while(!s.empty()){
            p2->val=s.top();
            s.pop();
            p2=p2->next;
        }
        return p1;
        }
};