#ifndef __H_FILE_MANAGER_H__
#define __H_FILE_MANAGER_H__
#include "hFileManager.h"
#endif

#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

class GameScene : public Scene
{
public:
	virtual bool init();
	CREATE_FUNC(GameScene);
};

#endif // __GAME_SCENE_H__