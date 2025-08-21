#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    // TODO: Return the correct size of the list.
    return current_size;
}

void List::push(int entry) {
    // TODO: Implement a function that pushes an Element with `entry` as data to
    // the front of the list.
    Element* newSong = new Element(entry);
    newSong->next = head;
    head = newSong;
    current_size++;
}

int List::pop() {
    // TODO: Implement a function that returns the data value of the first
    // element in the list then discard that element.
    if (!head)
    {
        throw std::out_of_range("List is empty, element can't be poped");
    }

    int ret = head->data;
    Element* tmp = head;
    head = head->next;
    delete tmp;
    current_size--;

    return ret;
}


void List::reverse() {
    // TODO: Implement a function to reverse the order of the elements in the
    // list.
    Element* prev = nullptr;
    Element* current = head;
    Element* next = nullptr;
    
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

List::~List() {
    // TODO: Ensure that all resources are freed on destruction
    while(head != nullptr)
    {
        Element* tmp = head;
        head = head->next;
        delete tmp;
    }
}

}  // namespace simple_linked_list
