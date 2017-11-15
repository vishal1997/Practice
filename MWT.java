/*
Name 		: Vishal Gupta
Reg. No. 	: 1541012426
Branch		: CSE
Sec		: C
------------------------------------------------------------------------
Question : Minimum triangulation weight

Input: Point[] = {{0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}}
Output: 15.3007
------------------------------------------------------------------------
*/
import java.util.*;
class Point {

	private double x;
	private double y;
	Point(double x, double y) {
		this.x = x;
		this.y = y;
	}
	
	public double getX() {
		return this.x;
	} 
	
	public double getY() {
		return this.y;
	}
}

class MWT {

	private double min(double x, double y) {
		return (x<=y) ? x: y;
	}
	
	private double dist(Point a, Point b) {
	
		return Math.sqrt( (a.getX() - b.getX()) 
				* (a.getX() - b.getX()) 
				+ (a.getY() - b.getY()) 
				* (a.getY() - b.getY()));
	}
	
	private double cost(Point points[], int i, int j, int k) {
		
		Point a = points[i];
		Point b = points[j];
		Point c = points[k];
		return dist(a,b) + dist(b,c) + dist(c,a);
	}
	
	private double mwt(Point points[], int n) {
	
		if(n < 3)
			return 0.0;
		double table[][] = new double[n][n];
		for(int gap = 0; gap < n ; gap++ ) {
		
			for(int i =0, j = gap ;j < n ;j++, i++) {
				
				if(j < i + 2) 
					table[i][j] = 0.0;
				else {
					table[i][j] = Integer.MAX_VALUE;
					for(int k = i+1; k < j ; k++) {
						double value = table[i][k] + table[k][j] + cost(points, i , j , k);
						if(value < table[i][j]) 
							table[i][j] = value;
					}
				}
			}
		}
		return table[0][n-1];
	}
	
	public static void main(String args[]) {
	
		Scanner sc = new Scanner(System.in);
		MWT obj = new MWT();
		System.out.println("Enter the number of points");
		int n = sc.nextInt();
		Point points[] = new Point[n];
		int x,y;
		for(int i=0;i<n;i++) {
		
			System.out.println("--------------------------------------------------------------------------");
			System.out.println("Enter " + (i+1) + "th point");
			System.out.println("Enter x");
			x=sc.nextInt();
			System.out.println("Enter y");
			y=sc.nextInt();
			points[i] = new Point(x, y);
		}
		System.out.println("--------------------------------------------------------------------------");
		double result = obj.mwt(points, n);
		System.out.println("Minimum triangulation weight= " + result);		
	}
}
