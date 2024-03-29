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
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

