#include <iostream>
#include <stdexcept>
using namespace std;

int do_factorial (int x) {
    int factorial = 1;
    for (int i=2; i <= x; i++) {
        factorial *= i;
    }

    return factorial;
}
int do_permutation (int a, int b) {
    int permutation;
    int afactorial = do_factorial(a);
    int abfactorial = do_factorial(a-b);
    permutation = afactorial / abfactorial;

    return permutation;
}

int do_combination (int a, int b) {
    int combination;
    int bfactorial = do_factorial(b);
    combination = do_permutation(a,b) / bfactorial;

    return combination;
}

int main () {
    int a, b;
    char cp;
    try {
        cout << "Enter two integers: ";

        if (cin >> a && cin >> b) {
            // we good
        } else if (a < 0 || b < 0) {
            throw runtime_error("Invalid input: please enter integers that are positive");
        } else {
            throw runtime_error("Invalid input: please enter integers");
        }

        cout << "Please enter 'p' for permutation or 'c' for combination: ";
        cin >> cp;

        if (cp == 'p') {
            // permutation
            if (b > a) {
                cout << "Permutation of " << a << " and " << b << " = " << 0 << endl;
            } else {
                cout << "Permutation of " << a << " and " << b << " = " << do_permutation(a,b) << endl;
            }
        } else if (cp == 'c') {
            // combination
            if (b > a) {
                cout << "Combination of " << a << " and " << b << " = " << 0 << endl;
            } else {
                cout << "Combination of " << a << " and " << b << " = " << do_combination(a,b) << endl;
            }
        } else {
          throw runtime_error("Invalid input: please enter a valid input");
        }

    } catch (runtime_error& e) {
        cout << e.what() << endl;
        return 0;
    }

    return 0;
}
