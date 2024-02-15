#pragma once
#include "Engine/GameObject.h"
class RectCollider :
    public GameObject

{
	float top;
	float bottom;
	float left;
	float right;
	float centerx;
	float centery;
	float width;
	float height;
public:
	
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	RectCollider(GameObject* parent);

	//������
	~RectCollider();
	void SetRectCenter(float _cx, float _cy, float _width, float _height);
	void SetRectTopBottom(float _left, float _top, float _width, float _height);
	float GetLeft();
	float GetRight();
	float GetTop();
	float GetBottom();
	float GetCenterX();
	float GetCenterY();
	float GetWidth();
	float GetHeight();
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

