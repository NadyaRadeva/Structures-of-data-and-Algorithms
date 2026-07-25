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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0, lengthB = 0;

        ListNode* currentA = headA;
        while(currentA != nullptr) {
            ++counterA;
            currentA = currentA->next;
        }

        ListNode* currentB = headB;
        while(currentB != nullptr) {
            ++counterB;
            currentB = currentB->next;
        }

        currentA = headA;
        currentB = headB;
        
        int diff = abs(lengthA - lengthB);

        if(lengthA > lengthB) {
            for(int i = 0; i < diff; ++i) {
                currentA = currentA->next;
            }
        }
        else {
            for(int i = 0; i < diff; ++i) {
                currentB = currentB->next;
            }
        }

        while(currentA != currentB) {
            currentA = currentA->next;
            currentB = currentB->next;
        }

        return currentA;
    }
};
