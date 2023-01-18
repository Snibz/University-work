#ifndef PLAYER_HH
#define PLAYER_HH

#include <iostream>
#include <vector>

class Player
{
public:
    Player();

    // constructor
    // Player object contains it's name, and a vector where we'll add names of games the player plays.
    Player(std::string name, std::vector<std::string> played_games);



    // Adds game to the player's played_games
    void add_game(std::string gamename);

    // Return name of player
    std::string get_name();

    //for testing, for now
    void print_played_games();

private:

    std::string name_;
    std::vector<std::string> played_games_;

};

#endif // PLAYER_HH
