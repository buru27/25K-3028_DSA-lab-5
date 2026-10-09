
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<char> inStack, outStack;

public:
    void enqueue(char x) {
        inStack.push(x);
    }

    char dequeue() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }

        if (outStack.empty()) {
            cout << "Queue is empty\n";
            return '\0';
        }

        char x = outStack.top();
        outStack.pop();
        return x;
    }
};

int main() {
    MyQueue q;

    q.enqueue('A');
    q.enqueue('B');

    cout << "Dequeued: " << q.dequeue() << endl;

    q.enqueue('C');

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    return 0;
}


