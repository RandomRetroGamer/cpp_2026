# cpp_2026
class work of comp science 2 c++


> includes homework 1 \
> includes graphics, with basic rendering \
> Includes homework 2 \ 

# build sh file for cpp

#!/bin/bash

SOURCE="main.cpp"
OUTPUT="main"

g++ -o $OUTPUT $SOURCE

if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    echo "    " 
    ./main  # Run the compiled program
else
    echo "Compilation failed."
fi




# summery of homework 2 


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

# summery of homework 3 

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
