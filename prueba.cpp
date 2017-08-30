#include <iostream>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Eigenvalues>
using Eigen::MatrixXd;
using Eigen::EigenSolver;
int main()
{
  MatrixXd m = MatrixXd(2,2);
  m(0,0) = 3;
  m(1,0) = 0;
  m(0,1) = 2;
  m(1,1) = 1;
  std::cout << m << std::endl;
  EigenSolver<MatrixXd> eigensolver(m);
  std::cout<<eigensolver.eigenvalues()<<std::endl;
  int n=30;
  MatrixXd s = MatrixXd(n,n);

}
