#include "queue.hh"
#include <iostream>

using namespace std;

Queue::Queue(unsigned int cycle): first_(nullptr), last_(nullptr),
is_green_(false), cycle_(cycle), left_to_go_(cycle) {

}

Queue::~Queue() {
    // Make destructor here

}

// Implement the member functions of Queue here

// Enqueue
void Queue::enqueue(string const& reg) {
    // Add's a vehicle into the fold.
    // If light is red, they're added to the queue.
    // If light is green, they can go on ahead.

    if (is_green_) {
        cout << "GREEN: The vehicle " << reg << " need not stop to wait" << endl;
        --left_to_go_;

        if (left_to_go_ == 0) {
            is_green_ = false;
        }
    } else {
        // It is red, vehicle is to be added to the back of the queue.

        Vehicle*  new_vehicle = new Vehicle{reg, nullptr};

        if (first_ == nullptr) {
            // que is empty
            last_ = new_vehicle;
            first_ = new_vehicle;
        } else {
            // already at least 1 in que. Make pointers
            // First in que will point to the next,
            // next to the one after that, etc. until the last vehicle.
            last_->next = new_vehicle;
            last_ = new_vehicle;
        }

    }
}

// Print
void Queue::print() const {
    // Print current status:
    // Light, vehicles if there are any in que.
    string color;
    if (is_green_) {
        color = "GREEN";
    } else {
        color = "RED";
    }

    if (first_ == nullptr) {
        cout << color << ": No vehicles waiting in traffic lights" << endl;
    } else {
        // There are qued vehicles
        Vehicle* current = first_;
        string vehicles = current->reg_num;
        current = current->next;
        while (current != nullptr) {
            vehicles += ' ' + current->reg_num;
            current = current->next;
        }
        cout << color << ": Vehicle(s) " << vehicles << " waiting in traffic lights" << endl;
    }
}

void Queue::dequeue() {
    // Lets a car go by if the light is green.
    // If that happens, reduces the count of vehicles that can go by.
    // This does not check to see if the state should change.

    // A vehicle can only be removed from the front of the que, i.e. the first
    // vehicle.
    Vehicle* vec_to_leave = first_;
    first_ = vec_to_leave->next;

    --left_to_go_;

    delete vec_to_leave;
}


void Queue::switch_light() {
    //
    if (is_green_ == false) {
        // switching from red to green
        is_green_ = true;

        left_to_go_ = cycle_; 

        if (first_ == nullptr) {
            cout << "GREEN: No vehicles waiting in traffic lights" << endl;
            return;
        } else {
            Vehicle* current = first_;
            string vehicles = current->reg_num;

            dequeue();

            while (left_to_go_ > 0 and first_ != nullptr) {
                Vehicle* current = first_;
                vehicles += ' ' + current->reg_num;

                dequeue();
            }

            cout << "GREEN: Vehicle(s) " << vehicles << " can go on" << endl;

            is_green_ = false;

        }
    } else {
        // switching from green to red
        is_green_ = false;
        print();
    }
}

void Queue::reset_cycle(unsigned int cycle) {
    cycle_ = cycle;
}
