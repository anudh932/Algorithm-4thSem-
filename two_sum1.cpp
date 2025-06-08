#include<iostream>
using namespace std;
int twosum(int n, int num[])
{
    int i,j;
    int target;
    cin>>target;
    for (i=0;i<n;i++)
    {
        int remain=target -num[i];
        for (j=i+1;j<n;j++)
        {
            if(remain==num[j])
            {
              return i,j ;
            }
        }

    }
}

int main()
{
    int n;
    cin>>n;
 int *num = new int[n];  // Dynamically allocate an array of size n

    for (int i=0;i<n;i++)
    {cin>>num[i];
    }
    twosum(n,num);
}
