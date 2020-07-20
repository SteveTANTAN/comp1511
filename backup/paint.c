// Assignment 1 19T3 COMP1511: CS Paint
// paint.c
//
// This program was written by Xingyu Tan (z5237560)
// on 15/10/2019
//
// Version 1.0.0 (2019-10-08): Assignment released.

#include <stdio.h>

#include <math.h>

// The dimensions of the canvas (20 rows x 36 columns).
#define N_ROWS 20
#define N_COLS 36

// Shades (assuming your terminal has a black background).
#define BLACK 0
#define WHITE 4





// Display the canvas.
void displayCanvas(int canvas[N_ROWS][N_COLS]);

// Clear the canvas by setting every pixel to be white.
void clearCanvas(int canvas[N_ROWS][N_COLS]);

// Calculate the distance between two points.
double distance(int row1, int col1, int row2, int col2);

//Determine if the image is one the canvas.
double point_distance( int row, int cols, int distance, int direction);

//Draw the line on the canvas.
void draw_line (int array[N_ROWS][N_COLS],int start_row, 
int start_col, int length, int direction,int color);

//Draw the square on the canvas.
void draw_sqare (int array[N_ROWS][N_COLS],int start_row, 
int start_col, int length, int direction, int color);

//modify the color.
int color_shade (int a);

//the fuction of copy and paste.
void copy_paste (int array[N_ROWS][N_COLS]);

//the fuction of drawing ellipse.
void draw_Ellipse (int array[N_ROWS][N_COLS], int color);


int main(void) {
    int canvas[N_ROWS][N_COLS];
    clearCanvas(canvas);
    int function;
    int color = BLACK;
    
    //input the command.
    while (scanf("%d", &function)==1) {
        int start_row, start_col, length, direction;
        
        
        //Determine which fuction should be used.       
        if (function == 1) {
            scanf("%d %d %d %d", &start_row, &start_col, 
            &length, &direction);
            
            draw_line (canvas, start_row, start_col, 
            length, direction, color);
        
        } else if (function == 2) {
            scanf("%d %d %d %d", &start_row, &start_col, 
            &length, &direction);
            
            draw_sqare (canvas, start_row, start_col, 
            length, direction, color);   
        
        } else if (function == 3) {
            color = color_shade (color);    
        
        } else if (function == 4) {
            copy_paste (canvas);
        
        } else if (function == 0) {
            draw_Ellipse (canvas, color);
        
        }
    }
    
    displayCanvas(canvas);
    
    return 0;
}

//the fuction of drawing the ellipse.
void draw_Ellipse (int array[N_ROWS][N_COLS], int color) {
    int focus_1_row, focus_1_col, focus_2_row, focus_2_col, fill;
    double length;
    //input the information.
    scanf("%d %d %d %d %lf %d", &focus_1_row, 
    &focus_1_col, &focus_2_row, &focus_2_col, &length, &fill); 
    
    int temp_row, temp_col;
    
    
    //define N_ROWS 20
    //define N_COLS 36
    //test for the example.
    temp_row = 0;
    while (temp_row < 20) {
        temp_col = 0;
        while (temp_col < 36) {
            //calculate for the sum of distance.
            double total_distance = distance(temp_row, temp_col, focus_1_row, focus_1_col)
            + distance(temp_row, temp_col, focus_2_row, focus_2_col);
            //the full fill version.
            if (total_distance <= (2 * length) && fill > 0) {
                array [temp_row][temp_col] = color;
            } else if (total_distance == (2 * length) && fill <= 0) {
                array [temp_row][temp_col] = color;
            }
            temp_col++;
        }
        temp_row ++;
    }   
}

//the function used for copy and paste.
void copy_paste (int array[N_ROWS][N_COLS]) {
    
    int start_row, start_col, length, direction, target_row, target_col;
    scanf("%d %d %d %d %d %d", &start_row, &start_col, &length, 
    &direction, &target_row, &target_col);
  
    int angle = direction % 360;
    
    if (point_distance(target_row, target_col, length, direction) == 1 
    && point_distance(start_row, start_col, length, direction) == 1
    ) {
       
        int row_temp,col_temp;
        int temp1 = start_col, temp2 = target_col;
        row_temp = 0;
       
        while (row_temp < length) {
            col_temp = 0;
            start_col = temp1;
            target_col = temp2;
            while (col_temp < length) { 
            
                array[target_row][target_col] = array[start_row][start_col];
                
               
                if (angle == 45 || angle == 135) {
                    start_col ++;
                    target_col ++;
                } else {
                    start_col--;
                    target_col--;
                }
                
                col_temp++;
            }
        if (angle == 45 || angle == 315) {
            start_row--;
            target_row--;
        } else {
            start_row ++;
            target_row ++;
        
        }
        row_temp++;
        } 
    
    }
}

//the function used for changing color.
int color_shade (int a) {
    int temp;
    scanf("%d", &temp);
    if (0 <= (temp + a) && (temp + a) <= 4) {
        a = temp + a;
    }
    return (a);
}

//the function used for drawing the square.   
void draw_sqare (int array[N_ROWS][N_COLS], int start_row, int start_col, int length, int direction, int color) {
    int new_angle = direction % 360;
    if (point_distance( start_row, start_col, length, direction) == 1) {
        if (new_angle == 0 || new_angle == 90 
            || new_angle == 180 || new_angle == 270) {
            draw_line (array, start_row, start_col, length, direction,color);         
        } else {
            int temp = length;
            
            while (temp > 0 && length >0) {
                if (new_angle == 45) {
                    draw_line(array, start_row, start_col, length, 90, color);
                    start_row--;
                } else if (new_angle == 135) {
                    draw_line(array, start_row, start_col, length, 90, color);
                    start_row++;
                
                } else if (new_angle == 225) {
                    draw_line(array, start_row, start_col, length, 270, color);
                    start_row++;
                } else if (new_angle == 315) {
                    draw_line(array, start_row, start_col, length, 270, color);
                    start_row--;
                }
                temp--;
            }
            
        }
    }    
}

//the function used for drawing the line.
void draw_line (int array[N_ROWS][N_COLS],int start_row, int start_col, int length, int direction, int color) {
    if (length < 0) {
            length = -length;
            direction = direction + 180;
        }
    
    if (length > 0 && point_distance(start_row, start_col, length, direction) == 1) {
        int temp = length - 1;
        int new_angle = direction % 360;
        
        array [start_row][start_col] = color;
        while (temp > 0 && start_col >= 0 && start_row >= 0) {
                
            if (new_angle == 0) {
                start_row -- ; 
            } else if (new_angle == 90) {
                start_col ++;
            } else if (new_angle == 180) {
                start_row ++; 
            } else if (new_angle == 270) {
                start_col --;
            } else if (new_angle == 45) {
                start_row -- ;
                start_col ++; 
            } else if (new_angle == 135) {
                start_col ++;
                start_row ++;
            } else if (new_angle == 225) {
                start_row ++; 
                start_col --;
            } else if (new_angle == 315) {
                start_col --;
                start_row --;
            } 
            array [start_row][start_col] = color;
            temp--;
        }
    }  
} 
        
// N_ROWS 20
// N_COLS 36
double point_distance( int row, int cols, int distance, int direction) {
    distance = distance - 1;
    int angle = direction % 360;
    int i=0;
    if (row >= 0 && row <20 && cols >= 0 && cols <36) {
        if (angle == 0 && (row-distance) >= 0) {
            i++;
        } else if (angle == 45 && (row - distance) >= 0 && (cols + distance) < 36) {
            i++;    
        } else if (angle == 90 && (cols + distance) < 36 ) {
            i++;
        } else if (angle == 135 && (row + distance) < 20 && (cols + distance) < 36) {
            i++;
        } else if (angle == 180 && (row + distance) < 20 ) {
            i++;
        } else if (angle == 225 && (row + distance) < 20 && (cols - distance) >= 0) {
            i++;
        } else if (angle == 270 &&  (cols - distance) >= 0) {
            i++;
        } else if (angle == 315 && (row - distance) >= 0 && (cols - distance) >= 0) { 
            i++;
        }
    }
    return (i);
}        
        //program for the square drawing.
       
               
   
        
        
      

        // TODO: Add your code here!

        // Hint: start by scanning in the command.
        //
        // If the command is the "Draw Line" command, scan in the rest of
        // the command (start row, start col, length, direction) and use
        // that information to draw a line on the canvas.
        //
        // Once your program can draw a line, add a loop to keep scanning
        // commands until you reach the end of input, and process each
        // command as you scan it.
   
 


// ADD CODE FOR YOUR FUNCTIONS HERE



// Displays the canvas, by printing the integer value stored in
// each element of the 2-dimensional canvas array.
//
// You should not need to change the displayCanvas function.
void displayCanvas(int canvas[N_ROWS][N_COLS]) {
    int row = 0;
    while (row < N_ROWS) {
        int col = 0;
        while (col < N_COLS) {
            printf("%d ", canvas[row][col]);
            col++;
        }
        row++;
        printf("\n");
    }
}


// Sets the entire canvas to be blank, by setting each element in the
// 2-dimensional canvas array to be WHITE (which is #defined at the top
// of the file).
//
// You should not need to change the clearCanvas function.
void clearCanvas(int canvas[N_ROWS][N_COLS]) {
    int row = 0;
    while (row < N_ROWS) {
        int col = 0;
        while (col < N_COLS) {
            canvas[row][col] = WHITE;
            col++;
        }
        row++;
    }
}

// Calculate the distance between two points (row1, col1) and (row2, col2).
// Note: you will only need this function for the Draw Ellipse command
// in Stages 3 and 4.
double distance(int row1, int col1, int row2, int col2) {
    int row_dist = row2 - row1;
    int col_dist = col2 - col1;
    return sqrt((row_dist * row_dist) + (col_dist * col_dist));
}
