#ifndef MyQueue_H
#define MyQueue_H

class MyQueue
{
    private:
        struct Node
        {
            char value;
            Node *next;
        };

        Node *head;
        Node *tail;

    public:
        MyQueue()
        { head = NULL; tail = NULL; }

        void enqueue(char);
        void dequeue(char &);
        bool isEmpty() const;
};

void MyQueue::enqueue(char val)
{
    /// Create a new Node
    Node *newNode = new Node;
    newNode->value = val;

    /// If queue is empty, make head points to the new node
    if( isEmpty() )
        head = newNode;

    /// If queue is not empty, make tail points to the new node
    else
        tail->next = newNode;

    newNode->next = NULL; /// Make the new node point to NULL
    tail = newNode; /// Make tail points to the new node
}

void MyQueue::dequeue(char &ch)
{
    /// If queue is empty, do nothing
    if( isEmpty() )
        return;

    /// If queue is not empty...
    else
    {
        Node *help = head; /// Create a help pointer and initialize to point to head
        head = head->next; /// Make head point to the next node
        ch = help->value;
        delete help; /// delete the node
    }
}

bool MyQueue::isEmpty() const
{
    if(head == NULL)
        return true;
    else
        return false;
}

#endif // MyQueue_H
