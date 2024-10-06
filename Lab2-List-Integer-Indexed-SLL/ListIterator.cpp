#include "ListIterator.h"
#include "IndexedList.h"
#include <exception>

ListIterator::ListIterator(const IndexedList& list) : list(list){
    currentElement = list.head;
}

void ListIterator::first(){
    currentElement = list.head;
}

void ListIterator::next(){
    if (!valid()) {
        throw std::exception();
    }
    currentElement = currentElement->next;
}

bool ListIterator::valid() const{
    return currentElement != nullptr;
}

TElem ListIterator::getCurrent() const{
    if (!valid()) {
        throw std::exception();
    }
    return currentElement->elem;
}
