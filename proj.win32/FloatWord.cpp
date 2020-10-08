#ifndef __H_FILE_MANAGER_H__
#define __H_FILE_MANAGER_H__
#include "hFileManager.h"
#endif

#include "FloatWord.h"

FloatWord* FloatWord::create(
	const std::string& word,
	const int fontSize,
	Vec2 begin)
{
	auto ret = new FloatWord();
	if (ret && ret->init(word, fontSize, begin))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}


bool FloatWord::init(
	const std::string& word,
	const int fontSize,
	Vec2 begin)
{
	if (!Node::init()) return false;

	_begin = begin;
	auto visibleSize = Director::getInstance()->getVisibleSize();

	_label = Label::create(word, "Verdana-Blod", fontSize);
	_label->setPosition(begin);
	this->addChild(_label);

	return true;
}


void FloatWord::floatIn(
	const float delay,
	std::function<void()>callback
	)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	
	auto move = MoveTo::create(delay, Vec2(visibleSize.width / 2, _begin.y));
	auto call = CallFunc::create(callback);
	
	auto action = Sequence::create(move, call, NULL);
	_label->runAction(action);
}


void FloatWord::floatOut(
	const float delay,
	std::function<void()>callback
	)
{
	auto visiblesize = Director::getInstance()->getVisibleSize();
	
	auto move = MoveTo::create(delay, Vec2(0, _begin.y));
	auto call = CallFunc::create(callback);
	auto removeC = CallFunc::create([this]{
		this->removeFromParentAndCleanup(true);
	});
	
	auto action = Sequence::create(move, call, removeC, NULL);
	_label->runAction(action);
}


void FloatWord::floatInOut(
	const float speed,
	const float delayTime,
	std::function<void()>callback)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	
	auto moveIn = MoveTo::create(speed, Vec2(visibleSize.width / 2, _begin.y));
	auto moveOut = MoveTo::create(speed, Vec2(0, _begin.y));
	auto removeC = CallFunc::create([this]{
		this->removeFromParentAndCleanup(true);
	});

	auto action = Sequence::create(
		moveIn,
		DelayTime::create(delayTime),
		moveOut,
		removeC,
		CallFunc::create(callback),
		NULL);
	_label->runAction(action);
}
