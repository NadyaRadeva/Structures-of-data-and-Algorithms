/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    
    if(position == 0) {
        newNode->next = llist;
        return newNode;
    }
    
    SinglyLinkedListNode *current = llist;
    int index = 0;
    
    while(current != nullptr && index < position - 1) {
        current = current->next;
        index++;
    }
    
    if(current == nullptr) {
        delete newNode;
        return llist;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    
    return llist;
}
