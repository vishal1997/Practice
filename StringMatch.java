import java.util.Scanner;

class StringMatch {

	String str1;
	String str2;
	StringMatch(String str1, String str2) {
		this.str1 = str1;
		this.str2 = str2;
	}
	public int stringMatch() {
	
		int m = str1.length();
		int n = str2.length();
		int table[][] = new int[m+1][n+1];
		
		for(int i = 0 ;i <= m ; i++) {
		
			for(int j = 0; j<= n ;j++) {
			
				if(i == 0) {
					table[i][j]= j;
				} else if(j==0) {
					table[i][j]= i;
				} else {
				
					if(str1.charAt(i-1) == str2.charAt(j-1)) {
						table[i][j]= table[i-1][j-1];
					} else {
						table[i][j] = min(table[i-1][j-1], table[i-1][j], table[i][j-1])+1;
					}
				}
			}
		}
		
		/*for(int i = 0; i< m ;i++) {
		
			System.out.println();
			for(int j = 0 ; j < n ;  j++) 
				System.out.print(table[i][j]+ " " );
		}*/
		return table[m][n];
	}
	
	int min(int a, int b, int c) {
	
		if(a<b && a<c)
			return a;
		if(b<a && b<c)
			return b;
		return c;
	}
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String s1 =sc.nextLine();
		String s2 = sc.nextLine();
		StringMatch obj = new StringMatch(s1,s2);
		System.out.println(obj.stringMatch());
	}
}
