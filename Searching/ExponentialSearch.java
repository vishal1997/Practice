import java.util.Arrays;
import java.util.Scanner;
class ExponentialSearch {
    public static int exponentialSearch(int[] array, int x) {
        if(array[0]==x)
            return 0;
        int i=1;
        int len=array.length;
        while(i<len && array[i]<=x){
            i *=2;
        }
        return Arrays.binarySearch(array, i/2, Math.min(i, len), x);
    }

    public static void main(String args[]) {
        int size;
        System.out.println("Enter the size of array");
        Scanner sc=new Scanner(System.in);
        size=sc.nextInt();
        int array[]=new int[size];
        for(int i=0;i<size;i++)
            array[i]=sc.nextInt();
        System.out.println("Enter the Element to search");
        int x=sc.nextInt();
        int result= exponentialSearch(array,x);
        System.out.println((result< 0) ? "Element not fount" : "Element found at index "+ result);
    }
}