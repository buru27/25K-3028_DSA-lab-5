
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor {
    stack<string> undoStack, redoStack;
    string document = "";

public:
    void type(string word) {
        undoStack.push(word);
        redoStack = stack<string>();

        if (document != "")
            document += " ";

        document += word;
        print();
    }

    void undo() {
        if (undoStack.empty()) {
            cout << "Nothing to undo\n";
            print();
            return;
        }

        string word = undoStack.top();
        undoStack.pop();
        redoStack.push(word);

        document.erase(document.length() - word.length());

        if (document.length() > 0 &&
    document[document.length() - 1] == ' ')
{
    document.erase(document.length() - 1, 1);
}

        print();
    }

    void redo() {
        if (redoStack.empty()) {
            cout << "Nothing to redo\n";
            print();
            return;
        }

        string word = redoStack.top();
        redoStack.pop();
        undoStack.push(word);

        if (!document.empty())
            document += " ";

        document += word;
        print();
    }

    void print() {
        cout << "Document: " << document << endl;
    }
};

int main() {
    TextEditor e;

    e.type("Hello");
    e.type("World");
    e.undo();
    e.redo();
    e.undo();
    e.type("There");
    e.redo();

    return 0;
}


