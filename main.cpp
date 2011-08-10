#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>

using namespace std;

#define WIDTH 10
#define HEIGHT 7

#define MAX_TRAPS 3

char board[WIDTH][HEIGHT];
int playerX; // The X loc of the player
int playerY; // The Y loc of the player

void setupBoard()
{
  for(int h = 0; h < HEIGHT; h++)
  {
    for(int w = 0; w < WIDTH; w++)
    {
      board[w][h] = '-';
    }
  }

  playerX = 0;
  playerY = 0;
  board[0][0] = 'P'; //Adds player to board.
  board[WIDTH - 1][HEIGHT - 1] = 'X'; //Adds game truesure to board.

  //this for loop adds traps to the board in random locations
  //other then where the player is or treasure.
  srand(time(NULL));
  for(int i = 0, rx, ry; i < MAX_TRAPS; i++)
  {
    rx = rand() % WIDTH;
    ry = rand() % HEIGHT;

    board[rx][ry] = 'T';
  }
}

void displayBoard()
{
  for(int h = 0; h < HEIGHT; h++)
  {
    for(int w = 0; w < WIDTH; w++)
    {
      cout << board[w][h];
    }
    cout << endl;
  }
}

// The params are the (x,y) coords of the object being checked
// and the direction of where it wants to move next
// Returns true if coords are still on board.. false otherwise.
bool isOnGrid(int x, int y, char direction)
{
  switch(direction)
  {
    case 'u':
      if((y - 1) < 0)
        return false;
      break;
    case 'r':
      if((x + 1) >= WIDTH)
        return false;
      break;
    case 'd':
      if((y + 1) >= HEIGHT)
        return false;
      break;
    case 'l':
      if((x - 1) < 0)
        return false;
  }
  return true;
}

int main()
{
assert(0);
  setupBoard();

  while(true) // Main game loop
  {

    displayBoard();
    cout << "Direction to move ('u','d','l','r')." << endl;
    char choice;
    cin >> choice;

    if(isOnGrid(playerX, playerY, choice))
    {
      int tempX, tempY;
      switch(choice) //gets the locaton of the new spot using the direction provided.
      {
        case 'u':
          tempX = playerX;
          tempY = playerY - 1;
          break;
        case 'r':
          tempX = playerX + 1;
          tempY = playerY;
          break;
        case 'd':
          tempX = playerX;
          tempY = playerY + 1;
          break;
        case 'l':
          tempX = playerX - 1;
          tempY = playerY;
      }

      if(board[tempX][tempY] == 'X')
      {
        displayBoard();
        cout << "Congratulations!!! You won!!!";
        break;
      }
      else if(board[tempX][tempY] == 'T')
      {
        displayBoard();
        cout << "Ouch!! You fell for the trap.";
        break;
      }
      else
      {
        board[playerX][playerY] = '-';
        playerX = tempX;
        playerY = tempY;
        board[playerX][playerY] = 'P';
      }
    }
  }
  return 0;
}
