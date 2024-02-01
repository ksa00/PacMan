#pragma once
#include "Engine/GameObject.h"
class Stage;
class Player :
    public GameObject
{
	int hplayer;
	float speed_;
	Stage* pstage;
public:
	Player(GameObject* parent);
	~Player();
	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;
};

