#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>
#include<chrono>
using namespace std;
void TimeCost()
{
	int count = 100;
	const int size = 256;
	double sinTable[size];
	auto start = chrono::high_resolution_clock::now();
	auto finish = chrono::high_resolution_clock::now();
	cout << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << "ns" << endl;
}