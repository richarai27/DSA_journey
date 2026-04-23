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
  // Time: O(n)
  // Space: O(1)
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* curr = head;
        while(curr){
            size++; curr = curr->next;
        }
        if(size == n) return head->next;

        int nthTerm = size - n + 1; int count = 0;
        ListNode* newhead = head;
        while(newhead){
            count++;
            if(count == nthTerm - 1){
                newhead->next = newhead->next->next;
            }
            newhead = newhead->next;
        }
        return head;
    }
};