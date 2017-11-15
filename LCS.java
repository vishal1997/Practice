import java.util.Scanner;
class LCS {

	public static void main(String args[]) {

		Scanner sc = new Scanner(System.in);
		String str1;
		String str2;
		str1= sc.next();
		str2= sc.next();
		char str1_[] = str1.toCharArray();
		char str2_[] = str2.toCharArray();
		int len=lcs(str1_, str2_, str1_.length, str2_.length);
		System.out.println(len);
	}

	public static int lcs(char str1_[], char str2_[], int m, int n) {
		
		int L[][] = new int[m+1][n+1];
		for(int i = 0; i <= m; i++) {

			for(int j=0; j<= n;j++) {
				
				if(i==0 || j==0) {
					L[i][j]=0;
				} else if(str1_[i-1] == str2_[j-1]) {
					L[i][j] = L[i-1][j-1] + 1;
				} else {
					L[i][j] = max(L[i-1][j], L[i][j-1]);
				}
			}
		}
		return L[m][n];
	}
	public static int max(int a, int b) {
		return (a>b) ? a: b;
	}
}
