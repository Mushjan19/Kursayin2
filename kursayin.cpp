#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <vector>
#include <windows.h>
using namespace std;

void printMatrix(int row, int column, int mat[10][10], int time) {
  for (int i = 0; i <= row - 1; i++) {
    for (int j = 0; j <= column - 1; j++) {
      printf("%3d", mat[i][j]);
      Sleep(time);
    }
    cout << endl;
  }
  Sleep(time);
}

void createRandomMatrix(int row, int column, int mat[10][10], int time) {
  int rnd;

  for (int i = 0; i <= row - 1; i++) {
    for (int j = 0; j <= column - 1; j++) {
      rnd = rand() % 100;
      mat[i][j] = rnd;
    }
  }

  printMatrix(row, column, mat, time);
}

void createMatrix(int row, int column, int mat[10][10], int time) {
  for (int i = 0; i <= row - 1; i++)
    for (int j = 0; j <= column - 1; j++)
      cin >> mat[i][j];

  system("cls");
  printMatrix(row, column, mat, time);
}
int IsSame(int mat[10][10], int row, int aCol, int bCol)
{
  for (int i = 0; i < row; i++)
  {
    int isSame = 0;
    for (int j = 0; j < row; j++)
    {
      if (mat[i][aCol] == mat[j][bCol])
      {
        isSame = 1;
        break;
      }
    }
    if (!isSame)
      return 0;
  }

  for (int i = 0; i < row; i++)
  {
    int isSame = 0;
    for (int j = 0; j < row; j++)
    {
      if (mat[i][bCol] == mat[j][aCol])
      {
        isSame = 1;
        break;
      }
    }
    if (!isSame)
      return 0;
  }

  return 1;
}

void deleteColumns(int row, int col, int mat[10][10], int time) {
  if (col == 1)return;

  for (int i = 0; i < col; i++)
  {
    for (int j = i + 1; j < col; j++)
    {
      if (IsSame(mat, row, i, j))
      {
        cout << i << " = " << j << endl;
      }
    }
  }
}

#define sleepTime 0

int main() {
  srand(time(0));
  int Matrix[10][10];
  int Row, Column;
  cout << "Insert Row and Column" << endl;
  cin >> Row >> Column;
  system("cls");
ChooseLabel:
  int choose;
  cout << "---------------------------------------" << "\n";
  cout << "1: Insert elements for matrix. " << "\n"
    << "2: Generate random elements for matrix." << "\n";
  cout << "---------------------------------------" << "\n";
  cout << "Your choose: ";
  cin >> choose;
  cout << "\n";

  system("cls");
  if (choose == 2) {
    createRandomMatrix(Row, Column, Matrix, sleepTime);
  }
  else if (choose == 1) {
    createMatrix(Row, Column, Matrix, sleepTime);
  }
  else
  {
    cout << "Worng input";
    goto ChooseLabel;
  }

  int sy = Row;
  cout << endl; sy++;
  cout << endl; sy++;
  cout << endl; sy++;

  printMatrix(Row, Column, Matrix, sleepTime);

  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD startPos = { 0, sy };

  //SetConsoleCursorPosition(h, startPos);
  deleteColumns(Row, Column, Matrix, 400);

  cout << "\nend";
  Sleep(-1);
  return 0;
}
