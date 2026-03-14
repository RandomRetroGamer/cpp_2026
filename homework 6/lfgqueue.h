#ifndef LFGQUEUE_H
#define LFGQUEUE_H

#include "player.h"

class LFGQueue
{
	public:
		// Constructs a new empty queue with capacity for 100 players
		LFGQueue();

		// Returns the number of players in the queue.
		int size();

		// Adds a (pointer to a) player to the back of the queue.
		// If there is no room for the new player it doubles the
		// capacity of the queue before adding the player
		void push_player(Player* p);

		// Returns a pointer to the frontmost player 
		// with the specified role. If no such player 
		// exists, returns nullptr.
		Player* front_player(Player::Role r);

		// Removes the frontmost player with the
		// specified role. If no such player exists
		// does nothing.
		void pop_player(Player::Role r);	

		// Returns whether the queue contains a complete group
		// (a Defender, a Hunter, and a Bard).
		//
		// This method sets the three elements of the array parameter
		// equal to the addresses of the frontmost:
		// 1. Defender (index 0)
		// 2. Hunter (index 1)
		// 3. Bard (index 2)
		// If the group is complete (there are no null pointers in the array),
		// it returns true. Otherwise, it returns false.
		bool front_group(Player** group);

		// Removes the frontmost Defender, Hunter, 
		// and Bard from the queue. If some role
		// has no player with that role, then
		// no players are removed.
		void pop_group();

	private:
		Player** players;		// Pointer to the queue (dynamic array)
		int count;				// Total quantity of players in the queue
		int capacity;			// Current capacity of the queue

// IMPORTANT: the queue MUST be implemented assuming BACK is at index 0
};

#endif

