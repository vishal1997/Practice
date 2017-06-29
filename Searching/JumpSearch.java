
 
import java.util.Scanner;
public class JumpSearch {
	public static int jumpSearch(int[] array, int x) {
		int size=array.length;
		int step=(int)Math.floor(Math.sqrt(size));
		int m=step;
		int prev=0;
		while(array[Math.min(step, size)-1]<x) {
			prev=step;
			step += (int)Math.floor(Math.sqrt(size));
			if(prev>=size)
				return -1;
		}
		while(array[prev]<x){
			prev++;
			if(prev==Math.min(step,size))
				return -1;
		}
		if(array[prev]==x)
			return prev;
		return -1;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int size;
		System.out.println("Enter the size of array");
		Scanner sc=new Scanner(System.in);
		size=sc.nextInt();
		int array[]=new int[size];
		for(int i=0;i<size;i++) {
			array[i]=sc.nextInt();
		}
		int x;
		System.out.println("Enter a number to search");
		x=sc.nextInt();
		int s=jumpSearch(array,x);
		if(s==-1)
			System.out.println("Not found");
		else
			System.out.println(s+1);
	}

}
