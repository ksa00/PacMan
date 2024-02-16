#pragma once
#include "Engine/GameObject.h"
class Stage;
class Player :
    public GameObject
{
	int hplayer;
	float speed_;
	int hpCrr_;
	int hpMax_;
	Stage* pstage;
	//RectCollider rec;
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

