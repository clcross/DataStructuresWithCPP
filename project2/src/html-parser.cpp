#include "html-parser.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

HTMLParser::HTMLParser(){
	htmlTags = std::vector<std::string>();
	fileVector = std::vector<fileNode>();
}

void HTMLParser::parse(std::string filename){
	fileNode tempVisit = fileNode(filename);
    fileVector.push_back(tempVisit);

    std::string tag = "";
    bool isBal = true;

    std::ifstream fileIn;
    fileIn.open(filename.c_str());

	if(!fileIn){
		fileVector.at(fileVector.size() - 1).set_isBal(false);
		return;
	}

    while(fileIn.peek() != EOF){
		tag = "";

		if(fileIn.peek() == '<'){
			fileIn.get();

			if(fileIn.peek() == '/'){
				if(htmlTags.size() == 0){
					isBal = false;
					break;
				}
				fileIn.get();

				while(fileIn.peek() != '>'){
					tag += fileIn.get();
				}
				fileIn.get();
				if(htmlTags.at(htmlTags.size() - 1) == tag){
					htmlTags.pop_back();
				}
				else{
					isBal = false;
					break;
				}
			}
			else if(fileIn.peek() == 'a'){
				tag += fileIn.get();

				if(fileIn.peek() == ' '){
					tag = "";
					htmlTags.push_back("a");
					fileIn.ignore(5, '=');

					while(fileIn.peek() != '>'){
						tag += fileIn.get();
					}

					std::string urlTag = tag.substr(0);

					// makes it work for mac and linux
					int hasEqual = urlTag.find("=");
					if(hasEqual != std::string::npos){
						urlTag = tag.substr(1);
					}

					fileVector.at(fileVector.size() - 1).set_mUrl(urlTag);

					fileIn.get();

					fileVector.at(fileVector.size() - 1).set_visitCount(1);
				}
				else{
					while(fileIn.peek() != '>'){
						tag += fileIn.get();
					}
					fileIn.get();
					htmlTags.push_back(tag);
				}
			}
			else{
				while(fileIn.peek() != '>'){
					tag += fileIn.get();
				}

				fileIn.get();
				htmlTags.push_back(tag);
			}
		}
		else{
			fileIn.get();
		}
	}

	fileVector.at(fileVector.size() - 1).set_isBal(isBal);


	if(!isBal){
		fileVector.at(fileVector.size() - 1).set_visitCount(0);
	}

	fileIn.close();
}

int HTMLParser::indexOf(std::string filename, std::vector<fileNode> rover){
    int location = 0;
    bool hasNum = false;
    for(int i = 0; i < rover.size(); i++){ 
        if(rover.at(i).get_mFileName() == filename){
            location = i;
            hasNum = true;
        }
    }
    if(hasNum == true){
        return location;
    }
    else{
        return -1;
    }
}

bool HTMLParser::isBalanced(std::string filename){
    if(fileVector.size() == 0){
		return false;
    }

	int temp = indexOf(filename, fileVector);
	if(temp > -1){
		return fileVector.at(temp).get_isBal();
	}
	else{
		return false;
	}
}

int HTMLParser::pageVisitAmount(std::string filename){
    if(fileVector.size() == 0){
		return 0;
    }

	int index = indexOf(filename, fileVector);

	if(index == -1){
		fileVector.at(index).set_visitCount(0);
		return fileVector.at(index).get_visitCount();
	}
    else if(fileVector.at(index).get_visitCount() == 0){
		fileVector.at(index).set_visitCount(0);
		return fileVector.at(index).get_visitCount();
    }

	std::string url = fileVector.at(index).get_mUrl();
	int urlIndex = indexOf(url, fileVector);

	if(urlIndex == -1){
		fileVector.at(index).set_visitCount(0);
		return fileVector.at(index).get_visitCount();
	}

	bool hasNext = true;

    // DPW: This only goes down one path.  It does not take into account multiple anchor tags.
	while(hasNext){
		if(fileVector.at(urlIndex).get_visitCount() > 0){
			fileVector.at(index).set_visitCount(fileVector.at(index).get_visitCount() + 1);
			url = fileVector.at(urlIndex).get_mUrl();
			urlIndex = indexOf(url, fileVector);
		}
		else{
			hasNext = false;
		}
	}

    return fileVector.at(index).get_visitCount();
}

HTMLParser::~HTMLParser(){
	std::vector<std::string>().swap(htmlTags);
	std::vector<fileNode>().swap(fileVector);
}
