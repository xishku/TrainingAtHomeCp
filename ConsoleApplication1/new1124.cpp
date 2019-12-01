#include "foo.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool isFlag(char ch)
{
    return (ch == '+' || ch == '-');
}

bool isNumber(char ch)
{
    return (ch <= '9' && ch >= '0');
}

bool isPoint(char ch)
{
    return (ch == '.');
}


std::string GetLongestNumberString(const std::string& inputString)
{
    vector<string> resultArray;
    //"1234567890abcd9.+13254.786.9ed"
    for(int i = 0; i < inputString.size(); ++i) {
        string curStr;
        char curCh = inputString.at(i);
        cout << "current pos i: " << curCh << "   pos:"  << i  << endl;
        if(isFlag(curCh) or isNumber(curCh)) {
            int pointNum = 0;
            int strLen = 1;
            int rightPos = i;
            for(int j = i + 1; j < inputString.size(); ++j) {
                char nextCh = inputString.at(j);
                cout << "current pos j: " << nextCh << "   pos:" << j << endl;
                if (isPoint(nextCh)) {
                    cout << "piont pos: " << i << "   "  << j << endl;
                    ++pointNum;
                    if(pointNum > 1){
                        break;
                    }
                } else if(isFlag(nextCh)) {
                    break;
                } else if(!isNumber(nextCh)) {
                    break;
                }

                cout << "rightPos pos: " << j << endl;
                ++strLen;
                rightPos = j;
            }

            if(isPoint(inputString.at(strLen))) {
                //number with flag and end with point, length > 2 means having number
                if(isFlag(curCh) && (strLen - i > 2)) {
                    cout << inputString.substr(i, strLen - 1) << endl;
                    resultArray.push_back(inputString.substr(i, strLen - 1));

                }
            } else {
                    cout << "no point: " << i << "  " << strLen << "    "  <<inputString.substr(i, strLen) << endl;
                    resultArray.push_back(inputString.substr(i, strLen));
            }
            i = rightPos;
        }
    }

    string maxStr;
    int maxLen = 0;

    for(auto it = resultArray.begin(); it != resultArray.end(); ++it) {
        if (it->length() >= maxLen) {
            maxStr = *it;
            maxLen = it->length();
        }
    }

    return maxStr;
}


int add(int a, int b)
{
    return a + b;
}
