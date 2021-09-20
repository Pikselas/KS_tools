#pragma once
#include<algorithm>
#include<string>
#include<vector>
namespace ksTools
{
  std::vector<std::string> split_by_delms(const std::string& str,const std::string& delms)
  {
    std::vector<std::string> LIST;
    auto flaggedIterStart = str.begin();
    auto flaggedIterEnd = std::find_first_of(str.begin(),str.end(),delms.begin(),delms.end());
    while(flaggedIterEnd != str.end())
    {
        std::string tempHolder;
        if(std::distance(flaggedIterStart,flaggedIterEnd) != 0)
        {
            std::for_each(flaggedIterStart,flaggedIterEnd,[&](const char& chr){
            tempHolder.push_back(chr);
            });
            LIST.emplace_back(tempHolder);
        }
        flaggedIterStart = flaggedIterEnd + 1;
        flaggedIterEnd = std::find_first_of(flaggedIterStart,str.end(),delms.begin(),delms.end());
    }
   if(std::distance(flaggedIterStart,flaggedIterEnd) != 0)
   {
        std::string tmp;
        std::for_each(flaggedIterStart,flaggedIterEnd,[&](const char& chr){
            tmp.push_back(chr);
        });
        LIST.emplace_back(tmp);
   }
   return LIST;
 }
 std::vector<std::string> split_by_word(const std::string& str, const std::string& word)
 {
   std::vector<std::string> LIST;
   auto FlaggedItrFirst = str.begin();
   auto FlaggedItrLast = FlaggedItrFirst;
   int word_length = std::distance(word.begin(),word.end()); 
   while(true)
   {
     FlaggedItrLast = std::search(FlaggedItrFirst,str.end(),word.begin(),word.end());
     if(FlaggedItrLast != str.end())
     {
       if(std::distance(FlaggedItrFirst,FlaggedItrLast) != 0)
       {
       std::string tmp;
       std::for_each(FlaggedItrFirst,FlaggedItrLast,[&](const char c){
         tmp.push_back(c);
       });
       LIST.emplace_back(tmp);
       }
       FlaggedItrFirst = FlaggedItrLast + word_length;
     }
     else
     {
       break;
     }
   }
   std::string tmp;
   std::for_each(FlaggedItrFirst,str.end(),[&](const char c){
     tmp.push_back(c);
   });
   LIST.emplace_back(tmp);
   return LIST;
 }
 std::vector<std::string> split_by_words(const std::string& str, const std::vector<std::string>& words)
 {
   std::vector<std::string> LIST;
    
   return LIST;
 }
}