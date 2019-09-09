/*
Author: <Yaru Niu> 
Class: ECE6122 
Last Date Modified: <2019-09-07>
Description: Solution to Problem 2 of Homework 1
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Main
int main()
{
	double beta, integral, width;
	unsigned long N;
	cout << "Please enter a value for the upper limit (beta):" << " ";
	cin >> beta;
	cout << "Please enter the number of subdivisions to use:" << " ";
	cin >> N;
    width = beta / N;
    for (int i = 1; i <= N; i++)
    {
        double x = 0.5 * width + (i-1) * width;
        integral = integral + (4 * width) / (1 + x * x);
    }
    cout << "The integral evaluates to" << " " <<  setprecision(16) << integral << endl;
}