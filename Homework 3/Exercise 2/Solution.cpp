// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* dummy = new SinglyLinkedListNode(0);
    SinglyLinkedListNode* current = dummy;
    
    while (head1 && head2) {
        if (head1->data <= head2->data) {
            current->next = head1;
            head1 = head1->next;
        } 
        else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }
    
    current->next = head1 ? head1 : head2;
    
    SinglyLinkedListNode* head = dummy->next;
    delete dummy;
    return head;
}
