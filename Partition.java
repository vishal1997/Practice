class Partition {

	public int partition(int s[], int k) {
	
		int p[] = new int[s.length];
		p[0] = 0;
		int n =s.length;
		for(int i =1; i< n;i++) 
			p[i] = p[i-1] + s[i];
		
		int m[][] = new int[n][k];
		int d[][] = new int[n][k];
		
		for(int i = 0 ; i< n ;i++) {
			m[i][1] = p[i];
		}
		
		for(int i = 0; i < k ;i++) {
			m[1][i] = s[0];
		}
		
		for(int i = 1 ; i<n ; i++) {
		
			for(int j= 1; j < k ; j++) {
				m[i][j] = Integer.MAX_VALUE;
				
				for(int x = 0;x < i-1 ; x++) {
					int t = max(m[x][j-1], p[i]-p[x]);
					if(t< m[i][j]) {
						m[i][j] = t;
						d[i][j]= x;
					}
				}
			}
		}
		return m[n-1][k-1];
	}
	
	int max(int a, int b) {
		return a>b ? a : b;
	}
	
	public static void main(String args[]) {
		
		Partition obj = new Partition();
		int arr[] = {1,2,3,4,5,6,7,8,9};
		System.out.println(obj.partition(arr, 3));
	}
}
