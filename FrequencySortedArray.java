import java.util.Scanner;

class FrequencySortedArray{
	static int count(int[] arr, int low, int high , int ele, int len){
		int i,j;
		i=first(arr,low,high,ele);
		System.out.println(i);
		
		if(i==-1)
			return i;
		j=last(arr,low,high,ele,len);
		System.out.println(j);
		return j-i+1;
	}
	
	static int first(int arr[], int low, int high ,int ele) {
		if(high>=low){
			int mid=low +(high-low)/2;
			if((mid==0 ||ele>arr[mid-1]  )&& ele==arr[mid])
				return mid;
			if(ele>arr[mid])
				return first(arr, mid+1, high, ele);
			return first(arr, low, mid-1, ele);
		}
		return -1;
	}
	
	static int last(int arr[] ,int low, int high , int ele, int len){
		if(high>=low){
			int mid= low +(high-low)/2;
			if((mid==len-1 || ele<arr[mid+1]) &&ele==arr[mid] )
				return mid;
			if(ele<arr[mid])
				return last(arr,low, mid-1,ele, len);
			else
				return last(arr,mid+1,high, ele,len);
		}
		return -1;
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
		int result=count(arr, 0, len-1, ele, len);
		System.out.println((result<0) ? "Not Found" : "Count=" + result);
	}
}