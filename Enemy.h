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

	int PosX_;
	int PosY_;
	int Speed_;

};