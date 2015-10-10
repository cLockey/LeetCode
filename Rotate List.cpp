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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k < 0) return NULL;
        if(k == 0) return head;
        int len = 1;
        ListNode *mid = head, *tail = head;
        while(tail->next){
            len++;
            tail = tail->next;
        }
        tail->next = head;  //必须放在newHead = mid->next前面，否则当len==1, k==1时会出问题。
        k %= len;
        for(int i=0; i<len-k-1; i++){
            mid = mid->next;
        }
        ListNode *newHead = mid->next;
        mid->next = NULL;
        return newHead;
    }
};
