#pragma once

#include <vector>
#include "Name.hpp"

void readNamesFromFile(const char *, std::vector<Name>&);

void writeNamesToFile(const char *, std::vector<Name>&);