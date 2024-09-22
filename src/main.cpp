/***************************************************************
  Student Name: Trevor Mee
  File Name: main.cpp
  Project 2

  @brief Contains main method to run simulation and compare the 
         statistics with the analytical model
***************************************************************/

#include "Headers/AnalyticalModel.hpp"
#include "Headers/PriorityQueue.hpp"
#include "Headers/Node.hpp"
#include "Headers/Fifo.hpp"

#include <iostream>

int main()
{

/**********Start analytical model testing -- PASSED******/
/*
The   analytical model should produce these results for the following inputs:

    lambda (l) = 2
    mu (m) = 3
    M = 2

    Po = 0.5
    L = 0.75
    W = 0.375
    Lq = 0.083
    Wq = 0.0417
*/
    
    double lambda = 2;
    double mu = 3;
    double M = 2;

    AnalyticalModel am;
    double p0 = am.ComputeP0(lambda, mu, M);
    std::cout << "Value of p0 = " << p0 << std::endl;

    double L = am.ComputeL(lambda, mu, M);
    std::cout << "Value of L  = " << L << std::endl;

    double W = am.ComputeW(lambda, mu, M);
    std::cout << "Value of W  = " << W << std::endl;

    double Lq = am.ComputeLq(lambda, mu, M);
    std::cout << "Value of Lq = " << Lq << std::endl;

    double Wq = am.ComputeWq(lambda, mu, M);
    std::cout << "Value of Wq = " << Wq << std::endl;

    double utilFactor = am.ComputeUtilFactor(lambda, mu, M);
    std::cout << "Value of U  = " << utilFactor << std::endl;

// End analytical model testing -- PASSED!
/***************************************************************/

//          START PRIORITY QUEUE TESTS

    PriorityQueue pq;
    std::cout << "\nInserting values into the priority queue...\n";
    pq.Insert(100.0);
    pq.Insert(50.0);
    pq.Insert(200.0);
    pq.Insert(250.0);
    pq.Traversal();

    std::cout << "\nServing elements from the priority queue\n";
    while (true) {
        float served = pq.Serve();
        if (served == -1.0) break; // Break if heap is empty
        
        std::cout << "Served: " << served << std::endl;
    }

    pq.Traversal();
    std::cout << "\nPriority queue test completed.\n";

//      END PRIORITY QUEUE TESTS!!!
/***************************************************************/

//      START FIFO TESTS

    Fifo queue;

    // Insert some elements into the queue
    std::cout << "\nInserting customers into the FIFO queue...\n";
    queue.Insert(5.0, 2.0);  // pqTime = 5.0, arrivalTime = 2.0
    queue.Insert(3.0, 1.5);  // pqTime = 3.0, arrivalTime = 1.5
    queue.Insert(8.0, 4.0);  // pqTime = 8.0, arrivalTime = 4.0
    queue.Insert(1.0, 0.5);  // pqTime = 1.0, arrivalTime = 0.5

    // Serve elements (FIFO - first in, first out)
    std::cout << "\nServing customers from the FIFO queue...\n";
    while (!queue.isEmpty()) {
        Node* servedCustomer = queue.Serve();
        std::cout << "Served customer with pqTime: " << servedCustomer->pqTime 
                  << ", arrivalTime: " << servedCustomer->arrivalTime << "\n";

        // Free memory for the served customer (optional but recommended to avoid memory leaks)
        delete servedCustomer;
    }

    std::cout << "\nFIFO queue test completed.\n";



//      END FIFO TESTS
/***************************************************************/


    return 0;
}