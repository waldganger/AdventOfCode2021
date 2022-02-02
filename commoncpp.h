#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> splitString(const std::string& str, std::string delimiter);
std::vector<std::string> readFile(const char* path);