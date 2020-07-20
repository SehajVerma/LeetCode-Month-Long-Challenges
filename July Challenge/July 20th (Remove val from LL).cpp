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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return NULL;
        ListNode* p=head;
        ListNode* q=p;
        while(head!=NULL && p!=NULL)
        {
            if(p->val==val)
            {
                if(p==head){
                    head=head->next;
                    p=head;
                }
                else
                {
                    q->next=p->next;
                    p->next=NULL;
                    p=q->next;
                }
            }
            else
            {
                q=p;
                p=p->next;
            }
        }
        return head;
    }
};
