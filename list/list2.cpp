#include <iostream> 
#include <bits/stdc++.h>
using namespace std;

class DoublyLinkedListNode {
public:
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;

    DoublyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    DoublyLinkedListNode* head;
    DoublyLinkedListNode* tail;

    DoublyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data) {
        DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        }
        else {
            this->tail->next = node;
            node->prev = this->tail;
        }

        this->tail = node;
    }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep ) {
    while (node) {
        cout << node->data;
        node = node->next;
        if (node) cout << sep;
    }
    cout << endl;
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;
        free(temp);
    }
}
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data);

    if (!llist || data <= llist->data) {
        newNode->next = llist;
        if (llist) llist->prev = newNode;
        return newNode;
    }

    DoublyLinkedListNode* current = llist;

    while (current->next && current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next) {
        current->next->prev = newNode;
    }

    current->next = newNode;

    return llist;
}

int main() {
    DoublyLinkedList list;
    int n, value;


    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> value;
        list.insert_node(value);
    }

    print_doubly_linked_list(list.head);

    cin >> value;
    list.head = sortedInsert(list.head, value);

    print_doubly_linked_list(list.head);

    free_doubly_linked_list(list.head);
    return 0;
}
