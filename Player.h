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
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

