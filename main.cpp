#include <iostream>
#include <cassert>
template <class T>
class DoublyLinkedList {
    struct node{
        node*next;
        node*pre;
        T item;
    };
public:
    node*head;
    node*tail;
    int length;
    DoublyLinkedList(): head{NULL},tail{NULL},length{0} {}
    bool isEmpty(){
        return head ==NULL;
    }
    void InsertLast(T newItem){
        node* newItemPtr = new node();
        newItemPtr->item = newItem;
        newItemPtr->next = NULL;
        if(isEmpty()){
            newItemPtr->pre = NULL;
            head = tail = newItemPtr;
        } else {
            newItemPtr->pre = tail;
            tail->next = newItemPtr;
            tail = newItemPtr;
        }
        length++;
    }
    void InsertFirst(T newItem){
        node* newItemPtr = new node();
        newItemPtr->item = newItem;
        if(isEmpty()){
            newItemPtr->next = NULL;
            newItemPtr->pre = NULL;
            head = tail = newItemPtr;
        }else{
            newItemPtr->pre = NULL;
            newItemPtr->next = head;
            head->pre = newItemPtr;
            head = newItemPtr;
        }
        length++;
    }
    void DeleteFirst(){
        assert(!isEmpty());
        node* temp = head;
        if(head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->pre = NULL;
        }
        temp = temp->next = NULL;
        delete temp;
        length--;
    }
    void DeleteLast(){
        assert(!isEmpty());
        node* temp = tail;
        if(head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->pre;
            tail->next = NULL;
        }
        delete temp;
        length--;
    }
    void removeAtPos(int pos){
        assert(pos >= 0 && pos < length);
        if(pos == 0){
            DeleteFirst();
        }
        else if(pos == length-1){
            DeleteLast();
        }
        else{
            node* cur = head;
            for(int i = 0; i < pos; i++){
                cur = cur->next;
            }
            node* preNode = cur->pre;
            node* nextNode = cur->next;
            preNode->next = nextNode;
            nextNode->pre = preNode;
            delete cur;
            length--;
        }
    }
    void insertAtPos(int pos, T newItem){
        assert(pos >= 0 && pos <= length);

        if(pos == 0){
            InsertFirst(newItem);
        }
        else if(pos == length){
            InsertLast(newItem);
        }
        else{
            node* cur = head;
            for(int i = 0; i < pos; i++){
                cur = cur->next;
            }
            node* preNode = cur->pre;

            node* newItemPtr = new node();
            newItemPtr->item = newItem;
            newItemPtr->next = cur;
            newItemPtr->pre = preNode;
            preNode->next = newItemPtr;
            cur->pre = newItemPtr;
            length++;
        }
    }
    T getTail(){
        assert(!isEmpty());
        return tail->item;
    }
    T getHead(){
        assert(!isEmpty());
        return head->item;
    }
    void print(){
        node*cur = head;
        std::cout <<  std::endl << "[";
        while(cur!=NULL){
            std::cout << cur->item;
            if(cur->next != NULL)std::cout << ",";
            cur=cur->next;
        }
        std::cout << "]" << std::endl;
    }
};
int main() {
    DoublyLinkedList<int> dll;
    dll.InsertLast(10);
    dll.InsertLast(20);
    dll.InsertLast(30);
    dll.print();
    dll.InsertFirst(5);
    dll.print();
    dll.insertAtPos(2, 15);
    dll.print();
    dll.DeleteFirst();
    dll.print();
    dll.DeleteLast();
    dll.print();
    dll.removeAtPos(1);
    dll.print();
    std::cout << std::endl<<  "Head: " << dll.getHead() << std::endl << std::endl;
    std::cout << "Tail: " << dll.getTail() << std::endl;
    return 0;
}
