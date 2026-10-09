
#include <iostream>
using namespace std;

class Stack {
    int arr[8];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == 7) {
            cout << "Stack is full\n";
            return;
        }

        arr[++top] = x;
        cout << "Push " << x << ": ";
        displayTop();
    }

    void undo() {
        if (top == -1) {
            cout << "Undo: Stack is empty\n";
            return;
        }

        cout << "Undo " << arr[top] << ": ";
        top--;
        displayTop();
    }

    void displayTop() {
        if (top == -1)
            cout << "Top = Empty\n";
        else
            cout << "Top = " << arr[top] << endl;
    }

    void displayStack() {
        cout << "\nRemaining operations (top to bottom): ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(12);
    s.push(25);
    s.push(17);
    s.push(31);
    s.push(44);
    s.push(19);

    s.undo();
    s.undo();
    s.undo();

    s.push(52);

    s.undo();
    s.undo();

    s.displayStack();

    return 0;
}


