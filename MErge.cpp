#include<bits/stdc++.h>
using namespace std;
void mrg(int ar[], int s,int mid, int e)
{
    vector<int>temp;
    int i=s;
    int j=mid+1;
    while(i<=mid && j<=e)
    {
        if(ar[i]<=ar[j])
            {temp.push_back(ar[i]);
        i++;}
        else
        {temp.push_back(ar[j]);
        j++;}
    }
    while(i<=mid)
    {
        temp.push_back(ar[i]);
        i++;
    }
    while(j<=e)
    {
        temp.push_back(ar[j]);
        j++;
    }
    int idx;
    for(int idx=0; idx<temp.size();idx++)
    {
        ar[idx+s]=temp[idx];
    }
}

void msort(int ar[],int s,int e)
{
    if(s<e)
    {
    int mid= (s+e)/2;
    msort(ar,s,mid);//for left
    msort(ar,mid+1,e);
    mrg(ar,s,mid,e);
    }}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int ar[n];
    cout<<"Enter the elements of the array: ";
    int i;
    for( i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    msort(ar,0,n-1);

    for(int val : ar)
    {
        cout<<val<<" ";
    }
}
