#include "strblob.h"

using std::string;

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>> (il)) {}

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

//const版本
const string& StrBlob::front() const
{
    check(0, "front on empty StrBlob.");
    return data->front();
}

string& StrBlob::front() 
{
    //如果vector为空，check会抛出一个异常
    check(0, "front on empty StrBlob.");
    return data->front();
}

const string& StrBlob::back() const
{
    check(0, "back on empty StrBlob.");
    return data->back();
}

string& StrBlob::back()
{
    check(0, "back on empty StrBlob.");
    return data->back();
}


