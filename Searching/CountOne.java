/*
 * Given a binary array sorted in non-increasing order, count the number of 1 in it.
 * Examples:

		Input: arr[] = {1, 1, 0, 0, 0, 0, 0}
		Output: 2
		
		Input: arr[] = {1, 1, 1, 1, 1, 1, 1}
		Output: 7
		
		Input: arr[] = {0, 0, 0, 0, 0, 0, 0}
		Output: 0
		Solved using binary search
 */

import java.util.Scanner;
class CountOne {
	public int countOne(int arr[], int low, int high){
		if(high<low)
			return -1;
		int mid=low +(high-low)/2;
		if((mid==high || arr[mid+1]==0) && arr[mid]==1)
			return mid+1;
		if(arr[mid]==1)
			return countOne(arr,mid+1,high);
		return countOne(arr,low,mid-1);
	}
	public static void main(String args[]) {
		int arr[] = {1, 1, 1, 1, 0, 0, 0};
	    CountOne obj=new CountOne();
	    int result=obj.countOne(arr,0,arr.length-1);
	    System.out.println("No of 1's="+result);
	}
}
