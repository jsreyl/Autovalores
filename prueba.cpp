#include <iostream>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Eigenvalues>
using Eigen::MatrixXd;
using Eigen::EigenSolver;
using Eigen::SelfAdjointEigenSolver;
int main(){
  int n=30;
  int i;
  int j;
  MatrixXd s = MatrixXd(n,n);
  for(i=0; i<=n-1 ;i++){
    for(j=0;j<=n-1;j++){
      if(i<=j){
	s(i,j)=n-j;
      }
      if(i>j){
	s(i,j)=n-i;
      }
    }
  }
  std::cout<< s << std::endl;
  SelfAdjointEigenSolver<MatrixXd> eigensolver(s);
  std::cout<<eigensolver.eigenvalues()<<std::endl;
}
