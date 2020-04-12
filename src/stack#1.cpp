/* Basic Stack Program */

#include <iostream>

class Stack
{
private:
    struct Node
    {
        int info;
        struct Node *next;
    };
    struct Node *top;

public:
    static const int maxLength = 1024;
    int length;
    Stack();
    ~Stack();
    void push(int data);
    int pop();
    void peek();
};

Stack::Stack()
{
    std::cout << "\nIntitialising an empty Stack...\n";
    length = 0;
    top = NULL;
}

Stack::~Stack()
{
    std::cout << "\nDestroying Stack...\n";
    if (top)
    {
        struct Node *temp;
        while (!top)
        {
            temp = top;
            top = top->next;
            delete temp;
        }
    }
}

void Stack::push(int data)
{
    if (length >= maxLength)
    {
        std::cout << "\nStack Overflow!\n";
        return;
    }
    struct Node *newNode = new struct Node();
    newNode->info = data;
    newNode->next = NULL;
    if (top)
        newNode->next = top;
    top = newNode;
    length++;
}

int Stack::pop()
{
    if (!top)
    {
        std::cout << "Stack is Empty!" << std::endl;
        return -1;
    }
    struct Node *temp = top;
    int data = temp->info;
    top = top->next;
    delete temp;
    length--;
    return data;
}

void Stack::peek()
{
    struct Node *temp;
    std::cout << "Stack:\n";
    for (temp = top; temp != NULL; temp = temp->next)
    {
        std::cout << temp->info << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Stack myStack = Stack();
    myStack.push(11);
    myStack.push(22);
    myStack.push(33);
    myStack.push(44);
    myStack.push(55);
    myStack.peek();
    std::cout << "Length of stack: " << myStack.length << std::endl;
    std::cout << "Popped: " << myStack.pop() << std::endl;
    std::cout << "Popped: " << myStack.pop() << std::endl;
    std::cout << "Popped: " << myStack.pop() << std::endl;
    myStack.peek();
    std::cout << "Length of stack: " << myStack.length << std::endl;
    return 0;
}