#define H 8 
#include <stdbool.h> 
#include <stdio.h> 
//****************************8 Queen puzzle using backtracking******************************

 //___________________________________Start_______________________________________
  // This function is defined to check whether the queen's position is safe or not 
bool issafe(int chess[H][H], int row, int colm) 
{ 
    int i, j; 
    for (i = 0; i < colm; i++) 
        if (chess[row][i]) 
            return false; 

    for (i = row, j = colm; i >= 0 && j >= 0; i--, j--) 
        if (chess[i][j]) 
            return false; 
    for (i = row, j = colm; j >= 0 && i < H; i++, j--) 
        if (chess[i][j]) 
            return false; 
  
    return true; 
} 
//____________________________________________________________________________
 // This function is defined  to solve the issue with the help of backtracking 
bool solve(int chess[H][H], int colm) 
{ 
    if (colm >= H) 
        return true; 
  
   
    for (int i = 0; i < H; i++) { 
       //if it is safe to place the queen at position i,colm -----> place it
        if (issafe(chess, i, colm)) { 
         
            chess[i][colm] = 1; 
  
         
            if (solve(chess, colm + 1)) 
                return true; 

  //it will be backtracked if the above condition is false
            chess[i][colm] = 0; // backtracking is being applied 
        } 
    } 
  
   
    return false; 
} 
//_________________________________________________________________________
 //This function is defined to print the solution
void printsolu(int chess[H][H]) 
{ 
    for (int i = 0; i < H; i++) { 
        for (int j = 0; j < H; j++) 
            printf(" %d ", chess[i][j]); 
        printf("\n"); 
    } 
} 
//________________________________Test_____________________________________
 // This is the driver program to test the abovementioned function 
int main() 
{ 
     int chess[H][H] = {{ 0, 0, 0, 0, 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 0, 0, 0 }}; 
  
    if (solve(chess, 0) == false) { 
        printf("There is no possible solution for this issue"); 
        return 0; 
    } 
  
    printsolu(chess); 
    return true; 
    return 0; 
}