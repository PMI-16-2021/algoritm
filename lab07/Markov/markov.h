#pragma once
#include "String.h"
#include <vector>

String MarkovAlgorithm(std::vector<std::pair<String,String>>rules, String string);
