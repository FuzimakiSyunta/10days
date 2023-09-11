#include "Enemy.h"
#include<Novice.h>

void Enemy::Initialize() {
	for (int i = 0; i < 5; i++) {
		PosX_[i] = 900.0f;
		PosY_[i] = 0.0f;
	}
	PosX_[1] = 700.0f;
	PosX_[2] = 1100.0f;
	PosX_[3] = 500.0f;
	PosX_[4] = 1300.0f;
	Speed_ = 5;
	frame_ = 0;
	timer_ = 0;
	formation_ = 0;
	formation1_ = false;
	formation2_ = false;
	formation3_ = false;
	Start_ = false;
	TimePosW_ = 1080;
	Attack_ = false;
	ExplosionFlag_ = false;
};

void Enemy::ExplosionInitialize() {
	ExplosionFrame = 0;
	ExplosionAnimation = 0;
	
}

void Enemy::Update() {
	for (int i = 0; i < 5; i++) {
		if (PosY_[i] < 300) {
			PosY_[i] += Speed_;
		}
	}
	if (PosY_[0] >= 300) {
		Start_ = true;
	}
	if (Start_ == true) {
		frame_ += 1;
	}
	if (frame_ == 10) {
		Attack_ = false;
	}
	if (frame_ >= 60) {
		timer_ += 1;
		frame_ = 0;
	}
	if (timer_ >= 2) {
		timer_ = 0;
		Speed_ = 0;
		TimePosW_ = 1080;
		formation_ = rand() % 3 + 1;
		if (formation_ == 1 && formation1_ == true) {
			for (int i{}; formation_ == 1; i++) {
				formation_ = rand() % 3 + 1;
			}
		}
		if (formation_ == 2 && formation2_ == true) {
			for (int i{}; formation_ == 2; i++) {
				formation_ = rand() % 3 + 1;
			}
		}
		if (formation_ == 3 && formation3_ == true) {
			for (int i{}; formation_ == 3; i++) {
				formation_ = rand() % 3 + 1;
			}
		}
	}
	if (formation_ == 1) {
		TimePosW_ -= 9;
		if (formation1_ == false) { //逆への字
			PosY_[0] = 300.0f;//真ん中
			PosY_[1] = 200.0f;//右
			PosY_[2] = 200.0f;//左
			PosY_[3] = 100.0f;//右端
			PosY_[4] = 100.0f;//左端
			formation1_ = true;
			formation2_ = false;
			formation3_ = false;
		}
	}
	if (formation_ == 2) {
		TimePosW_ -= 9;
		if (formation2_ == false) { //への字
			PosY_[0] = 100.0f;//真ん中
			PosY_[1] = 200.0f;//右
			PosY_[2] = 200.0f;//左
			PosY_[3] = 300.0f;//右端
			PosY_[4] = 300.0f;//左端
			formation1_ = false;
			formation2_ = true;
			formation3_ = false;
		}
	}
	if (formation_ == 3) {
		TimePosW_ -= 9;
		if (formation3_ == false) {//ギザギザ
			PosY_[0] = 200.0f;//真ん中
			PosY_[1] = 100.0f;//右
			PosY_[2] = 100.0f;//左
			PosY_[3] = 300.0f;//右端
			PosY_[4] = 300.0f;//左端
			formation1_ = false;
			formation2_ = false;
			formation3_ = true;
		}
	}
	if (ExplosionFlag_ == true) {
		ExplosionFrame++;
		if (ExplosionFrame >= 5) {
			ExplosionAnimation++;
			ExplosionFrame = 0;
		}
		if (ExplosionAnimation >= 6) {
			ExplosionAnimation = 0;
			ExplosionFrame = 0;
			ExplosionFlag_ = false;
		}
	}
}

void Enemy::ExplosionFlag() {
	ExplosionFlag_ = true;
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
	//左端
	Novice::DrawSprite(
		PosX_[3], PosY_[3],
		Shark_,
		1.0f, 1.0f,
		0.0f,
		WHITE
	);
	//右端
	Novice::DrawSprite(
		PosX_[4], PosY_[4],
		Shark_,
		1.0f, 1.0f,
		0.0f,
		WHITE
	);

	//時間制限バー描画
	Novice::DrawBox(
		420, 1030,
		TimePosW_, 100,
		0.0f,
		RED,
		kFillModeSolid
	);

	if (Attack_ == true) {
		Novice::DrawSprite(
			0, 0,
			Damage_,
			1.0f, 1.0f,
			0.0f,
			WHITE
		);
	}

	if (ExplosionFlag_ == true) {
		Novice::DrawSprite(
			800, 100,
			Explosion_[ExplosionAnimation],
			10,10, 
			0.0f,
			WHITE
		);
	}


	Novice::ScreenPrintf(0, 60, "EnemyX%d,EnemyY%d,EnemySpeed%d", PosX_[0], PosY_[0], Speed_);
	Novice::ScreenPrintf(0, 80, "frame%d,timer%d,Damage%d", frame_, timer_);
	Novice::ScreenPrintf(0, 180, "ExplosionFlag_%d,ExplosionFrame%d,ExplosionAnimation%d", ExplosionFlag_, ExplosionFrame, ExplosionAnimation);
}

void Enemy::SharkAttack() {
	Attack_ = true;
}

void Enemy::ExplosionDraw() {

}

//セッター
void Enemy::SetX(int PosX_) { this->PosX_[4] = PosX_; }

void Enemy::SetY(int PosY_) { this->PosY_[4] = PosY_; }

void Enemy::SetSpeed(int Speed_) { this->Speed_ = Speed_; }

void Enemy::Setformation(int formation_) { this->formation_ = formation_; }

void Enemy::SetTimever(int TimePosW_) { this->TimePosW_ = TimePosW_; }