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
   	ListNode* rev(ListNode* head){        //Reverses the Linked List
    
		if(head==NULL || head->next==NULL) return head;

		ListNode* prev=NULL, *curr=head;

		while(curr!=NULL){
			ListNode* n=curr->next;
			curr->next=prev;
			prev=curr;
			curr=n;
		}
		return prev;
	}

	bool isPalindrome(ListNode* head) {
    
		if(head==NULL || head->next==NULL) return true;

		ListNode* slow=head, *fast=head->next;    //Finding the mid point of LL and dividing it into LL's

		while(fast!=NULL && fast->next!=NULL){
			slow=slow->next;
			fast=fast->next->next;
		}

		ListNode* ll2_head=slow->next;          //LL2 head= slow->next
		slow->next=NULL;                        //slow->next=NULL i.e. breaking connection
		ListNode* newhead=rev(ll2_head);        //Reversing LL2

		while(head!=NULL && newhead!=NULL){     //Traversing both LL's simulataneously

			if(head->val!=newhead->val) return false;
			head=head->next;
			newhead=newhead->next;
		}

		return true;
	}
};