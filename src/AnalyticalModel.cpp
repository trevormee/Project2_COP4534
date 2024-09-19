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
  @brief Helper method to compute factorials
  @param x: number to find factorial for

  @return final factorial value
*/
unsigned int AnalyticalModel::factorial(int x)
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
double AnalyticalModel::P0Summation(double _lamda, double _mu, double _M)
{
    double sum = 0;
    for(int i = 0; i < _M; i++)
    {
      sum += (1 / factorial(i)) * pow(_lamda/_mu, i);
    }

    return sum;
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
    double summation = P0Summation(_lamda, _mu, _M);      // 5/3 1.667
    unsigned int fact = factorial(static_cast<int>(_M));  // 2
    double oneDivFact = 1 / static_cast<double>(fact); 
    double lambdaDivMuExponent = pow((_lamda / _mu), _M); // 4/9 0.444
    double MMuDivMMmuMinusLambda = ( (_M * _mu) / ( (_M * _mu) - _lamda) );
   
    return 1 / ( (summation) + ( (oneDivFact) * (lambdaDivMuExponent) * (MMuDivMMmuMinusLambda) ) );
}

/*
  @brief Computes the avg number of people in the system
  @param(s) _lamda avg number of arrivals per unit time
            _mu avg number of customers we can service per unit time
            _M number of service channels

  @return Avg number of people in system value
*/
double AnalyticalModel::ComputeL(double _lamda, double _mu, double _M)
{
    double p0 = ComputeP0(_lamda, _mu, _M);
    double numerator = _lamda * _mu * (pow((_lamda/_mu), _M));
    unsigned int fact = factorial(_M - 1);
    double denominator = static_cast<double>(fact) * (pow(( (_M*_mu) - _lamda), 2));
    double lambdaDivMu = _lamda / _mu;

    return ((numerator / denominator) * p0) + lambdaDivMu;
}

/*
  @brief Computes the avg time a customer spends in the system
  @param(s) _lamda avg number of arrivals per unit time
            _mu avg number of customers we can service per unit time
            _M number of service channels

  @return Avg time a customer spends in the system value
*/
double AnalyticalModel::ComputeW(double _lamda, double _mu, double _M)
{
    double p0 = ComputeP0(_lamda, _mu, _M);
    double numerator = _mu * (pow((_lamda / _mu), _M));
    unsigned int fact = factorial(_M - 1);
    double denominator = static_cast<double>(fact) * (pow(((_M * _mu) - _lamda), 2));
    double oneDivMu = 1 / _mu;

    return ((numerator / denominator) * p0) + oneDivMu;
}

/*
  @brief Computes average number of customers in queue
  @param(s) _lamda avg number of arrivals per unit time
            _mu avg number of customers we can service per unit time
            _M number of service channels

  @return
*/
double AnalyticalModel::ComputeLq(double _lamda, double _mu, double _M)
{
    double L = ComputeL(_lamda, _mu, _M);

    return L - (_lamda / _mu);
}

/*
  @brief Computes avg time customer spends in the priority queue 
  @param(s) _lamda avg number of arrivals per unit time
            _mu avg number of customers we can service per unit time
            _M number of service channels

  @return Avg time a customer spends in the priority queue
*/
double AnalyticalModel::ComputeWq(double _lamda, double _mu, double _M)
{
    double W = ComputeW(_lamda, _mu, _M);
    double oneDivMu = 1 / _mu;

    return W - oneDivMu;
}

/*
  @brief Computes the utilization factor for the system
  @param(s) _lamda avg number of arrivals per unit time
            _mu avg number of customers we can service per unit time
            _M number of service channels

  @return utilization factor value
*/
double AnalyticalModel::ComputeUtilFactor(double _lamda, double _mu, double _M)
{
    return _lamda / (_M * _mu);
}
