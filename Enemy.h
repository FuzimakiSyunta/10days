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

private:

	int posX;
	int posY;
	int speed;

};