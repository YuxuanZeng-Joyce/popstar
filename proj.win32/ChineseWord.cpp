#ifndef __H_FILE_MANAGER_H__
#define __H_FILE_MANAGER_H__
#include "hFileManager.h"
#endif

#include "ChineseWord.h"  

string ChineseWord(const char* wordId)
{
	auto txt_map = txt_vec.at(0).asValueMap();
	string ret = txt_map.at(wordId).asString();
	return ret;
}