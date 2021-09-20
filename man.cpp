#include<iostream>
#include"KsXstr.hpp"
int main()
{
    auto x = ksTools::split_by_word("helloXPlkXPomg","XP");
    for(auto cx:x)
    {
        std::cout<<cx<<std::endl;
    }
    return 0;
}