// Assignment 1 19T3 COMP1511: CS Paint
// paint.c
//
// This program was written by Xingyu Tan (z5237560)
// on 15/10/2019


#include <stdio.h>

#include <math.h>

// The dimensions of the canvas (20 rows x 36 columns).
#define N_ROWS 20
#define N_COLS 36

// Shades (assuming your terminal has a black background).
#define BLACK 0
#define WHITE 4
#define DrawLine 1
#define DrawSquare 2
#define ColorModify 3
#define CopyAndPaste 4
#define DrawEllipse 0





// Display the canvas.
void displayCanvas(int canvas[N_ROWS][N_COLS]);

// Clear the canvas by setting every pixel to be white.
void clearCanvas(int canvas[N_ROWS][N_COLS]);

// Calculate the distance between two points.
double distance(int row1, int col1, int row2, int col2);

//Determine if the image is one the canvas.
double if_image_on_canvas( int row, int cols, int distance, int direction);

//Draw the line on the canvas.
void draw_line (int array[N_ROWS][N_COLS], int start_row, 
int start_col, int length, int direction, int color);

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
    while (scanf("%d", &function) != EOF) {
        int start_row, start_col, length, direction;
        
        
        //Determine which fuction should be used.       
        if (function == DrawLine) {
            scanf("%d %d %d %d", &start_row, &start_col, 
            &length, &direction);
            
            draw_line (canvas, start_row, start_col, 
            length, direction, color);
        
        } else if (function == DrawSquare) {
            scanf("%d %d %d %d", &start_row, &start_col, 
            &length, &direction);
            
            draw_sqare (canvas, start_row, start_col, 
            length, direction, color);   
        
        } else if (function == ColorModify) {
            color = color_shade (color);    
        
        } else if (function == CopyAndPaste) {
            copy_paste (canvas);
        
        } else if (function == DrawEllipse) {
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
    
    temp_row = 0;
    while (temp_row < 20) {
        temp_col = 0;
        while (temp_col < 36) {
            
            //calculate for the sum of distance.
            double total_distance = distance(temp_row, temp_col, 
            focus_1_row, focus_1_col)
            + distance(temp_row, temp_col, 
            focus_2_row, focus_2_col);
            
            if (total_distance <= (2 * length)) {           
                //if the fill command is 0;
                //when fill == 0, drawing Hollow Ellipse.
                if (fill == 0) {
                    //considering points arround the central one 
                    //are not in the ellipse.
                    
                    //if the sum between the two focus and a point 
                    //is larger than lenth,
                    //the point is outside the ellipse.
                  
                    if ((distance(temp_row + 1, temp_col, 
                    focus_1_row, focus_1_col) 
                    + distance(temp_row + 1, temp_col, 
                    focus_2_row, focus_2_col)) > (2 * length)
                        
                    || (distance(temp_row - 1, temp_col, 
                    focus_1_row, focus_1_col)
                    + distance(temp_row - 1, temp_col, 
                    focus_2_row, focus_2_col)) > (2 * length)
                       
                    || (distance(temp_row, temp_col + 1, 
                    focus_1_row, focus_1_col)
                    + distance(temp_row, temp_col + 1, 
                    focus_2_row, focus_2_col)) > (2 * length) 
                       
                    || (distance(temp_row, temp_col - 1, 
                    focus_1_row, focus_1_col)
                    + distance(temp_row, temp_col - 1, 
                    focus_2_row, focus_2_col)) > (2 * length)) {
                       
                        array [temp_row][temp_col] = color;
                    } 
                
                } else {
                    //if the fill command is not zero;
                    array [temp_row][temp_col] = color;
                }
            } 
            temp_col++;
        }
        temp_row ++;
    }     
     
}

//the function used for copy and paste.
void copy_paste (int array[N_ROWS][N_COLS]) {
    
    //int the variable and scanf.
    int start_row, start_col, length; 
    int direction, target_row, target_col;
    
    scanf("%d %d %d %d %d %d", &start_row, &start_col, 
    &length, &direction, &target_row, &target_col);
  
    int angle = direction % 360;
    
    if (if_image_on_canvas(target_row, 
    target_col, length, direction) == 1 
    && if_image_on_canvas(start_row, 
    start_col, length, direction) == 1) {
       
        int row_temp, col_temp;
        //creat a new array to replace the old copied one 
        //to deal with overlap situation.
        int newArray [N_ROWS][N_COLS];
        row_temp = 0;
        while (row_temp < N_ROWS) {
            col_temp = 0;
            while (col_temp < N_COLS) {
                
                newArray[row_temp][col_temp] 
                = array[row_temp][col_temp];
                
                col_temp ++;
            }
            row_temp ++;
        }
        
        //new variable used for 
        //copy the col value of start and target.
        int origin_start_col = start_col; 
        int origin_target_col = target_col;
        row_temp = 0;
        
        while (row_temp < length) {
            col_temp = 0;
            start_col = origin_start_col;
            target_col = origin_target_col;
            while (col_temp < length) { 
                //copy the value
                array[target_row][target_col] 
                = newArray [start_row][start_col];
                
                //for the value change of col.               
                if (angle == 45 || angle == 135) {
                    start_col ++;
                    target_col ++;
                } else {
                    start_col--;
                    target_col--;
                }
                
                col_temp++;
            }
        
            //for the value change of row.    
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
    
    //Determine if it is invalid.
    if (0 <= (temp + a) && (temp + a) <= 4) {
        a = temp + a;
    }
    return (a);
}

//the function used for drawing the square.   
void draw_sqare (int array[N_ROWS][N_COLS], int start_row, 
int start_col, int length, int direction, int color) {
    
    int new_angle = direction % 360;
    
    //if the direction of command is rightangle, 
    //turn it into the line drawing.
    if (if_image_on_canvas(start_row, 
    start_col, length, direction) == 1) {
        
        if (new_angle == 0 || new_angle == 90 
            || new_angle == 180 || new_angle == 270) {
            
            draw_line (array, start_row, start_col, 
            length, direction, color);         
        
        } else {
            
            //if the direction if correct.
            int temp = length;
            while (temp > 0 && length > 0) {
                
                //drawing square by drawing three parallel same line 
                //in different direction.
                if (new_angle == 45) {
                    draw_line(array, start_row, 
                    start_col, length, 90, color);
                    
                    start_row--;
                } else if (new_angle == 135) {
                    draw_line(array, start_row, 
                    start_col, length, 90, color);
                    
                    start_row++;
                } else if (new_angle == 225) {
                    draw_line(array, start_row, 
                    start_col, length, 270, color);
                    
                    start_row++;
                } else if (new_angle == 315) {
                    draw_line(array, start_row, 
                    start_col, length, 270, color);
                    
                    start_row--;
                }
                temp--;
            }
            
        }
    }    
}


//the function used of drawing the line.
void draw_line (int array[N_ROWS][N_COLS], int start_row, 
int start_col, int length, int direction, int color) {
    
    //change the direction if the length is negative.
    if (length < 0) {
        length = -length;
        direction = direction + 180;
    }
    //use the fuction(if_image_on_canvas) to make sure all the paint on paint.
    if (length > 0 && if_image_on_canvas(start_row, 
    start_col, length, direction) == 1) {
        
        int temp = length - 1;
        int new_angle = direction % 360;
        
        array [start_row][start_col] = color;
        while (temp > 0 && start_col >= 0 
        && start_row >= 0) {
            //draw the line for the different angle.    
            if (new_angle == 0) {
                start_row --; 
            } else if (new_angle == 90) {
                start_col ++;
            } else if (new_angle == 180) {
                start_row ++; 
            } else if (new_angle == 270) {
                start_col --;
            } else if (new_angle == 45) {
                start_row --;
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
            temp --;
        }
    }  
} 
        
//the fuction of determining if the image is on the paint. 
double if_image_on_canvas(int row, int cols, 
int distance, int direction) {
    
    distance = distance - 1;
    int angle = direction % 360;
    int temp_counter = 0;
    //testing if the point after the movement, 
    //its position is outside the canvas.
    //this command would be ignore.
    // N_ROWS 20
    // N_COLS 36
    
    if (row >= 0 && row < 20 && cols >= 0 && cols < 36) {
        if (angle == 0 && (row-distance) >= 0) {
            temp_counter ++;
        } else if (angle == 45 && (row - distance) >= 0 
        && (cols + distance) < 36) {
            temp_counter ++;    
        
        } else if (angle == 90 && (cols + distance) < 36 ) {
            temp_counter ++;
        
        } else if (angle == 135 && (row + distance) < 20 
        && (cols + distance) < 36) {
            temp_counter ++;
        
        } else if (angle == 180 && (row + distance) < 20 ) {
            temp_counter ++;
        
        } else if (angle == 225 && (row + distance) < 20 
        && (cols - distance) >= 0) {
            temp_counter ++;
        
        } else if (angle == 270 &&  (cols - distance) >= 0) {
            temp_counter ++;
        
        } else if (angle == 315 && (row - distance) >= 0 
        && (cols - distance) >= 0) { 
            
            temp_counter ++;
        }
    }
    //if all the point is one the canvas, it would return 1;
    return (temp_counter);
}        

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
