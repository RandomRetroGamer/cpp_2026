//***********************************************************************
// Team 7 CSCI 2380 Spring 2026 Homework # 6
// Randy Coronado
// First and Last Name
//
//***********************************************************************

#include "lfgqueue.h"

/*-----------------------------------------------------------------------

code note* : 

In this homework_6 folder we see that he have a lot more files that usual, 
but lucky for us we only have to create this file "Ifgqueue.cpp".

Ifgqueue.h >> (being used by) Ifgqueue.cpp

-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------

LFGQueue::LFGQueue() code note* :

this very first constructor is very simple sets limits which we see 
capacity max limit is 100.

we also see that the count is at 0 ready for us to start count,

we create a dynamic array that stores the pointer to "Player"

-----------------------------------------------------------------------*/

LFGQueue::LFGQueue(){
    capacity = 100; // sets limit //
    count = 0; // ready for counting //
    players = new Player*[capacity]; // a shinny new dynamic pointer //
}

/*-----------------------------------------------------------------------

int LFGQueue::size() code note* :

as we see this simple function returns a value of count, since this function
starts with "int" it returns a simple integer value. 

However how simple this function is it is also part of LFGQueue class 
that is delcared in the Ifgqueue header.

we are going to use this for finding out the size of the queue.

-----------------------------------------------------------------------*/

int LFGQueue::size(){
    return count; // returns a integer "count" //
}

/*-----------------------------------------------------------------------

void LFGQueue::push_player(Player* p) code note* :

we just created count with a limit of 100, and the first line of code 
we have in this function is a if statements.

condition(1) << (count == capacity)
where if condition capacity(100) limit reaches the count we can finally 
go to the code down behind.

now importantly we have a line of code that creates a new array of players
for pointers that is linked to "new__players"

>> Player** new_players = new Player*[capacity];

more importantly we have to copy the old_players to the new array


what happens visually :

old: players [0] [1] [2] [3]
              v   v   v   v
new: players [null] // then //
new: players [0] [1] [2] [3] 

finally the old_players deletes the pointers to free old memory doesn't 
want to leak.

>> players = new_players // now players use the queue uses the bigger array 


--- understanding indexs --- 
now more importantly we are finally talk about index's, this is the most 
code is moving the index values inside.

if we remmeber that line of code before >> players = new Player*[capacity];
the line below should show it. 

memory layout visual example:
index: 0    1   2   3   4   ...(and so on)
value: []  []  []   []  []  []  
pos:  back                  front 
       -   -    -   -   -    - 

when we "shift right" this memory layout is filled and moves where each 
name is in.

memory layout visual example:
before: 

index: 0    1   2   3   4
plyer: ?    a   b   c   d  


after: 0    1   2   3   4
index: a    b   c   d    <- moved the front to 0, and back to 3. 


-----------------------------------------------------------------------*/
void LFGQueue::push_player(Player* p){
    // resize if capacity full //
    
    if (count == capacity){ // read code note* for more information //
        capacity *= 2;
        Player** new_players = new Player*[capacity]; // creates a new capacity //

        for (int i = 0; i < count; i++)
            new_players[i] = players[i]; // transfers older players to new array //

        delete[] players; // deletes old player from memory //
        players = new_players; // now queue uses the bigger array //
    }

    // shift right //
    for (int i = count; i > 0; i--){ // explains more in code note* //
        players[i] = players[i-1]; 
    }

    // insert at back  //
    players[0] = p;

    count++;
}

/*-----------------------------------------------------------------------

Player* LFGQueue::front_player(Player::Role r) code note* :

the first thing we notice about this code is " Player* " which the 
function must return a pointer to player object
we have two options in this code what can be returned.

return : (address of a player) OR (nullptr)

the loop is the main meat of the bones in this function where it 
starts from the FRONT of the queue,

front = index count-1

it checks the player's role but before we can go through that we have to
see the conditions of the if statement.

if (players[i]->role() == r ) 

condition(1) >> players[i] // points to a player
condtion(2) >> player[i]->role() // get the role of the player at index " i "

then if the roles we are searching for matches the pointer returns 
to that player.

however if nothing was found we find that nullptr is returned.

-----------------------------------------------------------------------*/
Player* LFGQueue::front_player(Player::Role r){
    for (int i = count - 1; i >= 0; i--) // starting at the front of the queue //
    {
        if (players[i]->role() == r) // read code note* for more information //
            return players[i]; // returns player and role to pointer //
    }

    return nullptr; // if nothing is found nullptr is returned //
}

/*-----------------------------------------------------------------------

void LFGQueue::pop_player(Player::Role r) code note* :

this function is one of many that minipulates memory and array, however 
as we can see this "pops" the front of the queue.

the first thing it does by finding the role to "pop" so in this example 
we can say 

>> LFGQueue::pop_player(Player::Hunter); // where the function looks for 
hunter in the queue from the front, 

finds the first hunter, and removes it. 

further more it shift the remaining players fills the gap.

if the player role  is not found then nothing happens :O

-----------------------------------------------------------------------*/
void LFGQueue::pop_player(Player::Role r){
    
    for (int i = count - 1; i >= 0; i--){ // starts searching in the queue //
        
        if (players[i]->role() == r){ // checcks the role //
        // does the player at index i have the role r? //
            
            for (int j = i; j < count - 1; j++){ // another loop -.- //
            // once the player is found it moves every player after //
                players[j] = players[j+1];
            }
            

            count--; // reduce the size of the queue //
            
            return; // stops the function after finding the player is removed //
        }
    }
}

/*-----------------------------------------------------------------------

bool LFGQueue::front_group(Player** group) code note* :

the very first thing we see in this code we start with a "bool" meaning
this function is going only to return True or False.

the main purpose of this code to confirm of a complete group does OR 
does not exist!

true -> then (a complete group exists)
false -> then (a complete group does NOT exist)

in this context a complete group consist of > (1) defneder > (1) hunter > (1) Bard

this array of player pointers passed through the function with "Player** group"

-----------------------------------------------------------------------*/
bool LFGQueue::front_group(Player** group){
    group[0] = front_player(Player::Defender); // finds at least one defender //
    group[1] = front_player(Player::Hunter); // finds at least one hunter //
    group[2] = front_player(Player::Bard); // finds at least one bard //

    return (group[0] != nullptr && // And //
            group[1] != nullptr && // And //
            group[2] != nullptr); // only true if all three exist //
}

/*-----------------------------------------------------------------------

void LFGQueue::pop_group() code note* :

the first thing this does it creates a array to hold group that stores 3 player
pointers. 

then it checks if the  full group exists and furthur more calls a function
we created earlier "front_group(group)"

remember the function finds the frontmost defender >> hunter >> bard 

then returns of the full group does or Does Not! exist.
however "(!front_group(group)" is looking for the group Does not have a complete
group. 

if the group is not complete then it stops the function and removes nobody

if the function passes through the first if statement then we can 
move onto the next lines, where we call another function we made earlier.

"pop_player(Player::Hunter);" >> removes hte frontmost hunter 


-----------------------------------------------------------------------*/
void LFGQueue::pop_group(){
    Player* group[3]; // creates array of 3 //

    if (!front_group(group)){ // check if the complete group exist //
        return;
    }

    pop_player(Player::Defender); // removes defender //
    pop_player(Player::Hunter); // removes hunter //
    pop_player(Player::Bard); // removes bard //
}

/*-----------------------------------------------------------------------

full summary code note* :

this assignment was quite shorter than the last ones but who am i to 
complain about that. This logic however was the main meat just like 
all the other assignments but was do-able. anyways now lets get into 
the summary. 

if we remember this code has three Players that simulates a match,
(1) defender, (1) hunter, and (1) bard. 

the queue that manages follows the (first in, first out) behavior where 
the first person that joined, well first, is prioritized.

we store the players using a "queue" or in the code >> Player** players
that uses a dynamic array of player pointers (fancy)

we uses index to keep track of the front and back of the "queue" using 
more fancy code.

Back of the queue = index 0
front of the queue = index count - 1

example using my funny humor of names :

 back                                     front
  v                                         v
[pro-gamer] [ultra-noob] [league-sweat] [mega-rager]
    0             1             2            3 
    
--- imporant varaibles ---

Player** players; // dynamic array storing pointers to players

int count; // tracks how many players are currently in the queue

int capacity; // tracks maximum size of the array 


--- imporant functions and or constructors ---

LFGQueue::LFGQueue(); // creates an empty queue,
sets capacity to 100
sets player count to 0
allocates memory to player array 

int LFGQueue::size(); // returns number of players currently in the queue 

void LFGQueue::push_player(Player* p); // adds a new player to back of the queue,
if the array is full -> doubles capacity,
shift all players to the right,
insert new player at index 0,
increase count

if you want more information how this works i highly recommend you check out 
" void LFGQueue::push_player(Player* p) code note* "

Player* front_player(Player::Role r) // finds the frontmost player with a specific role,
start searching from front " (count -1 ) ",
moves towards the back,
return the first plater with role "r".
returns >> pointer ot player IF found OR nullptr if NOT found.

bool front_group(Player** group); // checks if the queue contains a complete group

void pop_group(); // removes one full group from the queue

basically this code maintains the FIFO queue order by using the dynamic arrays we created 
and automatically resize when the queue grows, this is all supported by 
adding players, finding players and removing players, finally forming players.

-----------------------------------------------------------------------*/



