#include "linkedlist.h"

int LinkedList::listCount = 0; // initial list count

LinkedList::LinkedList() { // Constructor
    headPtr = nullptr;
}

void LinkedList::addElement(listType item) { / /Adds an element to the linked list.
    Node* newNode = new Node();
    newNode->data = item;

    if (headPtr == nullptr || headPtr->data.enterQTime >= item.enterQTime) { // Determines the position of new nodes in list by entered time
        newNode->nextPtr = headPtr; // Creates new node to add
        headPtr = newNode;
    } else {
        Node* current = headPtr;
        while (current->nextPtr != nullptr && current->nextPtr->data.enterQTime < item.enterQTime) {
            current = current->nextPtr;
        }

        newNode->nextPtr = current->nextPtr;
        current->nextPtr = newNode;
    }
    listCount++;
}

listType LinkedList::peek() {
    return headPtr->data;
}

void LinkedList::delElement() { // Deletes element by first position
    if (headPtr == nullptr) {
        return;
    }
    Node* temp = headPtr;
    headPtr = headPtr->nextPtr;
    delete temp;

    listCount--;
}

void LinkedList::printList() {
    if (headPtr == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* current = headPtr;

    while (current != nullptr) {
        cout << "Cart ID: " << current->data.cartId << endl;
        cout << "Item Count: " << current->data.itemCount << endl;
        cout << "Enter Queue Time: " << current->data.enterQTime << endl;
        cout << "Exit Queue Time: " << current->data.exitQTime << endl;

        current = current->nextPtr;
    }
}

bool LinkedList::listIsEmpty() { // Bool test to determine if list is empty
    return headPtr == nullptr;
}
