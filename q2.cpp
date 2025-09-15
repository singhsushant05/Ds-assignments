#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};
void insertAtEnd(Node* &head,int value){
  Node* newNode = new Node{value,nullptr};
  if (head == nullptr)
  {
    head = newNode;
    return;
  }
  Node* temp = head;
  while (temp->next!=nullptr)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void countAndDelete(Node* &head,int key){
int count = 0;

while (head != nullptr && head->data==key) {
  Node* toDelete = head;
  head = head->next;
  delete toDelete;
}

Node* temp = head;
while (temp != nullptr && temp->next != nullptr)
{
  if(temp->next->data == key){
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    count++;
  } else{
    temp = temp->next;
  }
}
 cout << "Deleted " << count << " node with value " << key << endl;
}

int main(){
  Node* head = nullptr;
  insertAtEnd(head, 5);
  insertAtEnd(head, 10);
  insertAtEnd(head, 20);
  insertAtEnd(head, 10);
  insertAtEnd(head, 30);

  cout << "Original list: ";
    displayList(head);

countAndDelete(head, 10);

    cout << "List after deletion: ";
    displayList(head);

return 0;
}