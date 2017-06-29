/*
	Given an array of integers, find the first repeating element in it. 
	We need to find the element that occurs more than once and whose index 
	of first occurrence is smallest.

	Examples:

		Input:  arr[] = {10, 5, 3, 4, 3, 5, 6}
		Output: 5 [5 is the first element that repeats]
		
		Input:  arr[] = {6, 10, 5, 4, 9, 120, 4, 6, 10}
		Output: 6 [6 is the first element that repeats]
*/
import java.util.Scanner;
import java.util.*;
class FirstRepeating{
	public int firstRepeat(int arr[], int size) {
		if(size<=0)
			return -1;
		if(size==1)
			return 0;
		int min=-1;
		HashSet<Integer> set =new HashSet<>();
		for(int i=size-1;i>=0;i--) {
			if(set.contains(arr[i]))
				min=i;
			else
				set.add(arr[i]);
		}
		return min;
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
		FirstRepeating ob=new FirstRepeating();
		int result=ob.firstRepeat(arr,size);
		System.out.println((result<0) ? "Element not found" : "First repeating element fount at index="+result );
	}
}