class NQueen {

	int arr[];
	NQueen() {
		arr = new int[4];
	}
	public void nQueen(int k, int n) {
	
		for(int i = 0; i < n; i++) {
		
			if(place(k,i)) {
				arr[k] = i;
				if(k == n-1) {
					display();
					break;	
				}
				else 
					nQueen(k+1, n);
			}
		}
	}
	
	public boolean place(int k, int i) {
	
		for(int j = 0; j<k; j++) {
			if( (arr[j] == i) || Math.abs(arr[j]-i) == Math.abs(j-k))
				return false;
		}
		return true;
	}
	
	public void display() {
		
		System.out.println("Solution");
		for(int i = 0 ; i < arr.length; i++) 
			System.out.println( i +" " + arr[i]);
	}
	
	public static void main(String agrs[]) {
	
		
		NQueen obj = new NQueen();
		obj.nQueen(0,4 );
	}
}
