/***************************************************************
  Student Name: Trevor Mee
  File Name: Fifo.hpp
  Project 2

  @brief Contains function declarations for setting up,
         inserting, and popping from a FIFO queue
***************************************************************/

#ifndef FIFO_HPP
#define FIFO_HPP

#include "Node.hpp"
#include <iostream>

class Fifo
{
    private:
        // Private Instance Variables
        Node* front;
        Node* back;

    public:
        // Default Constructor
        Fifo();

        // Insert a new customer
        void Insert(Node* newCustomer);
        
        // Serve (delete) a customer
        Node* Serve();

        // Checks if Fifo Queue is empty
        bool isEmpty();

        void Traversal();
        
        // Returns the current size of the fifo queue
        int getSize();
};
#endif
