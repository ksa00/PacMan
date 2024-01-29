#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Camera.h"

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
	
	if (Input::IsKey(DIK_A)) {
		transform_.position_.x -= 0.15;

	}
	if (Input::IsKey(DIK_D)) {
		transform_.position_.x += 0.15;
	}
	if (Input::IsKey(DIK_W)) {
		transform_.position_.z += 0.15;
	}
	if (Input::IsKey(DIK_S)) {
		transform_.position_.z -= 0.15;
	}
}

void Player::Draw()
{
	Model::SetTransform(hplayer, transform_);
	Model::Draw(hplayer);
}

void Player::Release()
{
}
