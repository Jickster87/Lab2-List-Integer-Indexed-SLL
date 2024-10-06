#include <exception>
//#include <utility>
#include "IndexedList.h"
#include "ListIterator.h"

IndexedList::IndexedList() {
    head = nullptr;
    tail = nullptr;
    listSize = 0;
}

int IndexedList::size() const {
    return listSize;
}

bool IndexedList::isEmpty() const {
    return listSize == 0;
}

TElem IndexedList::getElement(int pos) const {
    if (pos < 0 || pos >= listSize) {
        throw std::exception();
    }
    Node *nomad = head;
    for (int i = 0; i < pos; i++) {
        nomad = nomad->next;
    }
    return nomad->elem;
}

TElem IndexedList::setElement(int pos, TElem e) {
    if (pos < 0 || pos >= listSize) {
        throw std::exception();
    }
    Node *nomad = head;
    for (int i = 0; i < pos; i++) {
        nomad = nomad->next;
    }
    TElem oldVal = nomad->elem;
    nomad->elem = e;
    return oldVal;
}

void IndexedList::addToEnd(TElem e) {
    Node *newNode = new Node(e);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    listSize++;
}

void IndexedList::addToPosition(int pos, TElem e) {
    if (pos < 0 || pos > listSize) {
        throw std::exception();
    }
    
    Node *newNode = new Node(e);
    
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        if (listSize == 0) {
            tail = newNode;
        }
    } else {
        Node *nomad = head;
        for (int i = 0; i < pos - 1; i++) {
            nomad = nomad->next;
        }
        newNode->next = nomad->next;
        nomad->next = newNode;
        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }
    listSize++;
}

TElem IndexedList::remove(int pos) {
    if (pos < 0 || pos >= listSize) {
        throw std::exception();
    }
    
    TElem removedElem;
    if (pos == 0) {
        Node *toDelete = head;
        removedElem = toDelete->elem;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;  // If list becomes empty
        }
        delete toDelete;
    } else {
        Node *nomad = head;
        for (int i = 0; i < pos - 1; i++) {
            nomad = nomad->next;
        }
        Node *toDelete = nomad->next;
        removedElem = toDelete->elem;
        nomad->next = toDelete->next;
        if (toDelete->next == nullptr) {
            tail = nomad;  // If last element is removed
        }
        delete toDelete;
    }
    
    listSize--;
    return removedElem;
}

int IndexedList::search(TElem e) const {
    Node *nomad = head;
    int pos = 0;
    while (nomad != nullptr) {
        if (nomad->elem == e) {
            return pos;
        }
        nomad = nomad->next;
        pos++;
    }
    return -1;  // Element not found
}

ListIterator IndexedList::iterator() const {
    return ListIterator(*this);
}

IndexedList::~IndexedList() {
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}
