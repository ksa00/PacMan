#pragma once
#include "Engine/GameObject.h"
class Gauge :
    public GameObject
{
	int hGaugeBar;
	int hGaugeFrame_;

	int gaugeMaxVal;
	int gaugeCntVal;
public:
	Gauge(GameObject* parent);
	~Gauge();
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
	void SetGaugeVal(int _cnt,int _max);
};

