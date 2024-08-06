#include"Grades.h"
#include"List.h"
#include<iostream>
#include<string>
#include<fstream>
#include<sstream> 

int main()
{
    //テストコード
    List<Grades> list;

    std::ifstream file;
    std::string line;

    file.open("Scores.txt", std::ios::in);

    //一行ずつ読み込む
    while (std::getline(file, line))
    {
        Grades grades;

        //タブで区切り、リストに追加する。
        std::string temp;
        std::stringstream ss{ line };
        std::getline(ss, temp, '\t');
        grades.score = atoi(temp.c_str());
        std::getline(ss, temp, '\t');
        grades.name = temp;

        list.add(grades);
    }

    for (auto it = list.constBegin(); it != list.constEnd(); ++it)
    {
        std::cout << (*it).score << "\t" << (*it).name << std::endl;
    }
}
