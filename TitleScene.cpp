#include "TitleScene.h"
#include"Engine/Image.h"
#include"Engine/Input.h"
#include "Engine/SceneManager.h"
//コンストラクタ
TitleScene::TitleScene(GameObject * parent)
	: GameObject(parent, "TitleScene"),hTitle(-1)
{
}

//初期化
void TitleScene::Initialize()
{
hTitle=	Image::Load("Image/Title.png");
	assert(hTitle >= 0);
}

//更新
void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_RETURN)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//描画
void TitleScene::Draw()
{
	Image::SetTransform(hTitle, transform_);
	Image::Draw(hTitle);
}

//開放
void TitleScene::Release()
{
}
