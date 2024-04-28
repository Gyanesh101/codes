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
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* nex=NULL;
        while(curr!=NULL)
        {
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
       // cout<<prev->val;
        return prev;
    }
    ListNode* getK(ListNode* temp,int k)
    {
        k-=1;
        while(temp!=NULL && k>0)
        {
            k--;
            temp=temp->next;
            
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=head;
        while(temp!=NULL)
        {
            
            ListNode* kthNode=getK(temp,k);
            if(kthNode==NULL) break;
            ListNode* NextHead=kthNode->next;
            kthNode->next=NULL;
          ListNode* newHeadoFkGrp=reverse(temp);
          if(temp==head){ head=newHeadoFkGrp;}
          else{
          prev->next=newHeadoFkGrp;
          }
          prev=temp;
          temp=NextHead;
        }
        if(prev!=NULL) prev->next=temp;
        return head;
    }
};