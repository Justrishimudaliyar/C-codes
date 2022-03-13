#include <iostream>
using namespace std;

//declaration to use memoization
int element[1000];

//method to use the Fibonacci numbers of the n
int FiboMethod(int n) {
  if (n <= 1)
    return n;

//same logic, but using memoization
  if (element[n]!= 0)
  {
    return element[n];
  }
  else {
    element[n] = FiboMethod(n - 1) + FiboMethod(n - 2);
    return element[n];
  }
}

//The function to find the number of ways to reach a particular number is actually finding Fibonacci series first
int WaysToReachNumber(int n) {
  return FiboMethod(n + 1);
}

//Driver Code
int main() {
  int n;
  cout << "Enter the value of n: " << endl;
  cin >> n;
  cout << "The number of stairs required to reach " << n << " are " <<      WaysToReachNumber(n) << endl; 
  return 0;
}