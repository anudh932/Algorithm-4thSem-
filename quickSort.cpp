#include <iostream>
using namespace std;

int partitionn(int ar[],int st,int end)
{
    int pivot= ar[(st+end)/2];
    int i=st;
    int j=end;

    while(i<j)
    {
        while(ar[i]<pivot)
            i++;
        while (ar[j]>pivot)
            j--;
        if (i<=j)
        { swap(ar[i], ar[j]);

        }
        if(j<i)
        {
            swap(ar[j],ar[end]);
        }
    }
}



void quickSort(int ar[],int st,int end)
{
    if (st<end)
    {
        int j=partitionn(ar, st, end);
        quickSort(ar,st,j - 1);
        quickSort(ar,j,end);
    }
}

int main()
{
    int ar[]={1,4,2,9,5,3};
    int n =6;
    quickSort(ar,0,n-1);
    for(int i=0; i<n; i++)
    {
        cout<<ar[i]<<" ";
    }
    return 0;
}
