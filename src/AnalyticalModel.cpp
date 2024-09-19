/***************************************************************
  Student Name: Trevor Mee
  File Name: AnalyticalModel.cpp
  Project 2

  @brief Contains function definitions for various analytical 
         model computations
***************************************************************/

#include "Headers/AnalyticalModel.hpp"

/*
  @brief Default constructor to set private instance
         variables to default value of 0
*/
AnalyticalModel::AnalyticalModel()
{
    lambda = mu = M = 0;
}

/*
  @brief helper method to compute factorials
  @param x: number to find factorial for

  @return final factorial value
*/
double AnalyticalModel::factorial(double x)
{
    // Base case
    if(x == 0 or x == 1)
    {
      return 1;
    }
    // Invalid input 
    else if(x < 0)
    {
      std::cerr << "Factorial cannot be less than 0" << std::endl;
      return -1; 
    }
    // Compute factorial recursively
    else 
    {
      return x * factorial(x - 1);
    }
}

/*
  @brief Helper function for ComputeP0() to compute the summation from
         the denominator of the P0 algorithm
  @param(s) _lamda avg number of arrivals per unit time
            _mu avg number of customers we can service per unit time
            _M number of service channels

  @return value of the summation algorithm
*/
double P0Summation(double _lamda, double _mu, double _M)
{

}

/*
  @brief  Computes precent idle time (percentage of time that
          no one is in the system)
  @param(s) _lamda avg number of arrivals per unit time
            _mu avg number of customers we can service per unit time
            _M number of service channels

  @return Percent idle time
*/
double AnalyticalModel::ComputeP0(double _lamda, double _mu, double _M)
{
    
}

/*
  @brief 
  @param(s) _lamda avg number of arrivals per unit time
            _mu avg number of customers we can service per unit time
            _M number of service channels

  @return
*/
double AnalyticalModel::ComputeL(double _lamda, double _mu, double _M)
{
    
}

/*
  @brief 
  @param(s) _lamda avg number of arrivals per unit time
            _mu avg number of customers we can service per unit time
            _M number of service channels

  @return
*/
double AnalyticalModel::ComputeW(double _lamda, double _mu, double _M)
{
    
}

/*
  @brief
  @param(s) _lamda avg number of arrivals per unit time
            _mu avg number of customers we can service per unit time
            _M number of service channels

  @return
*/
double AnalyticalModel::ComputeLq(double _lamda, double _mu, double _M)
{
    
}

/*
  @brief
  @param(s) _lamda avg number of arrivals per unit time
            _mu avg number of customers we can service per unit time
            _M number of service channels

  @return
*/
double AnalyticalModel::ComputeWq(double _lamda, double _mu, double _M)
{
    
}
