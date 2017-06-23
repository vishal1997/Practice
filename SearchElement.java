/*
 * An element in a sorted array can be found in O(log n) time via binary search. 
 * But suppose we rotate an ascending order sorted array at some pivot unknown to you beforehand. 
 * So for instance, 1 2 3 4 5 might become 3 4 5 1 2. 
 * Devise a way to find an element in the rotated array in O(log n) time.
 */

import java.util.Scanner;

class SearchElement {
	static int search(int arr[] , int low,int high, int key) {
		int mid=low + (high - low)/2;
		if(arr[mid]==key)
			return mid;
		if(arr[low] <= arr[mid]){
			if(key>=arr[low] && key<=arr[mid])
				return search(arr, low, mid-1, key);
			return search(arr, mid+1, high, key);
		}
		
		if(key>=arr[mid] && key <= arr[high])
			return search(arr, mid+1, high,key);
		return search(arr, low, mid-1, key);
	}
	
	public static void main(String args[]) {
		int size;
		System.out.println("Enter the length of array:");
		Scanner sc=new Scanner(System.in);
		size=sc.nextInt();
		int arr[]=new int[size];
		for(int i=0;i<size;i++)
			arr[i]=sc.nextInt();
		int key;
		System.out.println("Enter the key to search");
		key=sc.nextInt();
		int result = search(arr,0,size,key);
		System.out.println((result < 0) ? "Not found " : "Found at : " + result);
	}
}