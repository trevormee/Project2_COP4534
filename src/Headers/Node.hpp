/***************************************************************
  Student Name: Trevor Mee
  File Name: Node.hpp
  Project 2

  @brief Contains a definiton for a node to be used to represent 
         a customer in the system
***************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

class Node
{
    public:
        // Public Instance variables
        float pqTime;
        float arrivalTime;
        float startOfServiceTime;
        float departureTime;
        bool isArrival;     // true if event is an arrival, false if departure
        Node* nextCustomer;

        // Parameterized Constructor
        Node(float pqTime, bool isArrival)
        {
            this->pqTime = pqTime;
            this->isArrival = isArrival;
            if(isArrival)
                arrivalTime = pqTime;
            else
                departureTime = pqTime;

            startOfServiceTime = 0;
            departureTime = 0;
            nextCustomer = nullptr;
        }
};
#endif