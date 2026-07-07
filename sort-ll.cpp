/* Structure of a Linked List Node
class Node
{
    int data;
    Node next;
    Node(int d) {
       data = d;
       next = nullptr;
    }
};*/
class Solution {
  public:
  Node* half(Node* head)
  {
      auto slow=head, fast=head->next;
      while(fast && fast->next)
      {
          slow=slow->next;
          fast=fast->next->next;
      }
      return slow;
  }
  Node* merge(Node*l1, Node*l2)
  {
      Node* dummy=new Node(-1);
      auto temp=dummy;
      while(l1 && l2)
      {
          if(l1->data<l2->data)
          {
          temp->next=l1;
          l1=l1->next;
      }
      else
      {
           temp->next=l2;
          l2=l2->next;
      }
      temp=temp->next;
      }
      if(l1)
      {
          temp->next=l1;
         
      }
      if(l2)
      {
          temp->next=l2;
      }
      return dummy->next;
  }
    Node* sortLL(Node* head) {
        // code here
         if(!head || !head->next)
            return head;
    auto left=head;
       auto mid= half(head);
       auto right=mid->next;
       mid->next=nullptr;
      left=sortLL(left);
      right=sortLL(right);
      return merge(left,right);
    }
};
