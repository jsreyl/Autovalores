#include <iostream>
#include <cmath>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Eigenvalues>
using Eigen::MatrixXd;
using Eigen::SelfAdjointEigenSolver;
int v(int i,int j,int n){
  int s;
  if(i<=j){
    s = n-j;
  }
  else{
    s = n-i;
  }
  return s;
}
int main(){
  std::cout.precision(7);
  int n=30;
  int i;
  int j;
  MatrixXd s = MatrixXd(n,n);
  for(i=0; i<=n-1 ;i++){
    for(j=0;j<=n-1;j++){
      s(i,j)=v(i,j,n);
    }
  }
  SelfAdjointEigenSolver<MatrixXd> es(s);
  std::cout<<"\n"<<"i"<<"\t"<<"Auto valor"<<"\t"<<"Auto valor t"<<"\t"<<"error porcentual \n"<<std::endl;
  //std::cout.setf(std::ios::scientific);
  for(int k=1;k<=n;k++){
    double E = es.eigenvalues()[n-k];
    double E_r = (1)/(2-(2*std::cos(((2*k)-1)*(M_PI)/((2*n)+1))));  
    double d = (std::abs(E-E_r))/E_r;
    std::cout<<k<<"\t"<<E<<"\t"<<E_r<<"\t"<<d<<std::endl;
  }
  //std::cout.unsetf(std::ios::scientific);
  std::cout<<"\n"<<"Matriz de auto vectores \n\n";
  std::cout<<es.eigenvectors()<<std::endl;
}
