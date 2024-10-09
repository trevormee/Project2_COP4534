/***************************************************************
  Student Name: Trevor Mee
  File Name: Simulator.cpp
  Project 2

  @brief Contains function definitions for running the simulation
***************************************************************/

#include "Headers/Simulator.hpp"

/*
    @brief Parameterized constructor
    @param(s) _lambda: avg number of arrivals per unit time
              _mu: avg number of customers we can service per unit time
              _M: number of available service channels at a given time
              _MaxEvents: maximum number of customers to simulate
*/
Simulator::Simulator(float _lambda, float _mu, float _M, const int _maxEvents)
{
    lambda = _lambda;
    mu = _mu;
    M = _M;
    maxEvents = _maxEvents;
    serverAvailableCnt = M;
}

/*
    @brief Function to run a simulation
*/
void Simulator::RunSim()
{  
    int totalArrivals = 0; 
    const int maxArrivals = maxEvents; 

    simulationTime = 0.0;
    lastDepartureTime = 0.0;
    
    for (int i = 0; i < M && totalArrivals < maxArrivals; i++)
    {
        float arrivals = GetNextRandomInterval(lambda);
        Node* newCustomer = new Node(arrivals, true);
        pq.Insert(newCustomer);
        totalArrivals++;
        simulationTime = arrivals;
    }
    
    while (!pq.isEmpty()) 
    {
        ProcessNextEvent();
        if (pq.theSize <= M + 1 && totalArrivals < maxArrivals)
        { 
            float arrivals = GetNextRandomInterval(lambda) + lastDepartureTime;
            Node* newCustomer = new Node(arrivals, true);
            pq.Insert(newCustomer);
            totalArrivals++;
            simulationTime = arrivals;
        } 
    }
    
    PrintSimulationResults();
}


/*
    @brief Processes a new event
*/
void Simulator::ProcessNextEvent()
{   
    Node* currCustomer = static_cast<Node*>(pq.Peek());

    // Arrival Event
    if (currCustomer->isArrival == true)
    {
        if (serverAvailableCnt > 0)
        {
            if(serverAvailableCnt == M)
            {
                totalIdleTime += (currCustomer->arrivalTime - lastDepartureTime);
            }

            serverAvailableCnt--;
            pq.Serve();
            currCustomer->startOfServiceTime = currCustomer->arrivalTime;
            float interval = GetNextRandomInterval(mu);
            currCustomer->departureTime = currCustomer->arrivalTime + interval;
            currCustomer->pqTime = currCustomer->departureTime;
            currCustomer->isArrival = false;
            pq.Insert(currCustomer);
        }
        else
        {
            fifo.Insert(currCustomer);
            pq.Serve(); 
        }
    }
    // Departure Event
    else 
    {
        serverAvailableCnt++;
        pq.Serve(); 
        ProcessStatistics(currCustomer);

        lastDepartureTime = currCustomer->departureTime;

        if (!fifo.isEmpty())
        {
            Node* nextCustomer = fifo.Serve();
            nextCustomer->startOfServiceTime = currCustomer->departureTime;
            float interval = GetNextRandomInterval(mu);
            nextCustomer->departureTime = nextCustomer->startOfServiceTime + interval;
            nextCustomer->pqTime = nextCustomer->departureTime;
            nextCustomer->isArrival = false;
            pq.Insert(nextCustomer);
            serverAvailableCnt--;
        }
    }
}


/*
    @brief Processes statistics for a given customer
*/
void Simulator::ProcessStatistics(Node* customer)
{
    float currentWaitTime = customer->startOfServiceTime - customer->arrivalTime;

    if(currentWaitTime > 0.0)
    {
        customerWaitedCnt++;
        totalQueueTime += currentWaitTime;
    }
    
    totalWaitTime = totalWaitTime + currentWaitTime;

    serviceTime = customer->departureTime - customer->startOfServiceTime;
    totalServiceTime = totalServiceTime + serviceTime;

    float timeInSystem = customer->departureTime - customer->arrivalTime;
    totalSystemTime += timeInSystem;
}


/*
    @brief Finalizes and prints overall statistics
*/
void Simulator::PrintSimulationResults()
{
    totalCustomers = maxEvents;    

    float p0 = abs(totalIdleTime / simulationTime);
    float w = totalSystemTime / totalCustomers;
    float wq = totalQueueTime / totalCustomers;
    float utilFactor = totalServiceTime / (M * simulationTime);
    float probOfWaiting = (static_cast<float>(customerWaitedCnt) / static_cast<float>(totalCustomers)) * 100;

    // Print results
    std::cout << "Simulation value of p0 = " << p0 << std::endl;
    std::cout << "Simulation value of W = " << w << std::endl;
    std::cout << "Simulation value for Wq = " << wq << std::endl;
    std::cout << "Simulation value of utilization factor (rho) = " << utilFactor << std::endl;
    std::cout << "Simulation value for the probability of waiting  = " << probOfWaiting << "%" << std::endl;   
}

/*
    @brief Helper function to get a random interval
    @param avg: Average number of events per unit time (lambda or mu)

    @return The random interval
*/
float Simulator::GetNextRandomInterval(float avg)
{
    float f = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float intervalTime = -1 * (1.0/avg) * log(f);
    return intervalTime;
}
