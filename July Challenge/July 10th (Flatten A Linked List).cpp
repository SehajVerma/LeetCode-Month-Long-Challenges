class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL)
            return NULL;
        stack<Node*>s;
        
        Node *p=head;
        Node *q=head;
        while(p!=NULL)
        {
            if(p->child)
            {
                if(p->next){
                s.push(p->next);
                }
                p->next=p->child;
                p->next->prev=p;
                Node *ch = p->child;
                p->child=NULL;
                p=ch;
            }
            else{
                q=p;
                p=p->next;
            }
            
            if(p==NULL && !s.empty())
            {
                p = s.top();
                s.pop();
                q->next=p;
                p->prev=q;;
            }
        }
        return head;
        
    }
};
