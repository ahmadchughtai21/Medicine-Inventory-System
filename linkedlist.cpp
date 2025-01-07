#include <iostream>
#include <string>

using namespace std;


class Node
{
public:
    string name;
    int quantity;
    int exp_date;
    Node *next;

    Node()
    {
        name = "Null";
        quantity = 0;
        exp_date = 0;
        next = nullptr;
    }
};

void add_med()
{
    Node *newNode = new Node;
}