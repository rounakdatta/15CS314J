#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

string getString(char x) {
    string s(1, x);
    return s;
}

int main() {
    int t;
    printf("Enter the number of test cases: ");
    cin >> t;

    for (int u = 0; u < t; u++) {
        int n;
        printf("\nEnter the no of productions: ");
        cin >> n;

        string lhs;
        printf("\nEnter LHS: ");
        cin >> lhs;
        vector <string> productions;
        for (int i = 0; i < n; i++) {
            string foo;
            cin >> foo;
            productions.push_back(foo);
        }

        int counter = 3;
        string commonFactor = "";
        while (productions[0][counter] == productions[1][counter]) {
            commonFactor += productions[0][counter];
            counter += 1;
        }

        string newProduction1 = lhs + "->" + commonFactor + lhs + "\'";
        for (int i = 2; i < n; i++) {
            newProduction1 += ("|" + productions[i].substr(3));
        }
        cout << newProduction1 << endl;

        string newProduction2 = lhs + "\'->";
        for (int i = 0; i < n; i++) {
            string bar;
            try {
                bar = productions[i].substr(counter);
                if (bar == "") {
                    bar = "ε";
                }
            } catch(...) {
                bar = "";
            }
            
            newProduction2 += (bar + "|");
        }

        cout << newProduction2 << endl;
     }
}