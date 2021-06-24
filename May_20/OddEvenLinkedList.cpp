/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
 

Constraints:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
The length of the linked list is between [0, 10^4].
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

//two idx pointers, increment and insert
//1 2 3 4 5 Null
//1 2
//1 3 2 4 5

//  1   2
//1 3 5 2 4
//.   1.  2

//2 1 3 5 6 4 7 Null
//2 3 1 5 6 4 7
//2 3 6 1 5 4 7
//2 3 6 7 1 5 4


class Solution {
public:
    //This function move the node of h2->next to h1->next, and update h2->next
    void MoveListNode(ListNode* h1, ListNode* h2){
        if(h2->next!= NULL){
            ListNode* tmp1 = h1->next;
            ListNode* tmp2 = h2->next->next;
            h1->next = h2->next;
            h1->next->next = tmp1;
            h2->next = tmp2;
        }
    }
    ListNode* oddEvenList(ListNode* head) {
        ListNode* h1 = head;
        ListNode* h2 = head;
        while(h2 !=NULL && h2->next != NULL){
            h2 = h2->next;
            MoveListNode(h1,h2);
            h1 = h1->next;
        }
        return head;
    }
};
