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
#include <ctime>
#include <cstdlib>

class Simulator
{
    private:
        // Private instance variables
        float lambda, mu, M;
        PriorityQueue pq;
        Fifo fifo;
        int maxEvents;
        int serverAvailableCnt;
        float simulationTime;
        float lastDepartureTime;
        float totalIdleTime = 0.0;
        int customerWaitedCnt = 0;
        float totalQueueTime = 0.0;
        float totalWaitTime = 0.0;
        float serviceTime;
        float totalServiceTime = 0.0;
        float totalSystemTime = 0.0;
        int totalCustomers;
        

    public:
        // Parameterized Constructor
        Simulator(float _lambda, float _mu, float _M, int maxEvents);

        // Run Simulation
        void RunSim();

        // Process Next Event
        void ProcessNextEvent();

        // Processes Statistcs for the current customer
        void ProcessStatistics(Node* customer);

        // Prints Simulation Statistics
        void PrintSimulationResults();

        // Gets a random interval
        float GetNextRandomInterval(float avg);
};
#endif