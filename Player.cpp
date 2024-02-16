#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Camera.h"
#include"Engine//Debug.h"
#include"Stage.h"
#include"Gauge.h"
#include"RectCollider.h"
#include"Engine/SceneManager.h"

namespace {
	const float player_movespeed = 0.15f;
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
	//rec.SetRectCenter(transform_.position_.x, transform_.position_.z, 1.0, 1.0);
}


void Player::Update()
{
	enum Dir
	{
		UP, LEFT, DOWN, RIGHT, NONE,
	};
	int moveDir = Dir::NONE;
	XMVECTOR vfront = { 0,0,1,0 };//direction
	XMVECTOR move{ 0,0,0,0 };//movement vector
	
	if (Input::IsKey(DIK_A)) {
		move = XMVECTOR{ -1,0,0,0 };
		moveDir = Dir::LEFT;
	}
	if (Input::IsKey(DIK_D)) {
	move = XMVECTOR{ 1,0,0,0 };
		moveDir = Dir::RIGHT;
	}
	if (Input::IsKey(DIK_W)) {
		move = XMVECTOR{ 0,0,1,0 };
		moveDir = Dir::UP;
	}
	if (Input::IsKey(DIK_S)) {
		move = XMVECTOR{ 0,0,-1,0 };
		moveDir = Dir::DOWN;
	}
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	XMVECTOR posTemp = XMVectorZero();
	posTemp = pos + speed_ * move;
	/*Debug::Log("X,Z=");
	Debug::Log(XMVectorGetX(pos));
	Debug::Log(",");
	Debug::Log(XMVectorGetZ(pos),true);*/
	int tx, ty;
	RectCollider trec;
	trec.SetRectCenter(XMVectorGetX(posTemp), XMVectorGetZ(posTemp), 1.0, 1.0);

	switch (moveDir)
	{
	case UP:
		tx = (int)(trec.centerx + 1);
		ty = pstage->GetStageHeight() - (int)(trec.top) - 1;
		break;
	case DOWN:
		tx = (int)(trec.centerx + 1);
		ty = pstage->GetStageHeight() - (int)(trec.bottom) - 1;
		break;
	case LEFT:
		tx = (int)(trec.left + 1);
		ty = pstage->GetStageHeight() - (int)(trec.centery) - 1;
		break;
	case RIGHT:
		tx = (int)(trec.right + 1);
		ty = pstage->GetStageHeight() - (int)(trec.centery) - 1;
		break;
	case NONE:
		tx = (int)(trec.centerx + 1);
		ty = pstage->GetStageHeight() - (int)(trec.centery) - 1;
		break;
	defaulet:
		break;
	}
	if (!(pstage->iswall(tx, ty))) {
		pos = posTemp;
	}
	else {
		hpCrr_ = hpCrr_ - 2;
		if (hpCrr_ <= 0) {
			hpCrr_ = 0;
			KillMe();
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_CLEAR);
		}
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
