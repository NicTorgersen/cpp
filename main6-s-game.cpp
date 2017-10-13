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

string code_validation(string guess, int length, int amount) {
    for (int i = 0 ; i < guess.size() ; i++){
        guess[i] = toupper(guess[i]);
    }
    cout << "Your guess: " << guess << endl;
    try{
        for ( int i = 0 ; i < guess.size() ; i++ ) {
            if ( !isalpha(guess[i]) ) { throw runtime_error("Invalid Guess.");
            }
        }
        if ( guess.size() != length) { throw runtime_error("Invalid Guess.");
        }
        for ( int i = 0 ; i < guess.size() ; i ++) {
            if ( int(guess[i]) > ( 64 + amount) ) { throw runtime_error("Invalid Guess: One of the letters you entered is out of bonds.");
            }
        }
    } catch ( runtime_error & e) {
        cout << e.what() << endl;
    }

    return guess;
}

void generate_code(int number_of_characters, int pattern_length) {
    srand(time(0));
    char temp;
    for (int i = 0; i < pattern_length ; i++){
        temp = rand() % number_of_characters + 65;
        code = code + temp;
    }
}

int get_correction(string guess) {
    int number_of_correct = 0;
    for ( int i = 0 ; i < guess.size() ; i++ ) {
        if ( code[i] == guess[i] ) {
            number_of_correct++;
        }
    }

    return number_of_correct;
}

int message(int amount) {
    int number_of_tries = 0;
    cout << "You guessed " << amount << " characters correctly" << endl;
    number_of_tries++;

    return number_of_tries;
}

void end_message(int number_of_tries) {
     cout << "You guessed the pattern in " << number_of_tries << " guesses" << endl;
}

int main() {
    int amount_of_characters = get_preference1("Enter the amount of different characters: ");
    if ( amount_of_characters == 0 ) { return 0; };
    int pattern_length = get_preference2("Enter the pattern length: ");
    if ( pattern_length == 0 ) { return 0; };

    generate_code(amount_of_characters, pattern_length);

    string code_guess;
    bool loop = true;
    while ( loop ) {
        code_guess = get_string("Enter your guess: ");
        code_guess = code_validation(code_guess, pattern_length, amount_of_characters);
        int number_of_correct = get_correction(code_guess);
        int number_of_tries = message(number_of_correct);
        if ( number_of_correct == code.size() ) {
            loop = false;
            end_message(number_of_tries);
        }
    }

    return 0;
}
