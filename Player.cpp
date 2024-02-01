#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Camera.h"
#include"Engine//Debug.h"
#include"Stage.h"
namespace {
	const float player_movespeed = 1.0f;
}
Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hplayer(-1),speed_(player_movespeed),pstage(nullptr)
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
	pstage = (Stage *)FindObject("Stage");
}


void Player::Update()
{
	/*enum Dir {
		UP,LEFT,DOWN,RIGHT,NONE,
	};
	int moveDir = Dir::NONE;*/

	XMVECTOR vfront = { 0,0,1,0 };//direction
	XMVECTOR move{ 0,0,0,0 };//movement vector
	
	if (Input::IsKeyDown(DIK_A)) {
		move = XMVECTOR{ -1,0,0,0 };
		//moveDir = Dir::LEFT;
	}
	if (Input::IsKeyDown(DIK_D)) {
		move = XMVECTOR{ 1,0,0,0 };
	//	moveDir = Dir::RIGHT;
	}
	if (Input::IsKeyDown(DIK_W)) {
		move = XMVECTOR{ 0,0,1,0 };
	//	moveDir = Dir::UP;
	}
	if (Input::IsKeyDown(DIK_S)) {
		move = XMVECTOR{ 0,0,-1,0 };
		//moveDir = Dir::DOWN;
	}
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	XMVECTOR posTemp = XMVectorZero();
	posTemp = pos + speed_ * move;
	//pos = pos + speed_ * move;
	/*Debug::Log("X,Z=");
	Debug::Log(XMVectorGetX(pos));
	Debug::Log(",");
	Debug::Log(XMVectorGetZ(pos),true);*/
	int tx, ty;
	tx = (int)(XMVectorGetX(pos)+1.0f);
	ty = pstage->GetStageWidth()-(int)(XMVectorGetZ(pos)+1.0f);
	if (!(pstage->iswall(tx, ty))) {
		pos = posTemp;
	}
	Debug::Log("iX,iZ=");
	Debug::Log(tx);
	Debug::Log(",");
	Debug::Log(ty, true);
	Debug::Log(":");
	Debug::Log(pstage->iswall(tx, ty));


	if(!XMVector3Equal(move,XMVectorZero())){
	XMStoreFloat3(&(transform_.position_), pos);

	XMVECTOR vdot=XMVector3Dot(vfront, move);
	assert(XMVectorGetX(vdot) <= 1 && XMVectorGetX(vdot) >= -1);
	
	float angle = acos(XMVectorGetX(vdot));

		XMVECTOR vcross = XMVector3Cross(vfront, move);
		if (XMVectorGetY(vcross) < 0) {
			angle *= -1;
		}
		transform_.rotate_.y = XMConvertToDegrees(angle);
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
