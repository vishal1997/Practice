/*

Name 		: Vishal Gupta
Reg. No. 	: 1541012426
Branch		: CSE
Sec		: C
------------------------------------------------------------------------
Question : Longest Increasing Subsequence

Input: arr = {10, 22, 9, 33, 21, 50, 41, 60, 80}.
Output: 6
------------------------------------------------------------------------
*/

import java.util.Scanner;
class LIS {
	
	int arr[];
	int len;
	LIS(int size) {
		this.arr=new int[size];
		this.len=size;
	}

	public static void main(String args[]) {

		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the length");
		int size= sc.nextInt();
		LIS lis = new LIS(size);
		int len = lis.getLis();
		System.out.println(len);
	}

	public int getLis() {
	
		int temp[] = new int[len];
		int templen=1;
		Scanner sc = new Scanner(System.in);
		System.out.println("Length="+len);
		for(int i=0;i<len;i++) {
			arr[i]= sc.nextInt();
			System.out.println("Input="+arr[i]);
		}
		temp[0]=arr[0];
		for(int i=1;i<len;i++) {
			
			if(arr[i] < temp[0]) {
				temp[0]=arr[i];
			} else if(arr[i] > temp[templen-1]) {
				temp[templen++]=arr[i];
			} else {
				temp[ceilIndex(0,len,arr[i])]=arr[i];
			}
		}
		return templen;
	}
	
	public int ceilIndex(int low, int high, int key) {

		int mid=low + (high-low)/2;
		if(arr[mid] ==key) {
			return mid;
		} else if(arr[mid]>key) {
			return ceilIndex(low, mid, key);
		}
		return ceilIndex(mid, high ,key);
	}
}
