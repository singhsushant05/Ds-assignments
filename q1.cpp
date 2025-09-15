#include <iostream>
#include <queue>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    queue<int> qu;

    while (true) {
        cout << "\nWhat do you want to perform: \n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                if ((int)qu.size() < size) {
                    int numPush;
                    cout << "Enter the number to add to queue: ";
                    cin >> numPush;
                    qu.push(numPush);
                    cout << "Queued " << numPush << " to the queue";
                } else {
                    cout << "Queue is full!";
                }
                break;
            }
            case 2: { 
                if (!qu.empty()) {
                    cout << "Removed " << qu.front() << " from the queue";
                    qu.pop();
                } else {
                    cout << "The queue is already empty!";
                }
                break;
            }
            case 3: { 
                if (qu.empty()) {
                    cout << "The queue is empty";
                } else {
                    cout << "The queue is not empty";
                }
                break;
            }
            case 4: { 
                if ((int)qu.size() == size) {
                    cout << "The queue is full";
                } else {
                    cout << "The queue is not full";
                }
                break;
            }
            case 5: { 
                if (qu.empty()) {
                    cout << "Queue is empty!";
                } else {
                    cout << "Queue elements: ";
                    queue<int> temp = qu;
                    while (!temp.empty()) {
                        cout << temp.front() << " ";
                        temp.pop();
                    }
                }
                break;
            }
            case 6: {
                if (qu.empty()) {
                    cout << "Queue is empty!";
                } else {
                    cout << "Front element: " << qu.front();
                }
                break;
            }
            case 7:
                cout << "Exiting! ";
                return 0;

            default:
                cout << "Invalid code. Try again!";
                break;
        }
    }
}
