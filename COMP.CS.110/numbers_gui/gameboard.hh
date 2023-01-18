#ifndef GAMEBOARD_HH
#define GAMEBOARD_HH

#include "numbertile.hh"
#include <vector>
#include <random>

/* COMP.CS.110
 * Projecti 'Peli nimeltä 2048'
 * Opiskelija: Eetu Luoma
 * Email: eetu.luoma@tuni.fi
 * Opiskelijanumero: K444309
 *
 * Vain muuttuja side_of_board lisätty, jotta laudan kokoa voidaan muuttaa.
 *
 */

// public variable side_of_board added

const int SIZE = 4;
const int PRINT_WIDTH = 5;
const int NEW_VALUE = 2;
const int DEFAULT_GOAL = 2048;

class GameBoard
{
public:
    // Constructor
    GameBoard();

    // Destructor
    ~GameBoard();

    // Initializes the gameboard with nullptrs.
    void init_empty();

    // Initializes the random number generator and fills the gameboard
    // with random numbers.
    void fill(int seed);

    // Resets the board without making new numbertiles.
    // Each tile first set to 0, then given rng-number
    void fill_existing();

    // Draws a new location (coordinates) from the random number generator and
    // puts the NEW_VALUE on that location, unless check_if_empty is true and
    // the gameboard is full.
    void new_value(bool check_if_empty = true);

    // Returns true, if all the tiles in the game board are occupied,
    // otherwise returns false.
    bool is_full() const;

    // Prints the game board.
    void print() const;

    // Moves the number tiles in the gameboard, if possible (by calling
    // move method for each number tile).
    // Finally, resets turn of all number tiles.
    bool move(Coords dir, long int goal);

    // Returns the element (number tile) in the given coordinates.
    NumberTile* get_item(Coords coords);

    // there needs to be an accessible variable for the size of the board,
    // so that the user can tweak the size of the board.
    int side_of_board_ = SIZE;

private:
    // Internal structure of the game board
    std::vector<std::vector<NumberTile*>> board_;


    // Random number generator and distribution,
    // they work better, if they are attributes of a class.
    std::default_random_engine randomEng_;
    std::uniform_int_distribution<int> distribution_;
};

#endif // GAMEBOARD_HH
