/*
 * An Array of integers is given, both +ve and -ve. 
 * You need to find the two elements such that their sum is closest to zero.
 */

import java.util.Scanner;
import java.util.Arrays;
class MinSumPair {
	static void minSumPair(int []arr, int size) {
		if(size<2){
			System.out.println("Invalid Input");
			return;
		}
		int sum=0, minSum=99999, l=0, r=size-1, m_l=0, m_r=0;
		Arrays.sort(arr);
		while(l<r) {
			sum=arr[l]+arr[r];
			if(Math.abs(sum)< Math.abs(minSum)){
				sum=minSum;
				m_l=l;
				m_r=r;
			}
			if(sum<0)
				l++;
			else
				r--;
		}
		System.out.println("Element whose sum id min="+ arr[m_l] + "and" + arr[m_r]);
	}
	
	public static void main(String args[]) {
		int size;
		System.out.println("Enter the size of array:");
		Scanner sc=new Scanner(System.in);
		size=sc.nextInt();
		int arr[]=new int[size];
		for(int i=0;i<size;i++) 
			arr[i]=sc.nextInt();
		minSumPair(arr,size);
	}
	
}