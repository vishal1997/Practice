/*
 *Given an array of integers which is initially increasing and then decreasing, 
 *find the maximum value in the array. 
 */

import java.util.Scanner;

class MaxNumber{
	static int maxNumber(int arr[], int low, int high) {
		if(low==high)
			return arr[low];
		if(low+1==high){
			if(arr[low]>arr[high])
				return arr[low];
			return arr[high];
		}
		int mid=low + (high-low)/2;
		if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
			return arr[mid];
		
		if(arr[mid]>arr[mid-1] && arr[mid] < arr[mid+1])
			return maxNumber(arr, mid+1, high);
		return maxNumber(arr, low, mid-1);
	}
	
	public static void main(String args[]) {
		int len;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the size of array:");
		len=sc.nextInt();
		int arr[]=new int[len];
		System.out.println("Enter the array elements");
		for(int i=0;i<len;i++)
			arr[i]=sc.nextInt();
		int result=maxNumber(arr, 0, len-1);
		System.out.println((result<0) ? "Not Found" : "Max Number=" + result);
	}
}