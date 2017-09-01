#include <iostream>
#include <cmath>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Eigenvalues>

using namespace Eigen;

double exactSol(int n,int i){
  double sol = 1.0/(2-2*std::cos(((2*i-1)*(M_PI))/(2*n+1)));
  return sol;
}

double error(double x, double x_real){
  double e = std::fabs(x-x_real)/x_real;
  return e;
}

int main()
{
  int n = 30;
  MatrixXd A(n,n);
  for(int i = 0; i <= n-1; i++){
    for(int j =0; j <= n-1; j++){
      if (i <= j){
	A(i,j)=n-j;
      }else{
	A(i,j) = n-i;
      }
    }
  }
  std::cout << "La matriz A es:\n" <<"\n"<< A <<"\n"<< std::endl;
  SelfAdjointEigenSolver<MatrixXd> eigensolver(A);
  if (eigensolver.info() != Success) abort();
  std::cout << "Los autovalores de A son:"<< std::endl;
  double e, e_real;
  std::cout.precision(7);
  std::cout<<"i"<<"\t"<<"Autovalores numéricos" <<"\t"<<"Autovalores teóricos"<<"\t"<<"Error"<<"\n";
  for(int i=1;i<=n;i++){
    e = eigensolver.eigenvalues()[n-i];
    e_real = exactSol(n,i);
    
    std::cout<<i<<"\t"<<e<<"\t"<<e_real<<"\t"<<error(e,e_real)<<std::endl;
  }
  std::cout <<"\n"<< "Y la matriz de autovectores de A, correspondiendo con los autovalores son: \n"<<"\n"
	    << eigensolver.eigenvectors() <<"\n"<< std::endl;
  
}
