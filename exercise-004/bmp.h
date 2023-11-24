#ifndef WORKSPACES_TEA21_EXERCISE_004_BMP_H
#define WORKSPACES_TEA21_EXERCISE_004_BMP_H

#include <string>

class BMP {
    bool read(const std::string&  filename);
    bool write(const std::string&  filename);
};
#endif