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
    @brief Inserts a new element to the end of the queue
*/
void Fifo::Insert(float pqTime, float arrivalTime)
{
    // new customer instance
    Node* newCustomer = new Node(pqTime, arrivalTime);
    // check if rear is null
    if(back == nullptr)
    {
        front = newCustomer;
        back = newCustomer;
    }
    // else set new customer to back of queue
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
    // check if queue is empty
    if(isEmpty())
    {
        std::cerr << "Fifo Queue is Empty! Nobody to serve!" << std::endl; 
    }

    // get customer to serve
    Node* removedCustomer = front;

    // set front to next customer in line
    front = front->nextCustomer;

    // Check if fifo queue is now empty after serving
    if(front == nullptr)
    {
        back = nullptr;
    }

    // return the served custeomer
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
