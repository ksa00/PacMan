#include "Stage.h"
#include"Engine/Model.h"
#include"Engine/Camera.h"
#include "Engine/CsvReader.h"
#include<vector>

Stage::Stage(GameObject* parent)
	:GameObject(parent,"Stage"),hfloor(-1),hblock(-1)
{
	CsvReader csv;
	csv.Load("map.csv");
	int STAGE_X = csv.GetWidth();
	int STAGE_Y = csv.GetHeight();
	for (int i = 0; i < STAGE_Y; i++) {
		vector<int>sdata(STAGE_X, 0);
		stageData_.push_back(sdata);
}
	for (int j = 0; j < STAGE_Y; j++)
	{
		for (int i = 0; i < STAGE_X; i++)
		{
			stageData_[i][j] = csv.GetValue(i, j);
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

	for (int z = 0; z < 15; z++) {
		for (int x = 0; x < 15; x++) {
			floorTrans.position_ = { (float)x, 0, (float)z };
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
}
