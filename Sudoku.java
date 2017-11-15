class Sudoku {

	class Cell {
		int row;
		int col;
		Cell() {
			row = 0;
			col = 0;
		}
	}
	
	Cell cell;
	int N;
	
	Sudoku(int n ) {
		N = n;
		cell = new Cell();
	}
	
	boolean solveSudoku(int grid[][]) {
		
		if(!findLocation(grid)) 
			return true;
		System.out.println();
		printGrid(grid);
		for(int i = 1; i<=9; i++) {
			if(isSafe(grid,i)) {
				grid[cell.row][cell.col] = i;
				if(solveSudoku(grid))
					return true;
				grid[cell.row][cell.col] = 0;
			}
		}
		return false;
	}
	
	boolean findLocation(int grid[][]) {
	
		for(cell.row = 0 ; cell.row < N ;cell.row++) {
			for(cell.col=0; cell.col < N; cell.col++) {
				if(grid[cell.row][cell.col]==0)
					return true;
			}
		}
		return false;
	}
	
	boolean usedInRow(int grid[][], int num) {
	
		for(int col = 0 ; col < N; col++) {
			if(grid[cell.row][col] == num)
				return true;
		}
		return false;
	}
	
	boolean usedInCol(int grid[][], int num) {
	
		for(int row = 0 ; row < N; row++) {
			if(grid[row][cell.col] == num)
				return true;
		}
		return false;
	}
	
	boolean usedInBox(int grid[][], int startRow, int startCol, int num) {
	
		for(int row = 0;row < 3 ; row++) {
			for(int col = 0 ; col < 3 ; col++) {
				if(grid[row+startRow][col + startCol] == num) 
					return true;
			}
		}
		return false;
	}
	
	boolean isSafe(int grid[][], int num) {
	
		return  !usedInRow(grid,num) &&
			!usedInCol(grid,num) &&
			!usedInBox(grid, cell.row - (cell.row%3), cell.col - (cell.col%3), num);
	}
	
	void printGrid(int grid[][]) {
	
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++)
			     System.out.print(grid[row][col] + " " );
			System.out.println();
		}
	}
	
	public static void main(String args[]) {
	
		int grid[][] ={{3, 0, 6, 5, 0, 8, 4, 0, 0},
			      {5, 2, 0, 0, 0, 0, 0, 0, 0},
			      {0, 8, 7, 0, 0, 0, 0, 3, 1},
			      {0, 0, 3, 0, 1, 0, 0, 8, 0},
			      {9, 0, 0, 8, 6, 3, 0, 0, 5},
			      {0, 5, 0, 0, 9, 0, 6, 0, 0},
			      {1, 3, 0, 0, 0, 0, 2, 5, 0},
			      {0, 0, 0, 0, 0, 0, 0, 7, 4},
			      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
			     
		Sudoku obj = new Sudoku(9);
		if (obj.solveSudoku(grid) == true)
			obj.printGrid(grid);
		else
			System.out.println("No solution exists");
	}
}
