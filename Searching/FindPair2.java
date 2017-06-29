/*
 * Write a C program that, given an array A[] of n numbers and another number x, 
 * determines whether or not there exist two elements in S whose sum is exactly x.
		
		1) Initialize Binary Hash Map M[] = {0, 0, ...}
		2) Do following for each element A[i] in A[]
		   (a)	If M[x - A[i]] is set then print the pair (A[i], x - A[i])
		   (b)	Set M[A[i]]
 */

import java.util.*;

class FindPair2{
	private static final int MAX = 100000;
	public static void findPair(int arr[] ,int sum, int len) {
		int temp;
		boolean []map= new boolean[MAX];
		for(int i=0;i<len;i++) {
			temp=sum-arr[i];
			if(temp>0 && map[temp]==true)
				System.out.println(sum +"=" + temp+ "+" +arr[i] );
			map[arr[i]]=true;
		}
	}
	public static void main (String[] args)
    {
        int A[] = {1, 4, 45, 6, 10, 8};
        int n = 16;
        findPair(A,  n,A.length);
    }
}