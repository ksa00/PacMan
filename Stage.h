#pragma once
#include "Engine/GameObject.h"
class Stage :
    public GameObject
{ 
	int hfloor;
public:
	Stage(GameObject* parent);
	~Stage();
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

