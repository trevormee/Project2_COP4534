/***************************************************************
  Student Name: Trevor Mee
  File Name: PriorityQueue.cpp
  Project 2

  @brief Contains function definitions for setting up a priority
         queue, inserting and serving a  customer
***************************************************************/

#include "Headers/PriorityQueue.hpp"

/*
  @brief Default constructor
*/
PriorityQueue::PriorityQueue()
{
    theSize = 0;
    heap[0] = -1;
}

/*
  @brief Percolate up thru heap while maintaining
         heap condition
  @param x: event time to insert
*/
void PriorityQueue::PercolateUp(float x)
{
    heap[0] = x;
    int slot = ++theSize;
    std::cout << "Inserted element: " << std::fixed << std::setprecision(2) << x << " at index: " << slot << std::endl; // Print the initial insertion
    
    while (x < heap[slot / 2])
    {
        heap[slot] = heap[slot / 2];
        slot /= 2;
        std::cout << "Moved element to index: " << slot << " with value: " << heap[slot] << std::endl; // Print each move
    }
    
    heap[slot] = x;
    std::cout << "Final position of element " << x << " is index: " << slot << std::endl; // Print final position
    std::cout << std::endl;
}

/*
  @brief Percolate down thru heap while maintaining 
         heap condition
  @param slot: index of heap to percolate down from
*/
void PriorityQueue::PercolateDown(int slot)
{
    int child;
    int tmp = heap[slot];

    while(slot * 2 <= theSize)
    {
      child = slot * 2;
      if(child != theSize && ( heap[child + 1] < heap[child] ))
          child++;
      if(heap[child] < tmp)
          heap[slot] = heap[child];
      else
          break;
      
      slot = child;
    }

    heap[slot] = tmp;
}

/*
  @brief Add a new item to the priority queue
  @param time: event time to be inserted
*/
void PriorityQueue::Insert(float time)
{
    // If heap is empty, set value of index 1 = time
    if(isEmpty())
    {
        std::cout << "Heap was empty" << std::endl;
        heap[1] = time;
        theSize++;
    }
    // Check for heap overflow
    else if(theSize > SIZE)
    {
        std::cerr << "Heap already full! Overflow Error!" << std::endl;
        return;
    }
    // Percolate up 
    else
    {
        PercolateUp(time);
    }

}

/*
  @brief Serve (pop) highest priority customer (min)

  @return The event at top of heap 
*/
float PriorityQueue::Serve()
{
    if(theSize == 0)
    {
      std::cerr << "Heap/Priority Queue is empty!" << std::endl;
      return -1.0;
    }

    float deleteItem = heap[1];
    heap[1] = heap[theSize--];
    PercolateDown(1);
    return deleteItem;
}


void PriorityQueue::Traversal()
{
    std::cout << "Traversal theSize = " << theSize << std::endl;
    for(int i = 1; i < theSize + 1; i++)
    {
      if(theSize > 0)
        std::cout << "Index: " << i << " has a value of : " << std::fixed << std::setprecision(2) << heap[i] << std::endl;
      else
        std::cout << "No traversal needed. Heap is empty!" << std::endl;
    }
}

/*
  @brief Checks if heap is empty

  @return true if theSize == 0
          false if theSize != 0
*/
bool PriorityQueue::isEmpty()
{
    return theSize == 0;
}