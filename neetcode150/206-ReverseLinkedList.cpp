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
    // Time: O(n) where n is the number of nodes in the linked list.
    // Space: O(1) since we are reversing the linked list in place and not using any additional data structures that grow with the input size.
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;
        ListNode* current = head;

        while(current){
             ListNode* temp = current->next;
             current->next = previous;
             previous = current;
             current = temp;
        }
        return previous;
    }
};