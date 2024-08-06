#include"Grades.h"
#include"List.h"
#include<iostream>
#include<string>
#include<fstream>
#include<sstream> 

int main()
{
    //�e�X�g�R�[�h
    List<Grades> list;

    std::ifstream file;
    std::string line;

    file.open("Scores.txt", std::ios::in);

    //��s���ǂݍ���
    while (std::getline(file, line))
    {
        Grades grades;

        //�^�u�ŋ�؂�A���X�g�ɒǉ�����B
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
