#pragma once
#include "Novice.h"

class Enemy {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 自キャラ
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	void SetX(int PosX_);
	void SetY(int PosY_);
	void SetSpeed(int Speed_);

private:

	float PosX_[5];
	float PosY_[5];
	int Speed_;
	int Shark_ = Novice::LoadTexture("./Resource./Shark.png");
	int frame_;
	int timer_;
	int formation_;
};