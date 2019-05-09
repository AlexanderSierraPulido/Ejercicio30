#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main()
    {
    double dx = 0.01,dt = 0.01;
    
    double t_max= 2.0;
    
    int n = t_max/dt, N=100;
    
    double u[N],u_o[N],u_fut[N];
    
    ofstream outfile;
    
    // Condiciones iniciales
    for(int i=0;i<N;i++)
        {
        u[i]=0.05*sin(4*M_PI*i/N);
        }
    
    outfile.open("datos.dat");

    for(int j=0;j<n;j++)
        {
        for(int i=1;i<N-1;i++)
            {
            u_fut[i]=u[i]-0.8/4*(u[i+1]*u[i+1]-u[i-1]*u[i-1])+(0.8*0.8/8)*((u[i+1]+u[i])*(u[i+1]*u[i+1]-u[i]*u[i])-(u[i]+u[i-1])*(u[i]*u[i]-u[i-1]*u[i-1]));
            }
        
        for(int i=1;i<N;i++)
            {
             outfile<<u[i]<<" ";
            }
        
         outfile<<"\n";
    
        for(int k=1;k<N;k++)// Se reescirben 
            {
             u[k] = u_fut[k];
            }
        }
    outfile.close();

  return 0;
}