#include<iostream>
#include<string>
using namespace std;
void heapify(string &st,int n,int i)
{
  int small= i;
  int left= 2*i+1;
  int right= 2*i+2;
  if(left<n && st[left]>st[small])
  {
      small= left;
  }
  if(right<n && st[right]>st[small])
  {
      small= right;
  }
  if(small !=i)
{
    swap(st[i],st[small]);
    heapify(st,n,small);
}
}

void heapSort(string &st,int n)
{
    for(int i=(n/2)-1;i>=0;i--)
    {
        heapify(st,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(st[0],st[i]);
        heapify(st,i,0);
    }
}
int main()
{
string st1;
string st2;
cin>>st1>>st2;
    int n1= st1.length();
    int n2= st2.length();

    heapSort(st1,n1);
     for(int i=0;i<n1;i++)
{
    cout<<st1[i]<<" ";
}
     heapSort(st2,n2);
    for(int i=0;i<n2;i++)
{
    cout<<st2[i]<<" ";
}


if(st1==st2)
{
    cout<<"true";
}
else
    cout<<"false";
}
