#include "Node.h"
#include <cstddef> // needed for definition of NULL
#include <iostream>
using namespace std;


Node::Node(void)
:value(0), next(NULL)
{
}

Node::Node(int value)
:value(value), next(NULL)
{
}

Node::~Node(void)
{
    cout << endl << "deleted Node with value " << value;
}

int Node::getValue(void)
{
  return value;
}

void Node::setValue(int value)
{
  this->value = value;
}

Node * Node::getNext(void)
{
  return (Node*)next;
}

void Node::setNext(Node * next)
{
  this->next = next;
}
