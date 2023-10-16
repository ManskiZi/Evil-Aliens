#include <iostream>

using namespace std;

class Alien {
public:
    int x_coordinate;
    int y_coordinate;
    
    // Alien constructor to initialize coordinates
    Alien(int x, int y) {
        this->x_coordinate = x;
        this->y_coordinate = y;
    }
    
    // Get the current health of the alien
    int getHealth() {
        return health;
    }
    
    // Inflict damage on the alien by reducing its health
    int hit() {
        health -= 1;

        // Ensure health doesn't go negative
        if (health < 0) {
            health = 0;
        }

        return health;
    }

    // Check if the alien is alive based on its health
    bool is_alive() {
        return health > 0;
    }
    
    // Teleport the alien to new coordinates
    int teleport(int x_new, int y_new) {
        this->x_coordinate = x_new;
        this->y_coordinate = y_new;
    }
    
    // Detect if two aliens occupy the same coordinates
    bool collision_detection(const Alien& other_alien) {
        return x_coordinate == other_alien.x_coordinate && y_coordinate == other_alien.y_coordinate;
    }
    
private:
    // Initial health of the alien
    int health = 3;
};

int main() {
    // Create instances of Alien
    Alien bad_alien(2, 0);
    Alien good_alien(3, 4);

    cout << "The Bad alien X coordinates are: " << bad_alien.x_coordinate << "\n";
    cout << "The Bad alien Y coordinates are: " << bad_alien.y_coordinate << "\n";
    
    bad_alien.hit();
    bad_alien.hit(); // Inflict more damage

    cout << "The Bad Alien's Health: " << bad_alien.getHealth() << "\n";
    cout << "Is the Bad alien alive? " << (bad_alien.is_alive() ? "Yes" : "No") << "\n";
    
    bad_alien.teleport(5, -4);
    cout << "The Bad alien teleported!\n";
    cout << "The Bad alien new X coordinates are: " << bad_alien.x_coordinate << "\n";
    cout << "The Bad alien new Y coordinates are: " << bad_alien.y_coordinate << "\n";

    good_alien.teleport(5, -4);
    cout << "The Good alien teleported!\n";
    cout << "The Good alien new X coordinates are: " << good_alien.x_coordinate << "\n";
    cout << "The Good alien new Y coordinates are: " << good_alien.y_coordinate << "\n";
    
    // Check if bad_alien and good_alien occupy the same coordinates
    bool collision = bad_alien.collision_detection(good_alien);
    cout << "Collision detected: " << (collision ? "Yes" : "No") << "\n";

    return 0;
}
