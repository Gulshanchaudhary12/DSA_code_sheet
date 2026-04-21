#include<iostream>
#include<vector>
using namespace std;



// =====================================================
// 📘 NOTES: Search an Element in Singly Linked List
// =====================================================
// Problem:
// Given head of a linked list and a key, return 1 if key exists else 0.
//
// Idea:
// Traverse node by node from head.
// If any node->data == key, return 1.
// If traversal ends, return 0.
//
// Time Complexity: O(N)
// Space Complexity: O(1)
// =====================================================


// =====================================================
// 1) Node Structure (Generic using Template)
// =====================================================
template <typename T>
class Node {
public:
    T data;         // value stored in node
    Node* next;     // pointer to next node

    Node(T val) {
        data = val;
        next = NULL;
    }
};


// =====================================================
// 2) Create Linked List (Input-based)
// =====================================================
Node<int>* createLinkedList() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n == 0) return NULL;

    int x;
    cin >> x;

    Node<int>* head = new Node<int>(x);
    Node<int>* temp = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        Node<int>* newNode = new Node<int>(x);
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}


// =====================================================
// 3) Search Function
// =====================================================
int searchInLinkedList(Node<int>* head, int key) {
    Node<int>* temp = head;

    while (temp != NULL) {
        if (temp->data == key) return 1;  // found
        temp = temp->next;
    }

    return 0;  // not found
}


// =====================================================
// 4) Print Linked List
// =====================================================
void printList(Node<int>* head) {
    Node<int>* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


// =====================================================
// 5) Driver Code
// =====================================================
int main() {
    // Step 1: Build linked list
    Node<int>* head = createLinkedList();

    // Step 2: Display list
    cout << "Linked List: ";
    printList(head);

    // Step 3: Input key and search
    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int result = searchInLinkedList(head, key);

    // Step 4: Print result
    if (result) cout << "Element Found\n";
    else cout << "Element Not Found\n";

    return 0;
}
