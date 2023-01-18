/*  COMP.CS.100 Project 2: GAME STATISTICS
 *
 * Student: Eetu Luoma
 * Student ID: K444309
 * Student email: eetu.luoma@tuni.fi
 *
 * About project:
 *  My first attempt at this project became a failure, so I started again from the beginning.
 *  There will be an explanation of functionality here once it is implemented.
 *
 *      Datastructure:
 *      Objects for all games and players are created.
 *      They are stored into maps, one for games and one for players.
 *      A game object contains it's name and a map of players and their scores.
 *      A player object contains it's name and a vector of games they play.
 *
 *      My apologies for this monstrosity. Just have to get it done at this point.
 *      There are plenty of comments in the code to explain how it functions.
 *
 *
 *
 *
 *
 *
 * ===============================
 * EXAMPLE SOLUTION
 * ===============================
 *
 *  Acts as a game statistics with n commands:
 * ALL_GAMES - Prints all known game names
 * GAME <game name> - Prints all players playing the given game
 * ALL_PLAYERS - Prints all known player names
 * PLAYER <player name> - Prints all games the given player plays
 * ADD_GAME <game name> - Adds a new game
 * ADD_PLAYER <game name> <player name> <score> - Adds a new player with the
 * given score for the given game, or updates the player's score if the player
 * already playes the game
 * REMOVE_PLAYER <player name> - Removes the player from all games
 *
 *  The data file's lines should be in format game_name;player_name;score
 * Otherwise the program execution terminates instantly (but still gracefully).
 *
 * */
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>

#include "game.hh"
#include "player.hh"

// const int NUMBER_TO_QUIT = 42;

unsigned int check_stoi(const std::string& string) {
    // This function checks if the string given is a proper number.
    // If it isn't, it returns 0.
    bool is_number = true;

    // Check each char in string to see if its a number
    for ( unsigned int i = 0; i < string.length(); ++i ) {
        if ( not isdigit(string.at(i)) ) {
            //string char at i is not an integer between 0 and 9
            is_number = false;
            break;
        }
    }
    if ( is_number == true ) {
        return stoi(string);
    } else {
        return 0;
    }

}

// Casual split func, if delim char is between "'s, ignores it.
std::vector<std::string> split( const std::string& str, char delim = ';' )
{
    std::vector<std::string> result = {""};
    bool inside_quatation = false;
    for ( auto current_char : str )
    {
        if ( current_char == '"' )
        {
            inside_quatation = not inside_quatation;
        }
        else if ( current_char == delim and not inside_quatation )
        {
            result.push_back("");
        }
        else
        {
            result.back().push_back(current_char);
        }
    }
    if ( result.back() == "" )
    {
        result.pop_back();
    }
    return result;
}

void manage_row_player_info(std::map<std::string, Player>& playerlist, std::string gamename,
                          std::string playername) {
    // Function creates player object if it doesn't already exist, if it does
    // the gamename will be added to the player objects playedgames-vector,
    // if it's not there already.
    //

    if ( playerlist.find(playername) == playerlist.end() ) {
        // Player called playername will be a new object.
        // A vector is created, which contains the identifiers of games the
        // player plays.
        std::vector<std::string> playedgames = {};
        playedgames.push_back(gamename);

        Player newplayer(playername, playedgames);
        playerlist.insert( { playername, newplayer } );
        // now the player object can be accessed by
        // playerlist.at(playername)

    } else {
        // Player object already exists.
        // If gamename not in  player object's vector of played games,
        // it is to be added there.
        playerlist.at(playername).add_game(gamename);
    }
    // player print test
    // playerlist.at(playername).print_played_games();

}

void manage_row_game_info(std::map<std::string, Game>& gamelist, std::string gamename,
                        std::string playername, unsigned int score) {
    // Creates a game object if one does not already exist.
    // This is only called when the file is being read,
    // since in the file each row must have a valid gamename and playername.

    if ( gamelist.find(gamename) == gamelist.end() ) {
        // Game called gamename will be a new object.
        // A map to store the game's players and their stores is created,
        // which will then be attached to the game object.
        std::map<std::string, unsigned int> scorelist;
        scorelist.insert( { playername, score} );

        Game newgame(gamename, scorelist);
        gamelist.insert( { gamename, newgame } );
    } else {
        // Game object already exists.
        // This means we only want to edit the map of players and scores
        // Since this function is being executed during reading of the file,
        // we can assume that the player does not already have a score for
        // this game. Either way. the function edit_scorelist
        // adds a new player and assigns them a score here.
        gamelist.at(gamename).edit_scorelist(playername, score);
    }

}

void insert_into_datastructure(std::map<std::string, Game>& gamelist,
                               std::map<std::string, Player>& playerlist,
                               std::string gamename, std::string playername,
                               unsigned int score) {
    // We create objects and insert them into the datastructure.
    // This is only called during reading the file the user has chosen.

    // Here we have a list of Game-object identifiers and a list of Player-object identifiers.
    // We use their respective names as identifiers.

    // First we check if an object of the player already exists.
    // The function called does what needs to be done in any case.
    manage_row_player_info(playerlist, gamename, playername);

    // Now we have a player object in the map of players.
    // Next we need to manage the game object.
    manage_row_game_info(gamelist, gamename, playername, score);

}

bool read_file(std::map<std::string, Game>& gamelist, std::map<std::string, Player>& playerlist,
              std::ifstream& file) {
    // Now we attempt to read the opened file.
    // We will also check that the formatting of text in file is valid.

    std::string filerow;

    while (getline(file, filerow)) {
        // If format of filerow isn't "gamename;playername;score",
        // then it's considered invalid, after which program ends with
        // value EXIT_FAILURE.
        // Though the score may be empty, or contain something which can't
        // be interpreted as a number. In that case, a score of 0 will be default.
        // Also, gamename or playername cannot be empty.
        std::vector<std::string> split_filerow = split(filerow);

        // For filerow format to be valid,
        // the size of the vector must be 3,
        // and gamename or playername cannot be empty.
        if ( split_filerow.size() != 3 ) {
            // Incorrect format
            std::cout << "Error: Invalid format in file." << std::endl;
            return false;
        }
        else {
            // Check to see if gamename or playername is empty
            std::string gamename = split_filerow.at(0);
            std::string playername = split_filerow.at(1);
            std::string score_as_string = split_filerow.at(2);


            unsigned int score = check_stoi(score_as_string);

            if (gamename.find_first_not_of(' ') == std::string::npos or
                playername.find_first_not_of(' ') == std::string::npos ) {
                // either or both is empty, invalid format.
                std::cout << "Error: Invalid format in file." << std::endl;
                return false;
            }
            // If we have gotten to this point, it means the format
            // in filerow is valid. Now to create the objects for the datastructure
            insert_into_datastructure(gamelist, playerlist,
                                      gamename, playername, score);
        }
    }
    return true;
}

std::string convert_to_upper(std::string command ) {
    // This function turns the string given as a parameter into uppercase.
    // Than string is then returned.
    for ( auto& character : command ) {
        character = toupper(character);
    }
    return command;
}

bool check_user_input_validity(std::vector<std::string>& vector_of_inputs,
                               std::map<std::string, unsigned int>& commandmap) {
    // This function determines if the user input is valid.
    // Firstly, it checks if the command given, first element of the param vector,
    // is an actual command. If it is,
    // it checks the user entered the minimum amount of parameters
    // that the command in question requires.
    // A check to see if the parameters themselves are valid will be done
    // if and when the command in question is executed.

    // Establish a map of valid commands as keys, mininmum amount of
    // parameters as payloads


    // To check if the command is valid
    std::map<std::string, unsigned int>::iterator mapiter;
    mapiter = commandmap.find(vector_of_inputs.at(0));

    if (mapiter == commandmap.end()) {
        // Command wasn't found in the list, as such it isn't valid
        std::cout << "Error: Invalid input." << std::endl;
        return false;
    }

    unsigned int params_in_input = vector_of_inputs.size();

    if ( params_in_input < commandmap.at(vector_of_inputs.at(0)) ) {
        // Less parameters entered than minimum requirement.
        std::cout << "Error: Invalid input." << std::endl;
        return false;
    }

    return true;
}

bool check_game_param(std::string gamename,
                      std::map<std::string, Game>& gamelist) {
    // This functions checks the validity of the second parameter user entered.
    // Checks for different commands done in separate functions to keep functions small.

    // the parameter must be a valid name of game
    if ( gamelist.find(gamename) == gamelist.end() ) {
        // game not in gamelist, so invalid
        std::cout << "Error: Game could not be found." << std::endl;
        return false;
    }

    return true;
}

void print_all_games(std::map<std::string, Game>& gamelist) {
    // All games are printed in alphabetical order.
    // Since the keys of gamelist are the names, we can simply
    // print the keys.

    for ( std::map<std::string, Game>::iterator mapiter = gamelist.begin();
          mapiter != gamelist.end(); ++mapiter) {
        std::cout << mapiter->first << std::endl;
    }   
}

void print_games_scorelist(Game& gameobject) {
    // // Prints the chosen game's scores and players
    // in an ascending order.
    // Layout: "score : player, player
    // I am aware this function is too large. Program is already spaghetti at this point.

    // Vector of pairs of player - score, that has been ordered by score.
    std::vector<std::pair<std::string, unsigned int> > pairvec;
    pairvec = gameobject.convert_to_ordered();
    std::vector<std::pair<std::string, unsigned int> >::iterator iter = pairvec.begin();

    // Keep track of scores already printed
    std::vector<unsigned int> managed_scores;


    for ( ; iter < pairvec.end(); ++iter) {
        // A vector of names of those who have the same score
        // as the current player
        std::vector<std::string> have_this_score;

        auto& score = iter->second;
        std::string name = iter->first;



        if ( std::find(managed_scores.begin(), managed_scores.end(), score) != managed_scores.end() ) {
            // this is a duplicate instance of a score, and as such it's already been
            // taken into account
            continue;
        }

        have_this_score.push_back(name);
        managed_scores.push_back(score);

        for (std::vector<std::pair<std::string, unsigned int> >::iterator nextiter = std::next(iter);
             nextiter < pairvec.end(); ++nextiter) {
            // We collect the names of each player who has the same score as the one in the
            // above for-loop
            unsigned int scorehere = nextiter->second;
            std::string namehere = nextiter->first;

            if ( scorehere == score ) {
                have_this_score.push_back(namehere);
            }
        }
        // Now have_this_score contains the names of all the players
        // with the score of score.
        std::sort(have_this_score.begin(), have_this_score.end());

        // At least 1 person must have this score
        std::string nameline = have_this_score.at(0);

        unsigned int names_for_this_score = have_this_score.size();

        if ( names_for_this_score > 1) {
            for (unsigned int i = 1; i < names_for_this_score; ++i) {
                std::string toadd = ", " + have_this_score.at(i);
                nameline += toadd;
            }
        }

         std::cout << score << " : " << nameline << std::endl;
    }
}

void print_all_players(std::map<std::string, Player>& playerlist) {
    // Prints all players in alphabetical order.
    std::cout << "All players in alphabetical order:" << std::endl;
    for (auto& player : playerlist ) {
        std::string name = player.first;
        std::cout << name << std::endl;
    }
}

bool check_player_param(std::string playername,
                        std::map<std::string, Player>& playerlist) {
    // The user has entered command PLAYER and at least 1 other parameter.
    // This function checks that the second parameter is a name of an existing
    // player object.

    if ( playerlist.find(playername) == playerlist.end() ) {
        std::cout << "Error: Player could not be found." << std::endl;
        return false;
    }
    return true;
}

void print_players_gamelist(Player playerobject) {
    // Prints the games the player plays in ascending order.
    std::cout << "Player " << playerobject.get_name() << " playes the following games:" << std::endl;
    playerobject.print_played_games();
}

bool check_game_name_availability(std::vector<std::string>& vector_of_inputs,
                                  std::map<std::string, Game>& gamelist) {
    // This function checks that the name the user entered
    // is not already in use with another game.

    std::string name = vector_of_inputs.at(1);

    if (gamelist.find(name) != gamelist.end() ) {
        // the name is in use
        std::cout << "Error: Already exists." << std::endl;
        return false;
    }
    return true;
}

void add_game(std::vector<std::string>& vector_of_inputs,
              std::map<std::string, Game>& gamelist) {
    // A new game is added to the map of games.
    // at this point it has no players.

    std::map<std::string, unsigned int> scorelist;
    std::string gamename = vector_of_inputs.at(1);

    Game newgame(gamename, scorelist);
    gamelist.insert( { gamename, newgame } );
    std::cout << "Game was added." << std::endl;
}

void remove_player(std::map<std::string, Game>& gamelist,
                   std::map<std::string, Player>& playerlist,
                   std::string playername) {
    // The player in question is removed from all games and playerlist.
    std::map<std::string, Game>::iterator iter;
    iter = gamelist.begin();
    while ( iter != gamelist.end() ) {
        iter->second.delete_player(playername);
        ++iter;
    }
    playerlist.erase(playername);
    std::cout << "Player was removed from all games." << std::endl;
}

bool execute_command(std::vector<std::string>& vector_of_inputs,
                     std::map<std::string, Game>& gamelist,
                     std::map<std::string, Player>& playerlist) {
    // Calls the function related to the command in question.
    // Returns true if command was executed successfully,
    // false otherwise.
    // Also a check is done to confirm a commands parameters' validity.
    // This is a large function, too large, but I'm not sure how else to do it.

    std::string command = vector_of_inputs.at(0);


    if ( command == "ALL_GAMES" ) {
        // Since the command is the only parameter, no further check required
        std::cout << "All games in alphabetical order:" << std::endl;
        print_all_games(gamelist);
    }
    if ( command == "GAME" ) {
        // Requires valid game as second param, error check is done
        std::string param1 = vector_of_inputs.at(1);
        bool second_param_validity = check_game_param(param1, gamelist);

        if ( second_param_validity == false ) {
            // param is invalid, return to main loop
            return false;
        } else {
            Game gameobject = gamelist.at(param1);
            std::cout << "Game " << param1 << " has these scores and players, listed in ascending order:"
            << std::endl;
            print_games_scorelist(gameobject);
        }
    }
    if ( command == "ALL_PLAYERS" ) {
        // No further param check needed
        print_all_players(playerlist);
    }
    if ( command == "PLAYER" ) {
        // requires valid player as second param, error check is done
        std::string param1 = vector_of_inputs.at(1);
        bool second_param_validity = check_player_param(param1, playerlist);

        if (second_param_validity == false ) {
            return false;
        } else {
            Player playerobject = playerlist.at(param1);

            print_players_gamelist(playerobject);
        }
    }
    if ( command == "ADD_GAME" ) {
        // requires a name for the game as second param.
        // Also need to check a game of same name doesn't
        // already exist.
        std::string param1 = vector_of_inputs.at(1);
        bool second_param_validity = check_game_name_availability(vector_of_inputs, gamelist);

        if (second_param_validity == false ) {
            return false;
        } else {
            add_game(vector_of_inputs, gamelist);
        }
    }
    if ( command == "ADD_PLAYER" ) {
        // requires a game as second param, player as third param and
        // score as fourth param.

        std::string gamename = vector_of_inputs.at(1);
        std::string playername = vector_of_inputs.at(2);
        // In case the player has entered something nonsensical
        // for the score, fourth param, it is read as 0.
        std::string scorestring = vector_of_inputs.at(3);
        unsigned int score = check_stoi(scorestring);

        // Only the game has to be an existing one, so
        // that's the only one that needs checking.
        bool is_gamename_ok = check_game_param(gamename, gamelist);

        if ( is_gamename_ok == false ) {
            return false;
        } else {
            // The player needs to be added only to the datastructure,
            // not to the file.
            // Luckily I created the function which creates datastructure
            // at start of program in such a away that it can be used here.

            insert_into_datastructure(gamelist, playerlist, gamename, playername, score);
            std::cout << "Player was added." << std::endl;
        }
    }
    if ( command == "REMOVE" ) {
        // Requires valid player name as second param.
        std::string playername = vector_of_inputs.at(1);

        bool is_playername_ok = check_player_param(playername, playerlist);

        if (is_playername_ok == false) {
            return false;
        } else {
            remove_player(gamelist, playerlist, playername);
        }
    }
    return true;
}

int main()
{
    // I'll begin implementation of this program by doing the
    // data structure and reading of file.
    // It is assumed that player and game names are unique.

    // A map of game objects, where the key is the game's name.
    std::map<std::string, Game> game_list = {};
    // Same as above but for player objects.
    std::map<std::string, Player> player_list = {};

    // Establish a map of valid commands as keys, mininmum amount of
    // parameters as payloads
    std::map<std::string, unsigned int> commandmap = {
        { "QUIT", 1 },
        { "ALL_GAMES", 1 },
        { "GAME", 2 },
        { "ALL_PLAYERS", 1 },
        { "PLAYER", 2 },
        { "ADD_GAME", 2 },
        { "ADD_PLAYER", 4 },
        { "REMOVE", 2 }
    };

    // Asks user for valid file name, attempts to open the file.
    // If opens file successfully, calls function to read file and
    // establish datastructure

    std::cout << "Give a name for input file: ";
    std::string nameinput;
    std::getline(std::cin, nameinput);

    std::ifstream file_thing(nameinput);

    if ( not file_thing ) {
        std::cout << "Error! File could not be read." << std::endl;
        return EXIT_FAILURE;
    }
    else {
        // File opened successfully
        bool file_read_successfully = read_file(game_list, player_list, file_thing);

        if ( file_read_successfully == false ) {
            return EXIT_FAILURE;
        }
    }

    // Now the file should be read and the game and player objects constructed and stored.
    // Input is asked from the user until user quits program
    bool run_ui = true;

    while ( run_ui ) {

        std::cout << "games> ";
        std::string input_line;
        std::getline(std::cin, input_line);
        // The user has given an input. It will have to be split
        // into parts separated by space ' '.
        // The first word will in any case be the command.

        char space_separator = ' ';
        std::vector<std::string> input_words = split(input_line, space_separator);
        // Now if the user actually entered something,
        // input_words has all the strings separated by space as elements,
        // with the command being the first element.

        // If user entered nothing, an error message is printed
        // and the loop begins anew.
        if ( input_line.empty()) {
            std::cout << "Error: Invalid input. " << std::endl;
            continue;
        }
        // So that the user may enter the command in either upper- or lowercase,
        // we make the command element in the vector uppercase.
        input_words.at(0) = convert_to_upper(input_words.at(0));

        // Now we have to determine what has been input, and if it's valid.
        bool can_input_be_valid = check_user_input_validity(input_words, commandmap);

        if ( can_input_be_valid == false ) {
            continue;
        }

        // If code is at this point, the command and and it's
        // amount of parameters are valid.

        // If the input command is to quit, program is quit.
        // Else, we execute whatever function the command does.
        if ( input_words.at(0) == "QUIT" ) {
            return EXIT_SUCCESS;
        } else {
            bool command_executed = execute_command(input_words, game_list, player_list);
            if ( command_executed == false ) {
                continue;
            }
        }
    }
    return EXIT_SUCCESS;
}
