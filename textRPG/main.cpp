#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <limits>

using namespace std;

class Player {
public:
    int health = 100;
    int attack = 10;
    int xp = 0;
    int level = 1;
    vector<string> inventory;
};

class Enemy {
public:
    int health = 50;
    int attack = 5; int xp = 10;
    string name;
};

int main() {
    srand(time(nullptr));
    Player player;
    Enemy enemyTemplate;

    while(true) {
        cout << "1. Look for enemies" << endl 
        << "2. Show stats" << endl 
        << "9. Exit Game." << endl;
        int choice;
        cin >> choice;
        if (cin.fail()) {
            cout << "Expected a number!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (choice == 1) {
            Enemy goblin = enemyTemplate;
            goblin.name = "goblin";
            cout << "A " << goblin.name << " appears!\n";

            while(player.health > 0 && goblin.health > 0) {
                cout << "1. Attack" 
                << endl << "2. Run" 
                << endl;
                int attackChoice;
                cin >> attackChoice;

                if (attackChoice == 1) {
                    int damagePlayer = player.attack + (rand() % 7 - 3);
                    int damageEnemy = goblin.attack + (rand() % 7 - 3);
                    goblin.health -= damagePlayer;
                    cout << "You attack the enemy. The enemy has " << goblin.health << " health." << endl;
                    
                    if (goblin.health > 0) {
                        player.health -= damageEnemy;
                        cout << "The enemy attacks you! You have " << player.health << " health left.\n";
                    }

                    if (goblin.health <= 0) {
                        player.xp = player.xp + goblin.xp;
                        cout << "Enemy defeated!\n"
                             << "You gained " << goblin.xp << " XP!" << endl
                             << "Player XP: " << player.xp << endl;
                        break;
                    }

                    else if (player.health <= 0) {
                        cout << "You died!" << endl;
                        break;
                    }
                }
                
                else if (attackChoice == 2) {
                    cout << "You ran away." << endl;
                    break;
                }
            }
        }
        else if (choice == 2) {
            cout << "Damage: " << player.attack << endl
                 << "Health: " << player.health << endl
                 << "Level: " << player.level << endl
                 << "1. Exit" << endl;
            cin >> choice;
            cout << endl;
            if (choice == 1) {
                continue;
            }
        }
        else if (choice == 9) {
            cout << "Stopped!";
            break;
        }

        else {
            cout << "That is not an option";
        }
        
    }
    return 0;
}
