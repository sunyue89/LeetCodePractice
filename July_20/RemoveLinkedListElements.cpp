/*
Remove Linked List Elements

Solution
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* t = head;
        ListNode* th = t;
        while(t!=nullptr){
            while(t!=nullptr && t->val == val){
                if(t==head){
                    t=t->next;
                    head = th = t;
                }else{
                    t=t->next;
                    th->next=t;
                }
            }
            if(t!=nullptr){
                th=t;
                t=t->next;
            }
        }
        return head;
    }
};
