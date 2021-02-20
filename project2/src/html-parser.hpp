#ifndef HTML_PARSER_HPP
#define HTML_PARSER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class fileNode {
    private:
        int visitCount;
        bool isBal;
        std::string mFileName;
        std::string mUrl;
    public:
        fileNode(std::string filename){
            isBal = false;
            visitCount = 0;
            mFileName = filename;
            mUrl = "";
        };

        void set_visitCount(int num){
            visitCount = num;
        };

        int get_visitCount(){
            return visitCount;
        };

        std::string get_mFileName(){
            return mFileName;
        };

        void set_mUrl(std::string url){
            mUrl = url;
        };

        std::string get_mUrl(){
            return mUrl;
        };

        void set_isBal(bool bal){
            isBal = bal;
        };

        bool get_isBal(){
            return isBal;
        };
};

class HTMLParser {
    private:
        std::vector<std::string> htmlTags;
        std::vector<fileNode> fileVector;
    public:
        HTMLParser();
        ~HTMLParser();
        void parse(std::string filename);
        bool isBalanced(std::string filename);
        int pageVisitAmount(std::string filename);
        int indexOf(std::string filename, std::vector<fileNode> rover);
};

#endif
