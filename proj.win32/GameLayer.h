#ifndef __H_FILE_MANAGER_H__
#define __H_FILE_MANAGER_H__
#include "hFileManager.h"
#endif

#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

class GameLayer : public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(GameLayer);

	// ½ø¹Ø¿¨Æ®×Ö
	void floatLevelWord();
	void floatTargetScoreWord();
	void removeFloatWord();

	void showStarMatrix();

	virtual void update(float delta);
	virtual bool onTouchBegan(Touch* touch, Event* event);

	void refreshMenu();
	void showLinkNum();
	void hideLinkNum();
	void floatLeftStarMsg(int leftNum);

	void gotoNextLevel();
	void gotoGameOver();


private:
	FloatWord* _levelMsg;
	FloatWord* _targetScore;
	TopMenu* menu;
	StarMatrix* matrix;
	Label* linkNum;
};

#endif //   __GAME_LAYER_H__