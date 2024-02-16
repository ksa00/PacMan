#include "PlayScene.h"
#include"Stage.h"
#include"Player.h"
#include"Gauge.h"
#include "Engine/Text.h"
//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene"),pText(nullptr)
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Instantiate<Player>(this);
	Instantiate<Gauge>(this);
	pText = new Text;
	pText->Initialize();

}

//更新
void PlayScene::Update()
{
	
}

//描画
void PlayScene::Draw()
{
	pText->Draw(512, 30, "P A C M A N");
}

//開放
void PlayScene::Release()
{
}
