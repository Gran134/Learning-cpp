#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));
    int number = rand() % 100;
    int winn = 0;

    while (winn == 0) {
        cout << "guess a number (1 - 100): ";
        int guess;
        cin >> guess;
        if (guess > 100) {
            cout << "Lower then 100" << endl;
        }
        else if (guess < 0) {
            cout << "Bigger then 0" << endl;
        }

        else {
            if (guess == number) {
                cout << "YIPPIEE!!" << endl;
                winn = 1;
            }
            else {
                cout << "NOOOOO!!!" << endl;
            }

            if (guess < number) {
                cout << "To smol" << endl;
            }
            else if (guess > number) {
                cout << "To big" << endl;
            }
        }
    }
    return 0;
}
