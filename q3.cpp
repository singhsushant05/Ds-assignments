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

int findMid(Node* &head){

  int count = 0;
  Node* temp = head;
  while (temp!=nullptr)
  {
    count++;
    temp = temp->next;
  }
  temp = head;
  for (int i = 0; i < count/2; i++)
  {
    temp = temp->next;
  }
  return temp->data;

}

int main(){
  Node* head = nullptr;
  insertAtEnd(head, 5);
  insertAtEnd(head, 10);
  insertAtEnd(head, 20);
  insertAtEnd(head, 124);
  insertAtEnd(head, 3);
  insertAtEnd(head, 34);
  insertAtEnd(head, 345);
cout << findMid(head);

return 0;
}