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
class Solution 
{
public:
    
    void Split(ListNode* head , ListNode** head1 , ListNode** head2 )
    {
        ListNode* slow = head , *fast = head->next;

        while(slow && fast && fast->next )
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        *head2 = slow->next;
        slow->next = NULL;
        *head1 = head;
         

    }

    ListNode* Merge(ListNode* head1 , ListNode* head2 )
    {
        if(!head1)return head2;
        else if(!head2)return head1;
        else if(head1 == head2)return head1;
        
        
        ListNode* cur1 = head1 , * cur2 = head2 , *next1 = cur1->next , *next2 = cur2->next;

        while(next1 && cur2)
        {
            if( cur2->val >= cur1->val && cur2->val <= next1->val )
            {
                // next2 = cur2->next;
                cur1->next = cur2;
                cur2->next = next1;

                cur2 = next2;
                if(cur2)next2 = cur2->next;
                cur1 = cur1->next;
                next1 = cur1->next;
            }
            else if(next1->next )
            {
                cur1 = next1;
                next1 = next1->next;
            }
            else
            {
                next1->next = cur2;
                return head1;
            }

        }
        
        if(cur2)
        {
            cur1->next = head2;
            
        }
        return head1;


    }

    
    
    ListNode* Merge_Sort(ListNode* head)
    {
        ListNode* cur = head;

        if( !cur || !cur->next )
        {
            return cur;
        }

        ListNode* head1 , *head2;
        Split(head,&head1,&head2);

         head1 =  Merge_Sort(head1);
         head2 =  Merge_Sort(head2);
        
        // if(!head1)return head2;
        // else if(!head2)return head1;
        // cout<<head1->val<<" "<<head2->val<<endl;
        

       if( head1->val < head2->val )
       {
           
           return Merge(head1,head2);
       }
       else
       {
           return Merge(head2,head1);
       }

       return head;

    }

    
    ListNode* sortList(ListNode* head) 
    {
         return Merge_Sort(head);
        return head;
        
        
    }
};