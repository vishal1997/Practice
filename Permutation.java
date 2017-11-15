
public class Permutation {

	public class candidate {

		int canArray[];
		int length;
		candidate() {
			canArray = new int[1000];
			length = 0 ;
		}
	}

	public static void main(String[] args) {

		Permutation obj = new Permutation();
		char [] s = { 'a', 'b', 'c', 'd' };
		obj.permutation(s);
	}

	public void permutation(char[] s) {

		int[] a = new int[s.length];
		backtrack(a, 0, s);
	}


	public void backtrack(int[] a, int k, char[] s) {

		if (isSolution(k, s)) {
			processSolution(a,s);
			return;
		}

		candidate candidates = constructCandidates(a, s, k);
		for (int i = 0; i < candidates.length; i++) {
			a[k] = candidates.canArray[i];
			backtrack(a, k + 1, s);
		}
	}

	public candidate constructCandidates(int arr[], char[] s, int k) {

		candidate candidates = new candidate();
		boolean pemIn[] = new boolean[s.length];

		for(int i = 0; i < s.length; i++) 
			pemIn[i] = false;
	
		for(int i = 0;i<k;i++) 
			pemIn[arr[i]] = true;

		int j =0;
		for(int i = 0; i < s.length; i++) 
			if(pemIn[i] == false)
				candidates.canArray[j++] = i; 	
		candidates.length = j;	
		return candidates;
	}

	public void processSolution(int[] a, char[] s) {

		System.out.print("{");
		for (int i = 0; i < s.length; i++) {
			System.out.print(" ");
			System.out.print(s[a[i]]);
		}
		System.out.println(" }");
	}

	public boolean isSolution(int k, char[] s) {
		return k == s.length;
	}
}
