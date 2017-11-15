/*

Name 		: Vishal Gupta
Reg. No. 	: 1541012426
Branch		: CSE
Sec		: C
------------------------------------------------------------------------
Question : Matrix chain multiplication

Input: arr[]= {1, 2, 3, 4};
Output: Minimum number of multiplication 18
------------------------------------------------------------------------
*/
import java.util.Scanner;
class MatrixCM {

	public int matrixChainMul(int p[] , int n) {
	
		int temp = 0;
		int table[][] = new int[n][n];
		for(int i = 1;i < n ;i++) 
			table[i][i] = 0;
			
		for(int l = 2; l < n; l++ ) {
		
			for(int i = 1 ; i < n-l+1; i++) {
				
				int j = i+l-1;
				if(j != n) {
					table[i][j] = Integer.MAX_VALUE;
					for(int k = i ;k < j; k++) {
						temp = table[i][k] + table[k+1][j] + (p[i-1] * p[k] * p[j]);
						if(temp<table[i][j]) 
							table[i][j] = temp;	
					}
				}
			}
		}
		return table[1][n-1];
	}
	
	public static void main(String args[]) {
	
		MatrixCM obj = new MatrixCM();
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the size of array" );
		int size = sc.nextInt();
		int arr[] = new int[size];
		System.out.println("Enter the array elements");
		for(int i = 0 ;i < size ;i++ ){
		
			System.out.println("Enter "+ (i+1) +"th element ");
			arr[i] = sc.nextInt();
		}
		System.out.println("Minimum number of multiplications is "+ obj.matrixChainMul(arr, size));
	}
}
