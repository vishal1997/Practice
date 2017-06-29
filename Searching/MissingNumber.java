import java.util.Scanner;

class MissingNumber{
	static int missingNumber(int[] arr , int size) {
		int x1=arr[0], x2=1;
		for(int i=1;i<size;i++) 
			x1 ^= arr[i];
		for(int i=2;i<=size+1; i++) 
			x2 ^= i;
		
		return x1^x2;
	}
	
	public static void main(String args[]) {
		int size;
		System.out.println("Enter the length of array:");
		Scanner sc=new Scanner (System.in);
		size=sc.nextInt();
		int arr[]=new int[size];
		for(int i=0;i<size;i++) {
			arr[i]=sc.nextInt();
		}
		System.out.println("Missing number=" + missingNumber(arr, size));
	}
}