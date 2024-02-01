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
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

