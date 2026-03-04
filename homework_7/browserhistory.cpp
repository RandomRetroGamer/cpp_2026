//***********************************************************************
// Team 7 CSCI 2380 Spring 2026 Homework # 4
// Randy Coronado
//
//
//***********************************************************************

/*-----------------------------------------------------------------------

this program shows the usage of stacks by providing functions such as

past.top() || future.top 
past.push() || future.push
past.pop() || future.pop

in this program we the stack Past and Future, that we control using functions
to minpulate the data we have

-----------------------------------------------------------------------*/

#include "browserhistory.h"

/*-----------------------------------------------------------------------

This simple constructor takes a string from a user input or in the this case
the program fills the string.

ex: past ["https://google.com"] // is now stored ontop of the stack

-----------------------------------------------------------------------*/
BrowserHistory::BrowserHistory(string default_url) { // gets the constructor from BrowserHistory //
    // string default_url is ready to be pushed into the stack "past" //
    past.push(default_url); // whatever is now filed in default_url is now pushed into past storing data at the top //
}

/*-----------------------------------------------------------------------

The function belows returns the past stack with the top of the data member being 
shown 

for example:

past ["https://youtube.com"] // newly added <-- returns this
past ["https://google.com"]

-----------------------------------------------------------------------*/
string BrowserHistory::current_url() { // 
    return past.top(); // returns the the top constructor //
}

/*-----------------------------------------------------------------------

the new URL is placed on the top of the stack and loops through the stack and the 
new URL immediately becomes the "current" page you are viewing. 

for example
past ["https://youtube.com"] <-- becomes current_url string
past ["https://google.com"] 

this is in a while loop for several purposes but the main reason is to loop 
through the past stack and find the top of the stack

-----------------------------------------------------------------------*/
void BrowserHistory::go_to_url(string url) {
    past.push(url); // pushes url into past stack //
    // when visitin a new page the future stack gets reset //
    while (!future.empty()) {
        future.pop(); // clears stack //
    }
}

/*-----------------------------------------------------------------------

this function is the back action when your exploring a page
it checks if there is an actual page to go back to

then if we have an actual page to go back to it sets a string current that
is equal to past.top() 

finally it pushes current string to the future stack.

-----------------------------------------------------------------------*/
void BrowserHistory::back() {
    if (can_go_back()) { // checks if a page is there to actually go back to //
        string current = past.top(); // sets string current value to past of the top //
        past.pop(); // cleans up left over values which is the top of the stack //
        future.push(current); // pushes current string value which is the top of the stack to the future stack //
    }
}

/*-----------------------------------------------------------------------

this is where actually where the can_go_back function happens, this simple
logic checks the stack size is greater than 1, which if it is then a page = to
go back to actually exist

-----------------------------------------------------------------------*/

bool BrowserHistory::can_go_back() {
    return past.size() > 1; // checks stack size greater than 1, if so then a page does go back to //
}

/*-----------------------------------------------------------------------

this interger function solves a problem that we come across when trying to 
figure out current_page, the current page is always ontop of the past
stack however the page lower than that is actually the past page.

past ["https://youtube.com"] <-- current page
past ["https://google.com"] <-- the actual past page we can go back to

-----------------------------------------------------------------------*/

int BrowserHistory::past_url_count() {
    return past.size() - 1; // actual past page we go back to //
}

/*-----------------------------------------------------------------------

this function is just like the past() function, instead of a back-button
this checks if there is a page the future can actually go to. 

next_url sets a string value that is attached to the top of future's stack
then the stack is moved around based on the values being moved around and 
we can return to the future stack.

-----------------------------------------------------------------------*/
void BrowserHistory::forward() {
    if (can_go_forward()) { // gets function that chesk the can_go_forward // 
        string next_url = future.top(); // next_url is equal to the top of future stack //
        future.pop(); // cleans up future stack //
        past.push(next_url); // new_url string is now pushed into past stack //
    }
}

/*-----------------------------------------------------------------------

checks if the future stack is empty and returns based on returns if the stack 
is not empty.

-----------------------------------------------------------------------*/

bool BrowserHistory::can_go_forward() {
    return !future.empty(); // returns of the stack is empty or not, looking for NOT empty in this //
}

/*-----------------------------------------------------------------------

returns the fullsize of the future stack's size

-----------------------------------------------------------------------*/

int BrowserHistory::future_url_count() {
    return future.size();
}

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
