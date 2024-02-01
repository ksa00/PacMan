#pragma once
#include "Engine/GameObject.h"

class Player :
    public GameObject
{
	int hplayer;
	float speed_;
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

