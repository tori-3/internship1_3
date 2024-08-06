#pragma once
#include<string>

///@brief 成績と名前を扱うクラスです。
struct Grades
{
    //! スコア
    int score;

    //! 名前
    std::string name;

    bool operator ==(const Grades& right)const
    {
        return (score == right.score) && (name == right.name);
    }

    bool operator !=(const Grades& right)const
    {
        return (score != right.score) || (name != right.name);
    }
};
