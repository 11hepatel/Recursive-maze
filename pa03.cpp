/* Declare any non-required functions above main.
 * The duty of main here is to interact with the user, take in input, and manage wrapping output and runtime.
 * Remember, if you are considering putting something in main or a function, double check the specifications.
 * Each function should only do what it is specified to do, and no more.
 */

#include "maze.h"


int main()
{
  int rows; //variable declaration for rows
  int row; //variable declaration for pass by reference row
  int col; //varaibel declaration for pass by reference col
  int cases = 0; //cases starts at 0

  //runs while the row is not equal to 0
  // terminates the program when rows are equal to zero
  while(rows != 0)
  {
    string* array = NULL; //intializing the pointer array to null
    cin >> rows; //gets the input from the user

    if(rows != 0)//if row is not equal to zero
    {
      cin.ignore(); //discard any newlines
      array = build_matrix(rows); //calls in the build_matrix function
      fill_matrix(array, rows); //calls the fill_matrix function
      find_start(array, rows, row, col); //calls the find_start function
      
      //if not find_exit, then outputs the no solution message
      if(!find_exit(array, row, col)) 
        cout << "Map "<< cases << " -- No solution found: " << endl;
      else //is found the exit, then outputs the following message
        cout << "Map " << cases << " -- Solution found:" << endl;

      //Puts the starting point
      array[row][col] = 'N';
      print_matrix(array, rows); //prints the solved maze
      cases++; //increments the cases
  
      delete_matrix(array); //deletes the matrix array 
    }
    cout << endl; //puts space in the outputs
  }
  return 0;
}
