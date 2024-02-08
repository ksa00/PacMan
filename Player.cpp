#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Camera.h"
#include"Engine//Debug.h"
#include"Stage.h"
#include"Gauge.h"
namespace {
	const float player_movespeed = 0.5f;
}
Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hplayer(-1),speed_(player_movespeed),
	pstage(nullptr),hpCrr_(100),hpMax_(100)
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
	

	XMVECTOR vfront = { 0,0,1,0 };//direction
	XMVECTOR move{ 0,0,0,0 };//movement vector
	
	if (Input::IsKey(DIK_A)) {
		move = XMVECTOR{ -1,0,0,0 };
		//moveDir = Dir::LEFT;
	}
	if (Input::IsKey(DIK_D)) {
		move = XMVECTOR{ 1,0,0,0 };
	//	moveDir = Dir::RIGHT;
	}
	if (Input::IsKey(DIK_W)) {
		move = XMVECTOR{ 0,0,1,0 };
	//	moveDir = Dir::UP;d
	}
	if (Input::IsKey(DIK_S)) {
		move = XMVECTOR{ 0,0,-1,0 };
		//moveDir = Dir::DOWN;
	}
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	XMVECTOR posTemp = XMVectorZero();
	posTemp = pos + speed_ * move;
	/*Debug::Log("X,Z=");
	Debug::Log(XMVectorGetX(pos));
	Debug::Log(",");
	Debug::Log(XMVectorGetZ(pos),true);*/
	int tx, ty;
	tx = (int)(XMVectorGetX(posTemp)+1.0f);
	ty = pstage->GetStageWidth()-(int)(XMVectorGetZ(posTemp)+1.0f);
	if (!(pstage->iswall(tx, ty))) {
		pos = posTemp;
	}
	else {
		hpCrr_ = hpCrr_ - 2;
		if (hpCrr_ < 0)hpCrr_ = 0;
	}

	if(!XMVector3Equal(move,XMVectorZero())){
	XMStoreFloat3(&(transform_.position_), pos);
	XMMATRIX rot = XMMatrixRotationY(XM_PIDIV2);
	XMVECTOR modifiedVec = XMVector3TransformCoord(move, rot);
	float angle = atan2(XMVectorGetZ(modifiedVec), XMVectorGetX(modifiedVec));
		transform_.rotate_.y = XMConvertToDegrees(-angle);
}
	Gauge* pGauge = (Gauge*)FindObject("Gauge");
	pGauge->SetGaugeVal(hpCrr_, hpMax_);
	}
void Player::Draw()
{
	Model::SetTransform(hplayer, transform_);
	Model::Draw(hplayer);

}

void Player::Release()
{
}
