#pragma once
#include "Directory.hpp"
#include <iostream>
#include <list>
#include <memory>
#include <string>

void File::remove() { std::cout << _name << " Deleted!" << std::endl; }

void Directory::add(std::shared_ptr<IDirectoryEntry> entry) { _list.push_back(entry); }
void Directory::remove() {
    for (auto &i : _list) {
        i->remove();
    }
    std::cout << _name << " Deleted!" << std::endl;
}

void SymbolicLink::remove() { std::cout << _name << " Deleted!" << std::endl; }
