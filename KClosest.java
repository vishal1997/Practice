/*
 * Given a sorted array arr[] and a value X, find the k closest elements to X in arr[]. 
	Examples:

	Input: K = 4, X = 35
       		arr[] = {12, 16, 22, 30, 35, 39, 42, 
               			45, 48, 50, 53, 55, 56}
	Output: 30 39 42 45
	
	Note that if the element is present in array, then it should not be in output, 
	only the other closest elements are required.
 */


import java.util.Scanner;

class KClosest{
	public int binarySearch(int arr[],int low,int high,int x) {
		if(high<low)
			return -1;
		if(x<arr[low])
			return low;
		else if(x>=arr[high])
			return high;
		int mid = low+ (high-low)/2;
		if(arr[mid]<=x && arr[mid+1]>x)
			return mid;
		if(arr[mid]<x)
			return binarySearch(arr,mid+1,high,x);
		return binarySearch(arr,low, mid-1,x);
	}
	
	public void kClosest(int arr[],int size, int x, int k) {
		if(size<=0)
			return ;
		int l=binarySearch(arr, 0, size-1, x);
		int r=l+1;
		int count=0;
		if(x==arr[l])
			l--;
		while(l>=0 && r<size && count<k) {
			if(x-arr[l] < arr[r] -x )
				System.out.print(arr[l--]+" ");
			else
				System.out.print(arr[r++]+" ");	
			count++;
		}
		// If there are no more elements on right side, then
        // print left elements
		while(count<k && l>=0){
			System.out.print(arr[l--]+" ");
			count++;
		}
		
		// If there are no more elements on left side, then
        // print right elements
		while(count<k && r<size){
			System.out.print(arr[r++]+" ");
			count++;
		}
	}
	
	public static void main(String args[])
    {
        KClosest ob = new KClosest();
        int arr[] = {12, 16, 22, 30, 35, 39, 42,
                     45, 48, 50, 53, 55, 56
                    };
        int n = arr.length;
        int x = 35, k = 4;
        ob.kClosest(arr, n, x, k);
    }
}