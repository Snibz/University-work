#include "player.hh"
#include <algorithm>

Player::Player(std::string name, std::vector<std::string> played_games):
    name_(name), played_games_(played_games) {

}

// A function to add a game into an existing player objects played_games vector
void Player::add_game(std::string gamename) {
    // We only add the game into the vector if it's not there already.
    // No need for duplicates, and this way this function may always be called as is.
    std::vector<std::string>::iterator veciter;
    veciter = find(played_games_.begin(), played_games_.end(), gamename);

    if ( veciter == played_games_.end() ) {
        // The gamename not in the vector. We add it there.
        played_games_.push_back(gamename);
    }
}

std::string Player::get_name() {
    // Returns name of player
    return name_;
}

void Player::print_played_games() {
    // This prints the games in the player's vector in ASCII-order
    std::sort(played_games_.begin(), played_games_.end());

    for ( auto& game : played_games_ ) {
        std::cout << game << std::endl;
    }
}
