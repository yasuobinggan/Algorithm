//
//


//lower_bound
//����ұ�:0,n
int lower_bound(int A[],int left,int right,int x)
{
    int mid;
    while(left<right)
    {
        mid=(left+right)/2;
        if(A[mid]>=x)
        {
            right=mid;
        }
        else
        {
            left=mid+1;
        }
    }
    return left;
}

//upper_bound
//����ұ�:0,n
int upper_bound(int A[],int left,int right,int x)
{
    int mid;
    while(left<right)
    {
        mid=(left+right)/2;
        if(A[mid]>x)
        {
            right=mid;
        }
        else
        {
            left=mid+1;
        }
    }
    return left;
}

//����ģ��
//����ұ�
int solve(int left,int right)
{
    int mid;
    while(left<right)
    {
        mid=(left+right)/2;
        if(��������)
        {
            right=mid;
        }
        else
        {
            left=mid+1;
        }
    }
    return left;
}
