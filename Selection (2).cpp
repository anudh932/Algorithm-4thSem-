#include<bits/stdc++.h>
using namespace std;

void  SelectionSort(int ar[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minn=i;
        for(int j=i+1;j<n;j++)
        {
          if(ar[j]<ar[minn])
         {
           minn=j;
         }
        }
    swap(ar[i],ar[minn]);
    }}
    void print(int ar[],int n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<ar[i]<<" ";
        }
        cout<<endl;
    }

int main()
{
  int ar[]={12,11,13,5,6};
  int n=5;
 SelectionSort(ar,n);
  print(ar,n);
  return 0;
}

