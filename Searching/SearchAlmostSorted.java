/*
 * Given an array which is sorted, but after sorting some elements are moved to 
 * either of the adjacent positions, i.e., arr[i] may be present at arr[i+1] or 
 * arr[i-1]. Write an efficient function to search an element in this array. 
 * Basically the element arr[i] can only be swapped with either arr[i+1] or arr[i-1].

		For example consider the array {2, 3, 10, 4, 40}, 4 is moved to next position 
		and 10 is moved to previous position.

		Example:
		
			Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 40
			Output: 2 
			Output is index of 40 in given array
		
			Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 90
			Output: -1
			-1 is returned to indicate element is not present
 * */
import java.util.Scanner;

class SearchAlmostSorted {
	public int search(int arr[], int low, int high, int ele) {
		if(high<low)
			return -1;
		int mid=low +(high-low)/2;
		if(arr[mid]==ele)
			return mid;
		if(arr[mid-1]==ele)
			return mid-1;
		if(arr[mid+1]==ele)
			return mid+1;
		if(arr[mid]>ele)
			return search(arr, low, mid-2, ele);
		return search(arr,mid+2,high,ele);
	}
	
	public static void main(String args[]) {
		int size,
		ele;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter size of array:");
		size=sc.nextInt();
		System.out.println("Enter the array elements:");
		int arr[]=new int[size];
		for(int i=0;i<size;i++)
			arr[i]=sc.nextInt();
		System.out.println("Enter the ele to search");
		ele=sc.nextInt();
		SearchAlmostSorted ob=new SearchAlmostSorted();
		int result=ob.search(arr,0,size-1,ele);
		System.out.println((result<0) ? "Element not found" : "Element fount at index="+result );
	}
}