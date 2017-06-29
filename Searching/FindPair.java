/*
 * Given an unsorted array and a number n, 
 * find if there exists a pair of elements in the array whose difference is n.
 * */
import java.util.Scanner;
import java.util.Arrays;

class FindPair{
	static void findPair(int arr[],int len,int n){
		int i=0,j=1;
		while(i<len && j<len){
			if(arr[j]-arr[i]==n && i!=j){
				System.out.println("Elements found=(" + arr[i] + "," + arr[j] + ")" );
				return;
			}
			if((arr[j]-arr[i])<n)
				j++;
			else
				i++;
		}
		System.out.println("Element not found");
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
		System.out.println("Enter difference");
		int ele=sc.nextInt();
		Arrays.sort(arr);
		findPair(arr, len,ele);
		
	}
}