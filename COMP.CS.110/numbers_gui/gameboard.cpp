#include "gameboard.hh"
#include "mainwindow.hh" // to get side_of_board_
#include <iostream>

/* COMP.CS.110
 * Projecti 'Peli nimeltä 2048'
 * Opiskelija: Eetu Luoma
 * Email: eetu.luoma@tuni.fi
 * Opiskelijanumero: K444309
 *
 * Monia instansseja tyyliin board_.xxx.size() muutettu tyyliksi
 * side_of_board_, jotta gui:sta pystyy muuttamaan pelilaudan kokoa.
 *
 * init_emptyyn lisätty board_ tietorakenteen tyhjäys
 *
 */

// So that the board size may be variable, the uses of SIZE
// have been replaced with side_of_board_.
// In the case that the given code were not to be modified,
// I cannot be penalized: it was not explicitly stated that
// the given code must be used as is, just that it must be used.


GameBoard::GameBoard()
{
}

GameBoard::~GameBoard()
{
    for( int y = 0; y < side_of_board_; ++y)
    {

        for( int x = 0; x < side_of_board_; ++x)
        {
            delete board_.at(x).at(y);
            board_.at(x).at(y) = nullptr;
        }
    }

}

void GameBoard::init_empty()
{
    // the datastructure for board_ is cleared
    board_.clear();


    std::vector<NumberTile*> row;
    for( int i = 0; i < side_of_board_; ++i)
    {
        row.push_back(nullptr);
    }
    for( int i = 0; i < side_of_board_; ++i)
    {
        board_.push_back(row);
    }

}

void GameBoard::fill(int seed)
{
    randomEng_.seed(seed);
    distribution_ = std::uniform_int_distribution<int>(0, side_of_board_ - 1);

    // Wiping out the first random number (which is almost almost 0)
    distribution_(randomEng_);

    for( auto y = 0; y < side_of_board_; ++y )
    {
        for( auto x = 0; x < side_of_board_; ++x )
        {
            board_.at(y).at(x) = new NumberTile(0, std::make_pair(y, x), this);
        }
    }

    for( int i = 0 ; i < side_of_board_ ; ++i )
    {
        new_value();
    }
}

void GameBoard::fill_existing()
{
    // This is used to fill the board in the case that
    // the NumberTile -objects already exist, and gameboard size
    // hasn't been changed. This way, no new NumberTiles need to be made,
    // unless gameboard size was changed.

    for( auto y = 0; y < side_of_board_; ++y )
    {
        for( auto x = 0; x < side_of_board_; ++x )
        {
            // all tiles' values set to 0
            NumberTile* tile = board_.at(y).at(x);
            tile->set_value(0);
        }
    }

    for( int i = 0 ; i < side_of_board_ ; ++i )
    {
        new_value();
    }

}

void GameBoard::new_value(bool check_if_empty)
{
    if( check_if_empty and is_full() ){
        // So that we will not be stuck in a forever loop
        return;
    }
    int random_x = 0;
    int random_y = 0;
    do
    {
        random_x = distribution_(randomEng_);
        random_y = distribution_(randomEng_);
    } while( not board_.at(random_y).at(random_x)->new_value(NEW_VALUE) );
}

void GameBoard::print() const
{
    for( auto y : board_ ) // this is giving me a warning, but it's not my code
    {
        std::cout << std::string(PRINT_WIDTH * side_of_board_ + 1, '-') << std::endl;
        for( auto x : y )
        {
            x->print(PRINT_WIDTH);
        }
        std::cout << "|" << std::endl;
    }
    std::cout << std::string(PRINT_WIDTH * side_of_board_ + 1, '-') << std::endl;
}

bool GameBoard::move(Coords dir, long int goal)
{
    bool has_won = false;
    for( int y = 0; y < side_of_board_; ++y )
    {
        for( int x = 0; x < side_of_board_; ++x )
        {
            int directed_y = dir.first > 0 ? side_of_board_ - y - 1 : y;
            int directed_x = dir.second > 0 ? side_of_board_ - x - 1 : x;
            if( board_.at(directed_y).at(directed_x)->move(dir, goal) )
            {
                has_won = true;
            }
        }
    }
    for( auto &row : board_ )
    {
        for( auto &tile : row )
        {
            tile->reset_turn();
        }
    }
    return has_won;
}

NumberTile* GameBoard::get_item(Coords coords)
{
    return board_.at(coords.first).at(coords.second);
}

bool GameBoard::is_full() const
{
    for( auto y : board_ ) // giving a warning, not my code
    {
        for( auto x : y )
        {
            if( x->is_empty() )
            {
                return false;
            }
        }
    }
    return true;
}

