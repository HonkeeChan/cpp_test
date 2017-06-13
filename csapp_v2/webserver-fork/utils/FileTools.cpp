/*
 * FileTools.cpp
 *
 *  Created on: 2017年2月10日
 *      Author: honkee
 */

#include "FileTools.h"
#include "TimeTools.h"
// #include <boost/filesystem.hpp> 
// #include <boost/algorithm/string.hpp>
#include <sys/stat.h>
#include <sys/types.h>
#include <vector>

namespace utils {

FileTools::FileTools() {
	// TODO Auto-generated constructor stub
}

FileTools::~FileTools() {
	// TODO Auto-generated destructor stub
}

int FileTools::mkdirp(string path){
	// namespace fs = boost::filesystem;
	// std::vector<std::string> vecs;
	// boost::split(vecs, path, boost::is_any_of("/")); 
	// string curPath;
	// if(vecs[0].length() == 0){
	// 	curPath += "/";
	// 	vecs.erase(vecs.begin());
	// }
	// for(auto it : vecs){
	// 	curPath += it + "/";
	// 	fs::create_directory(curPath);
	// }

	// return 0;
}

string FileTools::getFileModifyTimeLinux(string filePath){
	struct stat attrib;
	stat(filePath.c_str(), &attrib);
	return utils::TimeTools::getGMTime(attrib.st_ctime);
    
}

bool FileTools::isFileExist(string filePath){
	//return boost::filesystem::exists( filePath );
}

} /* namespace utils */
