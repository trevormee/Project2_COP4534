/***************************************************************
  Student Name: Trevor Mee
  File Name: PriorityQueue.cpp
  Project 2

  @brief Contains function definitions for setting up a priority
         queue, inserting and serving a customer
***************************************************************/

#include "Headers/PriorityQueue.hpp"

/*
  @brief Default constructor
*/
//PriorityQueue::PriorityQueue() {}
PriorityQueue::PriorityQueue() : theSize(0) {
    // Initialize the heap
    heap[0] = -1; // We won't use index 0, heap starts from 1
}

/*
  @brief Parameterized constructor to construct an 
         empty heap
  @param
*
PriorityQueue::PriorityQueue(int initialSize)
{

}
*/

/*
  @brief Percolate up thru heap while maintaining
         heap condition
  @param x: event time to insert
*/
void PriorityQueue::PercolateUp(double x)
{
    //std::cout << "\nx = " << x << std::endl;
    //std::cout << "The size = " << theSize << std::endl;
    heap[0] = x;
    std::cout << "heap[0] = " << heap[0] << std::endl;
    int slot = ++theSize;//theSize + 1;
    std::cout << "slot = " << slot << std::endl;
    while(x < heap[slot/2])
    {
      heap[slot] = heap[slot / 2];
      slot /= 2;
    }

    heap[slot] = x; 
    std::cout << "Final slot = " << slot << std::endl;
    std::cout << "heap[slot] = " << heap[slot] << std::endl;
  
    /*
    float temp = heap[index];
    std::cout << "Temp = " << temp << std::endl;

    // Move up the heap while the parent is greater than the current element
    while (index > 1 && heap[index / 2] > temp) {
        heap[index] = heap[index / 2];
        index /= 2;
    }

    heap[index] = temp;
    std::cout << "Heap[index] = " << heap[index] << std::endl;
    */
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
    if(theSize > SIZE)
    {
      std::cerr << "Heap/Priority Queue is full!" << std::endl;
      return;
    }
    std::cout << "the size = " << theSize << std::endl;
    std::cout << "time = " << time << std::endl;
    heap[++theSize] = time;
    std::cout << "the size = " << theSize << std::endl;
    std::cout << "heap ++ the size = " << time << std::endl;
    //PercolateUp(theSize);
    PercolateUp(time);
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
    std::cout << "(1) deleted item = " << deleteItem << std::endl;
    heap[1] = heap[theSize--];
    std::cout << "heap[thesize--] " << heap[1] << std::endl;
    PercolateDown(1);
    std::cout << "(2) deleted item = " << deleteItem << std::endl;
    return deleteItem;
}

void PriorityQueue::Traversal()
{
  for(int i = 0; i < theSize; ++i)
  {
      int y = heap[i];
      std::cout << "Index: " <<  i << " Value: "<< y << std::endl;
  }
}