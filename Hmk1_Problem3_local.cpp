/*
Author: <Yaru Niu> 
Class: ECE6122 
Last Date Modified: <2019-09-07>
Description: Solution to Problem 3 of Homework 1
*/

#include <iostream>
#include <vector>
using namespace std;

vector<unsigned long> recursiveBacktracking(vector<unsigned long> sequence, vector<unsigned long> sequence_ref, unsigned long number);

// Main
int main()
{
	unsigned long n;
	cout << "Please enter the number of knights:" << " ";
	cin >> n;
	vector<unsigned long>f_sequence;
	unsigned long f1 = 0, f2 = 1, t;
    f_sequence.push_back(f1);
    f_sequence.push_back(f2); 
	while ((f1 + f2) <= (2*n-1))
	{
		t = f2;
		f2 = f1 + f2;
		f1 = t;
		f_sequence.push_back(f2);
	}

    vector<unsigned long> sequence;
    vector<unsigned long> k_sequence;
    k_sequence = recursiveBacktracking(sequence, f_sequence, n);

    if (k_sequence.size() == 0)
    	cout << "No solution found!" << endl;
    else
    {
    	cout << "The knights should sit clockwise as follows: K," << " ";
	    for (int i = 0; i <= k_sequence.size()-1; i++)
	    {
	    	if (i != k_sequence.size()-1)
	    		cout << k_sequence[i] << "," << " ";
	    	else
	            cout << k_sequence[i] << endl;
	    }    	
    }

    
}

// The function of recursive backtracking for search
// Parameters: a vector with no element, generated finite Fibonacci numbers, number of knights
// Return: the sequence knights should follow
vector<unsigned long> recursiveBacktracking(vector<unsigned long> sequence, vector<unsigned long> sequence_ref, unsigned long number)
{
	if (sequence.size() == number)
		return sequence;
	vector<unsigned long> sequence_sup;
	vector<unsigned long>::iterator itr;
    for (unsigned long i = 1; i <= number; i++)
    {
    	itr = find(sequence.begin(), sequence.end(), i);
    	if (itr == sequence.end())
    		sequence_sup.push_back(i);
    }

    vector<unsigned long> failure;
    for (unsigned long j = 0; j <= (sequence_sup.size()-1); j++)
    {
    	if (sequence.size() == 0)
    	{
    		sequence.push_back(sequence_sup[j]);
    		vector<unsigned long> result;
    		result = recursiveBacktracking(sequence, sequence_ref, number);
    		if (result != failure)
    			return result;
    		sequence.pop_back();
    	}
    	else
    	{
	    	itr = find(sequence_ref.begin(), sequence_ref.end(), sequence_sup[j] + sequence[sequence.size()-1]);
	    	if (itr != sequence_ref.end())
	    	{
	    		sequence.push_back(sequence_sup[j]);
	    		vector<unsigned long> result;
	    		result = recursiveBacktracking(sequence, sequence_ref, number);
	    		if (result != failure)
	    			return result;
	    		sequence.pop_back();
	    	}    		
    	}

    }
    return failure;
}