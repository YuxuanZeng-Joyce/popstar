#ifndef __H_FILE_MANAGER_H__
#define __H_FILE_MANAGER_H__
#include "hFileManager.h"
#endif

#include "GameLayer.h"

bool GameLayer::init()
{
	if (!Layer::init()) return false;
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto bg = Sprite::create("bg_mainscene.jpg");
	bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(bg, 0);

	this->floatLevelWord();

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this);

	return true;
}


void GameLayer::floatLevelWord()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	_levelMsg = FloatWord::create(
		ChineseWord("guanqia") /*+
		String::createWithFormat(": %d", GAMEDATA::getInstance()->getNextLevel())->_string*/,
		50,
		Vec2(visibleSize.width, visibleSize.height / 3 * 2)
		);
	this->addChild(_levelMsg, 1);
	_levelMsg->floatIn(0.5f, CC_CALLBACK_0(GameLayer::floatTargetScoreWord, this));
	//Audio::getInstance()->playReadyGo();
}
void GameLayer::floatTargetScoreWord()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	_targetScore = FloatWord::create(
		ChineseWord("mubiao")
		//+ String::createWithFormat(": %d", GAMEDATA::getInstance()->getNextScore())->_string
		+ ChineseWord("fen"),
		50,
		Vec2(visibleSize.width, visibleSize.height / 3)
		);
	this->addChild(_targetScore,1);
	_targetScore->floatIn(0.5f, CC_CALLBACK_0(GameLayer::removeFloatWord, this));
}
void GameLayer::removeFloatWord()
{
	_levelMsg->floatOut(0.5f, nullptr);
	_targetScore->floatOut(0.5f, CC_CALLBACK_0(GameLayer::showStarMatrix, this));
}


void GameLayer::showStarMatrix()
{
	matrix = StarMatrix::create(this);
	this->addChild(matrix);
}

void GameLayer::update(float delta)
{
	if (matrix)
	{
		matrix->updateStar(delta);
	}
}


bool GameLayer::onTouchBegan(Touch* touch, Event* event)
{
	Vec2 p = touch->getLocationInView();
	p = Director::getInstance()->convertToGL(p);
	CCLOG("x=%f y=%f", p.x, p.y);
	if (matrix){
		matrix->onTouch(p);
	}
	return true;
}
//
//void refreshMenu();
//void showLinkNum();
//void hideLinkNum();
//void floatLeftStarMsg(int leftNum);
//
//void gotoNextLevel();
//void gotoGameOver();

