#include<bits/stdc++.h>
using namespace std;
void ins(int ar[],int n)
{   int i;
    for(i=1;i<n;i++)
    {   int temp= ar[i];
        int j=i-1;
        while(j>=0 &&temp>ar[j])
        {
           ar[j+1]=ar[j];
           j--;
        }
        ar[j+1]=temp;
    }
    for(i=0;i<n;i++)
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
    /*int ar[5]={23,27,22,25,21};
    int n=5;*/
    ins(ar,n);
}
