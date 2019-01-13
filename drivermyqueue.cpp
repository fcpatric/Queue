#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include "MyQueue.h"

int main (int argc, char const* argv[])
{
    int points = 0;

    MyQueue q;
    char c;
    string s;

    // test one -- tests isEmpty function when queue is empty
    if ( q.isEmpty() )
    {
        points++;
        cout << "TEST ONE: PASSED" << endl;
    }
    else
        cout << "TEST ONE: FAILED" << endl;

    // test two -- test isEmpty function with one elemet in queue
    q.enqueue('A');

    if ( !q.isEmpty() )
    {
        points++;
        cout << "TEST TWO: PASSED" << endl;
    }
    else
        cout << "TEST TWO: FAILED" << endl;

    // test three -- tests dequeue && isEmpty when dequeuing a node from
    // single node queue
    q.dequeue(c);

    if ( q.isEmpty() )
    {
        points++;
        cout << "TEST THREE: PASSED" << endl;
    }
    else
        cout << "TEST THREE: FAILED" << endl;

    // test four -- tests enqueue and dequeue and isEmpty.
    // enqueues 4 characters then dequeues all of them.
    // tests for FIFO.
    for( char c = 'a'; c <= 'f'; c++ )
        q.enqueue(c);

    while( !q.isEmpty() )
    {
        q.dequeue(c);
        s += c;
    }

    if ( s == "abcdef" )
    {
        points += 7;
        cout << "TEST FOUR: PASSED" << endl;
    }
    else
        cout << "TEST FOUR: FAILED" << endl;

    cout << "Points: " << points << endl;

    return 0;
}
