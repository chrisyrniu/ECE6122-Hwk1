/*
Author: <Yaru Niu> 
Class: ECE6122 
Last Date Modified: <2019-09-07>
Description: Solution to Problem 1 of Homework 1
*/

#include <iostream>
using namespace std;

// Main
int main()
{
	int n;
	int instance = 0;
    cout << "Please enter the starting number n:" << " " ;
    cin >> n;
    while(n != 1)
    {
        if (n % 7 == 0)
        	n = n / 7;
        else 
        	{
        		n = n + 1;
        		instance = instance + 1;
        	}
    }
    cout << "The sequence had" << " " << instance << " " << "instances of the number 1 being added" << endl;
}
