#include "queue.h"

CheckoutQueue::CheckoutQueue() { // Constructor
    front = nullptr;
    rear = nullptr;
}

void CheckoutQueue::enQueue(queueNodeData item) { // Add new node to the end of checkout
    queueNode* newNode = new queueNode;
    newNode->data = item;
    newNode->nextPtr = nullptr;

    if (rear == nullptr) {
        front = newNode;
    } else {
        rear->nextPtr = newNode;
    }
    rear = newNode;
}

queueNodeData CheckoutQueue::deQueue() { // Deletes nodes and updates list order
    if (front == nullptr) {
        cout << "Error: queue is empty" << endl;
        return { 0, 0 };
    }

    queueNode* temp = front;
    queueNodeData item = front->data;

    front = front->nextPtr;
    delete temp;

    if (front == nullptr) {
        rear = nullptr;
    }
    return item;
}

queueNodeData CheckoutQueue::peek() {
    if (front == nullptr) {
        cout << "Error: queue is empty" << endl;
        return { 0, 0 };
    }

    return front->data;
}

bool CheckoutQueue::queueEmpty() { // Bool test to determine is queue is empty
    return front == nullptr;
}

void CheckoutQueue::printQueue() {
    if (front == nullptr) {
        cout << "Queue is empty" << endl;
    }

    queueNode* current = front;
    cout << left << setw(15) << "Time Available " << "Item Count" << endl;

    while (current != nullptr) {
        cout << left << setw(15) << current->data.timeAvailable << current->data.itemCount << endl;
        current = current->nextPtr;
    }
}
