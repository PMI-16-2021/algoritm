#include "markov.h"

String MarkovAlgoritm(std::vector<std::pair<String,String>> productions, String string) {
    for(int i = 0; i < productions.size(); i++) {
        size_t marker = string.Find(productions[i].first);
        while(marker < string.Length()) {  // while substrings exists - replacing
            string.Replace(marker, marker+productions[i].first.Length(), productions[i].second);
            marker = string.Find(productions[i].first);;
        }
    }
    return string;
}