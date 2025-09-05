#include <iostream>
template <typename t>
class stack {
    struct node {
        t item;
        node*next;
    };
public:
    node*top;
    stack() : top(NULL) {}
    bool isEmpty(){
        return top == NULL;
    }
    void push(t newItem){
        node*newItemPtr = new node();
        newItemPtr->item = newItem;
        newItemPtr->next = top;
        top = newItemPtr;
    }
    void pop(){
        if(isEmpty()){
            std::cout << "LinkedList stack is empty!!" << std::endl;
        }else{
            node*temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }
    void print(){
        node*cur = top;
        std::cout << "[";
        while(cur!=NULL){
            std::cout << cur->item;
            if(cur->next!=NULL){
                std::cout << ",";
            }
            cur=cur->next;
        }
        std::cout << "]"<< std::endl;
    }
};
int main() {
    stack<int>s;

    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Stack after pushes: ";
    s.print();

    s.pop();
    std::cout << "Stack after pop: ";
    s.print();

    std::cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << std::endl;
    return 0;
}
