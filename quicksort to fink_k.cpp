#include<iostream>
using namespace std;

int Find_K(int* A, int L, int R,int K)
{
    int i = L, j = R;
    int baseval = A[L];
    while(i < j)
    {
        while(A[i] < baseval && i < j)   i++;
        if(i < j)   
        {
            swap(A[i],A[j]);
            j--;
        }
        while(A[j] > baseval && j > i)  j--;
        if(i < j)   
        {
            swap(A[i],A[j]);
            i++;
        }
    }
    A[i] = baseval;
    if(K == i)  return A[K];
    else if(i > K) Find_K(A,L,i-1,K);
    else Find_K(A,i+1,R,K);
}

int main()
{
    int A[5] = {1,3,5,2,4};
    cout << Find_K(A,0,4,4);
}