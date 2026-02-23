//***********************************************************************
// Team # CSCI 2380 Spring 2026 Homework # 3
// Randy Coronado
// Jason Garcia
//
//***********************************************************************

/*-----------------------------------------------------------------------

This program completes assignment 3. important notes that it uses
C[col(which is the colum as the x)] & [row (which is the colum as the y)]

In other words this assignment is heavly based on homework two and builds
on more information 

-----------------------------------------------------------------------*/

#include <iostream>
#include "canvas.h"

using namespace std;

/*-----------------------------------------------------------------------

function that creates and initalizes blank canvas of a certain width
which the width we want is 5

-----------------------------------------------------------------------*/

void init_blank_width(char**& C, int width) {

	if (width <= 0) {

		C = nullptr; // returns C char value with NULL = NO VALUE //

		return; // returns values in this if statement //
	}
	C = new char*[width]; // creates a new value that holds the pointer value //

	for (int i = 0; i < width; ++i) {
		C[i] = new char[5];

		for (int j = 0; j < 5; ++j) {
			C[i][j] = ' ';

		}
	}

}

/*-----------------------------------------------------------------------

this constructor is an empty canvas of a specified with a width ready 
to draw onto and add letters into, then can modify later.

-----------------------------------------------------------------------*/

Canvas::Canvas(int width) {

	_width = width; // whatever number gets passed through becomes the width //
	init_blank_width(C, _width); // uses the constructor from earlier to allocated memory //

}

/*-----------------------------------------------------------------------

this constructor draws a character "A" through "D" using the # as the pixel
it sets the canvas width = 5, and initializes a blank canvas with 5 * 5 
2D array C filled with blank spaces

Depending on whether x is "A" through "D" it loads a already defined 5 * 5 
pattern.

Finally it stores a interal 2D array

-----------------------------------------------------------------------*/

Canvas::Canvas(char x) {
	_width = 5; // defines a width of 5 //

	init_blank_width(C, _width); // actually creates the init_blank width of 5 * 5 //
	
	/*the lines below actually determine what letters with the already determined
	5 * 5 pattern */
	
	if (x == 'A') { 
        string pattern[5] = {" ### ", "#   #", "#####", "#   #", "#   #"};
        for (int row = 0; row < 5; ++row)
            for (int col = 0; col < 5; ++col)
                C[col][row] = pattern[row][col];
                
    } else if (x == 'B') {
        string pattern[5] = {"#### ", "#   #", "#### ", "#   #", "#### "};
        for (int row = 0; row < 5; ++row)
            for (int col = 0; col < 5; ++col)
                C[col][row] = pattern[row][col];
                
    } else if (x == 'C') {
        string pattern[5] = {" ####", "#    ", "#    ", "#    ", " ####"};
        for (int row = 0; row < 5; ++row)
            for (int col = 0; col < 5; ++col)
                C[col][row] = pattern[row][col];
    } else if (x == 'D') {
        string pattern[5] = {"#### ", "#   #", "#   #", "#   #", "#### "};
        for (int row = 0; row < 5; ++row)
            for (int col = 0; col < 5; ++col)
                C[col][row] = pattern[row][col];
    }
}

/*-----------------------------------------------------------------------

This constructor starts empty and adds the letter one by one, 
and if needed expanded the canvas as needed. 

C = nullptr really means in the memory, 
adds() reallocated your 2D array

-----------------------------------------------------------------------*/

Canvas::Canvas(string s) {

	_width = 0; // the canvas doesn't start with an width //
	C = nullptr; // The c array pointer is empty ( doesn't have an value to point to yet) //

	if (s.length() == 0) return;

	for ( int i = 0; i < s.length(); ++i ) { // loops through each character in the string //
		add(s[i]);
	}

}

/*-----------------------------------------------------------------------

This deletes the allocated memory that we have stored for the 2D array. 
uses a simple for loop to delete each 

-----------------------------------------------------------------------*/

Canvas::~Canvas() {
	for (int i = 0; i < _width; ++i) {
		delete[] C[i]; // deltes individual array stored inside of C //
	}
	delete[] C; // the final step to delete the pointer //
}

/*-----------------------------------------------------------------------

This simple function is a "getter" for anotehr function, the variable we 
see is a private function so now we can access the private varibale.

-----------------------------------------------------------------------*/

int Canvas::width() {

	return _width; // returns private varibale //

}

/*-----------------------------------------------------------------------

This function returns a formatted string repesentation of the 2D canvas
It turns all the 2D array the console can actually print.

-----------------------------------------------------------------------*/
string Canvas::to_string() {
	if (_width <= 0) return ""; /*
	if the canvas has no width, returns an empty string
	*/
	
	string res = ""; // holds til the final ouput //

	for(int row = 0; row < 5; ++row) { // loops through the rows //
		for(int col = 0; col < _width; ++col) {  // loops through the columns //
			res += C[col][row];  // grabs each character from 2D arrays and adds it to the string //
		} // also stores the characters in the (width) * 5 //
		res += "\n"; // adds a new empty newline to print below the newly creates character //
	}
	return res; // returns the res variable //
}

/*-----------------------------------------------------------------------

this function finds the "old_char" and returns a "new_char" using looks
to replace the " # " or a blank depending on the character. 

-----------------------------------------------------------------------*/

void Canvas::replace(char old_char, char new_char){
    for (int i = 0; i < _width; ++i){ // loops through the columns stored in the canvas //
        for (int j = 0; j < 5; ++j){
            if (C[i][j] == old_char) C[i][j] = new_char; /* loads new_char and old_char
            and checks if the line overwrites 
            */
        }
    }
}


/*-----------------------------------------------------------------------

this function adds a new letter 5 * 5 to the right side of the current canvas,
with its width expanding dynamically

For example if the canvas contains "A" the canvas would return to a width 
that fits the new width that can fit another letter like "B"

-----------------------------------------------------------------------*/

void Canvas::add(char x){
    int start_col = _width; // This is where the new letter starts //
    int new_width = (_width == 0) ? 5 : _width + 7; /* width becomes 5 just for
    this also adds 7 columns, 2 columns spacing, and 5 columns for the letter
    */
    
    char** new_C = new char*[new_width]; // creates a new array of column pointers //
    
    
    for (int i = 0; i < _width; ++i){ // this copies the pointers, and reuses old columns if needed //
        new_C[i] = C[i];
    }
    
    if (_width > 0) { // this adds spacing columns spaces if needed //
    /* the line below if something already exist it creates 2 blank columns
    fills them up with space and updates the start_col 
    */
        for (int i = _width; i < _width + 2; ++i) {
            new_C[i] = new char[5];
            
            for (int j = 0; j < 5; ++j) new_C[i][j] = ' ';
            
        } 
        
        start_col = _width + 2;
    }
    
    for(int i = start_col; i < new_width; ++i) { // allocates memory for 5 new columns //
    // each column has 5 rows and is filled with spaces initially //
        new_C[i] = new char[5];
        
        for (int j = 0; j < 5; ++j) new_C[i][j] = ' ';
        
    }
    
    Canvas temp(x); // calls the constructor from earlier //
    
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j) {
            new_C[start_col + i][j] = temp.C[i][j]; // calls letter into the 5 * 5 canvas //
        }
    }
    
    delete[] C; // deletes the old outer array //
    
    C = new_C;
    _width = new_width; // replaces pointer with the updated width //
}

/*-----------------------------------------------------------------------

summery of the code: 
an overall progrma creates a Canvas that dynamically creates and manages 
an 2D character-based drawing system using a char** array

the canvas stores the character in a "column-major" format using C[col][row]
each letter is drawn using a 5 * 5 grid of "#" and spaces.

the main functions of this program uses dymanic memory allocation, It uses 
new to allocated a 2D array, And also uses a destructor to free up all the 
uses memory that was stored, which was the letters. This also expands the canvas
that was dynamically created when a new letter are added.

This also uses multiple constructors that are variable, such assignment

Canvas(int width) > which creates a blank canvas of specified width
Canvas(char x) > creates a 5 * 5 canvas contain one letter " A " through " D " 
Canvas(string s) > builds a word by adding letters one at a time

The letter rendering " A " through " D " already are predefrined using 5 *5 ASC11 patterns
Then the characters are copied into the interal 2D array.

The dynamic expansion is done by using " add(char x) " function that creates a larger
canvas and preserves the existing letters. It adds shapcing and appends an new 5 * 5 letter
to the right of the canvas

width() > returns the current width
to_string() > converts the 2D canvas into a printable string
replace(old_char, new_char) > replaces characters across the entire conavas

finally with the last bit of the code it deletes the allocated memory that the program used
it is done by looping into each column and the outer pointer arrays and deletes them, this 
prevents any memory leaks.

-----------------------------------------------------------------------*/