/***************************************************************
  Student Name: Trevor Mee
  File Name: Fifo.cpp
  Project 2

  @brief Contains function declarations for setting up,
         inserting, and popping from a FIFO queue
***************************************************************/

#include "Headers/Fifo.hpp"

/*
    @brief Default constructor to set pointers to null
*/
Fifo::Fifo()
{
    this->front = nullptr;
    this->back = nullptr;
}

/*
    @brief Inserts a new node (customer) into FIFO queue
*/
void Fifo::Insert(Node* newCustomer)
{
    if(back == nullptr)
    {
        front = newCustomer;
        back = newCustomer;
    }
    else
    {
        back->nextCustomer = newCustomer;
        back = newCustomer;
    }
}

/*
    @brief Serves a customer (remove from queue)

    @return The deleted element
*/
Node* Fifo::Serve()
{
    if(isEmpty())
    {
        std::cerr << "FIFO Queue is Empty! No customers to serve" << std::endl; 
        return nullptr;
    }

    Node* removedCustomer = front;
    front = front->nextCustomer;

    if(front == nullptr)
    {
        back = nullptr;
    }

    return removedCustomer;
}

/*
    @brief Helper function to check if fifo queue is empty

    @return True if front == nullptr
            False if front != nullptr
*/
bool Fifo::isEmpty()
{
    if(front == nullptr)
    {
      return true;
    }
    return false;
}

/*
    @brief Traverse and print the queue from front to back
*/
void Fifo::Traversal()
{
    Node* current = front;
    
    if (isEmpty())
    {
        std::cout << "Fifo Queue is empty." << std::endl;
        return;
    }

    std::cout << "Fifo Queue contents (front to back):" << std::endl;
    
    while (current != nullptr)
    {
        std::cout << "Customer pqTime: " << current->pqTime;
        std::cout << ", Arrival: " << current->isArrival << std::endl;
        current = current->nextCustomer;
    }
}

/*
    @brief Checks the current size of the fifo queue

    @return Current size of the fifo queue
*/
int Fifo::getSize()
{
    int count = 0;
    Node* current = front;

    while (current != nullptr)
    {
        count++;
        current = current->nextCustomer;
    }

    return count;
}