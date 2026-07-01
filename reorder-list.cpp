
  Node* rev(Node* head)
  {
     auto temp=head;
      Node*prev=nullptr;
      while(temp)
      {
      Node* front=temp->next;
      temp->next=prev;
      prev=temp;
      temp=front;
      }
      return prev;
  }
  Node* mid(Node* head)
  {
      auto fast=head,slow=head;
      while(fast->next && fast->next->next)
      {
          slow=slow->next;
          fast=fast->next->next;
      }
     return slow;
  }
  void *merge(Node* head1,Node* head2)
  {
     Node* first = head1;
     Node* second = head2;
        while (first && second) {
            Node* front1 = first->next;
            Node* front2 = second->next;

            first->next = second;
            second->next = front1;

            first = front1;
            second = front2;
  }
  }
    void reorderList(Node* head) {
        // code here
        if (!head || !head->next) return;
        auto left=head;
        auto right=mid(head);
        right=rev(right);
        merge(left,right);
    }
