/*
 *Given a sorted array and a number x, find a pair in array whose sum is closest to x.

	Examples:
		Input: arr[] = {10, 22, 28, 29, 30, 40}, x = 54
		Output: 22 and 30
		
		Input: arr[] = {1, 3, 4, 7, 10}, x = 15
		Output: 4 and 10 
 */

class ClosestSum{
	public static void closestSum(int arr[], int size, int sum){
		int diff=Integer.MAX_VALUE;
		int s=0,i=0,j=size-1;
		int sp=0,fp=0;
		while(i<=j){
			s=Math.abs(sum-(arr[i]+arr[j]));
			if(s<diff){
				fp=i;
				sp=j;
				diff=s;
			}
			if(arr[i]+arr[j]<sum)
				i++;
			else
				j--;
		}
		System.out.println("Closest sum="+arr[fp] + " "+ arr[sp]);
	}
	public static void main(String[] args)
    {
        int arr[] =  {10, 22, 28, 29, 30, 40}, x = 54;
        int n = arr.length;
        closestSum(arr, n, x);        
    }
}
