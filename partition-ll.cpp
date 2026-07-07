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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessdummy=new ListNode(-1);
         ListNode* greaterdummy=new ListNode(-1);
        ListNode* less=lessdummy;
        ListNode* greater=greaterdummy;
        auto temp=head;
        while(temp)
        {
            ListNode* nxt = temp->next;
    temp->next = nullptr;
            if(temp->val<x)
            {
                less->next=temp;
                less=less->next;
            }
            else
            {
                greater->next=temp;
                greater=greater->next;
            }
             temp=nxt;
        }
        less->next=greaterdummy->next;
        return lessdummy->next;
    }
};
