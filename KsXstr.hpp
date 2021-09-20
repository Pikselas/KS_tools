#include<algorithm>
#include<string>
#include<vector>
namespace ksTools
{
  std::vector<std::string> split(const std::string& str,const std::string& delms)
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
}