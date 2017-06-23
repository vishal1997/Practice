import java.util.Scanner;
import java.util.Arrays;
class InterpolationSearch {
	public static int search(int[] arr, int x) {
		int hi=arr.length - 1;
		int pos=0;
		int lo=0;
		while(lo<=hi && x>=arr[lo] && x<=arr[hi] ){
			pos=lo + (((hi-lo)/(arr[hi]-arr[lo]))*(x-arr[lo]));
			if(x==arr[pos])
				return pos;
			if(x<arr[pos])
				hi=pos-1;
			else
				lo=pos+1;
		}
		return -1;
	}
	
	public static void main (String args[]) {
		int size=0;
		System.out.println("Enter the size of array:");
		Scanner sc=new Scanner(System.in);
		size=sc.nextInt();
		int[] arr=new int[size];
		for(int i=0;i<size;i++) 
			arr[i]=sc.nextInt();
		System.out.println("Enter the element to search:");
		int x=sc.nextInt();
		int result=search(arr,x);
		System.out.println((result<0) ? "Not found" : "Element found at index" + result);
	}
}