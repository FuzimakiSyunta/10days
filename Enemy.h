#pragma once
#include "Novice.h"

class Enemy {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();
	void ExplosionInitialize();

	/// <summary>
	/// 自キャラ
	/// 更新
	/// </summary>
	void Update();
	void HardUpdate();
	void SharkAttack();
	void ExplosionFlag();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	void ExplosionDraw();


	void SetX(int PosX_);
	void SetY(int PosY_);
	void SetSpeed(int Speed_);
	void Setformation(int formation_);
	void SetTimever(int TimePosW_);

	int Getformation() { return formation_; };
	int GetTimever() { return TimePosW_; };

	int ExplosionFrame;
	int ExplosionAnimation;

private:

	float PosX_[5]; //敵のX座標
	float PosY_[5]; //敵のY座標
	int Speed_; //敵のスピード
	int frame_; //フレーム
	int timer_; //タイマー
	int formation_; //フォーメーション
	int formation1_; //1個目のフォーメーションフラグ
	int formation2_; //2個目のフォーメーションフラグ
	int formation3_; //3個目のフォーメーションフラグ
	int Start_; //フレームを始めるためのフラグ
	int Attack_;
	int ExplosionFlag_;

	int TimePosW_;//時間バーの横の長さ

	int Shark_ = Novice::LoadTexture("./Resource./Shark.png"); //テクスチャ
	int Damage_ = Novice::LoadTexture("./Resource./Damege.png");
	int Explosion_[6] = { Novice::LoadTexture("./Resource./Explosion1.png"),Novice::LoadTexture("./Resource./Explosion2.png"),Novice::LoadTexture("./Resource./Explosion3.png"),Novice::LoadTexture("./Resource./Explosion4.png"),
		Novice::LoadTexture("./Resource./Explosion5.png"),Novice::LoadTexture("./Resource./Explosion6.png") };
};