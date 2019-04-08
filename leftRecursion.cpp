#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct nTerminal {
    char symbol;
    int count;
};

string getString(char x) {
    string s(1, x);
    return s;
}

int main() {
    printf("Enter the non-terminals: ");
    string nonTerminalsString;
    cin >> nonTerminalsString;

    vector <nTerminal> nonTerminals;

    for (int i = 0; i < nonTerminalsString.length(); i++) {
        nTerminal newn;
        newn.symbol = nonTerminalsString[i];
        nonTerminals.push_back(newn);
    }

    for (int i = 0; i < nonTerminals.size(); i++) {
        printf("\nEnter the no of productions for %c: ", nonTerminals[i].symbol);
        cin >> nonTerminals[i].count;
    }

    vector <string> productions;

    for (int i = 0; i < nonTerminals.size(); i++) {
        printf("\nEnter the right productions for %c: ", nonTerminals[i].symbol);
        for (int j = 0; j < nonTerminals[i].count; j++) {
            string prod;
            cin >> prod;
            productions.push_back(prod);
        }
    }

    for (int i = 0; i < productions.size(); i++) {
        string curr = productions[i];
        bool recursionExists = false;

        if (curr[0] == curr[3]) {
            recursionExists = true;
        } else {
            cout << curr << endl;
            continue;
        }

        string newProduction1 = getString(curr[0]) + "->" + curr.substr(4).substr(1) + getString(curr[0]) + "\'";
        string newProduction2 = getString(curr[0]) + "\'->" + curr.substr(4) + getString(curr[0]) + "\'|ε";
        cout << newProduction1 << endl;
        cout << newProduction2 << endl;
        
    }

    return 0;
}