#include "ClearScene.h"
#include"Engine/Image.h"
#include"Engine/Input.h"
#include"Engine/SceneManager.h"
//�R���X�g���N�^
ClearScene::ClearScene(GameObject* parent)
	: GameObject(parent, "TitleScene"),hGameOver(-1)
{
}

//������
void ClearScene::Initialize()
{
hGameOver=	Image::Load("Image/GameOver.png");
	assert(hGameOver >= 0);
}

//�X�V
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

//�`��
void ClearScene::Draw()
{
	Image::SetTransform(hGameOver, transform_);
	Image::Draw(hGameOver);
}

//�J��
void ClearScene::Release()
{
}
