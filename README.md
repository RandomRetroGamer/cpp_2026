# cpp_2026
class work of comp science 2 c++


> includes homework 1
> includes graphics, with basic rendering
> Includes homework 2 

#summery of homework 2 
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
