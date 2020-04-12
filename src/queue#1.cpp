/* Basic Queue Program */
#include <iostream>

class Queue
{
private:
    struct Node
    {
        int info;
        struct Node *next;
    };
    struct Node *front, *rear;

public:
    static const int maxLength = 1023;
    int length;
    Queue();
    ~Queue();
    void enqueue(int data);
    int dequeue();
    void display();
};

Queue::Queue()
{
    std::cout << "\nInitialising a empty queue...\n";
    front = rear = NULL;
    length = 0;
}

Queue::~Queue()
{
    std::cout << "\nDestroying queue...\n";
    if (front && rear)
    {
        if (front == rear)
            delete front;
        else
        {
            struct Node *temp = NULL;
            while (front)
            {
                temp = front;
                front = front->next;
                delete temp;
            }
        }
    }
}

void Queue::enqueue(int data)
{
    if (length >= maxLength)
    {
        std::cout << "Queue is full!" << std::endl;
        return;
    }
    struct Node *newNode = new struct Node();
    newNode->info = data;
    newNode->next = NULL;
    if (!front && !rear)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    length++;
}

int Queue::dequeue()
{
    if (!front && !rear)
    {
        std::cout << "Queue is empty!" << std::endl;
        return -1;
    }
    int data = front->info;
    if (front == rear)
    {
        delete front;
        front = rear = NULL;
    }
    else
    {
        struct Node *temp = front;
        front = front->next;
        delete temp;
    }
    length--;
    return data;
}

void Queue::display()
{
    std::cout << "Queue:\n";
    struct Node *temp;
    for (temp = front; temp != NULL; temp = temp->next)
    {
        std::cout << temp->info << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Queue myQueue = Queue();
    myQueue.enqueue(11);
    myQueue.enqueue(22);
    myQueue.enqueue(33);
    myQueue.enqueue(44);
    myQueue.enqueue(55);
    myQueue.display();
    std::cout << "Length of queue: " << myQueue.length << std::endl;
    std::cout << "Dequeued: " << myQueue.dequeue() << std::endl;
    std::cout << "Dequeued: " << myQueue.dequeue() << std::endl;
    myQueue.display();
    std::cout << "Length of queue: " << myQueue.length << std::endl;
    return 0;
}