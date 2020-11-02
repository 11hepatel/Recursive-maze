/* Here in the .cpp you should define and implement everything declared in the .h file.
 */

#include "maze.h"

//Function to assign my MST username to my_id
void get_identity(string &my_id)
{
  my_id = "hdpg4c";
}

//Function to build the matrix using rows as input
string * build_matrix(int rows)
{
  string* matrix; //matrix pointer declaration 
  matrix = new string[rows]; //builds the matrix using the rows
  return matrix; //returns string pointer 
}

//Function to fill the matrix with user inputs
void fill_matrix(string *matrix, int rows)
{
  //for loop to fill in the matrix using the input
  for(int i = 0; i < rows; i++)
    getline(cin, matrix[i]); //gets the input line by line using the getline
}

//Function to print the matrix
void print_matrix(string *matrix, int rows)
{
  //for loop to access the each elements
  for(int i = 0; i < rows; i++)
    cout << matrix[i] << endl; //prints each elements
}

//Function to delete the matrix array
void delete_matrix(string *&matrix)
{
  delete[] matrix;//deleting the entire array
}

//Function to find the start in the maze
void find_start(string *matrix, int rows, int &row, int &col)
{ 
  //For loop to go through each row 
  for(int i = 0; i < rows; i++)
  {
    //Goes through each column using the column length
    for(int j = 0; j < matrix[i].length(); j++)
    {
      if(matrix[i][j] == 'N') //Checks each element in the 
                              //matrix to find the starting point 'N'
      {
        row = i; //row is equal to found row 
        col = j; //column is equal to found column
      }
    }
  }
  return;
}

//Recursion function to find the exit
bool find_exit(string *matrix, int row, int col)
{
  //if at the end of the maze, than return true
  if(at_end(matrix, row, col))
    return true;

  matrix[row][col] = 'N'; //starting point in the maze

  //Recursion method to find exit using the valid paths
  //if direction is valid in north
  if(valid_move(matrix, row, col, "NORTH"))
  {
    //decrements the row to in north direction 
    if(find_exit(matrix, row - 1, col))
    {
      matrix[row][col] = '@'; //puts the @ at [row][column]  
      return true; 
    }
  }

  //checks in south direction 
  if(valid_move(matrix, row, col, "SOUTH"))
  {
    //increments the row 
    if(find_exit(matrix, row + 1, col))
    {
      matrix[row][col] = '@';
      return true;
    }
  }
  
  //checks the East direction 
  if(valid_move(matrix, row, col, "EAST"))
  {
    //decrements the column 
    if(find_exit(matrix, row, col - 1))
    {
      matrix[row][col] = '@';
      return true;
    }
  }

  //checks the WEST direction 
  if(valid_move(matrix, row, col, "WEST"))
  {
    //increments the column 
    if(find_exit(matrix, row, col + 1))
    {
      matrix[row][col] = '@'; //backtrack 
      return true;
    }
  }

  //puts a space when backtracking occurs
  matrix[row][col] = ' ';
  
  return false;
}

//Function to find the E in the matrix
bool at_end(string *matrix, int row, int col)
{ 
  //if the [row][col] is equal to letter 'E', then returns true 
  if(matrix[row][col] == 'E')
    return true;
 
  return false; //always returns false
}

//Functions to check the valid move in correct direction 
bool valid_move(string *matrix, int row, int col, string direction)
{
  //checks in North direction 
  if(direction == "NORTH")
  {
    //decrements the row and check letter 'E'
    if(matrix[row - 1][col] == 'E')
      return true;

    //decrements the row and checks for space
    else if(matrix[row - 1][col] == ' ')
      return true;
  }

  //checks in South direction 
  else if(direction == "SOUTH")
  {
    //incerements rows
    if(matrix[row + 1][col] == 'E')
      return true;

    else if(matrix[row + 1][col] == ' ')
      return true;
  }

  //checks in East direction 
  else if(direction == "EAST")
  {
    //decrements column 
    if(matrix[row][col - 1] == 'E')  
      return true;
    
    else if(matrix[row][col - 1] == ' ')
      return true;
  }

  //checks in West direction 
  else if(direction == "WEST")
  {
    //increments the column
    if(matrix[row][col + 1] == 'E') 
      return true;

    else if(matrix[row][col + 1] == ' ')
      return true;
  }

  return false;
}
