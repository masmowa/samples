#ifndef LINKED_LIST_WITH_INSERT_H_INCLUDED
#define LINKED_LIST_WITH_INSERT_H_INCLUDED
#include <iostream>

// node for single-linked-list
struct NODE {
    struct NODE * next;
    int data;

    NODE(int val)
    : next(NULL)
    , data(val)
    {
    }
};

class SLL {
private:
    NODE * head;
public:
    // initialize an empty list
    SLL() : head(NULL)
    {
    }

    SLL(int val)
    : head(NULL)
    {
        head = new NODE(val);
    }
    ~SLL() {
        std::cout << "++ SLL::~SLL()" << std::endl;
        NODE * walker = NULL;
        walker = this->Remove(head);
        while (walker != NULL) {
            std::cout << "delet (ing) " << walker << std::endl;
            delete(walker);
            walker = this->Remove(head);
        }
        std::cout << "-- SLL::~SLL()" << std::endl;
    }

    NODE* Insert(NODE * after, const int val) {
        std::cout << "SLL::Insert(" << after << " val = " << val << ")" << std::endl;
        NODE * inode = NULL;
        if (after == NULL) {
            // Assume inserting either after HEAD or at HEAD if head is NULL
            if (head == NULL) {
                head = new NODE(val);
                inode = head;
            }
            else {
                NODE* after_head = head->next;
                head->next = new NODE(val);
                head->next->next = after_head;
                inode = head->next;
            }
        }
        else {
            NODE* after_found = this->Find(after);
            // ensure after node exists in list
            if (after_found != NULL) {
                NODE* after_next = after->next;
                after->next = new NODE(val);
                after->next->next = after_next;
                inode = after->next;
            }
        }
        std::cout << "-- SLL::Insert(); inode = " << inode << std::endl;
        return inode;
    }

    NODE* Insert(const int after_val, const int val) {
        std::cout << "SLL::Insert(after_val, val)" << std::endl;
        NODE* after = this->Find(after_val);

        return this->Insert(after, val);
    }
    // find node with val data
    // return pointer to node containing value or NULL
    NODE* Find(NODE * node) {
        NODE * found = NULL;
        if (head != NULL) {
            NODE* walker = head;
            while (walker->next != NULL && walker != node) {
                walker = walker->next;
            }
            if (walker == node) {
                found = walker;
            }
        }
        return found;
    }

    // find node with val data
    // return pointer to node containing value or NULL
    NODE* Find(const int val) {
        NODE * found = NULL;
        if (head != NULL) {
            NODE* walker = head;
            while (walker->next != NULL && walker->data != val) {
                walker = walker->next;
            }
            if (walker->data == val) {
                found = walker;
            }
        }
        return found;
    }

    // remove node from list
    // does not release memory, caller responsible for deleting node
    NODE* Remove(NODE* node) {
        std::cout << "++ SLL::Remove(NODE* " << node << ") " << std::endl;
        NODE* removed = node;
        if (removed == NULL) {
            std::cout << "-- SLL::Remove() " << std::endl;
            return removed;
        }
        if (this->head == node) {
            this->head = node->next;
            std::cout << "-- SLL::Remove() list empty" << std::endl;
            return removed;
        }
        NODE* walker = head;
        NODE* prev = NULL;
        std::cout << "walker = " << walker << std::endl;
        while (walker != NULL) {
            std::cout << "walker != NULL" << std::endl;
            if (node == walker->next) {
                prev = walker;
                std::cout << "node == walker->next" << std::endl;
                removed = node;
                std::cout << "removed = " << removed << std::endl;
                if (prev != NULL) {
                    prev->next = walker->next;
                }
                break;
            }
            else if (walker == node) {
                if (prev != NULL) {
                    prev->next = walker->next;
                }
                removed = node;
                removed->next = NULL;
                break;
            }
            else {
                prev = walker;
                walker = walker->next;
            }
        }
        std::cout << "-- SLL::Remove() " << std::endl;
        return removed;
    }
    // remove node from list
    // does not release memory, caller responsible for deleting node
    NODE* Remove(int val) {
        NODE* removed = NULL;
        if (head == NULL) {
            return removed;
        }
        NODE* walker = head;
        NODE* prev = NULL;
        while (walker != NULL) {
            if (val == walker->data) {
                removed = walker;
                if (prev != NULL) {
                    prev->next = walker->next;
                }
            }
            else {
                prev = walker;
                walker = prev->next;
            }
        }
        return removed;
    }
    NODE* Head() {
        return this->head;
    }

    NODE* Tail() {
        NODE* tail = this->Next(NULL);
        while (tail != NULL && tail->next != NULL) {
            tail = tail->next;
        }
        return tail;
    }

    NODE* Next(NODE* hint) {
        return ((hint != NULL) ? hint->next : head);
    }

    int Size() {
        NODE* node = this->Next(NULL);
        int list_size = 0;
        while (node != NULL) {
            list_size++;
            node = this->Next(node);
        }
        return list_size;
    }

    void Dump() {
        NODE* node = this->Next(NULL);
        size_t counter = 0;

        while (node != NULL) {
            std::cout << counter << ": node: " << node << "data: " << node->data << std::endl;
            node = this->Next(node);
            ++counter;
        }
    }

};



#endif // LINKED_LIST_WITH_INSERT_H_INCLUDED
