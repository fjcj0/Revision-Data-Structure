#include <iostream>
#include <cassert>
using namespace std;
template <class t>
class queueLinkedList{
    struct node{
        node*next;
        t item;
    };
public:
    node*front;
    node*rear;
    queueLinkedList(){
        front = rear = NULL;
    }
    bool isEmpty(){
        return front==NULL;
    }
    void push(t newItem){
        if(isEmpty()){
            node*newItemPtr = new node();
            front=newItemPtr;
            front->item = newItem;
            front->next = rear;
            rear = front;
        }else{
            node*newItemPtr = new node();
            newItemPtr->item = newItem;
            rear->next = newItemPtr;
            rear = newItemPtr;
        }
    }
    void pop(){
        if(isEmpty()){
            std::cout << "LinkedList is empty!!"<<std::endl;
        }else{
            node*temp = front;
            front = front->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }
    void print(){
        node*cur=front;
        std::cout << "[";
        while(cur!=NULL){
            std::cout << cur->item;
            if(cur->next != NULL){
                std::cout << ",";
            }
            cur = cur->next;
        }
        std::cout << "]"<<std::endl;
    }
};
int main(){
    queueLinkedList<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.print();

    q.pop();
    q.print();

    q.pop();
    q.pop();
    q.pop();
    q.print();
    return 0;
}
