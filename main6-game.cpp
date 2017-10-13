#include <iostream>
#include <ctime>
#include <cctype>
#include <stdexcept>
using namespace std;

string code;

int get_preference1(string question) {
    int amount;
    cout << question;
    cin >> amount;

    try{
        if ( cin.fail() ) { throw runtime_error("Invalid Input: Please enter an integer.");
        }
        else if ( amount > 26 || amount < 1 ) { throw runtime_error("Invalid Input: Please enter an integer between 1 and 26.");
        }
    } catch ( runtime_error & e) {
        cout << e.what() << endl;
        return 0;
    }

    return amount;
}

int get_preference2(string question){
    int length;
    cout << question;
    cin >> length;

    try{
        if ( cin.fail() ) { throw runtime_error("Invalid Input: Please enter an integer.");
        }
        else if ( length < 1) { throw runtime_error("Invalid Input: Please enter a postive integer.");
        }
    } catch ( runtime_error & e) {
        cout << e.what() << endl;
        return 0;
    }

    return length;
}

string get_string(string question) {
    string guess;
    cout << question;
    cin >> guess;

    return guess;
}

void code_validation(string guess, int length, int amount) {
    for (int i = 0 ; i < guess.size() ; i++){
        guess[i] = toupper(guess[i]);
    }

    try{
        for ( int i = 0 ; i < guess.size() ; i++ ) {
            if ( !isalpha(guess[i]) ) { throw runtime_error("Please only enter letters.");
            }
        }
        if ( guess.size() != length) { throw runtime_error("Please enter the right amount of letters.");
        }
        for ( int i = 0 ; i < guess.size() ; i ++) {
            if ( int(guess[i]) > ( 64 + amount) ) { throw runtime_error("One of the letters you entered is out of bonds.");
            }
        }
    } catch ( runtime_error & e) {
        cout << e.what() << endl;
    }
}

void generate_code(int amount_of_characters, int pattern_length) {
    srand(time(0));
    char temp;
    for (int i = 0; i < amount_of_characters; i++){
        temp = rand() % pattern_length + 65;
        code = code + temp;
    }
}

int compare_guess_with_code (string code, string guess) {
    int hits = 0;

    for (int i = 0; i < code.size(); i++) {
        code[i] = toupper(code[i]);
        guess[i] = toupper(guess[i]);

        if (code[i] == guess[i]) {
            hits++;
        }
    }

    return hits;
}

int main() {
    int amount_of_characters = get_preference1("Enter the amount of different characters: ");
    if ( amount_of_characters == 0 ) { return 0; };
    int pattern_length = get_preference2("Enter the pattern length: ");
    if ( pattern_length == 0 ) { return 0; };
    string code_guess = "";
    int number_of_tries = 0;
    bool loop = true;

    generate_code(amount_of_characters, pattern_length);

    while (loop) {
        number_of_tries++;
        code_guess = get_string("Enter your guess: ");
        code_validation(code_guess, pattern_length, amount_of_characters);

        int hits = compare_guess_with_code(code, code_guess);

        if (hits == code.size()) {
            cout << "You win!" << "\tTries: " << number_of_tries << endl;
            loop = false;
        } else {
            cout << "Likeness:\t" << hits << endl;
        }

    }
    return 0;
}
