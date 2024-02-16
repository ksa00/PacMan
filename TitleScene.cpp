#include "TitleScene.h"
#include"Engine/Image.h"
#include"Engine/Input.h"
#include "Engine/SceneManager.h"
//�R���X�g���N�^
TitleScene::TitleScene(GameObject * parent)
	: GameObject(parent, "TitleScene"),hTitle(-1)
{
}

//������
void TitleScene::Initialize()
{
hTitle=	Image::Load("Image/Title.png");
	assert(hTitle >= 0);
}

//�X�V
void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_RETURN)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//�`��
void TitleScene::Draw()
{
	Image::SetTransform(hTitle, transform_);
	Image::Draw(hTitle);
}

//�J��
void TitleScene::Release()
{
}
