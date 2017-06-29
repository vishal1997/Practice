/*
 * Unbounded Binary Search Example (Find the point where a monotonically increasing function becomes positive first time)
 */

import java.util.Scanner;

class UnboundedSearch {
	static int func(int x) {
		return (x*x - 10*x - 20);
	}
	
	static int firstPositive() {
		int i=1;
		if(func(0) > 0)
			return 0;
		while(func(i) <= 0)
			i *= 2;
		
		return binarySearch(i, i/2);
	}
	
	static int binarySearch(int low, int high ) {
		int mid = low + (high-low) /2;
		if (func(mid) > 0 && (mid==low || func(mid-1)<=0))
			return mid;
		if(func(mid) <= 0)
			return binarySearch(mid+1, high );
		return binarySearch(low, mid-1);
	}
	
	public static void main(String args[]) {
		System.out.println("N=" + firstPositive());
	}
}