#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

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
    int health = 100;
    int attack = 10;
    int xp = 10;
    string name = "Goblin";
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

        if (choice == 1) {
            Enemy enemy = enemyTemplate;
            cout << "A " << enemy.name << " appears!\n";

            while(player.health > 0 && enemy.health > 0) {
                cout << "1. Attack" 
                << endl << "2. Run" 
                << endl;
                int attackChoice;
                cin >> attackChoice;

                if (attackChoice == 1) {
                    int damagePlayer = player.attack + (rand() % 7 - 3);
                    int damageEnemy = enemy.attack + (rand() % 7 - 3);
                    enemy.health -= damagePlayer;
                    cout << "You attack the enemy. The enemy has " << enemy.health << " health." << endl;
                    
                    if (enemy.health > 0) {
                        player.health -= damageEnemy;
                        cout << "The enemy attacks you! You have " << player.health << " health left.\n";
                    }

                    if (enemy.health <= 0) {
                        player.xp = player.xp + enemy.xp;
                        cout << "Enemy defeated!\n"
                             << "You gained " << enemy.xp << " XP!" << endl
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
    }
}
