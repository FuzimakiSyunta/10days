#include "Enemy.h"

void Enemy::Initialize() {
	
}

void Enemy::Update() {
	PosY_ += Speed_;
	if (PosY_ >= 250) {
		PosY_ = 0;
	}
}

void Enemy::Draw(){
	Novice::DrawBox(
		PosX_, PosY_,
		50, 50,
		0.0f,
		BLACK,
		kFillModeSolid
	);

	Novice::ScreenPrintf(0, 40, "EnemyX%d,EnemyY%d,EnemySpeed%d", PosX_, PosY_,Speed_);
}

//ゲッターとセッター
void Enemy::SetX(int PosX_) { this->PosX_ = PosX_; }

void Enemy::SetY(int PosY_) { this->PosY_ = PosY_; }

void Enemy::SetSpeed(int Speed_) { this->Speed_ = Speed_; }
