#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <deque>
using namespace std;

int main() {

vector <int> num;
vector <string> op;
deque <string> result;

    while(!cin.eof()) {
        string cItem;
        cin >> cItem;

        if (cItem == "")
            break;

        if(cItem == "+" || cItem == "-" || cItem == "*" || cItem == "/") {
            op.push_back(cItem);
        }
        else if (isdigit(cItem[0])) { 
            num.push_back(stoi(cItem));
        }
        else{
            cout << "Error"<< endl;
            return -1;
        }

    }

    if(op.size() != num.size() - 1) { 
            cout << "Error" << endl;
            return -1;
    }

    int counter;
    int integer_result = num.front();

    result.push_front(to_string(num[0]));

    for(int i = op.size()-1, j = 1; i >= 0; i--, j++) {

        if((op[i] == "*" || op[i] == "/")){

            if (counter > 0) {
                result.push_back(")");
                result.push_front("(");
                counter = 0;
            }

            if (op[i] == "*"){
                integer_result *= num[j];
            }
            else if (op[i] == "/"){
                integer_result /= num[j];
            }
        }

        else if(op[i] == "+" || op[i] == "-") {
            counter ++;

            if (op[i] == "+"){
                integer_result += num[j];
            }
            else if (op[i] == "-"){
                integer_result -= num[j];
            }
        }
        
        result.push_back(op[i]);
        result.push_back(to_string(num[j]));
        
    }

string h;

    for(int i = 0; i < result.size(); i++) {

        if(result[i] == "+")
            h+= " " + result[i] + " ";

        else if(result[i] == "-")
            h+= " " + result[i] + " ";
        
        else if(result[i] == "*")
            h+= " " + result[i] + " ";
        
        else if(result[i] == "/")
            h+= " " + result[i] + " ";

        else {h += result[i];}
    }



std::cout << h << " =" << " " << integer_result;

}