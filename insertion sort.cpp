#include<bits/stdc++.h>
using namespace std;

void  inSort(int ar[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=ar[i];
        int j=i-1;

     while(j>=0&&ar[j]<key)
     {
         ar[j+1]=ar[j];
         j--;
     }
     ar[j+1]=key;
    }
}
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
 inSort(ar,n);
  print(ar,n);
  return 0;
}

