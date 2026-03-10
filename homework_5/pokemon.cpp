//***********************************************************************
// Team # CSCI 2380 Spring 2026 Homework # 5
// Randy Coronado
// 
//
//***********************************************************************

#include "pokemon.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

/*----------------------------------------------------------------------

Code note*

>pokedex.h > being used by > pokedex.cpp
>pokemon.h > being used by > pokemon.cpp

----------------------------------------------------------------------*/

/*----------------------------------------------------------------------

string type_to_string(Pokemon::Type t) code note* :

the function takes a pokemon's type and returns its name as text,
this function is prepared store and saved as a one of 5 types,

example:

Pokemon::Flying -> "Flying"
Pokemon::Poison -> "Poison"

----------------------------------------------------------------------*/

string type_to_string(Pokemon::Type t) {
    switch (t) {
        case Pokemon::Normal:   return "Normal"; // (1) //
        case Pokemon::Fighting: return "Fighting"; // (2) //
        case Pokemon::Flying:   return "Flying"; // (3) //
        case Pokemon::Poison:   return "Poison"; // (4) //
        default:                return "Normal"; // (5) //
    }
}

/*----------------------------------------------------------------------

Pokemon::Type string_to_type(string s) code note*

this Constructor uses if statements that uses a function returns a Pokemon::Type

example:
Pokemon::Type t = string_to_type("Poison");
then the Constructor Pokemon::Posion

like many of this functions they work together to provide an output and 
a data minpulation to store in arrays,

example:
Pokemon::Flying   ↓
type_to_string()  ↓
string_to_type()  ↓

output : Pokemon::Flying



----------------------------------------------------------------------*/
Pokemon::Type string_to_type(string s) {
    if (s == "Fighting") return Pokemon::Fighting; // check code note* for more information //
    if (s == "Flying")   return Pokemon::Flying;
    if (s == "Poison")   return Pokemon::Poison;
    if (s == "Normal")   return Pokemon::Normal;

    return Pokemon::Normal;
}

/*----------------------------------------------------------------------

Pokemon::Pokemon(string name, int ndex, Type type1) code note* :

this constructor is a special function that runs when a new pokemon objedct
is created and initalizes it's data. 


_name (data_type) sets the pokemon's name
for example :
    name = "monkey"

then:
    _name = "monkey"
    
the _ndex (data_type) stores the pokemon's pokedex number,
for example :
    ndex = 56 
    
then :
    _ndex = 56
    
types[0] sets up and assigns types,
for example :
    type1 = Fighting

then :
    types[0] = Fighting
    
finally last (data_type) type_count
for example :
    type_count = 1
    
    this means that the pokemon is a single-type
    
output : "Pokemon p("monkey", 56, Pokemon::Fighting);"

----------------------------------------------------------------------*/

Pokemon::Pokemon(string name, int ndex, Type type1) {
    _name      = name;
    _ndex      = ndex;
    types[0]   = type1;
    type_count = 1;
}

/*----------------------------------------------------------------------

Pokemon::Pokemon(string name, int ndex, Type type1, Type type2) code note*

the Constructor create a pokemon's with two types,
some pokemon in general have dual types,

super_monkey -> fire/flying

the Constructor header takes four inputs with, name ndex, type1 and type2

output : Pokemon p("super_monkey", Pokemon:fire, Pokemon::flying)
and the object will contain

_name = "super_monkey"
_ndex = 41
types[0] = fire
types{1] = flying
type_count = 2

----------------------------------------------------------------------*/
Pokemon::Pokemon(string name, int ndex, Type type1, Type type2) {
    _name      = name;
    _ndex      = ndex;
    types[0]   = type1;
    types[1]   = type2;
    type_count = 2;
}

/*----------------------------------------------------------------------

Pokemon::Pokemon(string summary) code note*

the Constructor takes one string that contains all hte pokemon's information,
it converts a string so it can read it piece by piece with " stringstream ss(summary) "

before code  :
    "ultra_monkey, #1, Posion, Normal "
    
after this code it becomes :

ultra_monkey
#1,
Flying,
Normal

it stores it to pieces using " string token ",
then reads teh pokemon's name

then after all this it removes leading space (if it has space left over)

reads the Ndex number using "getline(ss, token, ',')" then so the pokemon's 
example is #1, " int pos = token.find('#'); "

#1 > position 0

_ndex = stoi(token.substr(pos) + 1));

after all this code the output is :
    "ultra_moneky, #1, Flying, Normal"

----------------------------------------------------------------------*/
Pokemon::Pokemon(string summary) {
    stringstream ss(summary);
    string token;

    // Name //
    getline(ss, token, ',');
    _name = token;

    // Remove leading space if present //
    if (_name[0] == ' ')
        _name = _name.substr(1);

    // Ndex //
    getline(ss, token, ',');
    int pos = token.find('#');
    _ndex = stoi(token.substr(pos + 1));

    // Type 1 //
    getline(ss, token, ',');
    if (token[0] == ' ')
        token = token.substr(1);

    types[0] = string_to_type(token);
    type_count = 1;

    // Type 2 (optional) //
    if (getline(ss, token, ',')) {
        if (token.size() > 1) {
            if (token[0] == ' ')
                token = token.substr(1);

            types[1] = string_to_type(token);
            type_count = 2;
        }
    }
}

/*----------------------------------------------------------------------

Varaibles && Pokemon::Type Pokemon::type2() code note* :

Varaibles* :
_name = "super_monkey"

thisstring the name is stored in _name, 
and calling p.name()

it returns "super_monkey"
a simple way to returns the pokedex 

Pokemon::Type Pokemon::type2()* :
returns the second type of the pokemon only when it exist

----------------------------------------------------------------------*/
string Pokemon::name()         { return _name; }
int    Pokemon::Ndex()         { return _ndex; }
Pokemon::Type Pokemon::type1() { return types[0]; }
bool   Pokemon::is_multitype() { return type_count == 2; }

Pokemon::Type Pokemon::type2() {
    // Only meaningful when is_multitype() is true //
    return types[1];
}

/*----------------------------------------------------------------------

string Pokemon::summary() code note* :

this gathers from a pokemon's name, Ndex number, and types(s) returns 
a summart string that describes a pokemon. 

importantly we have some functions that belong to the complete the code,

string Pokemon::summary() :
    the function returns a string 
    it doesn't take any parameters,
    
the string prints with the pokedex number with formatting tools,
setw(3) -> ensures hte number has 3 digits, 
setfill('0') -> fills empty spaces with 0,

type_to_string() -> converts the type enum into text

finally it returns an complete string, "return.oss.str()"

example output : " super_monkey, #1, Flying, normal"

----------------------------------------------------------------------*/

string Pokemon::summary() {
    ostringstream oss;

    oss << _name << ", ";
    oss << "#" << setw(3) << setfill('0') << _ndex << ", ";
    oss << type_to_string(types[0]) << ",";

    if (type_count == 2) {
        oss << " " << type_to_string(types[1]) << ",";
    }

    return oss.str();
}

/*----------------------------------------------------------------------

float Pokemon::damage_multiplier(Type attack_type) code note* :

this simple function returns a float (decimal number) it takes a attack_type,
attack_type -> the type of the attacking move



----------------------------------------------------------------------*/
float Pokemon::damage_multiplier(Type attack_type) {
    // Placeholder — full type chart not required by these tests //
    return 1.0f;
}

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
