#include "Stage.h"
#include"Engine/Model.h"
#include"Engine/Camera.h"
#include "Engine/CsvReader.h"
#include<vector>

bool Stage::iswall(int _x, int _y)
{
//	assert();
	if (stageData_[_y][_x] == STAGE_OBJ::WALL) {
		return true;
	}
	else {
		return false;
	}
}


Stage::Stage(GameObject* parent)
	:GameObject(parent,"Stage"),hfloor(-1),hblock(-1)
{
	CsvReader csv;
	csv.Load("map.csv");
	stageWidth_= csv.GetWidth();
	stageHeight_ = csv.GetHeight();
	
	for (int i = 0; i < stageHeight_; i++) {
		vector<int>sdata(stageWidth_, 0);
		stageData_.push_back(sdata);
}
	for (int j = 0; j < stageHeight_; j++)
	{
		for (int i = 0; i < stageWidth_; i++)
		{
			stageData_[j][i] = csv.GetValue(i, j);
		}
	}
}

Stage::~Stage()
{
}

void Stage::Initialize()
{
	hfloor = Model::Load("Model/floor.fbx");
	assert(hfloor >= 0);
	hblock = Model::Load("Model/Wall.fbx");
	assert(hblock >= 0);
	Camera::SetPosition({ 6.5,10,-3 });
	Camera::SetTarget({ 6.5,0,5.5 });
}

void Stage::Update()
{
}

void Stage::Draw()
{
	Transform floorTrans;
	floorTrans.position_ = { 0,0,0 };

	for (int z = 0; z < stageHeight_; z++) {
		for (int x = 0; x < stageWidth_; x++) {
			floorTrans.position_ = { (float)x, 0, (float)(14-z) };
			//if (x == 0 || z == 0 || x == 14 || z == 14) {
			//	Model::SetTransform(hBlock_, floorTrans);
			//	Model::Draw(hBlock_);
			//}
			//else {
			//	Model::SetTransform(hFloor_, floorTrans);
			//	Model::Draw(hFloor_);
			//}
			if (stageData_[z][x] == 1 ) {
				Model::SetTransform(hblock, floorTrans);
				Model::Draw(hblock);
			}
			else {
				Model::SetTransform(hfloor, floorTrans);
				Model::Draw(hfloor);
			}
		}
	}
}

void Stage::Release()
{
	for (int i = 0; i < stageHeight_; i++) 
	{
		stageData_[i].clear();
	}
	stageData_.clear();
}
