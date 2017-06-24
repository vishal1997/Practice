import java.util.Scanner;

class CeilingSearch{
	static int ceilingSearch(int[] arr, int low, int high, int ele) {
		if(ele<=arr[low])
			return  low;
		if(ele>arr[high])
			return -1;
		int mid=low + (high-low)/2;
		if(ele==arr[mid])
			return mid;
		if(arr[mid]<ele) {
			if(mid+1<=high && arr[mid+1]>ele)
				return mid+1;
			else
				return ceilingSearch(arr, mid+1, high, ele);
		}
		else{
			if(mid-1 >= low && arr[mid-1]<ele)
				return mid;
			else
				return ceilingSearch(arr, low, mid-1, ele);
		}
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
		System.out.println("Enter element");
		int ele=sc.nextInt();
		int result=ceilingSearch(arr, 0, len-1, ele);
		System.out.println((result<0) ? "Not Found" : "Ceiling=" + arr[result]);
	}
}