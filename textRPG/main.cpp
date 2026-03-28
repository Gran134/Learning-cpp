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
    Player player;
    Enemy enemy;
    

    cout << "A " << enemy.name << " appears!\n";

    while(true) {
        srand(time(nullptr));

        int damagePlayer = player.attack + (rand() % 7 - 3);
        int damageEnemy = enemy.attack + (rand() % 7 - 3);

        cout <<"1. Attack" << endl << "2. Run" << endl << "3. Stats" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            enemy.health -= damagePlayer;
            cout << "You attac the enemy. " << "The enemy has " << enemy.health << " health." << endl;
            
            
            if (enemy.health > 0) {
                player.health -= damageEnemy;
                cout << "The enemy attacks you! You have " << player.health << " health left.\n";

                
            }

            if (enemy.health <= 0) {
                player.xp = player.xp + enemy.xp;
                cout << "Enemy defited!\n" << "You gained " << enemy.xp << " xp!" << endl << "Player xp: " << player.xp << " xp" << endl;
                break;
            }

            else if (player.health <= 0) {
                    cout << "You died!";
                    break;
            }
        }
        
        else if (choice == 2) {
            cout << "You ran away" << endl;
            break;
        }

        else if (choice == 3) {
            cout << "Damage: " << player.attack << endl << "Health: " << player.health << endl << "Level: " << player.level << endl << "1. exit" << endl;
            cin >> choice;
            cout << endl;
            if (choice == 1) {
                continue;
            }
        }
    }
}