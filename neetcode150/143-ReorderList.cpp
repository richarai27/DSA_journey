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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* tail = slow->next;
        ListNode* prev = slow->next = nullptr;
        while(tail){
            ListNode* temp = tail->next;
            tail->next = prev;
            prev = tail;
            tail = temp;
        }

        while(prev){
            ListNode* temp1 = head->next;
            ListNode* temp2 = prev->next;
            head->next = prev;
            prev->next = temp1;
            head = temp1; prev = temp2;
        }
    }
};