/***************************************************************
  Student Name: Trevor Mee
  File Name: PriorityQueue.hpp
  Project 2

  @brief Contains function declarations for implementing a 
         priority queue 
***************************************************************/

#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <iostream>
#include <iomanip>
#include "Node.hpp"

class PriorityQueue
{
    private:
      // Private Instance Variables
      const static int SIZE = 200;   // As per Proj. 2 Instructions

    public:
      // Public Instance Variables
      int theSize;
      Node* heap[SIZE + 1];

      // Default Constructor
      PriorityQueue();
      
      // Percolate up thru heap
      void PercolateUp(Node* node);

      // Percolate down thru heap
      void PercolateDown(int slot);

      // Insert a new item into heap
      void Insert(Node* node);

      // Serve a cutomer (Pop)
      Node* Serve();

      // Get the first customer
      Node* Peek();
      
      // Checks if heap is empty
      bool isEmpty();
};
#endif
