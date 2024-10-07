/***************************************************************
  Student Name: Trevor Mee
  File Name: Simulator.hpp
  Project 2

  @brief Contains function declarations for running the simulation
***************************************************************/

#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include "PriorityQueue.hpp"
#include "Fifo.hpp"
#include <cmath>

class Simulator
{
    private:
        float lambda, mu, M;
        PriorityQueue pq;
        Fifo fifo;

        int maxEvents;
        int serverAvailableCnt;
        float startOfServiceTime;
        int numCustomers;
        float currentWaitTime;
        int customerWaitedCnt = 0;
        float totalWaitTime = 0.0;
        float totalServiceTime = 0.0;
        float totalIdleTime = 0.0;
        int totalCustomers;
        float simulationTime;
        float lastDepartureTime;

        float totalQueueLength = 0.0;  // For Lq
        float totalSystemLength = 0.0; // For L
        float timeLastEvent = 0.0;     // To track system idle time
        float totalSystemTime = 0.0;   // To calculate W (time in system)
        float totalQueueTime = 0.0;    // To calculate Wq (time in queue)
        float serviceTime;

    public:
        // Parameterized Constructor
        Simulator(float _lambda, float _mu, float _M, int maxEvents);

        // Run Simulation
        void RunSim();

        // Process Next Event
        void ProcessNextEvent();

        // Processes Statistcs for the current customer
        void ProcessStatistics(Node* customer);

        // Display Simulation Statistics
        void PrintSimulationResults();

        // Gets a random interval
        float GetNextRandomInterval(float avg);
};
#endif