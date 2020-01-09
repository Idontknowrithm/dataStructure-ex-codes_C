#include<stdio.h>
#include<stdlib.h>
void print_maze(int (*maze)[5]);
int main() {
	int stack[100][2];
	int top = -1;
	int column = 0; int row = 1;
	int maze[5][5] = {  { 1, 1, 1, 1, 1 },
						{ 0, 0, 0, 0, 1 },
						{ 1, 0, 1, 1, 1 },
						{ 1, 0, 0, 0, 1 },
						{ 1, 0, 1, 0, 0 } };
	// start point : [0][1]  
	// finish point : [4][4] 

	if (maze[1][0] == 1) {
		printf("Can't find exit\n");
		return 0;
	}
	else {
		maze[row][column] = 9;
		stack[++top][0] = row;
		stack[top][1] = column;
		print_maze(maze);
	}

		while (1) {
			if (maze[row][column + 1] == 0) {
				stack[++top][0] = row;
				stack[top][1] = ++column;
				maze[row][column] = 9;
				print_maze(maze);
				if(maze[4][4] == 9)
				break;
			}
			else if (maze[row + 1][column] == 0) {
				stack[++top][0] = ++row;
				stack[top][1] = column;
				maze[row][column] = 9;
				print_maze(maze);
				if (maze[4][4] == 9)
				break;
			}
			else if (maze[row][column - 1] == 0) {
				stack[++top][0] = row;
				stack[top][1] = --column;
				maze[row][column] = 9;
				print_maze(maze);
				if (maze[4][4] == 9)
				break;
			}
			else if (maze[row - 1][column] == 0) {
				stack[++top][0] = --row;
				stack[top][1] = column;
				maze[row][column] = 9;
				print_maze(maze);
				if (maze[4][4] == 9)
				break;
			}
			else {	//nowhere to go
				row = stack[--top][0];
				column = stack[top][1];
			}
			
		}
		
		return 0;
}
void print_maze(int (*maze)[5]) {
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++)
			printf("%d ", maze[i][j]);
		printf("\n");
	}
	printf("\n");
}