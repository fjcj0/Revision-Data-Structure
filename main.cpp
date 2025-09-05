#include <iostream>
const int max_size = 100;
class stack {
    int top;
    int item[max_size];
public:
    stack() : top(-1) {}
    void push(int element) {
        if (top >= max_size - 1) {
            std::cout << "Stack is full!!" << std::endl;
        } else {
            top++;
            item[top] = element;
        }
    }

    bool isEmpty() {
        return top < 0;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty!!" << std::endl;
        } else {
            top--;
        }
    }

    void pop(int &element) {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
        } else {
            element = item[top];
            top--;
        }
    }

    void getTop(int &stackTop) {   // Changed return type to void
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
        } else {
            stackTop = item[top];
            std::cout << stackTop << std::endl;
        }
    }

    void print() {
        std::cout << "[";
        for (int i = 0; i <= top; i++) {
            std::cout << item[i];
            if (i < top) {
                std::cout << ",";
            }
        }
        std::cout << "]" << std::endl;
    }
};
int main() {
    stack s;
    s.push(100);
    s.push(200);
    s.push(400);

    s.print();

    int topValue;
    s.getTop(topValue);

    s.pop();
    s.print();

    return 0;
}
