#include <iostream>
#include <vector>
using namespace std;

vector<int> calculate_fibonacci (int max_length) {
    vector<int> fibonacci_sequence{1, 2};

    while (fibonacci_sequence[fibonacci_sequence.size() - 1] < max_length) {
        if (fibonacci_sequence[fibonacci_sequence.size() - 2] + fibonacci_sequence[fibonacci_sequence.size() - 1] > max_length) {
            return fibonacci_sequence;
        }
        fibonacci_sequence.push_back( (fibonacci_sequence[fibonacci_sequence.size() - 2] + fibonacci_sequence[fibonacci_sequence.size() - 1]) );
    }

    return fibonacci_sequence;
}

int main () {
    int max_length, sum_of_even;
    vector<int> fib;

    max_length = 4000000;
    sum_of_even = 0;

    cout << "Tell me what the highest number from fibonacci you want: ";
    cin >> max_length;

    cout << "Great, now calculating fibonacci sequence with " << max_length << " as highest number." << endl;

    fib = calculate_fibonacci(max_length);

    for (int i = 0; i < fib.size(); i++) {
        if (fib[i] % 2 == 0) {
            cout << (int) fib[i] << endl;
            sum_of_even += (int)fib[i];
        }
    }

    cout << endl << (int) sum_of_even;

    return 0;
}
