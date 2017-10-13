#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

int main(){
    int i, j;
    string data, temp;
    vector<string> output;

    i = 0;
    j = 0;

    cout << "Enter the data to be compressed: ";
    cin >> data;

    //try{
        for( i=0 ; i<data.length() ; i++){
            if(data[i] != data[i+1]){
                temp = to_string(i);
                output.push_back(temp);
                output.push_back(string(1, data[i]));
            }
        }
    //}

    for( j=0 ; j<output.size() ; j++){
        cout << output[j] << " " << endl;
    }
    //cout << output.size() << output[0] << endl;
    //cout << temp << endl;
    return 0;
}
