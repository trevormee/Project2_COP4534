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
        Node* front;
        Node* back;

    public:
        // Default Constructor
        Fifo();

        // Insert a new customer
        void Insert(float pqTime, float arrivalTime);

        // Serve (delete) a customer
        Node* Serve();

        // Checks if Fifo Queue is empty
        bool isEmpty();
};
#endif
