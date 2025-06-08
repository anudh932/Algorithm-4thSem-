#include<bits/stdc++.h>
using namespace std;
void sel(int ar[],int n)
{   int i;
    for(i=0;i<n-1;i++)
    {   int minn= i;
        int j ;
        for(j=i+1; j<n;j++)
            {
                if(ar[j] < ar[minn])
                {
                    minn=j;
                }
            }
            if(minn!=j)
            {
                swap(ar[i],ar[minn]);
            }
    }
    for( i=0;i<n;i++)
        {
            cout<<ar[i]<<" ";
        }
}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int ar[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    sel(ar,n);
}
