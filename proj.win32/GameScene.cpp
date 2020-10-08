#ifndef __H_FILE_MANAGER_H__
#define __H_FILE_MANAGER_H__
#include "hFileManager.h"
#endif

#include "GameScene.h"

bool GameScene::init()
{
	if (!Scene::init()) return false;
	//Audio::getInstance()->playBGM();
	this->addChild(GameLayer::create());

	return true;
}