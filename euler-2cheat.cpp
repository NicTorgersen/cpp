#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a = 1;
    int b = 2;
    int i;
    int answer=0;
    vector<int> sequence{1, 2};

    do {
        a = a + b;
        sequence.push_back(a);
        b = b + a;
        sequence.push_back(b);
    } while ( a + b < 8000000);

    for (i=0 ; i < sequence.size() ; i++) {
        if (sequence[i] % 2 == 0) {
            cout << sequence[i] << endl;
            answer = answer + sequence[i];
        }
        else {
            answer = answer;
        }
    }
    cout << answer;
    return 0;
}
