#ifndef LABIRINTOCACHORRO_H_INCLUDED
#define LABIRINTOCACHORRO_H_INCLUDED

// Maze size
#define N 4

void printSolution(int sol[N][N]);
int isSafe(int maze[N][N], int x, int y);
int solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);
int solveMaze(int maze[N][N]);


#endif // LABIRINTOCACHORRO_H_INCLUDED
