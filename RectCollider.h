#pragma once

class RectCollider 
   

{
public:
	float top;
	float bottom;
	float left;
	float right;
	float centerx;
	float centery;
	float width;
	float height;
	//引数：parent  親オブジェクト（SceneManager）
	RectCollider();

	//初期化
	~RectCollider();
	void SetRectCenter(float _cx, float _cy, float _width, float _height);
	void SetRectTopBottom(float _left, float _top, float _width, float _height);
	float GetLeft();
	float GetRight();
	float GetTop();
	float GetBottom();
	float GetCenterX();
	float GetCenterY();
	float GetWidth();
	float GetHeight();
	
};

