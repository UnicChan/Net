#include <iostream>
#include <vector>
#include <filesystem>
#include <Windows.h>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

namespace fs = std::filesystem;
int space;

void realSort(std::string filenameStr) {

    std::string tabul;
    int s = filenameStr.size();
    for (int i = 0; i < s; i++) {
        if (filenameStr[i] == '\\') {
            std::cout << '\n';
            tabul = tabul + ' ' + ' ';
            std::cout << tabul;
            space++;
        }
        std::cout << filenameStr[i];
    }
    std::cout << "\n";
}

void papa(std::string path) {           //should be called when a folder is found to output the full path
    fs::path fsPath = fs::path(path);   //(the 85th line shows that I want to use the "sort" of the path)

    for (const auto& entry : fs::directory_iterator(fsPath)) {
        const auto filenameStrPapa = entry.path().string();
        const auto filenameStrChild = entry.path().filename().string();
        if (entry.is_directory()) {
            SetConsoleTextAttribute(hConsole, 3);
            realSort(filenameStrPapa);              //dir:  9 3 1 11
            papa(filenameStrPapa);
            space = 0;
        }
        else if (entry.is_regular_file()) {
            SetConsoleTextAttribute(hConsole, 11);
            for (int i = 0; i < space+2; i++) {
                std::cout << " ";
            }
            std::cout << "--" << filenameStrChild << '\n';  //file:
        }
        else
            //SetConsoleTextAttribute(hConsole, 4);
            std::cout << "??    " << filenameStrChild << '\n';
    }
}

void open(std::string* path) {     
    
    std::cout << "\nPattern: ' Z:\\for\\example ' \n";
    std::cout << "Folder: ";
    std::cin >> (*path);
    std::cout << "\n\n";
}

int main() {
    SetConsoleCP(1251);          //for Rus language in cmd
    SetConsoleOutputCP(1251);

    SetConsoleTextAttribute(hConsole, 14);
    std::string path;
    open(&path);          //folder enter
    papa(path);              //exploring folders and files

    SetConsoleTextAttribute(hConsole, 14);
    return 0;
}