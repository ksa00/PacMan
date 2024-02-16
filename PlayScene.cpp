#include "PlayScene.h"
#include"Stage.h"
#include"Player.h"
#include"Gauge.h"
#include "Engine/Text.h"
//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene"),pText(nullptr)
{
}

//������
void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Instantiate<Player>(this);
	Instantiate<Gauge>(this);
	pText = new Text;
	pText->Initialize();

}

//�X�V
void PlayScene::Update()
{
	
}

//�`��
void PlayScene::Draw()
{
	pText->Draw(512, 30, "P A C M A N");
}

//�J��
void PlayScene::Release()
{
}
