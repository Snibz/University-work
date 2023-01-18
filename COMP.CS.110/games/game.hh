#ifndef GAME_HH
#define GAME_HH

#include "player.hh"
#include <iostream>
#include <map>

class Game
{
public:
    Game();

    // constructor
    // A game object has a name and a map of Playername - Score pairs.
    Game(std::string name, std::map<std::string, unsigned int> scorelist);



    // Here comes functions, not yet determined.
    void edit_scorelist(std::string playername, unsigned int score);

    // Return name of game
    std::string get_name();

    // Test to see if datastructure works, prints names of players playing game
    std::map<std::string, unsigned int> get_scorelist();

    // Convets scorelist into a vector for ordering
    std::vector<std::pair<std::string, unsigned int> > convert_to_ordered();

    void delete_player(std::string playername);

    std::string name_;
    std::map<std::string, unsigned int> scorelist_;

private:

    static bool sortbyvalue(const std::pair<std::string, unsigned int> &x,
                     const std::pair<std::string, unsigned int> &y);




};

#endif // GAME_HH
