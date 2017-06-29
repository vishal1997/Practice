

class kSmallest{
	public static int kthSmallest(int arr[], int l, int r, int k) {
		if(k<=0 || k>r-l+1)
			return -1;
		int pos=partition(arr,l,r);
		if(pos-l==k-1)
			return arr[pos];
		if(pos-l>k-1)
			return kthSmallest(arr,l,pos-1,k);
		return kthSmallest(arr,pos+1,r,k-pos+l-1);
		
	}
	public static int partition(int arr[], int l, int r)
	{
	    int x = arr[r], i = l;
	    for (int j = l; j <= r - 1; j++)
	    {
	        if (arr[j] <= x)
	        {
	        	int tem=arr[i];
	        	arr[i]=arr[j];
	        	arr[j]=tem;
	            i++;
	        }
	    }
	    int tem=arr[i];
    	arr[i]=arr[r];
    	arr[r]=tem;
	    return i;
	}
	 
	// Driver program to test above methods
	public static void main(String args[])
	{
	    int arr[] = {12, 3, 5, 7, 4, 19, 26};
	    int n = arr.length, k = 3;
	    System.out.println( "K'th smallest element is " + kthSmallest(arr, 0, n-1, k));
	}
}