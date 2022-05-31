#include<iostream>
#include"Markov.h"
int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "usage:\n " << argv[0] << " rulefile text\n";
        return EXIT_FAILURE;
    }

    std::ifstream rulefile(argv[1]);
    std::vector<rule> rules = read_rules(rulefile);

    std::string input(argv[2]);
    std::string output = markov(rules, input);

    std::cout << output << "\n";
}