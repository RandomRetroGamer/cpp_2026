//***********************************************************************
// Team 7 CSCI 2380 Spring 2026 Homework # 5
// Randy Coronado
// First and Last Name
//
//***********************************************************************

#include "pokedex.h"
#include <fstream>
#include <string>
using namespace std;

/*-----------------------------------------------------------------------

Code note*

this assignment is a little different were us the classmate create's one
".cpp" file we are require to make two files. Both of the files use
either one of these files based on the names

>pokedex.h > being used by > pokedex.cpp
>pokemon.h > being used by > pokemon.cpp

-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------

Pokedex::Pokedex() code note*

This code class the constructor from the pokedex.h,  where it sets an
array that is filled with "nullptr"

A[0] = nullptr
A[1] = nullptr // and so on

-----------------------------------------------------------------------*/


Pokedex::Pokedex() {
	for (int i = 0; i < 1000; i++) {
		A[i] = nullptr; // fills all arrays with "nullptr" //
	}
}

/*-----------------------------------------------------------------------

Pokedex::Pokedex(string filename) code note*

once again this code class from the 'pokemon.h' constructor and creates
an "Pokedex" object by loading it from the "Pokedex.txt" file.

the array is loaded with nullptr as the value and the code is set to load
each value from the array.

-----------------------------------------------------------------------*/

Pokedex::Pokedex(string filename) {
	for (int i = 0; i < 1000; i++) {
		A[i] = nullptr;
	}

	ifstream file(filename); // actually opens file which is "pokedex.txt" //
	string line;


	while (getline(file, line)) { // while loop to loop through each line in the file //
		if (!line.empty()) {
			Pokemon* p = new Pokemon(line); // stores the pokemon in array //
			add(p);
		}
	}

	file.close(); // close the open file //
}

/*-----------------------------------------------------------------------

Pokedex::save(string filename) code note*

This function saves the entire Pokedex to a file and actually contains
if the pokemon's value exist

A[56] = pointer -> "example_pokemon"

so if the condition is true

if A[57] = nullptr

then the condition is false and nothing happens in the code

if the condition is true where the pointer has a value
(A[i] != (not) nullptr)
the code accesses the pointer and returns a string

"example_pokemon, #056, fighting"
this gets added into the file

-----------------------------------------------------------------------*/


void Pokedex::save(string filename) {
	ofstream file(filename); // opens the file "pokedex.txt" //

	for (int i = 0; i < 1000; i++) {
		if (A[i] != nullptr) { // is the array stored with "nullptr" ? //
			// if the array is filled with nullptr then this line below gets executed //
			file << A[i]->summary() << "\n"; // access a function from an pointer and returns string //
		} // gets stored into the file "pokedex.txt"
	}

	file.close(); // closes the file //
}

/*-----------------------------------------------------------------------

Pokedex::add(Pokemon* P) code note*

once again this function belongs to the pokedex.h class members,
it takse the pointer to a pokemon and doesn't return anything like a constructor

The main part of the code has three conditions

condition (1) >> idx >= 0
This means the Ndex must not be negative

condition (2) >> idx < 1000
since the array only has a value of 999 so anything >= 1000 would crash the program

condition (3) >> A[idx] == nullptr
this checks if the array slot is actually empty (means nothing is actually
stored there yet)

finally if the conditions are passed through the line stores the pokemon

before  :
  A[56] = nullptr

after if statements :
  A[56] -> example_pokemon

-----------------------------------------------------------------------*/
void Pokedex::add(Pokemon* p) {
	int idx = p->Ndex(); // gets pokemon's Ndex //

	if (idx >= 0 && idx < 1000 && A[idx] == nullptr) { // three condition, check code note* for more infomration //
		A[idx] = p;
	}
}

/*-----------------------------------------------------------------------

void Pokedex::remove(Pokemon* P) code note* :

this function removes and clears the slot in the array and makes sure that
the array condition is valid for this to go through.

the condition checks if the variable idx for the array A

condition (1) idx >= 0 // checks if the "idx" is not negative
condition (2) idx < 1000 // checks if the idx is less than the array size

we use the && "and" statement to unioize the conditions together

Finally if the conditions are vaild we have "A[idx] = nullptr" which clears
the array slot

Before :
    A[626] -> example_pokemon

After the condition logic is True :
    A[626] -> nullptr

How ever this doesn't delete the pokemon object and it still exist in
the memory, this on hte other end deletes the pointer to the objects

-----------------------------------------------------------------------*/
void Pokedex::remove(Pokemon* p) {
	int idx = p->Ndex();
	if (idx >= 0 && idx < 1000) { // read the code note for more information //
		A[idx] = nullptr; // fills value with "nullptr" //
	}
}

/*-----------------------------------------------------------------------

Pokemon* Pokedex::lookup_by_name(string name) code note*

This function searches through the "pokedex.txt" with a specific name
and returns the pointer if it actually exist

the conditions are also the main point of this code

condition (1) "A[i] != nullptr" // makes sure if the pokmeon exist in specific slot

condition (2) "A[i]->name() == name" // access the function through a pointer

finally we have the && statment that unionize the if statements together

for example how this code work we are gonna search is for "goober" in the Pokedex

A[0]
...
A[16] -> "nintendo's rat"   : doesn't match!
...
A[27] -> "common nintendo's rat"    : doesn't match!
A[28] -> "goober"   : matches!

finally if it finds hte pokemon it is searching thorugh then it returns a string
if it doesn't Then it returns a nullptr

-----------------------------------------------------------------------*/


Pokemon* Pokedex::lookup_by_name(string name) {
	for (int i = 0; i < 1000; i++) { // looks through the entire array //
		if (A[i] != nullptr && A[i]->name() == name) { // look at code note* for more information //
			return A[i]; // returns pokemon's pointer //
		}
	}
	return nullptr; // returns nullptr //
}

/*-----------------------------------------------------------------------

Pokemon* Pokedex::lookup_by_Ndex(int ndex) code note* :

like every past function we have been going through this finds something in
a statement, then returns it when we found something. -.-

the ndex takes an interger parameter and returns the pointer to the pokemon

when we call "Pokemon* p D1.lookup_by_Ndex(56) -> give me this pokemon with Ndex 56 "
finally we have the if condtional statements, again ._.

"if (ndex < 0 || ndex >= 1000) return nullptr "

condition (1) "ndex < 0" // checks if the array index is postive if not then its invalid

condition (2) "ndex >= 1000" // is it within 1000 ?

finally we have the OR statement that unionize statements

example we are looking for "nintedo_rat"

A[16]  → "cringelord" this one doesn't match !
A[56]  → "Mankey" : this one doesn't match !
A[88]  → "Grimer" : this one doesn't match !
A[641] → "nintendo_rat" : this one matches !

the function returns back with the pointer 641


-----------------------------------------------------------------------*/
Pokemon* Pokedex::lookup_by_Ndex(int ndex) {
	if (ndex < 0 || ndex >= 1000) return nullptr; // check the code note* for more infomration //
	return A[ndex];   // nullptr if empty //
}

/*-----------------------------------------------------------------------

int Pokedex::size() code note* :

the main way this code works it askes " how many pokemon's are in this pokedex "
and returns an answer,

it creates a "int count" to keep count on what is found, count = 0
loops through the entire array, 

if (A[i] != nullptr) performs this, :
A[0] -> nullptr         : (empty)
A[1] -> pokemon pointer : (a pokemon's pointer)
A[2] -> nullptr         : (empty)

basically (array does it have something?)
and it increased the count for each time it finds a pokemon in the array

-----------------------------------------------------------------------*/
int Pokedex::size() {
	int count = 0; // creates int count with 0, ready for counting //
	for (int i = 0; i < 1000; i++) { //checks the  entire array //
		if (A[i] != nullptr) count++; // check code note* for more information //
	}
	return count;
}

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


