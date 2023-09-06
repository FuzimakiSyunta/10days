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

	int PosX_;
	int PosY_;
	int Speed_;

};