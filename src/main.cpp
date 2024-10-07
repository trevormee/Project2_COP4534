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
#include "Headers/Simulator.hpp"

#include <iostream>
#include <fstream>
#include <sstream>


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
    
    std::cout << " " << lambda << " " << mu << " " << M << " " << numEvents << std::endl;
    fileRead.close();
    
}

int main()
{
    double lambda = 0.0; 
    double mu = 0.0; 
    double M = 0.0;
    int numEvents = 0;

    std::string TEST1 = "../test1.txt";
    ReadFile(TEST1, lambda, mu, M, numEvents);
    
    AnalyticalModel am1(lambda, mu, M);
    std::cout << "Analytical Model Results from test1.txt..." << std::endl;
    am1.PrintResults();

    Simulator s(static_cast<float>(lambda), static_cast<float>(mu), static_cast<float>(M), numEvents);
    s.RunSim();

    std::string TEST2 = "../test2.txt";
    ReadFile(TEST2, lambda, mu, M, numEvents);
    AnalyticalModel am2(lambda, mu, M);
    std::cout << "Analytical Model Results from test2.txt..." << std::endl;
    am2.PrintResults();


    return 0;
}