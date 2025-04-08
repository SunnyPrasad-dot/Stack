#include <iostream>
using namespace std;

// Stack class using array
class Stack {
private:
    int* arr;
    int topIndex;
    int capacity;

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Push method
    void push(int value) {
        if (topIndex >= capacity - 1) {
            cout << "Stack is full. Cannot push." << endl;
        } else {
            arr[++topIndex] = value;
            cout << value << " pushed to stack." << endl;
        }
    }

    // Pop method
    void pop() {
        if (topIndex < 0) {
            cout << "Stack is empty. Cannot pop." << endl;
        } else {
            cout << arr[topIndex--] << " popped from stack." << endl;
        }
    }

    // Top method
    void displayTop() {
        if (topIndex < 0) {
            cout << "Stack is empty. No top element." << endl;
        } else {
            cout << "Top element is: " << arr[topIndex] << endl;
        }
    }

    // Check if empty
    void isEmpty() {
        if (topIndex == -1)
            cout << "Stack is empty." << endl;
        else
            cout << "Stack is not empty." << endl;
    }

    // Check if full
    void isFull() {
        if (topIndex == capacity - 1)
            cout << "Stack is full." << endl;
        else
            cout << "Stack is not full." << endl;
    }
};

// Main function
int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack s(size);

    int choice, value;

    do {
        cout << "\n1. Push\n2. Pop\n3. Display Top\n4. Check if Empty\n5. Check if Full\n6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.displayTop();
            break;
        case 4:
            s.isEmpty();
            break;
        case 5:
            s.isFull();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 6);

    return 0;
}