// # include <iostream>
// # include <math.h>
// # include <vector>
// #include <stack>
// using namespace std;
// class Stack{
//     //properties
//     public:
//         int *arr;
//         int top;
//         int size;
//         //behaviour
//         Stack(int size){
//             this->size=size;
//             arr=new int[size];
//             top=-1;
//         }
//         void push(int element){
//             if(size-top>1){
//                 top++;
//                 arr[top]=element;

//             }
//             else{
//                 cout<<"Stack overflow"<<endl; 
//             }
//         }
//         void pop(){
//             if(top>=0){
//                 top--;
//             }
//             else{
//                 cout<<"Stack underflow"<<endl;
//             }
//         }
//         int peek(){
//             if(top>=0){
//                 return arr[top];
//             }
//             else{
//                 cout<<"Stack is empty"<<endl;
//                 return -1;
//             }
//         }
//         bool isEmpty(){
//             if(top==-1){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }
// };
// int main() {
//     //imolemention of stack by array
//     Stack st(5);
//     st.push(34);
//     st.push(23);
//     st.push(88);
//     st.push(99);
//     st.push(11);
//     cout<<"Top element of stack is "<<st.peek()<<endl;
//     st.pop();
//     cout<<"Top element of stack is "<<st.peek()<<endl;
//     st.pop();
//     cout<<"Top element of stack is "<<st.peek()<<endl;
//     cout<<st.isEmpty();
//     /*
//     //implement of stack by STL
//     stack <int> s;
//     s.push(3);
//     s.push(5);
//     s.push(8);
//     cout<<"stack element are "<<s.top()<<endl;
//     cout<<"stack size is "<<s.size()<<endl;
//     */
// return 0;
// }


// IMPLEMENT USING LINKEDLIST
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Top pointer
Node* top = NULL;

// Push operation
void push(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    cout << x << " pushed into stack\n";
}

// Pop operation
void pop() {
    if (top == NULL) {
        cout << "Stack Underflow\n";
        return;
    }
    Node* temp = top;
    cout << temp->data << " popped from stack\n";
    top = top->next;
    delete temp;
}

// Peek operation
void peek() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top element is: " << top->data << endl;
}

// Check if stack is empty
bool isEmpty() {
    return top == NULL;
}

// Display stack
void display() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    Node* temp = top;
    cout << "Stack elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function
int main() {
    push(10);
    push(20);
    push(30);
    
    display();
    peek();
    
    pop();
    display();
    
    return 0;
}
