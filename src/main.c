#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "life.h"
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>

/* Be sure to read life.h and the other given source files to understand
 * what they provide and how they fit together.  You don't have to
 * understand all of the code, but you should understand how to call
 * parse_life() and clearterm().
 */

/* This is where your program will start.  You should make sure that it
 * is capable of accepting either one or two arguments; the first
 * argument (which is required) is a starting state in one of the Life
 * formats supported by parse_life(), and the second (which is optional)
 * is a number of generations to run before printing output and stopping.
 *
 * The autograder will always call your program with two arguments.  The
 * one-argument format (as described in the handout) is for your own
 * benefit!
 */
int main(int argc, char *argv[]){
    if(argc<2 || argc>3) {
        printf("Error: Invalid number of arguments\n");
        return -1;
    }
    int genNum = (argc!=2)?atoi(argv[2]):0;
    char **grid = parse_life(argv[1]);
    char expandedgrid[GRIDY+2][GRIDX+2];
    int currentGen = 0;
    while(currentGen < genNum) {
    for(int i = 0; i < GRIDY+2;i++) {        //Initializes Expandedgrid using Grid
        for(int j = 0; j < GRIDX+2;j++) {
            if(i==0||i==GRIDY+1) {
                expandedgrid[i][j] = DEAD;
            }
            else if(j==0||j==GRIDX+1){
                expandedgrid[i][j] = DEAD;
            }
            else {
                expandedgrid[i][j] = grid[i-1][j-1];
            }
        }
    }

    for(int i = 1; i<GRIDY+1;i++) {
        for(int j = 1; j<GRIDX+1;j++) {
            int countliving = 0;
                if(expandedgrid[i-1][j-1]==LIVE) {
                    countliving += 1;
                }
                if(expandedgrid[i-1][j]==LIVE) {
                    countliving += 1;
                }
                if(expandedgrid[i-1][j+1]==LIVE) {
                    countliving += 1;
                }
                if(expandedgrid[i][j-1]==LIVE) {
                    countliving += 1;
                }
                if(expandedgrid[i][j+1]==LIVE) {
                    countliving += 1;
                }
                if(expandedgrid[i+1][j-1]==LIVE) {
                    countliving += 1;
                }
                if(expandedgrid[i+1][j]==LIVE) {
                    countliving += 1;
                }
                if(expandedgrid[i+1][j+1]==LIVE) {
                    countliving += 1;
                }
                if(expandedgrid[i][j]==LIVE){
                    if(countliving<2) {
                        grid[i-1][j-1] = DEAD;
                    }
                    else if(countliving>3) {
                        grid[i-1][j-1] = DEAD;
                    }
                    else {
                        grid[i-1][j-1] = LIVE; //continue living
                    }
                }
                else if(expandedgrid[i][j]==DEAD && countliving == 3) {
                    grid[i-1][j-1] = LIVE;
                }
        }
    }
    currentGen++;
    }
    for(int i = 0; i < GRIDY;i++) {    //prints out first state
        for(int j = 0; j < GRIDX;j++) {
            printf("%c",grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}
