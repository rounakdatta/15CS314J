#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

struct production {
    string lhs;
    vector <string> rhs;
};

struct leadStruct {
    string lhs;
    vector <char> rhs;
};

string getString(char x) {
    string s(1, x);
    return s;
}

int main() {
    int n;
    cout << "Enter the no. of productions: ";
    cin >> n;

    vector <production> productions;

    cout << "\nEnter the productions: ";
    for (int i = 0; i < n; i++) {
        string prod;
        cin >> prod;

        string lhs = prod.substr(0, 1);
        string rhs = prod.substr(3);

        production newp;
        newp.lhs = lhs;

        string placeholder = "";
        for (int j = 0; j < rhs.length(); j++) {
            if (rhs[j] != '|') {
                placeholder = placeholder + rhs[j];
            } else {
                newp.rhs.push_back(placeholder);
                cout << placeholder << endl;
                placeholder = "";
            }
        }

        if (placeholder != "") {
            newp.rhs.push_back(placeholder);
        }

        productions.push_back(newp);
    }

    vector <leadStruct> leadVector;

    for (int i = 0; i < n; i++) {
        production curr = productions[i];
        leadStruct news;
        news.lhs = curr.lhs;

        for (vector <string>::iterator p = curr.rhs.begin(); p != curr.rhs.end(); p++) {
            string payload = *p;
            int counter = 0;
            bool terminalFound = false;
            while (!terminalFound) {
                if (!isupper(payload[counter])) {
                    // terminal found
                    news.rhs.push_back(payload[counter]);
                    terminalFound = true;
                } else {
                    // non-terminal => add the lead of that to the current
                    leadStruct otherLead;
                    for (int k = 0; k < leadVector.size(); k++) {
                        if (leadVector[k].lhs == getString(payload[counter])) {
                            otherLead = leadVector[k];
                        }
                    }

                    for (int k = 0; k < otherLead.rhs.size(); k++) {
                        news.rhs.push_back(otherLead.rhs[k]);
                    }
                    terminalFound = true;
                }
            }
        }

        leadVector.push_back(news);

        cout << "\nLEAD [" << news.lhs << "] = ";
        for (vector <char>::iterator p = news.rhs.begin(); p != news.rhs.end(); p++) {
            cout << *p;
        }
        cout << endl;
    }
 
    return 0;
}