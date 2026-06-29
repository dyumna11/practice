
ListNode* reverse(ListNode* head)
{
    auto temp=head;
    ListNode* prev=nullptr;
    while(temp)
    {
         ListNode* front=temp->next;
                temp->next=prev;
                prev=temp;
                temp=front;
    }
   return prev;

}
    ListNode* reverseKGroup(ListNode* head, int k)
     {
        if(!head || !head->next)
        return head;
        auto temp=head;
        int c=0;
       while(temp)
       {
        temp=temp->next;
        ++c;
       }
       ListNode*dummy=new ListNode(0,head);
        auto prevgp=dummy;
       
       while(c>=k)
       {
        auto grouphead=prevgp->next;
        temp=grouphead;
        
        for(int i=1;i<k;++i)
        temp=temp->next;
        ListNode* nextgrouphead=temp->next;
        temp->next=nullptr;

        auto newhead=reverse(grouphead);
        prevgp->next=newhead;
        grouphead->next=nextgrouphead;

       prevgp=grouphead;
       grouphead=nextgrouphead;
        c-=k;
       }

       return dummy->next;
    }
