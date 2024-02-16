#include "Gauge.h"
#include"Engine/Image.h"
Gauge::Gauge(GameObject* parent)
	:GameObject(parent,"Gauge"),hGaugeBar(-1),hGaugeFrame_(-1),
	gaugeMaxVal(200),gaugeCntVal(100)
{
}

Gauge::~Gauge()
{
}

void Gauge::Initialize()
{
	hGaugeBar = Image::Load("Image/health.png");
	assert(hGaugeBar >= 0);
	hGaugeFrame_ = Image::Load("image/lifebarframe.png");
	assert(hGaugeFrame_ >= 0);
	transform_.position_.x =- 0.95f;
	transform_.position_.y = 0.85f;

}

void Gauge::Update()
{
}

void Gauge::Draw()
{
	Transform tr = transform_;
	tr.scale_.x = (float)gaugeCntVal / (float)gaugeMaxVal;
	Image::SetTransform(hGaugeBar, tr);
	Image::Draw(hGaugeBar);
		Image::SetTransform(hGaugeFrame_, transform_);
	Image::Draw(hGaugeFrame_);


	
}
	
	

void Gauge::Release()
{
}

void Gauge::SetGaugeVal(int _cnt, int _max)
{
	gaugeMaxVal = _max;
	gaugeCntVal = _cnt;
}
