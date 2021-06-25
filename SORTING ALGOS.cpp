void bubble_sort(vector<int>v1 )
{
    int n = v1.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0; j<n-i-1;j++) 
        {
            if( v1[j] > v1[j+1] )
            {
                swap( v1[j] , v1[j+1] );
            }
        }
    }
}

void insertion_sort(vector<int>v1)
{
    int n = v1.size();

    for(int i=1; i<n;i++)
    {
        int val = v1[i];
        int j = i-1;

        while(j>=0 && arr[j] > val)
        {
            arr[j+1] = arr[j]; j--;
        }

        arr[j+1] = val;
    }
}

void selection_sort(vector<int>v1)
{
    int n = v1.size();

    for(int i=0;i<n;i++)
    {
        int min_idx = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < arr[min_idx] )
            {
                min_idx = j;
            }
        }
        swap(arr[i] , arr[min_idx] );
    }
}