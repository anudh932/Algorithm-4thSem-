#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
        int num[n],i;
    for (i=0;i<n;i++)
    {cin>>num[i];
    }
    int j;
    int target;
    cin>>target;
    for (i=0;i<n;i++)
    {
        int remain=target -num[i];
        for (j=i+1;j<n;j++)
        {
            if(remain==num[j])
            {
              cout<<i<<" "<<j;
            }
        }

    }
}
