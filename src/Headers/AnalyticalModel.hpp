/***************************************************************
  Student Name: Trevor Mee
  File Name: AnalyticalModel.hpp
  Project 2

  @brief Contains function declarations for various analytical 
         model computations
***************************************************************/

#ifndef ANALYTICALMODEL_HPP
#define ANALYTICALMODEL_HPP

#include <iostream>
#include <math.h>

class AnalyticalModel
{
    private:
        // Private instance variables
        double lambda, mu, M;

        // Helper function to compute factorials
        unsigned int factorial(int x);

        // Helper function for computing percent idle time
        double P0Summation(double _lamda, double _mu, double _M);

    public:
        // Constructor
        AnalyticalModel();

        // Parameterized Constructor
        AnalyticalModel(double, double, double);

        // Compute P_0
        double ComputeP0(double, double, double);

        // Compute L
        double ComputeL(double, double, double);
        
        // Compute W
        double ComputeW(double, double, double);

        // Compute L_q
        double ComputeLq(double, double, double);

        // Compute W_q
        double ComputeWq(double, double, double);

        // Compute utilization factor
        double ComputeUtilFactor(double, double, double);

        // Print analytical model results
        void PrintResults();
};
#endif