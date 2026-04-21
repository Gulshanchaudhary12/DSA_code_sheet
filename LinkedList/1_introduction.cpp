#include<iostream>
#include<vector>
using namespace std;

struct Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* y = new Node(arr[0]);
    cout << "First node data: " << y->data << endl;
}


/*
============================================
🔹 WHAT IS A LINKED LIST?
============================================
- A Linked List is a collection of nodes
- Each node contains:
    1. Data
    2. Pointer to next node

👉 Unlike arrays:
- Not stored in contiguous memory
- Dynamic size
- Efficient insertion/deletion

Example:
[1 | * ] → [2 | * ] → [3 | * ] → NULL
*/


/*
============================================
🔹 NODE STRUCTURE
============================================
*/

struct Node {

    int data;      // stores value
    Node* next;    // pointer to next node

    /*
    --------------------------------------------
    🔸 Constructor 1
    - Initializes data + next pointer
    --------------------------------------------
    */
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    /*
    --------------------------------------------
    🔸 Constructor 2
    - Initializes only data
    - next = NULL (default)
    --------------------------------------------
    */
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


/*
============================================
🔹 MAIN FUNCTION (BASIC CREATION)
============================================
*/

int main(){

    // Step 1: Create an array
    vector<int> arr = {1, 2, 3, 4, 5};

    // Step 2: Create first node (HEAD)
    Node* head = new Node(arr[0]);

    // Step 3: Access data
    cout << "First node data: " << head->data << endl;

    return 0;
}


/*
============================================
🔹 following is the class structure of the Node class:

template <typename T>
class Node {
    public:
    T data;
    Node<T>* next;
    Node()
    {
        this->data = 0;
        this-> next - NULL;
        }
        Node(T data)
        {
            this->data = data;
            this->next = NULL;
        }
        Node(T data, Node<T>* next)
        {
            this->data = data;
            this->next = next;
        }
};
============================================
*/