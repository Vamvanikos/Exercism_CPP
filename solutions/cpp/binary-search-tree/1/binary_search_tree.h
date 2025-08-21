#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <memory>
#include <iterator>
#include <stack>

namespace binary_search_tree {

template <typename T>
class binary_tree {
public:
    using tree_ptr = std::unique_ptr<binary_tree<T>>;

    explicit binary_tree(const T& val) : value(val) {}

    void insert(const T& val) {
        if (val <= value) {
            if (!left_child) {
                left_child = std::make_unique<binary_tree<T>>(val);
            } else {
                left_child->insert(val);
            }
        } else {
            if (!right_child) {
                right_child = std::make_unique<binary_tree<T>>(val);
            } else {
                right_child->insert(val);
            }
        }
    }

    const T& data() const {
        return value;
    }

    const tree_ptr& left() const {
        return left_child;
    }

    const tree_ptr& right() const {
        return right_child;
    }

    // Iterator class for in-order traversal
    class iterator {
    public:
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::input_iterator_tag;

        iterator() = default;

        explicit iterator(binary_tree<T>* root) {
            push_left(root);
        }

        T& operator*() const {
            return node_stack.top()->value;
        }

        iterator& operator++() {
            binary_tree<T>* node = node_stack.top();
            node_stack.pop();
            if (node->right_child) {
                push_left(node->right_child.get());
            }
            return *this;
        }

        bool operator==(const iterator& other) const {
            return node_stack == other.node_stack;
        }

        bool operator!=(const iterator& other) const {
            return !(*this == other);
        }

    private:
        std::stack<binary_tree<T>*> node_stack;

        void push_left(binary_tree<T>* node) {
            while (node) {
                node_stack.push(node);
                node = node->left_child.get();
            }
        }
    };

    iterator begin() {
        return iterator(this);
    }

    iterator end() {
        return iterator();
    }

private:
    T value;
    tree_ptr left_child{nullptr};
    tree_ptr right_child{nullptr};
};

}  // namespace binary_search_tree

#endif  // BINARY_SEARCH_TREE_H
