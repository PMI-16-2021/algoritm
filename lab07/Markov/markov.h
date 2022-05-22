#pragma once
#include "String.h"
#include <vector>

String MarkovAlgoritm(std::vector<std::pair<String,String>> productions, String string);