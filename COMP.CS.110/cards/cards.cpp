#include "cards.hh"
#include <iostream>

using namespace std;

// TODO: Implement the methods here

Cards::Cards(): top_(nullptr), bottom_(nullptr) {

}

Cards::~Cards() {

    while (top_ != nullptr) {
        Card_data* card_to_remove = top_;
        top_ = top_->next;

        delete card_to_remove;
    }
}

void Cards::add(int id) {
    // add card to struct, update pointers.
    Card_data* new_card = new Card_data{id, nullptr, nullptr};

    if ( top_ == nullptr) {
        top_ = new_card;
        bottom_ = new_card;
    } else {
        top_->previous = new_card;
        new_card->next = top_;
        top_ = new_card;
    }
}

void Cards::print_from_top_to_bottom(ostream& s) {

    int rowcounter = 1;
    Card_data* card_to_print = top_;

    while (card_to_print != nullptr) {
        int id = card_to_print->data;
        s << rowcounter << ": " << id << endl;

        ++rowcounter;
        card_to_print = card_to_print->next;
    }
}

Card_data* Cards::get_topmost() {
    return top_;
}

bool Cards::bottom_to_top() {

    if (top_ == nullptr) {
        // empty structure, return false
        return false;
    }

    // So, the bottom card is moved to the top.
    // Relevant pointers must be updated.

    // First, add pointer next -> top_ to the current bottom
    // Then, add pointer previous -> bottom to current top
    // Then, designate current bottom as top_
    // Then, designate top_->previous as new bottom

    // Then, delete pointer previous from current top_
    // Then, delete pointer next from current bottom_
    // Then it should work

    Card_data* card_to_move = bottom_;
    card_to_move->next = top_;
    top_->previous = card_to_move;
    top_ = card_to_move;
    bottom_ = top_->previous;
    top_->previous = nullptr;
    bottom_->next = nullptr;

    return true;

}

bool Cards::top_to_bottom() {

    if (top_ == nullptr) {
        // empty structure, return false
        return false;
    }

    // So, the top card is moved to the bottom.

    Card_data* card_to_move = top_;
    card_to_move->previous = bottom_;
    bottom_->next = card_to_move;
    bottom_ = card_to_move;
    top_ = bottom_->next;
    bottom_->next = nullptr;
    top_->previous = nullptr;


    return true;
}

void Cards::print_from_bottom_to_top(ostream& s) {

    int rowcounter = 1;
    Card_data* card_to_print = bottom_;

    while (card_to_print != nullptr) {
        int id = card_to_print->data;
        s << rowcounter << ": " << id << endl;

        ++rowcounter;
        card_to_print = card_to_print->previous;
    }
}

bool Cards::remove(int& id) {
    // Removes topmost card. Return false if struct empty,
    // true otherwise.

    if (top_ == nullptr) {
        return false;
    }

    Card_data* card_to_remove = top_;
    id = card_to_remove->data;

    top_ = card_to_remove->next;

    delete card_to_remove;

    return true;
}
