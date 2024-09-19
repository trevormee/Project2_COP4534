/***************************************************************
  Student Name: Trevor Mee
  File Name: main.cpp
  Project 2

  @brief Contains main method to run simulation and compare the 
         statistics with the analytical model
***************************************************************/

#include "Headers/AnalyticalModel.hpp"
#include <iostream>

int main()
{

/**********Start analytical model testing -- PASSED******/
    double lambda = 2;
    double mu = 3;
    double M = 2;
 
/*
The analytical model should produce these results for the following inputs:

    lambda (l) = 2
    mu (m) = 3
    M = 2

    Po = 0.5
    L = 0.75
    W = 0.375
    Lq = 0.083
    Wq = 0.0417
*/

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
    return 0;
}