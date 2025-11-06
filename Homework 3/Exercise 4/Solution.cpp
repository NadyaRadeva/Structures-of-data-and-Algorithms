//terminated due to timeout

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct SinglyLinkedListNode {
    long long key;
    long long value;
    SinglyLinkedListNode* next;
    
    SinglyLinkedListNode(long long key, long long value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};

struct SinglyLinkedList {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
    long long size;
    
    SinglyLinkedList() {
        head = tail = nullptr;
        size = 0;
    }
};

void removeLast(SinglyLinkedList* llist) {
    if (llist->head == nullptr) {
        return;
    }

    if (llist->head == llist->tail) {
        delete llist->head;
        llist->head = llist->tail = nullptr;
        llist->size = 0;
        return;
    }

    SinglyLinkedListNode* cur = llist->head;
    while (cur->next != llist->tail) {
        cur = cur->next;
    }

    delete llist->tail;
    llist->tail = cur;
    llist->tail->next = nullptr;
    llist->size--;
}

void put(SinglyLinkedList* llist, long long key, long long value, long long capacity) {
    SinglyLinkedListNode* cur = llist->head;
    SinglyLinkedListNode* prev = nullptr;

    while (cur != nullptr) {
        if (cur->key == key) {
            cur->value = value;
            if (prev != nullptr) {
                prev->next = cur->next;
                if (cur == llist->tail) llist->tail = prev;
                cur->next = llist->head;
                llist->head = cur;
            }
            return;
        }
        prev = cur;
        cur = cur->next;
    }

    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(key, value);
    newNode->next = llist->head;
    llist->head = newNode;
    
    if (llist->tail == nullptr) {
        llist->tail = newNode;
    }
    
    llist->size++;

    if (llist->size > capacity) {
        removeLast(llist);
    }
}

long long get(SinglyLinkedList* llist, long long key) {
    SinglyLinkedListNode* cur = llist->head;
    SinglyLinkedListNode* prev = nullptr;

    while (cur != nullptr) {
        if (cur->key == key) {
            long long val = cur->value;
            if (prev != nullptr) {
                prev->next = cur->next;
                if (cur == llist->tail) llist->tail = prev;
                cur->next = llist->head;
                llist->head = cur;
            }
            return val;
        }
        prev = cur;
        cur = cur->next;
    }
    return -1;
}

int main() {
    long long capacity, n, K;
    cin >> capacity >> n >> K;

    SinglyLinkedList* cache = new SinglyLinkedList();
    long long ops = 0;

    for (long long i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "put") {
            long long key, val;
            cin >> key >> val;
            put(cache, key, val, capacity);
            ops++;
        } else if (cmd == "get") {
            long long key;
            cin >> key;
            cout << get(cache, key) << endl;
            ops++;
        }

        if (K > 0 && ops % K == 0) {
            removeLast(cache);
        }
    }

    while (cache->head != nullptr) {
        removeLast(cache);
    }
    
    delete cache;
    return 0;
}
