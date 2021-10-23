int divisibleSumPairs(int n, int k, int ar_count, int* ar) {
    int count=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int sum= ar[i]+ar[j];
            if(sum%k==0)
            {
                count++;
            }
        }
    }
    return count;

}
