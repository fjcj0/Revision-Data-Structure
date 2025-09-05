#include <iostream>
#include <cassert>
using namespace std;

template <class T>
class FullLinkedList {
    struct node {
        node* next;
        T item;
    };

public:
    node* head;
    node* tail;
    int length;

    FullLinkedList() {
        head = tail = NULL;
        length = 0;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void addFirst(T newItem) {
        node*newItemPtr = new node();
        newItemPtr->item = newItem;
        if(isEmpty()){
            newItemPtr->next = NULL;
            head = tail = newItemPtr;
        }else{
            newItemPtr->next = head;
            head = newItemPtr;
        }
        length++;
    }
    
    void addLast(T newItem){
        node*newItemPtr = new node();
        newItemPtr->item = newItem;
        if(isEmpty()){
            newItemPtr->next = NULL;
            head = tail = newItemPtr;
        }else{
            newItemPtr->next = NULL;
            tail->next = newItemPtr;
            tail = newItemPtr;
        }
        length++;
    }
    
    void addAtPos(T newItem,int index){
        if(index==0){
            addFirst(newItem);
        }else if (index == length){
            addLast(newItem);
        }else{
            node*newItemPtr = new node();
            newItemPtr->item = newItem;
            node* cur = head;
            node* pre = NULL;
            for (int i = 0; i < index; i++) {
                pre = cur;
                cur = cur->next;
            }
            pre->next = newItemPtr;
            newItemPtr->next = cur;
            length++;
        }
    }

    void removeFirst() {
        assert(!isEmpty() && "Cannot pop from an empty linked list!");
        node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        delete temp;
        length--;
    }
    
    void removeLast() {
        assert(!isEmpty() && "Cannot pop from an empty linked list!");
        node * cur = head->next;
        node * pre = head;
        while(cur!=tail){
            pre = cur;
            cur =cur->next;
        }
        pre->next = NULL;
        tail = pre;
        cur = cur->next = NULL;
        delete cur;
        length--;
    }
    
    void removeAt(int index) {
        assert(index < length && "Index is out of bounds!");
        if (index == 0) {
            removeFirst();
        } else if (index == length - 1) {
            removeLast();
        } else {
            node* cur = head;
            node* pre = NULL;
            for (int i = 0; i < index; i++) {
                pre = cur;
                cur = cur->next;
            }
            pre->next = cur->next;
            delete cur;
            length--;
        }
    }
    
    int findIndexOf(T element){
        assert(!isEmpty() && "Cannot Find Index from an empty linked list!");
        int count = 0;
        node*cur = head;
        while(cur!=NULL){
            if(cur->item == element){
                return count;
            }
            count++;
            cur=cur->next;
        }
        return -1;
    }
    
    T getElementOfIndex(int index){
        assert(!isEmpty() && "Cannot Get Element from an empty linked list!");
        assert(index >= 0 && index < length && "Index is out of bounds!");
        if(index==0) return getHead();
        else if (index==length-1)return getTail();
        node* cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->item;
    }
    
    void print(){
        node*cur = head;
        std::cout << "[";
        while(cur!=NULL){
            std::cout << cur->item;
            if(cur->next != NULL)std::cout << ",";
            cur=cur->next;
        }
        std::cout << "]"<<std::endl;
    }
    
    T getHead() {
        assert(!isEmpty() && "Linked list is empty, no head!");
        return head->item;
    }
    
    T getTail(){
        assert(!isEmpty() && "Linked list is empty, no tail!");
        return tail->item;
    }
    
    int size() {
        return length;
    }
    
    void reverse(){
        assert(!isEmpty() && "Linked list is empty, no reverse!");
        node*cur = head;
        node*nxt = head->next;
        node*pre = NULL;
        while(cur!=NULL){
            nxt = cur->next;
            cur->next = pre;
            pre=cur;
            cur=nxt;
        }
        head = pre;
    }
};

int main() {
    FullLinkedList<int> list;
    list.addFirst(10);
    list.addFirst(20);
    list.addFirst(30);
    list.addAtPos(100, 2);
    list.addAtPos(0, 0);
    list.print();
    std::cout << list.findIndexOf(100)<<std::endl;
    std::cout << list.getElementOfIndex(2) << std::endl;
    list.reverse();
    list.print();
    return 0;
}
