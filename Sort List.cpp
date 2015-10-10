/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *merge(ListNode *n1, ListNode *n2){
        ListNode *fakeHead = new ListNode(-1);
        ListNode *curNode = fakeHead;
        while(n1 && n2){
            if(n1->val < n2->val){
                curNode->next = n1;
                n1 = n1->next;
            }
            else{
                curNode->next = n2;
                n2 = n2->next;
            }
            curNode = curNode->next;
        }
        if(n1){
            curNode->next = n1;
        }
        if(n2){
            curNode->next = n2;
        }
        ListNode *head = fakeHead->next;
        delete fakeHead;
        return head;
    }
    
    ListNode *getMid(ListNode *head){
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* partition(ListNode *head){
        if(!head || !head->next) return head;
        ListNode *mid = getMid(head);
        ListNode *midNext = mid->next;
        mid->next = NULL;
        return merge(partition(head), partition(midNext));
    }
    
    ListNode* sortList(ListNode* head) {
        return partition(head);
    }
};
