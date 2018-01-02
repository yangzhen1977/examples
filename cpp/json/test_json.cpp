// Example program
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <regex>

#include <json/json.h>

//https://open-source-parsers.github.io/jsoncpp-docs/doxygen/index.html

int test_json1(int argc, char* argv[])
{
    Json::CharReaderBuilder rbuilder;
    rbuilder["collectComments"] = false;

    std::string errs;
    std::string str = "{\"1\":\"2\"}";
    std::stringstream ss;
    ss << str;
    ss.flush();

    Json::Value root;
    bool ok = Json::parseFromStream(rbuilder, ss, &root, &errs);
    if(!ok){
        std::cerr << "test_json1 failed, errs is " << errs << std::endl;
    }
    return 0;
}

int test_json2(int argc, char *argv[])
{
    Json::CharReaderBuilder rbuilder;
    rbuilder["collectComments"] = false;

    std::string str = "{\"1\":\"2\"}";
    Json::Value root;

    Json::CharReaderBuilder builder;
    Json::CharReader *reader = builder.newCharReader();
    std::string errs;
    bool ok = reader->parse(str.c_str(), str.c_str() + str.length() +1, &root, &errs);
    if(!ok){
        std::cerr << errs << std::endl;
    }
    assert(ok);
    delete(reader);
    return 0;
}
int main(int argc, char *argv[])
{
    test_json1(argc, argv);
    test_json2(argc, argv);
    return 0;
}
