#define _USE_MATH_DEFINES
#include <cmath>
#include<chrono>
#include<iostream>
#include<omp.h>
using namespace std;
void ParallelArea()
{
	const int size = 30;
	int table[size];
#pragma omp parallel num_threads(30)  
	{
		
		for (int i = 0; i < size; i++)
		{
			int worker = omp_get_thread_num();
			table[i] = i*5;
			cout << "worker : "<< worker <<"  assign value "<< i*5 <<" to table "<< i << endl;
		}

	}
}