#include "Stage.h"
#include"Engine/Model.h"
#include"Engine/Camera.h"

Stage::Stage(GameObject* parent)
	:GameObject(parent,"Stage"),hfloor(-1),hblock(-1)
{
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
	Camera::SetPosition({ 6.5,10,-5 });
	Camera::SetTarget({ 6.5,0,5.5 });
}

void Stage::Update()
{
}

void Stage::Draw()
{
	Transform floorTrans;
	floorTrans.position_ = { 0,0,0 };
	for (int r = 1; r < 16; r++) 
	{
		for (int c = 1; c < 16; c++) 
		{
			if(r==1||r==15||c==1||c==15)
			{
				Model::SetTransform(hblock, floorTrans);
				Model::Draw(hblock);
			}
			else {

			}
	Model::SetTransform(hfloor, floorTrans);
    
	Model::Draw(hfloor);
	
	floorTrans.position_.x += 1;
		}
		floorTrans.position_.z += 1;
		floorTrans.position_.x = 0;
	}
	
}

void Stage::Release()
{
}
