/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  // Floyd's Tortoise and Hare Algorithm
  // Time Complexity: O(n)
  // Space Complexity: O(1)
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;        
    }
};