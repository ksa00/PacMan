#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Camera.h"
namespace {
	const float player_movespeed = 0.015f;
}
Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hplayer(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	hplayer = Model::Load("Model/Player.fbx");
	assert(hplayer >= 0);
	transform_.position_.x = 0.5;
	transform_.position_.z = 1.5;
}

void Player::Update()
{
	/*enum Dir {
		UP,LEFT,DOWN,RIGHT,NONE,
	};
	int moveDir = Dir::NONE;*/

	XMVECTOR vfront = { 0,0,1,0 };
	XMVECTOR move{ 0,0,1,0 };
	
	if (Input::IsKey(DIK_A)) {
		move = XMVECTOR{ -1,0,0,0 };
		//moveDir = Dir::LEFT;
	}
	if (Input::IsKey(DIK_D)) {
		move = XMVECTOR{ 1,0,1,0 };
	//	moveDir = Dir::RIGHT;
	}
	if (Input::IsKey(DIK_W)) {
		move = XMVECTOR{ 0,0,1,0 };
	//	moveDir = Dir::UP;
	}
	if (Input::IsKey(DIK_S)) {
		move = XMVECTOR{ 0,0,-1,0 };
		//moveDir = Dir::DOWN;
	}
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	pos = pos + speed_ * move;
	XMStoreFloat3(&(transform_.position_), pos);
	XMVECTOR vdot=XMVector3Dot(vfront, move);
	float angle = acos(XMVectorGetX(vdot));
		transform_.rotate_.y=XMConvertToDegrees(angle);
		XMVECTOR vcross = XMVector3Cross(vfront, move);
		if (XMVectorGetY(vcross) < 0) {
			angle *= -1;
		}
		transform_.rotate_.y = XMConvertToDegrees(angle);
}

void Player::Draw()
{
	Model::SetTransform(hplayer, transform_);
	Model::Draw(hplayer);
}

void Player::Release()
{
}
