#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
void insert(Node* &head,int value){

 Node* newNode = new Node{value,nullptr};
 if (!head)
 {
   head = newNode;
   return;
 }
 Node* temp = head;
    while (temp->next) {   
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
void revLinkedL(Node* &head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
int main(){
  Node* head = nullptr;
  insert(head, 5);
  insert(head, 10);
  insert(head, 20);
  insert(head, 124);
  insert(head, 3);
  insert(head, 34);
  insert(head, 345);

displayList(head);

revLinkedL(head);
displayList(head);

return 0;
}
