/*

Name 		: Vishal Gupta
Reg. No. 	: 1541012426
Branch		: CSE
Sec		: C
------------------------------------------------------------------------
Question : Find the binomial coefficent 

Input: n=5, k = 2
Output: C(n,k) = 10
------------------------------------------------------------------------
*/
import java.util.*;
class BinomialCo {

	private int binomial(int n, int k) {
	
		int c[][]= new int[n+1][k+1];
		for(int i = 0; i<= n ;i++) {
			for(int j = 0 ;j <= min(i,k); j++) {
			
				if(j == 0 || j == i)
					c[i][j] = 1;
				else {
					c[i][j] = c[i-1][j-1] + c[i-1][j];
				} 
			}
		}
		return c[n][k];
	}
	
	private int min(int a, int b) {
		return (a<b) ? a : b;
	}
	
	public static void main(String args[]) {
	
		BinomialCo obj = new BinomialCo();
		Scanner sc = new Scanner(System.in);
		System.out.println("C(n,k) ");
		System.out.println("Enter the value of n = ");
		int n = sc.nextInt();
		System.out.println("Enter the value of k = ");
		int k = sc.nextInt();
		int result = obj.binomial(n, k);
		System.out.println("Result = " + result);
	}
}
