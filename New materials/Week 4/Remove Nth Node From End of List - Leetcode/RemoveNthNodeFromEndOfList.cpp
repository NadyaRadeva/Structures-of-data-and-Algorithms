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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* previous = nullptr;
        ListNode* current = head;

        while(current != nullptr) {
            ListNode* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        head = previous;

        if(n == 1) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            ListNode* current = head;

            for(int i = 1; i < n - 1; i++) {
                current = current->next;
            }

            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }

        previous = nullptr;
        current = head;

        while(current != nullptr) {
            ListNode* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        return previous;
    }
};
