#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void RecPermute(string soFar, string rest, vector<string>& res)
{
    if (rest == "" && find(res.begin(), res.end(), soFar) == res.end()){ // No more characters
        res.push_back(soFar);
    }
    else // Still more chars
    // For each remaining char
        for (int i = 0; i < rest.length(); i++) {
        string next = soFar + rest[i]; // Glue next char
        string remaining = rest.substr(0, i)+ rest.substr(i+1);
        RecPermute(next, remaining, res);
    }
}
// "wrapper" function
void ListPermutations(string s) {
    vector<string> result;
    RecPermute("", s, result);
    for(int i = 0; i < result.size(); i ++){
        cout << result[i] << endl;
    }
}

int main()
{
    string s;
    cout << "Enter text: ";
    cin >> s;
    ListPermutations(s);
}
