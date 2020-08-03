int qsort(int low,int high,int* arr)
{
    int j,k,x;
    k=low;j=high;x=arr[k];
    while(k<j)
    {
        while(arr[j]>=x&&k<j) j--;
        if(k<j){
            arr[k]=arr[j];
            k++;
        }
        while(arr[k]<=x&&k<j) k++;
        if(k<j)
        {
            arr[j]=arr[k];
            j--;
        }
        for(int i=0;i<10;++i)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    arr[k]=x;
    return k;
}

int selectK(int low,int high,int k,int* arr)
{
    if(low==high && k==1)
        return arr[low];
    int index=qsort(low,high,arr);
    int pos=index-low+1;
    if(k<=pos)
        return selectK(low, index, k, arr);
    else
        return selectK(index+1, high, k-pos, arr);
}
