#ifndef __H_FILE_MANAGER_H__
#define __H_FILE_MANAGER_H__
#include "hFileManager.h"
#endif

#ifndef _CHINESE_WORD_H_  
#define _CHINESE_WORD_H_

static ValueVector txt_vec = FileUtils::getInstance()->getValueVectorFromFile("ChineseWords.xml");

string ChineseWord(const char* wordId);

#endif // _CHINESE_WORD_H_