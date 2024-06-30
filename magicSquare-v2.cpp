#include <iostream> 
using namespace std;

int** createMagicSquareOdd(int n);
int** createMagicSquareEven(int n);

int main() {
	int** magicSquare;
	int n;
	cout << "Enter the size of your Magic Square: ";
	cin >> n;
	
	if (n % 2 == 0) {
		magicSquare = createMagicSquareEven(n);
	}
	else{
		magicSquare = createMagicSquareOdd(n);
	}

	// Show the Magic Square
	for (int i = 0; i < n; i++) {
		cout << "|";
		for (int j = 0; j < n; j++) {
			cout << magicSquare[i][j] << " ";
		}
		cout << "|\n";
	}
	cout << "\nAli is the best!" ;

  return 0;
}

int** createMagicSquareOdd(int n) {
//	Declare a 2D array
	int** magicSquare = new int*[n];
	for ( int i = 0; i < n; i++) {
		magicSquare[i] = new int[n];
	}
	
//	Initialize the square with 0's
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			magicSquare[i][j] = 0;
		}
	}
//	Generate the Magic Square
	int row = 0, col = n / 2;
	for (int number = 1; number <= n * n; number++) {
		if (magicSquare[row][col] != 0) {
			row += 2;
			col--;
		}
		magicSquare[row][col] = number;
		row--;
		col++;
		if (!(row >= 0 && row < n)  && (col >= 0 && col < n)) row += n;
		else if (!(col >= 0 && col < n) && (row >= 0 && row < n)) col = 0;
		else if (!(col >= 0 && col < n) && !(row >= 0 && row < n)) {
			row += 2;
			col--;
		}
		
	}
//	Return the generated square 
	return magicSquare;	
}

int** createMagicSquareEven(int n) {
	//	Declare a 2D array
	int** magicSquare = new int*[n];
	for ( int row = 0; row < n; row++) {
		magicSquare[row] = new int[n];
	}
	
//	Initialize the square with 0's
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			magicSquare[row][col] = 0;
		}
	}

//  Generate the Magic Square
  if (n % 4 == 0) {
    int num = 1;
    for (int row = 0; row < n; row++) {
      for (int col = 0; col < n; col++) {
        magicSquare[row][col] = num++;
      }
    } 
    for (int row = 0; row < n / 4; row++) {
      for (int col = 0; col < n / 4; col++) {
        magicSquare[row][col] = (n * n + 1) - magicSquare[row][col];
        magicSquare[row][n - col - 1] = (n * n + 1) - magicSquare[row][n - col - 1];
        magicSquare[n - row - 1][col] = (n * n + 1) - magicSquare[n - row - 1][col];
        magicSquare[n - row - 1][n - col - 1] = (n * n + 1) - magicSquare[n - row - 1][n - col - 1];
      }
    }
    for (int row = n / 4; row < 3 * n / 4; row++) {
      for (int col = n / 4; col < 3 * n / 4; col++) {
        magicSquare[row][col] = (n * n + 1) - magicSquare[row][col];
      }
    }
  }
  else {
  //  Devide the square to 4 sub-squares
    //  1. Top left
    int row = 0, col = n / 4;
    for (int number = 1; number <= (n * n) / 4; number++){
      if (magicSquare[row][col] != 0) {
        row += 2;
        col--;
		  }
      magicSquare[row][col] = number;
      row--;
      col++;
      if (!(row >= 0 && row < n / 2)  && (col >= 0 && col < n / 2)) row += n / 2;
      else if (!(col >= 0 && col < n / 2) && (row >= 0 && row < n / 2)) col = 0;
      else if (!(col >= 0 && col < n / 2) && !(row >= 0 && row < n / 2)) {
			  row += 2;
			  col--;
		  }
    }
    //  2. Bottom right 
    row = n / 2, col = (n / 4) * 3 + 1;
    for (int number = (n * n) / 4 + 1; number <= (n * n) / 2; number++){
      if (magicSquare[row][col] != 0) {
        row += 2;
        col--;
		  }
      magicSquare[row][col] = number;
      row--;
      col++;
      if (!(row >= n / 2 && row < n)  && (col >= n / 2 && col < n)) row += n / 2;
      else if (!(col >= n / 2 && col < n) && (row >= n / 2 && row < n)) col = n / 2;
      else if (!(col >= n / 2 && col < n) && !(row >= n / 2 && row < n)) {
        row += 2;
        col--;
		  }
    }
    //   3. Top right
    row = 0, col = (n / 4) * 3 + 1;
    for (int number = (n * n) / 2 + 1; number <= ((n * n) / 4) * 3; number++){
      if (magicSquare[row][col] != 0) {
			  row += 2;
			  col--;
		  }
      magicSquare[row][col] = number;
      row--;
      col++;
      if (!(row >= 0 && row < n / 2)  && (col >= n / 2 && col < n)) row += n / 2;
      else if (!(col >= n / 2 && col < n) && (row >= 0 && row < n / 2)) col = n / 2;
      else if (!(col >= n / 2 && col < n) && !(row >= 0 && row < n / 2)) {
        row += 2;
        col--;
		  }
    }
    //  4. Bottom left
    row = n / 2, col = n/ 4;
    for (int number = ((n * n) / 4) * 3 + 1; number <= n * n; number++){
      if (magicSquare[row][col] != 0) {
        row += 2;
        col--;
		  }
      magicSquare[row][col] = number;
      row--;
      col++;
      if (!(row >= n / 2 && row < n)  && (col >= 0 && col < n / 2)) row += n / 2;
      else if (!(col >= 0 && col < n / 2) && (row >= n / 2 && row < n)) col = 0;
      else if (!(col >= 0 && col < n / 2) && !(row >= n / 2 && row < n)) {
        row += 2;
        col--;
      }
    }
  //  Fix the bug :/
  int store;
  if (n == 6){
    int maxIndex = n - 1;
    for (int row = 0; row <= n / 4;row++) {
      for (int col = 0; col <= n / 4; col++) {
        if (row == col && row == n / 4 && col == n / 4) {
          store = magicSquare[row][col];
          magicSquare[row][col] = magicSquare[maxIndex - row][col];
          magicSquare[maxIndex - row][col] = store;
        }
        else if(row == col) {
          store = magicSquare[row][col];
          magicSquare[row][col] = magicSquare[n / 2 + row][col];
          magicSquare[n / 2 + row][col] = store;
          store = magicSquare[maxIndex / 2 - row][col];
          magicSquare[maxIndex / 2 - row][col] = magicSquare[maxIndex - row][col];
          magicSquare[maxIndex - row][col] = store;
        }
        else continue;
      }
    }
  }
  else if(n == 10) {
    for (int row = 0; row < n / 2; row++) {
      store = magicSquare[row][0];
      magicSquare[row][0] = magicSquare[row + n / 2][0];      
      magicSquare[row + n / 2][0] = store;
      store = magicSquare[row][n - 1];
      magicSquare[row][n - 1] = magicSquare[row + n / 2][n - 1];
      magicSquare[row + n / 2][n - 1] = store;
      if (row > 0 && row < (n / 2 - 1)) {
        store = magicSquare[row][1];
        magicSquare[row][1] = magicSquare[row + n / 2][1];
        magicSquare[row + n / 2][1] = store;
      }
      else if(row == 0 || row == (n / 2 - 1)) {
        store = magicSquare[row][n / 2 - 1];
        magicSquare[row][n / 2 - 1] = magicSquare[row + n / 2][n / 2 - 1];
        magicSquare[row + n / 2][n / 2 - 1] = store;
      }
    }
  }
  }
  //  to be completed...

//  Return the Magic Square
return magicSquare;
}