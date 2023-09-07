#include "Enemy.h"
#include<Novice.h>

void Enemy::Initialize() {
	PosY_ = 0;
};

void Enemy::Update() {
	PosY_ += Speed_;
	if (PosY_ >= 250) {
		PosY_ = 250;
	}
}

void Enemy::Draw(){
	//真ん中
	Novice::DrawSprite(
		PosX_, PosY_,
		Shark_,
		1.0f, 1.0f,
		0.0f,
		WHITE
	);
	//左
	Novice::DrawSprite(
		PosX_-200, PosY_,
		Shark_,
		1.0f, 1.0f,
		0.0f,
		WHITE
	);
	//右
	Novice::DrawSprite(
		PosX_+200, PosY_,
		Shark_,
		1.0f, 1.0f,
		0.0f,
		WHITE
	);

	//Novice::DrawBox(
	//	PosX_, PosY_,
	//	50, 50,
	//	0.0f,
	//	BLACK,
	//	kFillModeSolid
	//);

	Novice::ScreenPrintf(0, 60, "EnemyX%d,EnemyY%d,EnemySpeed%d", PosX_, PosY_,Speed_);
}

//ゲッターとセッター
void Enemy::SetX(int PosX_) { this->PosX_ = PosX_; }

void Enemy::SetY(int PosY_) { this->PosY_ = PosY_; }

void Enemy::SetSpeed(int Speed_) { this->Speed_ = Speed_; }
