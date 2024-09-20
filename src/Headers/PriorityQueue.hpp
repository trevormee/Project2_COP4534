/***************************************************************
  Student Name: Trevor Mee
  File Name: PriorityQueue.hpp
  Project 2

  @brief Contains function declarations for setting up a priority
         queue, inserting and serving a customer
***************************************************************/

#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <iostream>

class PriorityQueue
{
    private:
      const static int SIZE = 200;   // As per Proj. 2 Instructions
      int theSize;
      float heap[SIZE + 1];

    public:
      // Default Constructor
      PriorityQueue();
      
      // Parameterized Constructor
      //PriorityQueue(int initialSize);
      
      // Percolate up thru heap
      void PercolateUp(double);

      // Percolate down thru heap
      void PercolateDown(int slot);

      // Insert a new item into heap
      void Insert(float time);

      // Serve a cutomer (Pop)
      float Serve();

      void Traversal();
};
#endif
