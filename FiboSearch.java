import java.util.Scanner;
import java.util.Arrays;

class FiboSearch {
	static int fiboSearch(int[] arr, int x) {
		int offset=-1;
		int fib1=1, fib2=0, fib=fib1+fib2;
		int len=arr.length;
		while(fib<len) {
			fib2=fib1;
			fib1=fib;
			fib=fib1+fib2;
		}
		while(fib>1) {
			int i=Math.min(offset+fib2, len);
			if(arr[i]<x) {
				offset=i;
				fib=fib1;
				fib1=fib2;
				fib2=fib-fib1;
			}
			else if(arr[i]>x){
				fib=fib2;
				fib1=fib1-fib2;
				fib2=fib-fib1;
			}
			else
				return i;
		}
		if(fib1>0 && arr[offset+1]==x)
			return offset+1;
		return -1;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int size;
		System.out.println("Enter the size of array");
		Scanner sc=new Scanner(System.in);
		size=sc.nextInt();
		int array[]=new int[size];
		for(int i=0;i<size;i++) {
			array[i]=sc.nextInt();
		}
		int x;
		System.out.println("Enter a number to search");
		x=sc.nextInt();
		int s=fiboSearch(array,x);
		if(s==-1)
			System.out.println("Not found");
		else
			System.out.println(s+1);
	}

}