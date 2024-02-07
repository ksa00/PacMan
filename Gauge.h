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
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
	void SetGaugeVal(int _cnt,int _max);
};

