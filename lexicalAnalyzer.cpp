#include <iostream>
#include <fstream>
#include <map>
using namespace std;

map <string, string> constructTable() {
    string delimiters[] = {" ", "\n", ",", ";", "+", "-", "*", "/", "%", "=", "<", ">", "(", ")", "[", "]", "{", "}"};
    string operators[] = {"+", "-", "*", "/", "%", "=", "<", ">"};
    string keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", 
    "do", "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while",
    "double", "else", "enum", "extern",
    "float", "for", "goto", "if", "main", "scanf", "printf"};

    map <string, string> token2id;
    for (int i = 0; i < sizeof(delimiters)/sizeof(delimiters[0]); i++) {
        token2id[delimiters[i]] = "delimiter";
    }
    for (int i = 0; i < sizeof(operators)/sizeof(operators[0]); i++) {
        token2id[operators[i]] = "operator";
    }
    for (int i = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++) {
        token2id[keywords[i]] = "keyword";
    }
    return token2id;
}

string getString(char x) {
    // get the string for a char
    string s(1, x);
    return s;
}

bool isNumber(string foo) {
    // try converting a string to number
    char *p;
    strtol(foo.c_str(), &p, 10);
    return *p == 0;
}

int main() {
    ifstream program;
    program.open("sample.c");

    map <string, string> table = constructTable();

    char c;
    char token[100];
    int counter = 0;

    while (program >> noskipws >> c) {
        if (table[getString(c)].compare("delimiter") == 0) {
            token[counter] = '\0';

            if (string(token).compare("") != 0) {
                string verdict = table[string(token)];

                if (verdict.length() == 0) {

                    if (token[0] == '"') {
                        verdict = "string";
                    } else if(isNumber(string(token))) {
                        verdict = "number";
                    } else {
                        verdict = "identifier"; 
                    }
                }

                cout << token << " " << verdict << endl;
            }
            
            counter = 0;
        } else {
            token[counter++] = c;
        }
    }

    return 0;
}