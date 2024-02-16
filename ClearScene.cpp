#include "ClearScene.h"
#include"Engine/Image.h"
#include"Engine/Input.h"
#include"Engine/SceneManager.h"
//コンストラクタ
ClearScene::ClearScene(GameObject* parent)
	: GameObject(parent, "TitleScene"),hGameOver(-1)
{
}

//初期化
void ClearScene::Initialize()
{
hGameOver=	Image::Load("Image/GameOver.png");
	assert(hGameOver >= 0);
}

//更新
void ClearScene::Update()
{
	if (Input::IsKeyDown(DIK_RETURN)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
	if (Input::IsKeyDown(DIK_ESCAPE)) {
		exit(0);
	}
}

//描画
void ClearScene::Draw()
{
	Image::SetTransform(hGameOver, transform_);
	Image::Draw(hGameOver);
}

//開放
void ClearScene::Release()
{
}
