/*Given an array that is sorted and then rotated around an unknown point. 
 * Find if array has a pair with given sum x. 
 * It may be assumed that all elements in array are distinct.

Examples:

Input: arr[] = {11, 15, 6, 8, 9, 10}, x = 16
Output: true
There is a pair (6, 10) with sum 16

Input: arr[] = {11, 15, 26, 38, 9, 10}, x = 35
Output: true
There is a pair (26, 9) with sum 35

Input: arr[] = {11, 15, 26, 38, 9, 10}, x = 45
Output: false
There is no pair with sum 45.
*/
class PairRotated{
	public static boolean findPair(int arr[], int sum,int len) {
		int i;
		for(i=0;i<len;i++)
			if(arr[i]>arr[i+1])
				break;
		int low=(i+1)%len;
		int high=i;
		while(low!=high) {
			if(sum==arr[low]+arr[high])
				return true;
			if(sum<arr[low]+arr[high])
				high=(len+high-1)%len;
			else
				low=(low+1)%len;
		}
		return false;
	}
	public static void main (String[] args)
    {
		int arr[] = {11, 15, 6, 8, 9, 10};
	    int sum = 16;
        System.out.println(findPair(arr,  sum,arr.length));
    }
}