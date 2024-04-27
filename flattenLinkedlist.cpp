Node* Merge(Node* a,Node* b)
    {
        Node* dummy=new Node(0);
        Node* temp=dummy;
        while(a!=NULL && b!=NULL)
        {
            if(a->data<b->data)
            {
                dummy->bottom=a;
                dummy=dummy->bottom;
                a=a->bottom;
            }
            else{
                dummy->bottom=b;
                dummy=dummy->bottom;
                b=b->bottom;
            }
        }
        if(a) dummy->bottom=a;
        else dummy->bottom=b;
        return temp->bottom;
    }
Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL || root->next==NULL) return root;
   root->next=flatten(root->next);
   root=Merge(root,root->next);
   return root;
}