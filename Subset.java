public class Subset {

	 public static void main(String[] args) {
	 
		Subset obj = new Subset();
		char [] s = { 'a', 'b', 'c', 'd' };
		obj.subset(s);
	 }

	 public void subset(char[] s) {
	 
		boolean[] a = new boolean[s.length];
		backtrack(a, 0, s);
	 }


	 public void backtrack(boolean[] a, int k, char[] s) {
	 
		if (isSolution(k, s)) {
			processSolution(a,s);
			return;
	  	}

		boolean[] candidates = constructCandidates();
		
		for (int i = 0; i < candidates.length; i++) {
			a[k] = candidates[i];
			backtrack(a, k + 1, s);
		}
	 }

	 public boolean[] constructCandidates() {
	 
		boolean [] C = new boolean[2];
		C[0] = false;
		C[1] = true;
		return C;
	 }
	 
	 public void processSolution(boolean[] a, char[] s) {
	 
		System.out.print("{");
		for (int i = 0; i < s.length; i++) {
			if (a[i] == true) {
				System.out.print(" ");
				System.out.print(s[i]);
			}
		}
		System.out.println(" }");
	 }

	 public boolean isSolution(int k, char[] s) {
		return k == s.length;
	 }
}
