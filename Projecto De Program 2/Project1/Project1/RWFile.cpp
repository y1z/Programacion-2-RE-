#include "RWFile.hpp"

#include <fstream>
#include <stdexcept>

void readNamesFromFile(const char *path, std::vector<Name> &names)
{

    std::ifstream infile(path);
    if (!infile)
    {
        throw std::runtime_error("Error opening file.");
    }
    std::string line;
    while (std::getline(infile, line))
    {
        names.push_back(Name(line));
    }

    infile.close();
}

void writeNamesToFile(const char *path, std::vector<Name> &names)
{
    std::ofstream outfile(path);
    if (!outfile)
    {
        throw std::runtime_error("Error opening file.");
    }

    for (int i = 0; i < names.size(); i++)
    {
        if (i > 0)
        {
            outfile << "\n";
        }
        outfile << names[i];
    }

    outfile.close();
}