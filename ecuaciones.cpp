#include <iostream>

double delta_x=0.01;
double c=300.0;
double delta_t=(0.5*delta_x)/c;
int L=1;
int v0=0;
double A0=0.1;
double x;
double t;
int i;
int j;
int pasos;


int main()
{
	int N = 100;
	double m=2.0*A0/L;
	double phi_pass[N];
	double phi_pres[N];
	double phi_futu[N];
	double A[N];
	
	//Condiciones iniciales
	for(int i=0.0; i<N-1; i++)
	{
		if(delta_x*i<=L/2.0)
		{
			A[i]=m*i*delta_x;
		}
		else
		{
			A[i]=(-m*i*delta_x)+(2.0*A0);
		}	

	}
	
	//Condiciones iniciales 2.0
	for(int i=0; i<N-1; i++)
	{	
		phi_pass[i]=phi_futu[i];
		phi_pres[i]=((c*c*delta_t*delta_t/(delta_x*delta_x*2))*(A[i+1]+A[i-1]-2*A[i]))+2*A[i];
		//std::cout<<phi_pres[i]<<std::endl;	
			
	}
	
	//for tiempo
	for(int j=0; j<1; j++ )
	{
		int pasos=0;

		for(int i=1; i<N-1; i++)
		{  
			phi_futu[i]=((c*c*delta_t*delta_t/delta_x*delta_x)*(phi_pres[i+1]+phi_pres[i-1]-2*phi_pres[i]))-phi_pass[i]+2*phi_pres[i];
		}
		
		for(int i=1; i<N-1; i++)
		{
			phi_pass[i]=phi_pres[i];
			phi_pres[i]=phi_futu[i];
			//std::cout<<phi_pres[i]<<std::endl;
		}
		
		pasos+=1;
		
		std::cout<<phi_pres[j]<<std::endl;
		/*for(int i=0; i<N; i++)
			{
				std::cout<<phi_pres[i]<<std::endl;
			}*/

		/*if(pasos==10)
		{
			for(int i=0; i<N; i++)
			{
				std::cout<<phi_pres[i]<<std::endl;
			}
			pasos=0;	
		}*/	
	}
	
	return 0;
}




