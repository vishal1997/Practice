import java.util.Stack;

/*
 *Given an array of integers, find the nearest smaller number for every element 
 *such that the smaller element is on left side.

	Examples:
	
		Input:  arr[] = {1, 6, 4, 10, 2, 5}
		Output:         {_, 1, 1,  4, 1, 2}
		First element (1) has no element on left side. For 6, 
		there is only one smaller element on left side 1. 
		For 10, there are three smaller elements on left side (1,
		6 and 4), nearest among the three elements is 4.
		
		Input: arr[] = {1, 3, 0, 2, 5}
		Output:        {_, 1, _, 0, 2} 
 */
import java.util.*;
class NearestSmaller{
	public static void findNear(int arr[], int len) {
		Stack <Integer> st=new Stack<Integer>();
		for(int i=0;i<len;i++) {
			while(!st.empty() && (st.peek() >= arr[i]))
				st.pop();
			if(st.empty())
				System.out.print("_");
			else
				System.out.print(st.peek());
			st.push(new Integer(arr[i]));
		}
	}
	public static void main (String[] args)
    {
		int arr[] = {1, 6, 4, 10, 2, 5};
        findNear(arr,arr.length);
    }
}