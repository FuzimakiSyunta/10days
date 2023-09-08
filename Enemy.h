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

	float PosX_[5]; //敵のX座標
	float PosY_[5]; //敵のY座標
	int Speed_; //敵のスピード
	int Shark_ = Novice::LoadTexture("./Resource./Shark.png"); //テクスチャ
	int frame_; //フレーム
	int timer_; //タイマー
	int formation_; //フォーメーション
	int formation1_; //1個目のフォーメーションフラグ
	int formation2_; //2個目のフォーメーションフラグ
	int formation3_; //3個目のフォーメーションフラグ
	int Start_; //フレームを始めるためのフラグ

	int TimePosW_;//時間バーの横の長さ
};