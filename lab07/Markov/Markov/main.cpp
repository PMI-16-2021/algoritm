#include "StringM.h"

#include <vector>
#include <iostream>


int main() {
    String str("11");
    std::vector<std::pair<String, String>> NAM = { { "x0","0x" }, { "x1","1x" }, { "x","y" }, { "0y",".1" }, { "1y","y0" }, { "y",".1" }, { "","x" } };
    str.MarkovAlgorithm(NAM);
    std::cout << str.getStr();
}
//{"x0","0x"},{"x1","1x"},{"x","y"},{"0y",".1"},{"1y","y0"},{"y",".1"}, {"","x"}

//{ {"1",  "0|"},
//{"|0", "0||"},
//                                                  { "0",  "" } };