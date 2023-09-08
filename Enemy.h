#pragma once
#include "Novice.h"

class Enemy {
public:
	/// <summary>
	/// ‰Šú‰»
	/// </summary>
	void Initialize();

	/// <summary>
	/// ©ƒLƒƒƒ‰
	/// XV
	/// </summary>
	void Update();

	/// <summary>
	/// •`‰æ
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
	int formation1_;
	int formation2_;
	int formation3_;
	int Start_;
};