#include <iostream>
#include <vector>
#include <filesystem>
#include <Windows.h>


namespace fs = std::filesystem;

/*void childs(std::string path) {
    fs::path fsPath = fs::path(path);

    for (const auto& entry : fs::directory_iterator(fsPath)) {
        //       const auto filenameStr = entry.path().filename().string();
        const auto filenameStr = entry.path().string();
        if (entry.is_directory()) {
            std::cout << "dir:  " << filenameStr << '\n';
            childs(filenameStr);
        }
        else if (entry.is_regular_file()) {
            std::cout << "\t";
            std::cout << "file: " << filenameStr << '\n';
        }
        else
            std::cout << "??    " << filenameStr << '\n';
    }

}*/

/*void dfs(Node* a) {

	cout << a->data;

	for (auto el : a->v)
	{
		dfs(el);
	}
}
*/

void realSort(std::string filenameStr) { //dont using. function,  that should output the path beautifully

    std::string tabul;
    int s = filenameStr.size();
    for (int i = 0; i < s; i++) {

        if (filenameStr[i] == '\\') {
            std::cout << '\n';
            tabul = tabul + ' ' + ' ';
            std::cout << tabul;
        }

        std::cout << filenameStr[i];
    }
}

void childs(std::string path) {         //using by next function 'papa', if a file was detected
    fs::path fsPath = fs::path(path);

    for (const auto& entry : fs::directory_iterator(fsPath)) {
        //       const auto filenameStr = entry.path().filename().string();
        const auto filenameStr = entry.path().filename().string();
        if (entry.is_directory()) {
            std::cout << filenameStr << '\n';  //dir:
            childs(filenameStr);
        }
        else if (entry.is_regular_file()) {
            std::cout << "\t";
            std::cout << filenameStr << '\n';  //file:
        }
        else
            std::cout << "??    " << filenameStr << '\n';
    }

}

void papa(std::string path) {    //should be called when a folder is found to output the full path
                                 //(the 85th line shows that I want to use the "sort" of the path)
    fs::path fsPath = fs::path(path);

    for (const auto& entry : fs::directory_iterator(fsPath)) {
 //     const auto filenameStr = entry.path().filename().string();
        const auto filenameStr = entry.path().string();
        if (entry.is_directory()) {
            std::cout << filenameStr << '\n';  //dir:
            //realSort(filenameStr);
            childs(filenameStr);
        }
        else if (entry.is_regular_file()) {
            std::cout << "\t";
            std::cout << filenameStr << '\n';  //file:
            //childs(filenameStr);
        }
        else
            std::cout << "??    " << filenameStr << '\n';
    }

}

void sort(std::string* path) {  //called by next function 'start_sort'
    
    //std::cout << "Put namespace: ";
    //std::string path;
    //std::cin >> path;
    //std::cout << "\n";

    std::string tabul;
    int s = (*path).size();
    for (int i = 0; i < s; i++) {

        if ((*path)[i] == '\\') {
            std::cout << '\n';
            tabul = tabul + ' ' + ' ';
            std::cout << tabul;
        }

        std::cout << (*path)[i];
    }
}

void start_sort(std::string* path) { //I tried to do it the way the path should be output

    std::cout << "--как должна выглядеть 'сортировка'--\n" << "do you want to sort? Press'Y' or 'N': ";
    char c;
    std::cin >> c;
    std::cout << "\n";

    if (c == 'y' or c == 'Y') {
        sort(&(*path));
        return;
    }
    if (c == 'n' or c == 'N') {
        std::cout << "Kk";
    }
    else {
        std::cout << "\n!!!! ONLY 'Y' OR 'N'!!!!\n\n";
        start_sort(&(*path));
    }
}

void example(std::string* path) {     
    std::cout << "Use blank (Press any key) or conduct manually? (press 0): ";
    char c;
    std::cin >> c;
    if (c != '0') {
        (*path) = "C:\\Users\\Алексей\\Desktop\\kermit";
        std::cout << "\n";
    }
    else {
        std::cout << "Folder: ";
        std::cin >> (*path);
    }
}

int main() {
    SetConsoleCP(1251);          //for Rus language in cmd
    SetConsoleOutputCP(1251);

    std::string path;
    //path = "C:\\Users\\Алексей\\Desktop\\kermit";
    example(&path);          //folder enter
    papa(path);              //exploring folders and files
    std::cout << "\n\n";
    start_sort(&path);       //test functions for "cosmetics"
    std::cout << "\n\n";
    return 0;
}