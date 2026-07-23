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
    ListNode* middleNode(ListNode* head) {
        int counter = 0;
        ListNode* current = head;

        while(current != nullptr) {
            ++counter;
            current = current->next;
        }

        current = head;

        for(int i = 0; i < counter/2; ++i) {
            current = current->next;
        }

        return current;
    }
};
