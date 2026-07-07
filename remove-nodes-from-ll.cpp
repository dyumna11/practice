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
    ListNode* removeNodes(ListNode* head) {
         if (!head || !head->next)
    return head;
        head=reverse(head);
        auto temp=head;
        int mx=head->val;
        while(temp && temp->next)
        {
            if(temp->next->val<mx)
            {
               ListNode* del=temp->next;
               temp->next=del->next;
            }
            else
            {
                temp=temp->next;
                mx=temp->val;
            }

        }
        return reverse(head);
    }
};
