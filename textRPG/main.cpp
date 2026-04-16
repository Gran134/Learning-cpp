#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
#include <ctime>


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

void showMenu() {
    cout << "1. Look for enemies" << endl 
    << "2. Show stats" << endl 
    << "9. Exit Game." << endl;
}

void showStats(const Player& player) {
    cout << "Damage: " << player.attack << endl
    << "Health: " << player.health << endl
    << "Level: " << player.level << endl;
}

Enemy createRandomEnemy() {
    Enemy enemyTemplate;

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

    vector<Enemy> enemies {goblin, skeleton};
    int randomEnemy = rand() % enemies.size();
    
    return enemies[randomEnemy];
}
int readInt() {
    int value;

    while (true) {
        cin >> value;

        if (cin.fail()) {
            cout << "Expected a number!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

void fightEnemy(Player& player, Enemy currentEnemy) {
    cout << "A " << currentEnemy.name <<" appears!\n";
    
    while (player.health > 0 && currentEnemy.health > 0) {
        cout << "1. Attack" 
        << endl << "2. Run" 
        << endl;

        int attackChoice = readInt();

        if (attackChoice == 1) {
            int dammagePlayer = player.attack + (rand() % 7 - 3);
            int damageEnemy = currentEnemy.attack + (rand() % 7 - 3);
            currentEnemy.health -= player.attack;

            cout << "You attack the enemy. The enemy has " << currentEnemy.health << " health." << endl;
            
            if (currentEnemy.health > 0) {
                player.health -= damageEnemy;
                cout << "The enemy attacks you! You have " << player.health << " health left.\n";
            }
            if (currentEnemy.health <= 0) {
                player.xp = player.xp + currentEnemy.xp;
                cout << "Enemy defeated!\n"
                        << "You gained " << currentEnemy.xp << " XP!" << endl
                        << "Player XP: " << player.xp << endl;
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

void savePlayer(const Player& player) {
    ofstream saveFile("saves.json");

        if (saveFile.fail()) {
        cout << "Could not open the file!" << endl;
        return;
    }
    saveFile << "{\n";
    saveFile << "   \"health\": " << player.health << ",\n";
    saveFile << "   \"attac\": " << player.attack << ",\n";
    saveFile << "   \"xp\": " << player.xp << ",\n";
    saveFile << "   \"level\": " << player.level << "\n";

    for (const string& item : player.inventory) {
        saveFile << "   \"Inventory\": " << item << "\n";
    }
    saveFile << "}\n";
    saveFile.close();
}

int main() {







    srand(time(nullptr));
    Player player;

    while(true) {
        showMenu();
        int choice = readInt();

        if (choice == 1) {
            Enemy currentEnemy = createRandomEnemy();
            fightEnemy(player, currentEnemy);
            savePlayer(player);

        }
        else if (choice == 2) {
            showStats(player);
        }
        else if (choice == 9) {
            cout << "Stopped!" << endl;
            savePlayer(player);
            break;
        }
        else {
            cout << "That is not an option!" << endl;
        }
    }
    return 0;
}
