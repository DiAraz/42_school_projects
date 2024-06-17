/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:29:48 by daraz             #+#    #+#             */
/*   Updated: 2024/06/17 12:42:11 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <cstring>
#include <iostream>
#include <fstream>

bool openFiles(std::ifstream &ifs, std::ofstream &ofs, const std::string &inFile, const std::string &outFile) {
    ifs.open(inFile.c_str());
    if (!ifs.is_open()) {
        std::cerr << "Error: " << inFile << ": " << strerror(errno) << std::endl;
        return false;
    }

    ofs.open(outFile.c_str(), std::ofstream::out | std::ofstream::trunc);
    if (!ofs.is_open()) {
        std::cerr << "Error: " << outFile << ": " << strerror(errno) << std::endl;
        ifs.close();
        return false;
    }

    return true;
}

std::string replaceSubstring(const std::string &line, const std::string &toFind, const std::string &toReplace) {
    std::string result;
    size_t pos = 0;
    size_t found = line.find(toFind);

    while (found != std::string::npos) {
        result.append(line, pos, found - pos);
        result.append(toReplace);
        pos = found + toFind.length();
        found = line.find(toFind, pos);
    }
    result.append(line, pos, line.length() - pos);
    return result;
}

bool processAndReplace(std::ifstream &ifs, std::ofstream &ofs, const std::string &toFind, const std::string &toReplace) {
    std::string line;

    while (std::getline(ifs, line)) {
        if (ifs.fail()) {
            return false;
        }

        if (!toFind.empty()) {
            line = replaceSubstring(line, toFind, toReplace);
        }

        ofs << line;
        if (!ifs.eof()) {
            ofs << std::endl;
        }
    }

    return true;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Error: arguments: <filename> <string_to_find> <string_to_replace>" << std::endl;
        return 1;
    }

    std::string inFile = argv[1];
    std::string outFile = inFile + ".replace";
    std::string toFind = argv[2];
    std::string toReplace = argv[3];

    std::ifstream ifs;
    std::ofstream ofs;

    if (!openFiles(ifs, ofs, inFile, outFile)) {
        return 1;
    }

    if (!processAndReplace(ifs, ofs, toFind, toReplace)) {
        ifs.close();
        ofs.close();
        return 1;
    }

    ifs.close();
    ofs.close();
    return 0;
}
