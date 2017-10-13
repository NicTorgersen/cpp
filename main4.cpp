#include <iostream>
#include <vector>
using namespace std;

vector<int> calculate_terms (int iters) {
    vector<int> terms;

    for (int i = 1; i <= iters; i++) {
        terms.push_back(2*i - 3);
    }

    return terms;
}

int main () {
    int iterations;
    int term_to_know;
    vector<int> terms;

    cout << "Enter number of iterations: ";
    cin >> iterations;

    cout << "Which term would you like to know? ";
    cin >> term_to_know;

    terms = calculate_terms(iterations);

    cout << "The value of term " << term_to_know << " is " << terms[term_to_know-1] << endl;

    cout << "The entire sequence up to " << iterations << " terms is: ";

    for (int i = 0; i < terms.size(); i++) {
        cout << terms[i] << " ";
    }
}
