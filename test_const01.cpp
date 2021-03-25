#include <iostream>
#include <string.h>
using namespace std;

class TextBlock
{
public:
    const char& operator[](size_t position) const
    {
        if(position >= length())
            return NULL;
        //边界检验
        //志记数据访问
        //检验数据完整性
        return pText[position];
    }
    char& operator[](size_t position)
    {
        return 
            const_cast<char&>(static_cast<const TextBlock&>(*this)[position]);
    }
    size_t length() const;
private:
    char* pText;
    mutable size_t textLength;
    mutable bool lengthIsValid;
};
size_t TextBlock::length() const
{
    if(!lengthIsValid)
    {
        textLength = strlen(pText);
        lengthIsValid = true;
    }
    return textLength;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

