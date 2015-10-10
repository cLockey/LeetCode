/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //非递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *prev = head;
        head = head->next;
        prev->next = NULL;
        while(head){
            ListNode *tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
};

//递归
class Solution {
public:
    ListNode *reverse(ListNode *reversed, ListNode *next){
        if(!next) return reversed;
        ListNode *tmp = next->next;
        next->next = reversed;
        reverse(next, tmp);
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(NULL, head);
    }
};
