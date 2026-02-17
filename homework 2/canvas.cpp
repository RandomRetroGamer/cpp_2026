//***********************************************************************
//
// Team #7 CSCI 2380 Spring 2026 Homework # 2
// Randy Coronado
// First and Last Name
//
//***********************************************************************


/*---------------------------------------------------------------------

this assignments shows the usage of class and making data from said 
private class to construct the " for-loops "

-- final solution

this canvas.cpp file includes important libaries such as iostream and 
canvas.h which is the given file for the assignemnt. 

iostream is a basic libary for us to access the terminal.

---------------------------------------------------------------------*/


#include "canvas.h"
#include <iostream>


/* ---------------------------------------------------------------------

constructors allocates a canvas of given width and height of 5
code note: C[colum] [row] structure is used

--------------------------------------------------------------------- */

Canvas::Canvas( int width ) {
    
    // calling width from private function in canvas.h //
    _width = width; 
    
    if ( _width <= 0 ) {
        
        C = nullptr;
        _width = 0;
        
        
    } else {
        
        // allocated arrays of pointers, one for each colum //
        C = new char*[_width];
        
        for ( int i = 0; i < _width; i++ ) {
            
            
            C[i] = new char[5];
            
            for ( int j = 0; j < 5; j++ ) {
                C[i][j] = ' ';
            }
        }
    }
}


/*---------------------------------------------------------------------

this function sets the set the width of the 2d array, width to 5 state
Also allocates memory it creates a 2d array of character on the heap
then clears teh canvas it resets the loop to fill every coordiante with
a space ' '

---------------------------------------------------------------------*/

Canvas::Canvas( char x ) {
    
    _width = 5;
    C = new char*[_width];
    
    for (int i = 0; i < _width; i++) {
        C[i] = new char[5];
        
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++){
            C[i][j] = ' ';
        }
    }
    
    if ( x == 'A' ) {
        
        // creates the top portion of the rows //
        C[1][0] = C[2][0] = C[3][0] = '#';
        // create middle bars with "#" at row 2 //
        for ( int i = 0; i < 5; i++ ) C[i][2] = '#';
        
        // creates the side bar row // 
        C[0][1] = C[4][1] = '#';
        C[0][3] = C[4][3] = '#';
        C[0][4] = C[4][4] = '#';
        
        
    } else if ( x == 'B' ) {
        
        // creates left vertical //
        for ( int j = 0; j < 5; j++) C[0][j] = '#';
        // creates top //
        C[1][0] = C[2][0] = C[3][0] = '#';
        // creates mid //
        C[1][2] = C[2][2] = C[3][2] = '#';
        // creates bottom //
        C[1][4] = C[2][4] = C[3][4] = '#';
        // creates right curves //
        C[4][1] = C[4][3] = '#';
        
    } else if ( x == 'C' ){
        
        // creates left vertical ( middle ) // 
        for (int j = 1; j < 4; j++) C[0][j] = '#';
        // creates top //
        for (int i = 1; i < 5; i++) C[i][0] = '#';
        // creates bottom // 
        for (int i = 1; i < 5; i++) C[i][4] = '#';
        
    } else if ( x == 'D' ){
        
        // creates left vertical //
        for (int j = 0; j < 5; j++) C[0][j] = '#';
        // creates top //
        for (int i = 1; i < 4; i++) C[i][0] = '#';
        // create bottom //
        for (int i = 1; i < 4; i++) C[i][4] = '#';
        // creates right vertical //
        for (int j = 1; j < 4; j++) C[4][j] = '#';
        
    }
}

/*---------------------------------------------------------------------

this simple function below gets the _width from canvas and returns the value

---------------------------------------------------------------------*/

int Canvas::width() {
    return _width;
}

/*---------------------------------------------------------------------

Return the canvas as a string and must be iterate by row then each column 

---------------------------------------------------------------------*/

string Canvas::to_string() {
    
    
    if (_width == 0 || C == nullptr) return "";

    string result = "";
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < _width; col++) {
            result += C[col][row];
        }
        result += '\n';
    }
    return result;
}
    
/*---------------------------------------------------------------------

this function search and replace function is utility for drawing Canvas
A small summary is that it scans every " pixel " which is the character
in the 2D array that we create and edits them to match what we are 
looking for. 

---------------------------------------------------------------------*/

void Canvas::replace(char old_char, char new_char) {
    
    
    if (C == nullptr) return;
    
    for (int i = 0; i < _width; i++) {
        for (int j = 0; j < 5; j++) {
            if (C[i][j] == old_char) {
                C[i][j] = new_char;
            }
        }
    }
}

/*---------------------------------------------------------------------

the last function is very important where it deletes the the allocation
it uses a loop to delete the allocated memory, this prevents memory leaks
or causing the program to crash

---------------------------------------------------------------------*/

Canvas::~Canvas() {
    
    
    if (C != nullptr) {
        for (int i = 0; i < _width; i++){
            delete[] C[i]; 
        }
        delete[] C; 
    }
}

/*---------------------------------------------------------------------

-- summary of the code


-- foundation of the code and how memory is allocated and deallocated

the code uses memoery manangement throughout the code, this creates an
dynamic memory allocation, meaning it request memory from the computer's
hardware or this case the memory given for us to use in " onlinegdb "

we do this by using the constructor to create and allocated an 2D array
of char based on the requested width

the destructor is the " cleanup crew " for the memory allocation, to prevent
memory overflow and preventing the program from crashing. The last function
" Canvas::~Canvas() " deletes every row and the main array from memory leaks

-- building canvas 

the code is simple, we created a hard coded varable of width that = to 5
this creates a blank canvas that can be filled with anything we want to 

we can fill these canvases with " a " ," b ", "c " or " d " and it
automtically creates a height of 5 to math the 5 width and fills in 
" # " to form the letter we want.

-- Utility function
Simple functions that we use throughout the code to help us and make things
simpler.

width()         - is a simple getter to tell use how wide the canvas is

to_string()     - converts the 2D array into a single long string with newlines
(\n) and this alows us cout the entire drawing to the  terminal at once

replace         - scans the entire grid to replace every instantce with 
a disear character with another ( changes # with @ or vis versa )

-- i think i might have wrote too much notes 

---------------------------------------------------------------------*/



