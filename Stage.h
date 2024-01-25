#pragma once
#include "Engine/GameObject.h"
class Stage :
    public GameObject
{ 
	int hfloor;
public:
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

