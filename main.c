#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void mazeGen(char maze[21][21], char traversed[21][21]);
void recur(char maze[21][21], char traversed[21][21], int xpos, int ypos);
int main()
{
                    //Stores the maze
                    char maze[21][21] = {
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                    {'#','O','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};

                    //Keeps track of areas that have already been traversed and/or never will be traversed
                   char traversed[21][21] =
                   {{'#','#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#'},
                    {'#','O' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'#'},
                    {'#','t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#'},
                    {'#','t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'#'},
                    {'#','t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#'},
                    {'#','t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'#'},
                    {'#','t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#'},
                    {'#','t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'#'},
                    {'#','t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#'},
                    {'#','t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'#'},
                    {'#','t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#'},
                    {'#','t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'#'},
                    {'#','t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#'},
                    {'#','t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'#'},
                    {'#','t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#'},
                    {'#','t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'#'},
                    {'#','t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#'},
                    {'#','t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'#'},
                    {'#','t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#'},
                    {'#','t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'#'},
                    {'#','#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#'}};
                    mazeGen(maze, traversed);


}
    //Prim's Algorithm
    //add o to 1,1
    //repeat until reched 10,10
    //Look around item.
    //Pick a point at random
    //if wall can be carved within bounds and point not already traversed
    //carve wall
    //else
    //look for new wall
    //add 10,10

    void mazeGen(char maze[21][21], char traversed[21][21])
    {
        srand(time(NULL));
        int xpos = 1;
        int ypos = 1;
        //Sets the first cell to the marker indicating a starting point.
        maze[xpos][ypos] = 'O';
        //Calls the recursion function to generate maze.
        recur(maze, traversed, xpos, ypos);
        //After the recursion function is finished, marks the destination
        maze[19][19] = 'X';
        //Prints the finished maze
        for(int n = 0; n<21; n++)
        {
            for(int k = 0; k<21; k++)
            {
                printf("%c", maze[n][k]);
            }
            printf("%c", '\n');
        }
    }
    void recur(char maze[21][21], char traversed[21][21], int xpos, int ypos)
    {
        //Generates a random number between 0 and 3 inclusive.
        int randomnumber = rand()%4;
        //This loop runs while there are any empty spaces surrounding the coordinates in said location
        while(traversed[xpos-1][ypos-1] == 't'  || traversed[xpos][ypos-1] == 't'  ||
        traversed[xpos+1][ypos-1] == 't'  || traversed[xpos-1][ypos] == 't'  || traversed[xpos][ypos] == 't'  ||
        traversed[xpos+1][ypos] == 't'  || traversed[xpos-1][ypos+1] == 't'  || traversed[xpos][ypos+1] == 't'  || traversed[xpos+1][ypos+1] == 't' ){
        //Determines a random direction in which to draw the path(either up, down, left, or right)
        randomnumber = rand()%4;
        //If the random number is zero, try to draw a path left
        if(randomnumber == 0)
        {
            if((xpos >1) && (traversed[xpos-2][ypos] == 't' ))
            {
                //Take the x position to the wall
                xpos--;
                //Tear down said wall and mark as visited
                maze[xpos][ypos] = ' ';
                //Calls the recursion function for the next cell
                traversed[xpos][ypos]= ' ';
                //Set coordinates to interior of next cell
                xpos--;
                //Mark cell as visited and as path as the wall is certain to be empty
                traversed[xpos][ypos]= ' ';
                //Calls this function(recursion) for the next cell
                recur(maze,traversed, xpos, ypos);
                //Resets any changes made to the ypos value in the previous statements within this if statement so the loop can continue to check the same cell until all the surrounding areas are full.
                xpos+=2;
            }
            //If drawing the path would create a loop(according to Prim's algorithm), leave the wall and mark the area as traversed.
            else if(traversed[xpos-2][ypos] != 't' )
            {
                traversed[xpos-1][ypos] = '#';
            }
        }
        //If the random number is one, try to draw the path right
        else if(randomnumber == 1)
        {
            if((xpos <19) && (traversed[xpos+2][ypos] == 't' ))
            {

                //Take the x position to the wall
                xpos++;
                //Tear down said wall and mark as visited
                maze[xpos][ypos] = ' ';
                traversed[xpos][ypos]= ' ';
                //Set coordinates to interior of next cell
                xpos++;
                //Mark cell as visited and as path as the wall is certain to be empty
                traversed[xpos][ypos]= ' ';
                //Calls this function(recursion) for the next cell
                recur(maze,traversed, xpos, ypos);
                //Resets any changes made to the ypos value in the previous statements within this if statement so the loop can continue to check the same cell until all the surrounding areas are full.
                xpos-=2;
            }
            //If drawing the path would create a loop(according to Prim's algorithm), leave the wall and mark the area as traversed.
            else if(traversed[xpos+2][ypos] != 't' )
            {
                traversed[xpos+1][ypos] = '#';
            }
        }
        //If the random number is two, try to draw the path up
        else if(randomnumber == 2)
        {
            if((ypos >1) && (traversed[xpos][ypos-2] == 't' ))
            {
                //Take the y position to the wall
                ypos--;
                //Tear down said wall and mark as visited
                maze[xpos][ypos] = ' ';
                traversed[xpos][ypos]= ' ';
                //Set coordinates to interior of next cell
                ypos--;
                //Mark cell as visited and as path as the wall is certain to be empty
                traversed[xpos][ypos]= ' ';
                //Calls this function(recursion) for the next cell
                recur(maze,traversed, xpos, ypos);
                //Resets any changes made to the ypos value in the previous statements within this if statement so the loop can continue to check the same cell until all the surrounding areas are full.
                ypos+=2;
            }
            //If drawing the path would create a loop(according to Prim's algorithm), leave the wall and mark the area as traversed.
            else if(traversed[xpos][ypos-2] != 't' )
            {
                traversed[xpos][ypos-1] = '#';
            }
        }
        //If the random number is three, try to draw the path down
        else
        {
            if((ypos <19) && (traversed[xpos][ypos+2] == 't' ))
            {
                //Take the y position to the wall
                ypos++;
                //Tear down said wall and mark as visited
                maze[xpos][ypos] = ' ';
                traversed[xpos][ypos]= ' ';
                //Set coordinates to interior of next cell
                ypos++;
                //Mark cell as visited and as path as the wall is certain to be empty
                traversed[xpos][ypos]= ' ';
                //Calls this function(recursion) for the next cell
                recur(maze,traversed, xpos, ypos);
                //Resets any changes made to the ypos value in the previous statements within this if statement so the loop can continue to check the same cell until all the surrounding areas are full.
                ypos-=2;
            }
            //If drawing the path would create a loop(according to Prim's algorithm), leave the wall and mark the area as traversed.
            else if(traversed[xpos][ypos+2] != 't' )
            {

                 traversed[xpos][ypos+1] = '#';
            }
        }
    }
}

