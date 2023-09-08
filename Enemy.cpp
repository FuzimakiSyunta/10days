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
	Save_ = 0;
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
	if (frame_ >= 60) {
		timer_ += 1;
		frame_ = 0;
	}
	if (timer_ >= 3) {
		timer_ = 0;
		Speed_ = 0;
		formation_ = rand() % 3 + 1;
	}
	if (formation_ == 1) {
		if (Save_ != 1) {
			PosY_[0] = 300.0f;//�^��
			PosY_[1] = 200.0f;//�E
			PosY_[2] = 200.0f;//��
			PosY_[3] = 100.0f;//�E�[
			PosY_[4] = 100.0f;//���[
			Save_ = 1;
		}
	}
	if (formation_ == 2) {
		if (Save_ != 2) {
			PosY_[0] = 100.0f;//�^��
			PosY_[1] = 200.0f;//�E
			PosY_[2] = 200.0f;//��
			PosY_[3] = 300.0f;//�E�[
			PosY_[4] = 300.0f;//���[
			Save_ = 2;
		}
	}
	if (formation_ == 3) {
		if (Save_ != 3) {
			PosY_[0] = 200.0f;//�^��
			PosY_[1] = 100.0f;//�E
			PosY_[2] = 100.0f;//��
			PosY_[3] = 300.0f;//�E�[
			PosY_[4] = 300.0f;//���[
			Save_ = 3;
		}
	}
}

void Enemy::Draw(){
	//�^��
	Novice::DrawSprite(
		PosX_[0], PosY_[0],
		Shark_,
		1.0f, 1.0f,
		0.0f,
		WHITE
	);
	//��
	Novice::DrawSprite(
		PosX_[1], PosY_[1],
		Shark_,
		1.0f, 1.0f,
		0.0f,
		WHITE
	);
	//�E
	Novice::DrawSprite(
		PosX_[2], PosY_[2],
		Shark_,
		1.0f, 1.0f,
		0.0f,
		WHITE
	);
	//���[
	Novice::DrawSprite(
		PosX_[3], PosY_[3],
		Shark_,
		1.0f, 1.0f,
		0.0f,
		WHITE
	);
	//�E�[
	Novice::DrawSprite(
		PosX_[4], PosY_[4],
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
	Novice::ScreenPrintf(0, 80, "frame%d,timer%d,Formation%d", frame_, timer_,formation_);
}

//�Z�b�^�[
void Enemy::SetX(int PosX_) { this->PosX_[0] = PosX_; }

void Enemy::SetY(int PosY_) { this->PosY_[0] = PosY_; }

void Enemy::SetSpeed(int Speed_) { this->Speed_ = Speed_; }
