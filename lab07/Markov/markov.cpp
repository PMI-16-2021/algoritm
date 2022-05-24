#include "markov.h"

String MarkovAlgorithm(std::vector<std::pair<String,String>>rules, String string) {
    String ret_str = string;
    size_t string_len = string.Length(); // for checking if replacement was accomplished
    std::vector<std::pair<String,String>>::iterator it = rules.begin();
    while(it != rules.end()) {
        size_t check = ret_str.Find(it->first);
        if(check != ret_str.Length()+1){  // if rule appropriate - replace, or go to the next rule
            ret_str.Replace(check,check+it->first.Length(), it->second);
            if(ret_str.Length() == (string_len- ((check+it->first.Length()) - check) + it->second.Length())){
                //length_ - (to - from) + other.length_
                string_len = ret_str.Length();
                it = rules.begin();
            }
            else {
                it++;
            }
        }
        else{
            it++;
        }
    }
    return ret_str;
}