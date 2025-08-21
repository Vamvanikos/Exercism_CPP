#pragma once
#include <memory>
#include <stdexcept>

namespace linked_list {

template <typename T>
class List {
private:
    struct Node {
        T value;
        std::unique_ptr<Node> next;
        Node* prev = nullptr;

        Node(const T& val) : value(val) {}
    };

    std::unique_ptr<Node> head;
    Node* tail = nullptr;
    std::size_t size = 0;

public:
    List() = default;

    void push(const T& val)
    {
        auto newNode = std::make_unique<Node>(val);
        newNode->prev = tail;

        if (tail)
        {
            tail->next = std::move(newNode);
            tail = tail->next.get();
        }
        else
        {
            head = std::move(newNode);
            tail = head.get();
        }
        ++size;        
    }

    T pop()
    {
        if (!tail)
            throw std::runtime_error("Can't pop from empty list.");

        T data = tail->value;
        if (tail == head.get())
        {
            tail = nullptr;
            head.reset();
        }
        else
        {
            tail = tail->prev;
            tail->next.reset();
        }
        --size;

        return data;
    }

    void unshift(const T& val)
    {
        auto newNode = std::make_unique<Node>(val);
        newNode->next = std::move(head);

        if(newNode->next)
            newNode->next->prev = newNode.get();
        head = std::move(newNode);
        if (!tail)
            tail = head.get();
        ++size;
    }

    T shift()
    {
        if (!head) throw std::runtime_error("Can't shift from empty list.");

        T data = head->value;
        head = std::move(head->next);
        if (head)
            head->prev = nullptr;
        else 
            tail = nullptr;
        --size;

        return data;
    }

    std::size_t count() const
    {
        return size;
    }

    bool erase(const T& val)
    {
        auto current = head.get();
        while (current != nullptr)
        {
            if (current->value == val)
            {
                if (current == head.get())
                    shift();
                else if (current == tail)
                    pop();
                else
                {
                    Node* prev = current->prev;
                    std::unique_ptr<Node>& next = prev->next;
                    next = std::move(current->next);
                    if (next)
                        next->prev = prev;
                    --size;                    
                }
                
                return true;
            }
            current = current->next.get();
        }
        
        return false;
    }
};

}  // namespace linked_list
