#include <iostream>
#include <cmath>

using namespace std;


void print(double* p, const int N, const double dx,
           const double xmin)
{
   for(int i=0; i<N; i++)
       cout << i*dx + xmin << "\t" << p[i] << endl;
}

void gridpoints(double* p, const int N, const double xmin, const double dx){
  for(int i=0; i<N; i++){
    p[i] = exp(-(xmin+i*dx)*(xmin+i*dx));}
  }
  
void derivative(double* p, const int N, const double dx){
  double pb = p[0];
  p[0]=p[1]/(2*dx);
  
  for(int i=1; i<N-1; i++){
    double pbb = p[i];
    p[i]=(p[i+1]-pb)/(2*dx);
    pb = pbb;
  }
  p[N-1] = -pb/(2*dx);
}

int main(){
  const int N = 256;
  double p[N];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);
  
  gridpoints(p, N, xmin, dx);	// call to function which fills array p here
  derivative(p, N, dx);		// call to function which calculates the derivative
  
  print(p,N,dx,xmin);

  return 0;
}
