//https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
 
 void printLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* current = head;

    while (current != nullptr) {
        cout << current->data << endl;
        current = current->next;
    }
}
 
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
        if(head == nullptr){
            head = newNode;
        }
        else{
        SinglyLinkedListNode* temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
            temp->next = newNode;
        }
        
        printLinkedList(head);
        
    return head;
}
