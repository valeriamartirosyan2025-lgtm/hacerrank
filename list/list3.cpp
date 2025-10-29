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
DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* current = llist;
    DoublyLinkedListNode* temp = nullptr;

    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if (temp) {
        llist = temp->prev;
    }

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

    list.head = reverse(list.head);

    print_doubly_linked_list(list.head);

    free_doubly_linked_list(list.head);
    return 0;
}
