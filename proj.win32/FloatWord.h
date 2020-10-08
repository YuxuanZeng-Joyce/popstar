#ifndef __H_FILE_MANAGER_H__
#define __H_FILE_MANAGER_H__
#include "hFileManager.h"
#endif

#ifndef __FLOAT_WORD_H__
#define __FLOAT_WORD_H__

class FloatWord : public Node
{
public:
	static FloatWord* create(
		const string& word,
		const int fontSize,
		Vec2 begin);
	bool init(
		const string& word,
		const int fontSize,
		Vec2 begin);

	void floatIn(
		const float delay,
		function<void()>callback
		);
	void floatOut(
		const float delay,
		function<void()>callback
		);
	void floatInOut(
		const float speed,
		const float delayTime,
		function<void()>callback);

private:
	int _fontSize;
	Vec2 _begin;
	Label* _label;

};

#endif // __FLOAT_WORD_H__
