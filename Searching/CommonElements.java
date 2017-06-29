/*
	Given three arrays sorted in non-decreasing order, print all common elements in these arrays.
	
	Examples:
	
		ar1[] = {1, 5, 10, 20, 40, 80}
		ar2[] = {6, 7, 20, 80, 100}
		ar3[] = {3, 4, 15, 20, 30, 70, 80, 120}
		Output: 20, 80
		
		ar1[] = {1, 5, 5}
		ar2[] = {3, 4, 5, 5, 10}
		ar3[] = {5, 5, 10, 20}
		Output: 5, 5
*/

import java.util.Scanner;
class CommonElements {
	public void commonElements(int arr1[], int arr2[], int arr3[], int len1, int len2, int len3) {
		int i=0,
			j=0,
			k=0;
		while(i<len1 && j<len2 && k<len3) {
			if(arr1[i]==arr2[j] && arr2[j]==arr3[k]){
				System.out.println(arr1[i]);
				i++;
				k++;
				j++;
			}
			else if(arr1[i]<arr2[j])
				i++;
			else if(arr2[j]<arr3[k])
				j++;
			else
				k++;
		}
	}
	
	public static void main(String args[]) {
		int ar1[] = {1, 5, 10, 20, 40, 80};
	    int ar2[] = {6, 7, 20, 80, 100};
	    int ar3[] = {3, 4, 15, 20, 30, 70, 80, 120};
	    int len1=ar1.length;
	    int len2=ar2.length;
	    int len3=ar3.length;
	    CommonElements obj=new CommonElements();
	    obj.commonElements(ar1,ar2,ar3,len1,len2,len3);
	}
}