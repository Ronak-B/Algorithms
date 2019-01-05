#include<iostream>
using namespace std;

struct subarray{
        int low,high,sum;
};

subarray findMaxCrossingSubarray(int A[],int low,int mid,int high)
{
    int maxLow,maxHigh;
    int leftSum=-100000;
    int rightSum=leftSum;
    int sum=0;
    for(int i=mid;i>=low;i--)    //finding max left sum
    {
        sum=sum+A[i];
        if(sum>leftSum)
        {
            leftSum=sum;
            maxLow=i;
        }
    }
    sum=0;
    for(int j=mid+1;j<=high;j++)   //finding max right sum
    {
        sum=sum+A[j];
        if(sum>rightSum)
        {
            rightSum=sum;
            maxHigh=j;
        }
    }
    subarray s;
    s.low=maxLow;
    s.high=maxHigh;
    s.sum=leftSum+rightSum;
    return s;

}

subarray findMaxSubarray(int A[],int low,int high)
{
    if(low==high)
    {
        subarray s;
        s.low=low;
        s.high=high;
        s.sum=A[low];
        return s;
    }
    else
    {
        int mid=(low+high)/2;
        subarray left,right,cross;
        left=findMaxSubarray(A,low,mid);
        right=findMaxSubarray(A,mid+1,high);
        cross=findMaxCrossingSubarray(A,low,mid,high);
        if(left.sum>right.sum && left.sum>cross.sum) return left;
        else if(right.sum>left.sum && right.sum>cross.sum) return right;
        else return cross;
    }
}

int main()
{
    int A[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    subarray s=findMaxSubarray(A,0,15);
    int sum=0;
    for(int i=s.low;i<=s.high;i++)
    {
        sum+=A[i];
        cout<<A[i]<<" ";
    }
    cout<<endl<<sum;
}
