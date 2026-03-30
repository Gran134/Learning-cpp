#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <limits>
#include <list>
#include <random>

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
    int health;
    int attack;
    int xp;
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
            goblin.health = 75;
            goblin.attack = 7;
            goblin.xp = 10;

            Enemy skeleton = enemyTemplate;
            skeleton.name = "skeleton";
            skeleton.health = 50;
            skeleton.attack = 5;
            skeleton.xp = 5;

            vector<Enemy> enemies {"goblin", "skeleton"};
            int randomEnemy = rand() % enemies.size();
            Enemy currnetEnemy = enemies[randomEnemy];

            
            cout << "A " << currnetEnemy.name <<" appears!\n";
            

            while(player.health > 0 && currnetEnemy.health > 0) {
                cout << "1. Attack" 
                << endl << "2. Run" 
                << endl;
                int attackChoice;
                cin >> attackChoice;

                if (attackChoice == 1) {
                    int damagePlayer = player.attack + (rand() % 7 - 3);
                    int damageEnemy = currnetEnemy.attack + (rand() % 7 - 3);
                    currnetEnemy.health -= damagePlayer;

                    cout << "You attack the enemy. The enemy has " << currnetEnemy.health << " health." << endl;
                    
                    if (currnetEnemy.health > 0) {
                        player.health -= damageEnemy;
                        cout << "The enemy attacks you! You have " << player.health << " health left.\n";
                    }

                    if (currnetEnemy.health <= 0) {
                        player.xp = player.xp + currnetEnemy.xp;
                        cout << "Enemy defeated!\n"
                             << "You gained " << goblin.xp << " XP!" << endl
                             << "Player XP: " << currnetEnemy.xp << endl;
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
