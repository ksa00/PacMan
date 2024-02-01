#pragma once
#include "Engine/GameObject.h"
#include<vector>
using std::vector;
//const int STAGE_FLOOR{ 0 };
//const int STAGE_WALL{ 1 };
enum STAGE_OBJ {
	FLOOR,
	WALL
};
class Stage :
    public GameObject
{ 
	int hfloor;
	int hblock;
	vector<vector<int>> stageData_;
	int stageWidth_, stageHeight_;
public:
	int GetStageWidth() { return stageWidth_; }
	int GetStageHeight() { return stageHeight_; }
	bool iswall(int _x, int _y);
	Stage(GameObject* parent);
	~Stage();
	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;
};

