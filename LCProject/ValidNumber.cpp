/******************************************************************************
 * Question: #65 Valid Number
 * company tag: LinkedIn
 * Validate if a given string is numeric.
 Some examples:
 "0" => true
 " 0.1 " => true
 "abc" => false
 "1 a" => false
 "2e10" => true
 * Note: It is intended for the problem statement to be ambiguous. You should gather all
 * requirements up front before implementing one.
*****************************************************************************/

#include <string>

// DFA : Determinstic finite automaton

using namespace std;
bool isNumber(string s) {
    enum state {SPACE, SIGN, NUM, EXP, EXP_NUM, EXP_SIGN, DOT, NUM_SPACE, NUM_DOT, DOT_NUM};
    int len = s.length(), i = 0;
    int state = SPACE;
    while(i < len)
    {
        char curr = s[i++];
        switch(state)
        {
            case SPACE:
                if(curr == ' ') state = SPACE;
                else if(curr == '+' || curr == '-') state = SIGN;
                else if(curr <= '9' && curr >= '0') state = NUM;
                else if(curr == '.') state = DOT;
                else return false;
                break;
            case SIGN:
                if(curr <= '9' && curr >= '0') state = NUM;
                else if(curr == '.') state = DOT;
                else return false;
                break;
            case NUM:
                if(curr == '.') state = NUM_DOT;
                else if(curr <= '9' && curr >= '0') state = NUM;
                else if(curr == 'e') state = EXP;
                else if(curr == ' ') state = NUM_SPACE;
                else return false;
                break;
            case EXP:
                if(curr == '+' || curr == '-') state = EXP_SIGN;
                else if(curr <= '9' && curr >= '0') state = EXP_NUM;
                else return false;
                break;
            case NUM_DOT:
                if(curr <= '9' && curr >= '0') state = DOT_NUM;
                else if(curr == ' ') state = NUM_SPACE;
                else if(curr == 'e') state = EXP;
                else return false;
                break;
            case DOT:
                if(curr <= '9' && curr >= '0') state = DOT_NUM;
                else return false;
                break;
            case DOT_NUM:
                if(curr <= '9' && curr >= '0') state = DOT_NUM;
                else if(curr == ' ') state = NUM_SPACE;
                else if(curr == 'e') state = EXP;
                else return false;
                break;
            case EXP_NUM:
                if(curr <= '9' && curr >= '0') state = EXP_NUM;
                else if(curr == ' ') state = NUM_SPACE;
                else return false;
                break;
            case EXP_SIGN:
                if(curr <= '9' && curr >= '0') state = EXP_NUM;
                else return false;
                break;
            case NUM_SPACE:
                if(curr == ' ') state = NUM_SPACE;
                else return false;
                break;
            default:
                return false;
                break;
        }
    }
    if(state == NUM || state == EXP_NUM || state == DOT_NUM || state == NUM_DOT || state == NUM_SPACE) return true;
    return false;
}
