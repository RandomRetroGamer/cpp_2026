//***********************************************************************
//
// Team 7 CSCI 2380 Spring 2026 Homework # 7
// Randy Coronado
// Jason Garcia
//
//***********************************************************************

#include "lfgqueue.h"

/*-----------------------------------------------------------------------

code note* : 

lfgqueue.cpp >> lfgqueue.h

As you see this assignment uses the last homework_6 but this time we are 
going to focus on roles that uses heads, tails, and count arrays

------------------------------------------------------------------------*/

/*------------------------------------------------------------------------

LFGQueue::LFGQueue() code note* :

the function "LFGQueue" is the default constructor for the LFGQueue class
it's purpose is to initialize a new instance of the class in an empty state.

more importantly this sets up all the elements with "nullptr", all the 
arrays we see here are important for the simulated game we are working on.

then it finally sets the count array to 0

------------------------------------------------------------------------*/

LFGQueue::LFGQueue() {
    for (int i = 0; i < 3; ++i) {
        heads[i] = nullptr; // sets to null //
        tails[i] = nullptr; // sets to null //
        counts[i] = 0; // sets to 0 //
    }
}

/*------------------------------------------------------------------------

int LFGQueue::size() code note* :

this functions calculates and returns the total number of players 
that is waiting in the match making system.

as we see this function mainly uses the count array where we depending on
the number inside the "[]" it repersents a type of class member

counts[0] >> defender queue
counts[1] >> hunter queue
counts[2] >> bard queue

after this we see each number of the queue then we add up the to return the
total size of the queue

pretty easy

------------------------------------------------------------------------*/

int LFGQueue::size(){
    return counts[0] /* defnder */ + counts[1] /* hunter */ + counts[2] /* bard */;
}

/*------------------------------------------------------------------------

void LFGQueue::push_player(Player* plyr) code note* :

this function adds a new player to the end of the list that is linked to 
the specific role. 

the first step it does it checks the provided player is "nullptr" to 
prevent any memory errors. 

the second step it converts its player role into an interger index "(r)" 
so it can access the correct node, head, tails, and counts arrays.

Finally we have the node creation where a new node is allocated on the heap 
then stores the player's address and settings its next pointer to nullptr. 

Queue placement is another big role of this, if the Queue is empty the new 
node becomes both the head and the tail. 

However if the current tail node's next pointer is updated to point to the
new node, then finally the tail pointer is moved to this new last node.

------------------------------------------------------------------------*/

void LFGQueue::push_player(Player* plyr){
    if (plyr == nullptr) return; // checks if plyr is null //
    
    int r = static_cast<int>(plyr->role()); // converts a value from role... //
    // ... enumeration type into a standard interger //
    
    Node* newNode = new Node();
    newNode->p = plyr;
    
    newNode->next = nullptr;
    
    if (heads[r] == nullptr) { // checks if head is null //
        
        heads[r] = newNode;
        tails[r] = newNode;
        // both heads and tails become one node //
        
    } else {
        
        tails[r]->next = newNode;
        tails[r] = newNode;
        
    }
    
    counts[r]++;
}

/*------------------------------------------------------------------------

Player* LFGQueue::front_player(Player::Role r) code note* :

This function lets us to "peek" at the person who has been waiting for the
longest to any role we desire without removing them from the queue.

this basically means they look at the "head" of the line for

>> defenders
>> hunters
>> bards

it takes the requested Role r and converts it into a valid array by using 
static_cast<int>

we have an conditonal statment where "heads pointer" is equal to nullptr,

finally if the queue isn't empty it access the Node at the head of that list
and returns the pointer to the Player or "p" stored inside.

------------------------------------------------------------------------*/


Player* LFGQueue::front_player(Player::Role r) {
    int roleIdx = static_cast<int>(r); // makes array valid for us to use /
    
    if (heads[roleIdx] == nullptr){ // checks if head is empty //
        return nullptr;
    }
    
    return heads[roleIdx]->p; // returns the pointer that is stored //
    
}

/*------------------------------------------------------------------------

void LFGQueue::pop_player(Player::Role r) code note* :

If we know anything about the meaning of pop, this means this function removes
from the front of a specific role's queue, since as we seen earlier this
follows "first in, first out" or (FIFO) for short. Understanding this logic 
we can assume the person who has been waiting the longest at the head is the 
one removed.

(1) The first thing we see it uses static_cast<int>(r) that converts the player's
role into an array index, (0, 1, or 2) that allows use to directly acess the
linked list. 

(2) then we do an empty check where "if heads [ roleIdx ] is nullptr ? ", the
queue for that role is already empty, so the functions exits early to avoid 
errors, 

(3) we create an temporary pointer " Node* temp " to hold the address of the 
current first node. This part is very needed because if we want to move the heads
pointer without saving the old address we will loose the step top delete the
pointer thus causing a memory leak. 

(4) basically moves the head pointer for the role to the person next in line👍👍👍 

(5) we have an conditonal statement where if the queue becomes empty even after 
the removal, then its sets the " tails [ roleIdx ] " to nullptr. This makes sense
where after this it doesn't access a tail that no longer exist.

 

------------------------------------------------------------------------*/

void LFGQueue::pop_player(Player::Role r) {
    int roleIdx = static_cast<int>(r); // check (1) for more information //
    if (heads[roleIdx] == nullptr) { // check (2) for more information //
        return; // exits the code without crashing it //
    }

    Node* temp = heads[roleIdx]; // check (3) for more infomration // 
    heads[roleIdx] = heads[roleIdx]->next; // have you checked note (4) ? //
    
    // If the queue is now empty, update the tail //
    if (heads[roleIdx] == nullptr) { // check (5) for more information //
        tails[roleIdx] = nullptr; // sets tail to nullptr //
    }

    delete temp; // deletes temp to free memory //
    
    counts[roleIdx]--; // it decrements the count for that role to keep //
    // the total queue size accurate //
}

/*------------------------------------------------------------------------

bool LFGQueue::front_group(Player** group) code note* :

this function checks the matchmaking system can form a complete group. of 
course we use 

>> defender >> counts[0]
>> hutner >> counts[1]
>> bard >> counts[2]

and returns an address if they are available. for this we use the if 
statement we see below check all the classes we have available.

after all the pointers are copied inot the array the function returns true.

------------------------------------------------------------------------*/

bool LFGQueue::front_group(Player** group){
    if (counts[0] == 0 || counts[1] == 0 || counts[2] == 0){ // checks class system //
        return false;
    }
    
    group[0] = heads[0]->p; // stores //
    group[1] = heads[1]->p; // stores //
    group[2] = heads[2]->p; // stores //
    
    return true;
}

/*------------------------------------------------------------------------

void LFGQueue::pop_group() code note* :

This function completes the matchmaking cycle by removing one player of 
each required role from the front of their class respectively queues. 

this starts the game for the most senior group in line, but we use another if 
statement where it ensures the players are only removed if there is atleast one
>> defender >> counts[0]
>> hunter >> counts[1] 
>> bard >> counts[2] 

when we deleting the memory we simply use the pop_player function three times
for each specific role.


------------------------------------------------------------------------*/

void LFGQueue::pop_group() {
    if (counts[0] > 0 && counts[1] > 0 && counts[2] > 0){ // check code note for more information //
        pop_player(Player::Defender); // pops defender //
        pop_player(Player::Hunter); // pops hunter //
        pop_player(Player::Bard); // pops bard //
    }
}




/*------------------------------------------------------------------------

summary of code note* :

This game matchmaking uses a "linked-list-based" matchmaking queues for 
a simulated online game. This is done by three main groups,

>> defender
>> hunter
>> bard

using three separate sub-queues to ensure that adding or removing players.

The player classes are simple data containers that stores a players name and
their role which is defined as enum where Defender = 0, Hunter = 1 and Bard = 2

The LFGQueue class is the manager that handles the logic, where it contains three 
interal linked that tracked by three array. 

>> heads[3]: points to the front of each role's queues
>> tails[3]: points to the end of each role queues (allowing for instant additions)
>> counts[3]: interger tracking how many players are in each specific role

more than importantly we have the functions we have to go through where it 
actually makes the meat of the code,

Functions:

>> push_player() >> creates a new node and addits back of the list according to that's 
player's role.

>> front_player() >> returns the player at the front of a specific role's queues
without removing them

>> pop_player() >> removes the first player in line for a specific role and deletes
their Node to free memory

>> front_group() >> checks if atleast one Defender, hunter, bard are present, if so 
it returns their addresses as a "complete group"

>> pop_group() >> removes the head of all three queues simulaneously one a full
party is formed.

>> size() >> returns the sum of all players across all three roles.

------------------------------------------------------------------------*/











