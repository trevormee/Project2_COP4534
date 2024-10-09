/***************************************************************
  Student Name: Trevor Mee
  File Name: PriorityQueue.cpp
  Project 2

  @brief Contains function definitions for implementing a 
         priority queue 
***************************************************************/

#include "Headers/PriorityQueue.hpp"

/*
  @brief Default constructor to set the size of the 
         heap and first index of heap to default value
*/
PriorityQueue::PriorityQueue()
{
    theSize = 0;
    heap[0] = nullptr;
}

/*
  @brief Percolate up thru heap while maintaining
         heap condition
  @param node: Node to insert
*/
void PriorityQueue::PercolateUp(Node* node)
{
    heap[0] = node;  
    int slot = ++theSize;
    
    while (node->pqTime < heap[slot / 2]->pqTime)
    {
        heap[slot] = heap[slot / 2];
        slot /= 2;
    }
    
    heap[slot] = node;
}

/*
  @brief Percolate down thru heap while maintaining 
         heap condition
  @param slot: index of heap to percolate down from
*/
void PriorityQueue::PercolateDown(int slot)
{
    int child;
    Node* tmp = heap[slot];

    while(slot * 2 <= theSize)
    {
        child = slot * 2;
        if(child != theSize && ( heap[child + 1]->pqTime < heap[child]->pqTime ))
            child++;
        if(heap[child]->pqTime < tmp->pqTime)
            heap[slot] = heap[child];
        else
            break;
        
        slot = child;
    }

    heap[slot] = tmp;
}

/*
  @brief Add a new item to the priority queue
  @param node: Node to be inserted
*/
void PriorityQueue::Insert(Node* node)
{
    if(isEmpty())
    {
        heap[1] = node;
        theSize++;
    }
    else if(theSize > SIZE)
    {
        std::cerr << "Heap already full! Overflow Error!" << std::endl;
        return;
    }
    else
    {
        PercolateUp(node);
    }
}


/*
  @brief Serve (pop) highest priority customer (min)

  @return The event at top of heap 
*/
Node* PriorityQueue::Serve()
{
    if(theSize == 0)
    {
      std::cerr << "Heap/Priority Queue is empty!" << std::endl;
      return nullptr;
    }

    Node* deleteNode = heap[1];
    heap[1] = heap[theSize--];

    return deleteNode;
}

/*
    @brief peeks (grabs) first node at index 1 in heap

    @return heap[1] if heap is not empty
            nullptr if heap is empty
*/
Node* PriorityQueue::Peek()
{
    if(!isEmpty())
    {
        return heap[1];
    }

    std::cerr << "Could not peek! PQ is empty!" << std::endl;
    return nullptr;
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