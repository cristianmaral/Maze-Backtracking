#ifndef LABIRINTOCACHORRO_H_INCLUDED
#define LABIRINTOCACHORRO_H_INCLUDED

// Maze size
#define N 5

typedef struct {
    int valor;
    int visitou;
} Maze;

void printSolution(int sol[N][N]);
int solveMazeUtil(Maze maze[N][N], int x, int y, int sol[N][N]);
int solveMaze(Maze maze[N][N]);


#endif // LABIRINTOCACHORRO_H_INCLUDED
