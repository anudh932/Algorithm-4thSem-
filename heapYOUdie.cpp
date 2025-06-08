#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int n,int i)
{
   int max= i;
   int l= 2*i+1;
   int r= 2*i+2;
   if(l<n && a[l]<a[max])
   {
       max=l;
   }
   if(r<n && a[r]<a[max])
   {
       max=r;
   }
   if(max!=i)
   {
       swap(a[i],a[max]);
       heapify(a,n,max);
   }

}

void hsort(int a[],int n)
{   int i;
    for(i=(n/2)-1;i>=0;i--)//build heap from non leaf element(n/2-1)
    {
        heapify(a,n,i);
    }
    for(i=n-1;i>0;i--)
        {
            swap(a[i],a[0]);
            heapify(a,i,0);
        }
        for( i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }

}



int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    hsort(a,n);
}
