#include "Enemy.h"
#include<Novice.h>

void Enemy::Initialize() {
	for (int i = 0; i < 5; i++) {
		PosX_[i] = 900.0f;
		PosY_[i] = 0.0f;
	}
	PosX_[1] = 700.0f;
	PosX_[2] = 1100.0f;
	frame_ = 0;
	timer_ = 0;
};

void Enemy::Update() {
	for (int i = 0; i < 5; i++) {
		if (PosY_[i] < 300) {
			PosY_[i] += Speed_;
		}
		
		if (PosY_[i] >= 300) {
			frame_ += 1;
		}
	}
	if (frame_ == 240) {
		timer_ += 1;
		frame_ = 0;
	}
}

void Enemy::Draw(){
	//真ん中
	Novice::DrawSprite(
		PosX_[0], PosY_[0],
		Shark_,
		1.0f, 1.0f,
		0.0f,
		WHITE
	);
	//左
	Novice::DrawSprite(
		PosX_[1], PosY_[1],
		Shark_,
		1.0f, 1.0f,
		0.0f,
		WHITE
	);
	//右
	Novice::DrawSprite(
		PosX_[2], PosY_[2],
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

	Novice::ScreenPrintf(0, 60, "EnemyX%d,EnemyY%d,EnemySpeed%d", PosX_[0], PosY_[0], Speed_);
	Novice::ScreenPrintf(0, 80, "frame%d,timer%d", frame_, timer_);
}

//セッター
void Enemy::SetX(int PosX_) { this->PosX_[5] = PosX_; }

void Enemy::SetY(int PosY_) { this->PosY_[5] = PosY_; }

void Enemy::SetSpeed(int Speed_) { this->Speed_ = Speed_; }
