/***************************************************************
  Student Name: Trevor Mee
  File Name: main.cpp
  Project 2

  @brief Contains function to read from a text file main method 
         to run simulation and compare the statistics with the 
         analytical model
***************************************************************/

#include "Headers/AnalyticalModel.hpp"
#include "Headers/PriorityQueue.hpp"
#include "Headers/Node.hpp"
#include "Headers/Fifo.hpp"
#include "Headers/Simulator.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

/*
    @brief Reads in a text file and extracts lambda, mu,
            M, and number of events
    @param(s) filename: file we are to read from
              lambda: avg number of arrivals per unit time
              mu: avg number of customer we can service per unit time
              M: number of available service channels at a given time
              numEvents: number of simulation arrivals to simulate
*/
void ReadFile(std::string& filename, double& lambda, double& mu, double& M, int& numEvents)
{
    std::ifstream fileRead(filename);
    
    if (!fileRead.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    fileRead >> lambda;
    fileRead >> mu;
    fileRead >> M;
    fileRead >> numEvents;
    
    fileRead.close();
}


int main()
{
    double lambda = 0.0; 
    double mu = 0.0; 
    double M = 0.0;
    int numEvents = 0;

    // Analytical Model & Simulation for test1.txt
    std::string TEST1 = "../test1.txt";
    ReadFile(TEST1, lambda, mu, M, numEvents);

    AnalyticalModel am1(lambda, mu, M);
    std::cout << "Analytical Model Results from test1.txt..." << std::endl;
    am1.PrintResults();

    std::cout << "\nSimulation Results from test1.txt..." << std::endl;
    Simulator s(static_cast<float>(lambda), static_cast<float>(mu), static_cast<float>(M), numEvents);
    s.RunSim();

    // Analytical Model & Simulation for test2.txt
    std::string TEST2 = "../test2.txt";
    ReadFile(TEST2, lambda, mu, M, numEvents);

    AnalyticalModel am2(lambda, mu, M);
    std::cout << "\nAnalytical Model Results from test2.txt..." << std::endl;
    am2.PrintResults();

    Simulator s2(static_cast<float>(lambda), static_cast<float>(mu), static_cast<float>(M), numEvents);
    std::cout << "\nSimulation Results from test2.txt..." << std::endl;
    s2.RunSim();

    return 0;
}