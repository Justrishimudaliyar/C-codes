#include <iostream>
using namespace std;

//function to print the array
void printarray(int arr[], int n)
{
  for(int i = 0; i < n; i++)
  {
		cout << arr[i];
  }
  cout << endl;
}
//function to actually swap the numbers for different combinations
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

//function implementing the logic of Permutation, ensuring all the digits are unique in the different observations created
void PermutationRecursion(int *arr, int left, int right)
{
  if(left == right)
  {
    printarray(arr, right+1);
    return;
  }
  for(int i = left; i <= right; i++)
  {
    swap((arr+i), (arr+left));
    PermutationRecursion(arr, left+1, right);
    swap((arr+i), (arr+left));
  }
}

//Driver Code
int main() 
{
  int n;
  
  cout << "Enter the value of n: ";
  cin >> n;
  
  //Visual C++ doesn't do stack allocations, hence a number has to be given for the array size at compile time
  //int arr[100];

  //to achive that, we can allocate the array explicitly
  int *arr = (int *)_alloca(n * sizeof(*arr));
  cout << "Enter the array elements: " << endl;
  for(int i = 0; i < n; i++) 
  {
    cin >> arr[i];
  }
  
  cout << "The elements in the permuted ways are: " << endl;
  PermutationRecursion(arr, 0, n-1);
  
  return 0;
}