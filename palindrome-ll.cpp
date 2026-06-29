
ListNode* reverse(ListNode* head)
{
   auto temp=head;
   ListNode* prev=nullptr;
   while(temp)
   {
    auto front=temp->next;
    temp->next=prev;
    prev=temp;
    temp=front;
   }
    return prev;  
  }
    bool isPalindrome(ListNode *head) {
        if(!head || !head->next)
        return true;
        auto fast=head,slow=head;
        while(fast && fast->next->next)
       {
         slow=slow->next;
        fast=fast->next->next;
       
       }
       auto right=reverse(slow->next);
       slow->next=nullptr;
       auto left=head;
       
       while(right && left)
       {
        if(right->val!=left->val)
        return false;
        right=right->next;
        left=left->next;
       }
       return true;
    }
