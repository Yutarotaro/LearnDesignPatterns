#include <iostream>
#include <memory>
#include "Directory.hpp"

int main(){

    std::shared_ptr<File> file1 = std::make_shared<File>("file1");
    std::shared_ptr<File> file2 = std::make_shared<File>("file2");
    std::shared_ptr<File> file3 = std::make_shared<File>("file3");
    std::shared_ptr<File> file4 = std::make_shared<File>("file4");

    std::shared_ptr<Directory> dir1 = std::make_shared<Directory>("dir1");
    dir1->add(file1);

    std::shared_ptr<Directory> dir2 = std::make_shared<Directory>("dir2");
    dir2->add(file2);
    dir2->add(file3);
    dir1->add(dir2);
    dir1->add(file4);

    dir1->remove();

}