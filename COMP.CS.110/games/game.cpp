#include "game.hh"
#include <map>
#include <algorithm>

Game::Game(std::string name, std::map<std::string, unsigned int> scorelist):
    name_(name), scorelist_(scorelist) {

}

// A function to edit a player's score in scorelist.
// If player not in scorelist, the pair is added there.
// If the player is, their score is updated.
void Game::edit_scorelist(std::string playername, unsigned int score) {

    if ( scorelist_.find(playername) == scorelist_.end() ) {
        // Player not in the scorelist.
        // We add them and their score.
        scorelist_.insert( { playername, score } );
    } else {
        // Player is in the scorelist.
        // We want to assign the player a new score.
        scorelist_.at(playername) = score;
    }

}

void Game::delete_player(std::string playername) {
    // Player is deleted from the game's scorelist.
    scorelist_.erase(playername);
}

std::string Game::get_name() {
    // Return name contained in game object
    return name_;
}

std::map<std::string, unsigned int> Game::get_scorelist() {
    // Returns the list of scores that the game contains
    return scorelist_;
}

 bool Game::sortbyvalue(const std::pair<std::string, unsigned int>& x,
                       const std::pair<std::string, unsigned int>& y) {
    // This compares the second parts of two pairs, used for
    // ordering the scorelist.
    // Inspired by the internet.
    return (x.second < y.second);
}

std::vector<std::pair<std::string, unsigned int> > Game::convert_to_ordered() {
    // Returns a vector of pairs of scorelist.
    // This is done so we can order the map by value.

    //
    std::vector<std::pair<std::string, unsigned int> > pairvec;
    for (const auto& pair : scorelist_) {
        std::string pname = pair.first;

        pairvec.push_back(pair);

    }

    // This bit with the comparer is borrowed from the internet.

    std::sort(pairvec.begin(), pairvec.end(), sortbyvalue);


    return pairvec;

}
