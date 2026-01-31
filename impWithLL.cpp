#include<iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Stack operations
class Stack {
public:
    Node* head;   // top of stack

    Stack() {
        head = NULL;
    }

    // PUSH
    void push(int data) {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    // POP
    void pop() {
        if (head == NULL) {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // PEEK
    int peek() {
        if (head == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return head->data;
    }

    bool isEmpty() {
    if (head == NULL)
        return true;
    else
        return false;
}


    // DISPLAY
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    st.display();   // 40 30 20 10

    st.pop();
    st.display();   // 30 20 10

    cout << "Top element: " << st.peek() << endl;

    st.isEmpty();

    return 0;
}
