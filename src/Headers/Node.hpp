/***************************************************************
  Student Name: Trevor Mee
  File Name: Node.hpp
  Project 2

  @brief Contains a definiton for a node structure to be used
         in class 'Fifo'
***************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

class Node
{
    public:
        
        // Public member variables
        float pqTime;
        float arrivalTime;
        float startOfServiceTime;
        float departureTime;
        Node* nextCustomer;

        // Parameterized Constructor
        Node(float pqTime, float arrivalTime)
        {
            this->pqTime = pqTime;
            this->arrivalTime = arrivalTime;
            startOfServiceTime = 0;
            departureTime = 0;
            nextCustomer = nullptr;
        }
};
#endif