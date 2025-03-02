//ABIGAIL BRAGA
//Lab #2

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

const int NUM_CREATURES = 5;

const string CREATURE_NAMES_FILE = "creature_names.txt";

enum MenuOption {
    PRINT_CREATURES = 1,
    UPDATE_CREATURES,
    PRINT_DAMAGE,
    EXIT
};

// Creature class.
class Creature {
public:
    int strength = 0;
    int health = 0;
    string id = "";

    // Sets the creature's strength, health, and id.
    void setCreature(int strength, int health, string id) {
        this->strength = strength;
        this->health = health;
        this->id = id;
    }

    // Get the creature's health, strength, and id.
    int getHealth() const {
        return health;
    }

    int getStrength() const {
        return strength;
    }

    string getId() const {
        return id;
    }

    // Calculates how much damage the creature does.
    int damage() const {
        return (rand() % strength) + 1;
    }

    // Turns the creature's information into a string so we can print it easily.
    string toString() const {
        stringstream ss;
        ss << left << setw(15) << id << right << setw(5) << health << setw(5) << strength;
        return ss.str();
    }
};

// Prints the creatures' information in a table.
void printCreatures(const Creature creatures[], int size) {
    cout << "\nCreatures:\n";
    cout << left << setw(15) << "ID" << right << setw(5) << "Health" << setw(5) << "Strength" << endl;
    for (int i = 0; i < size; i++) {
        cout << creatures[i].toString() << endl;
    }
}

// Updates the creatures' health, strength, and id.
void updateCreatures(Creature creatures[], int size) {
    // Open the file with creature names.
    ifstream namesFile(CREATURE_NAMES_FILE);
    if (!namesFile.is_open()) {
        cerr << "Error opening creature names file." << endl;
        return;
    }

    // Read the names from the file.
    string names[size];
    for (int i = 0; i < size && getline(namesFile, names[i]); ++i);
    namesFile.close();

    // Update each creature.
    for (int i = 0; i < size; i++) {
        // Generate random health and strength.
        int health = rand() % (250 - 75 + 1) + 75;
        int strength = rand() % (200 - 50 + 1) + 50;
        creatures[i].setCreature(strength, health, names[i]);
    }
    cout << "\nCreatures updated.\n";
}

// Prints the damage each creature can do.
void printDamage(const Creature creatures[], int size) {
    cout << "\nDamage Report:\n";
    cout << left << setw(15) << "ID" << right << setw(5) << "Health" << setw(5) << "Strength" << setw(8) << "Damage" << endl;
    for (int i = 0; i < size; i++) {
        cout << left << setw(15) << creatures[i].getId() << right << setw(5) << creatures[i].getHealth() << setw(5) << creatures[i].getStrength() << setw(8) << creatures[i].damage() << endl;
    }
}

int main() {
    // Random number generator.
    srand(time(0));

    // Array to hold our creatures.
    Creature creatures[NUM_CREATURES];

    int choice;
    // Keep showing the menu until the user chooses to exit.
    do {
        cout << "\nMenu:\n";
        cout << "1. Print Creatures\n";
        cout << "2. Update Creatures\n";
        cout << "3. Print Damage\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Do something based on the user's choice.
        switch (static_cast<MenuOption>(choice)) {
            case PRINT_CREATURES:
                printCreatures(creatures, NUM_CREATURES);
                break;
            case UPDATE_CREATURES:
                updateCreatures(creatures, NUM_CREATURES);
                break;
            case PRINT_DAMAGE:
                printDamage(creatures, NUM_CREATURES);
                break;
            case EXIT:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != EXIT);

    return 0;
}

/*
Menu:
1. Print Creatures
2. Update Creatures
3. Print Damage
4. Exit
Enter your choice: 2

Creatures updated.

Menu:
1. Print Creatures
2. Update Creatures
3. Print Damage
4. Exit
Enter your choice: 3

Damage Report:
ID             HealthStrength  Damage
                 128   93      91
                 188  177      76
                  86   74      24
                 106   77      37
                 198   61      25

Menu:
1. Print Creatures
2. Update Creatures
3. Print Damage
4. Exit
Enter your choice: 4
Exiting...


...Program finished with exit code 0
Press ENTER to exit console.*/