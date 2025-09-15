#include<iostream>
using namespace std;

struct Node 
{
    int data;
    Node *next;
};
void insertAtBeginning(Node* &head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

void insertAtEnd(Node* &head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteFromBeginning(Node* &head) {
    if (head == nullptr) return;

    Node* deleting = head;
    head = head->next;
    delete deleting;
}

void deleteFromEnd(Node* &head) {
    if (head == nullptr) return;
    
    if (head->next == nullptr) {
        delete head;
        head = nullptr; 
        return;
    }
    
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void insertAtPos(Node* &head, int value, int pos) {
    if (pos < 1) {
        cout << "Invalid position" << endl;
        return;
    }
    if (pos == 1) {
        insertAtBeginning(head, value);
        return;
    }
    
    Node* temp = head;
    for (int i = 1; i < pos-1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    
    if (temp == nullptr) {
        cout << "Invalid position" << endl;
        return;
    }
    Node* newNode = new Node{value, temp->next};
    temp->next = newNode;
}
void deleteAtPos(Node* &head, int pos) {
    if (head == nullptr || pos < 1) {
        cout << "Invalid position" << endl;
        return;
    }
    
    if (pos == 1) {
        deleteFromBeginning(head);
        return;
    }
    
    Node* temp = head;
    for (int i = 1; i < pos-1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Invalid position" << endl;
        return;
    }
    
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void delByValue(Node* &head, int value) {
    if (head == nullptr) return;
    
    if (head->data == value) {
        deleteFromBeginning(head);
        return;
    }
    
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }
    
    if (temp->next == nullptr) {
        cout << "Value not found" << endl;
        return;
    }
    
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void searchNode(Node* &head, int value) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    int pos = 1;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Value found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value not found" << endl;
}

void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Insert at end
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    cout << "List after inserting at end: ";
    displayList(head);

    // Insert at beginning
    insertAtBeginning(head, 5);
    cout << "List after inserting 5 at beginning: ";
    displayList(head);

    // Insert at position
    insertAtPos(head, 15, 3);
    cout << "List after inserting 15 at position 3: ";
    displayList(head);

    // Delete from beginning
    deleteFromBeginning(head);
    cout << "List after deleting from beginning: ";
    displayList(head);

    // Delete from end
    deleteFromEnd(head);
    cout << "List after deleting from end: ";
    displayList(head);

    // Delete at position
    deleteAtPos(head, 2);
    cout << "List after deleting node at position 2: ";
    displayList(head);

    // Delete by value
    delByValue(head, 15);
    cout << "List after deleting value 15: ";
    displayList(head);

    // Search
    searchNode(head, 20);
    searchNode(head, 100);
    return 0;
}