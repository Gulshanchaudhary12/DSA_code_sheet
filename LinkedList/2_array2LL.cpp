#include<iostream>
#include<vector>
using namespace std;

/*
============================================
🔹 NODE STRUCTURE
============================================
*/

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

/*
============================================
🔹 FUNCTION: CONVERT ARRAY → LINKED LIST
============================================

🔸 Steps:
1. Create HEAD node from first element
2. Use a pointer (mover) to track last node
3. Traverse array
4. Create new node for each element
5. Link nodes using next pointer
*/

Node* convertArr2LL(vector<int> &arr){

    // Edge Case: empty array
    if(arr.size() == 0) return nullptr;

    // Step 1: Create head
    Node* head = new Node(arr[0]);

    // Step 2: Mover pointer
    Node* mover = head;

    // Step 3: Traverse remaining elements
    for(int i = 1; i < arr.size(); i++){

        // Create new node
        Node* temp = new Node(arr[i]);

        // Link node
        mover->next = temp;

        // Move pointer forward
        mover = temp;
    }

    return head;
}


/*
============================================
🔹 FUNCTION: PRINT LINKED LIST
============================================
*/

void printLL(Node* head){

    Node* temp = head;

    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


/*
============================================
🔹 MAIN FUNCTION
============================================
*/

int main(){

    vector<int> arr = {1, 2, 3, 4, 5};

    // Convert array to Linked List
    Node* head = convertArr2LL(arr);

    // Print Linked List
    printLL(head);

    return 0;
}