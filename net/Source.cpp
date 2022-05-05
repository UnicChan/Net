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

void realSort(std::string filenameStr) { //�� ������������ ��� �����. ��� �������, ������� ������ �������
                                         //�������� ���� 

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

void childs(std::string path) {         //���������� �� ��������� ������� 'papa', ���� ��������� ����
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

void papa(std::string path) {    //������ ����������, ����� ���������� �����, ����� ������� ������ ����
                                 //(�� 85 ������� �����, ��� � ���� ������������ "����������" ����)
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

void sort(std::string* path) {  //���������� �� ��������� ������� 'start_sort'
    
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

void start_sort(std::string* path) { //���������� ������� ���, ��� ������ ���������� ����

    std::cout << "--��� ������ ��������� '����������'--\n" << "������ �������������? Press'Y' or 'N': ";
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

void example(std::string* path) {     //������������ ������������� ���� ��� ���������, ��� ������ ������� ������
    std::cout << "������������ ��������� (Press any key) ��� ������ ���� ����? (press 0): ";
    char c;
    std::cin >> c;
    if (c != '0') {
        (*path) = "C:\\Users\\�������\\Desktop\\kermit";
        std::cout << "\n";
    }
    else {
        std::cout << "����: ";
        std::cin >> (*path);
    }
}

int main() {
    SetConsoleCP(1251);          //����� � ������� ������� ����� ���������
    SetConsoleOutputCP(1251);

    std::string path;
    //path = "C:\\Users\\�������\\Desktop\\kermit";
    example(&path);          //������, ���� ������� ���� 
    papa(path);              //������������� ����� � ������
    std::cout << "\n\n";
    start_sort(&path);       //�������� ������� �� "���������" 
    std::cout << "\n\n";
    return 0;
}