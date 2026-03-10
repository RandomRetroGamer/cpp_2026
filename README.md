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
# summery of homework 4


/*-----------------------------------------------------------------------

summery of the code:

this code demostrates the double-stack algoritm and is the standard way of 
looking throuhg the modern-web effectively, based on the URLs and actions 
we do it deterins of the URL is considered Past or Future.

throughout this code i haved used 
["https://youtube.com"], ["https://google.com"]
to shows how the data structure is managed and functions

push > (pushes) a string variable into either past or future stack. 

top > checks the top of the stack either from past or future, we see this by "past.top" & "future.top"

pop > destroys and cleans the stack's top, 

empty > we see this mainly in !<stack's name>.empty() to check if the stack is empty and determins
how the code will move on from here

size > checks the <stacks>.size(), it says in the name.

these stacks behave how minipulates we use the browers 

opening a page > pushes the URL to the top of the past stack
important code note : past stack's top layer is the current_page 

past stack :
(1) ["https://youtube.com"]

going to another new page > pushes the new URL into the past stack
past stack :
(1) ["https://google.com"] <-- becomes the new current page 
(2) ["https://youtube.com"] <-- gets pushed down to the layer

pressing back > pushes the top of the stack to the future stack 

future stack :
(1) ["https://google.com"] <-- the past's current page is now the top of the future stack 

past stack :
(1) ["https://youtube.com"] <-- this is now the current page since its ontop of the stack

pressing forward > returns the future page back into current page (which is the top of the past stack)

future stack :
(1) NULL <-- the last value stored in this stack is now in past's stack top layer

past stack :
(1) ["https://google.com"] <-- came from future stack and is now the current page
(2) ["https://youtube.com"] <-- pushed down because of the new value's location



-----------------------------------------------------------------------*/

#Homework 5

/*----------------------------------------------------------------------

summary of code note* :

the point of this file (pokemon.cpp) is to store and manage pokemon classes
such as :
    name,
    Pokedex number (Ndex)
    Type(s)
    summary description
    
the main things that these codes do creates pokemon's objects through constructors.

it create a single-type pokemon with " Pokemon(string namem, int ndex, Type type1)"
example:
    ultra_monkey
    #1
    Fighting
    
this cpp file also uses a two-type pokemon,
Pokemon(string name, int ndex, Type type1, Type type2) example :
    ultra_monkey
    #1
    Flying / normal

Pokemon(string summary) example :
    "ultra_monkey, #01, Flying, normal"
    
    this constructors name, Ndex number, type(s)

the other thing this code access pokemon information that several function allows 
other of hte porgram to get information about the pokemon.

name()      → returns the pokemon's name
Ndex()      → returns the pokedex number
type1()     → return the first type
type2()     → return the second type
is_multitype() → checks if the pokemon has two types 

convert the types between and enum 
the file also contains other helps functions

type_to_string()
string_to_type()

these functions convert enum → (to) string

example:
    Pokemon::Flying → "Flying"
    "Flying" → Pokemon::Flying
    
summary → creates a formatted string that describes the pokemon
example output "ultra_monkey, #1, flying, normal"

saving pokemon to files and displays them in the program

the damage_multiplier(Type attack_type) provides a placeholder for battle damage
calculations

want more information on pokedex.cpp? check the file!

----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------

pokedex.cpp code summary :

As you can see this assignment has 2 user made .cpp files, so this summary 
will be focused on the pokedex.cpp, if you want information on pokemon.cpp
file please check that file instead.

This code shows the control we have over and access from the "pokedex.txt",
we use an array that equals 1000.

the array stores either 2 types of values,
A[1] -> pokemon_example
A[2] -> nullptr

and the code response on the value that is stored. 

we use 6 main functions that control how the data is stored or minpulated

void Pokedex::add(Pokemon* p) (1) :
    This gets the Pokemon's Ndex number
    it uses as index in the array
    stores the Pokemon's pointer in the slot
    
    A[25] -> Pikachu
    ...
    A[56] -> monkey
    
Pokemon* Pokedex::lookup_by_Ndex(int ndex) (2) :
    checks if the index is valid
    returns the pokemon's stored in that index
    
    lookup_by_Ndex(56) -> returns monkey as the value
    if we remember the value A[56] from the pervious example 56 -> returns monkey
    
Pokemon* Pokedex::lookup_by_name(string name) (3) :
    loops through the entire array,
    compares each pokemon's name
    returns the matching pokemons
    
    lookup_by_name("monkey") -> the pointer is now monkey
    
void Pokedex::remove(Pokemon* p) (4) :
    finds the pokemon's Ndex number
    set that slot in the array in nullptr
    
    A[55] -> nullptr // removes the nullptr from the pokedex //

int Pokedex::size() (5) :
    loops through the entire array (again)
    counts how many slots are NOT nullptr
    
    size() -> 42 // example duh not real // 
    
void Pokedex::save(string filename) (6) :
    opens a file
    loops through all pokemon's stored
    writes each Pokemon's summary to the file
    
    "025, pikachu eletric"
    
-----------------------------------------------------------------------*/

