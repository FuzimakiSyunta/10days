#include"Player.h"
#include "Novice.h"


void Player::Initialize() {
	for (int i = 0; i < 5; i++) {
		Frame[i] = 0;
		Anime[i] = 0;
	}
	PosX_[0] = 870.0f;
	PosY_[0] = 700.0f;
	PosX_[1] = 670.0f;
	PosY_[1] = 700.0f;
	PosX_[2] = 1070.0f;
	PosY_[2] = 700.0f;
	PosX_[3] = 470.0f;
	PosY_[3] = 700.0f;
	PosX_[4] = 1270.0f;
	PosY_[4] = 700.0f;
}

void Player::Update()
{
	// アニメーション
	if (Frame[0] >= 37) {
		Anime[0]++;
		Frame[0] = 0;
	}
	if (Anime[0] >= 2) {
		Anime[0] = 0;
	}
	Frame[0]++;
	// アニメーション
	if (Frame[1] >= 35) {
		Anime[1]++;
		Frame[1] = 0;
	}
	if (Anime[1] >= 2) {
		Anime[1] = 0;
	}
	Frame[1]++;
	// アニメーション
	if (Frame[2] >= 32) {
		Anime[2]++;
		Frame[2] = 0;
	}
	if (Anime[2] >= 2) {
		Anime[2] = 0;
	}
	Frame[2]++;
	// アニメーション
	if (Frame[3] >= 38) {
		Anime[3]++;
		Frame[3] = 0;
	}
	if (Anime[3] >= 2) {
		Anime[3] = 0;
	}
	Frame[3]++;
	// アニメーション
	if (Frame[4] >= 34) {
		Anime[4]++;
		Frame[4] = 0;
	}
	if (Anime[4] >= 2) {
		Anime[4] = 0;
	}
	Frame[4]++;
}


void Player::MoveUpdate()//陣1
{

	PosX_[0] = 870.0f;//真ん中
	PosY_[0] = 700.0f;

	PosX_[1] = 678.0f;//左1
	PosY_[1] = 810.0f;

	PosX_[4] = 490.0f;//左2
	PosY_[4] = 700.0f;
	
	PosX_[2] = 1062.0f;//右1
	PosY_[2] = 810.0f;

	PosX_[3] = 1250.0f;//右2
	PosY_[3] = 700.0f;

	
}

void Player::SecondMoveUpdate() // 陣2
{
	PosX_[0] = 870.0f; // 真ん中
	PosY_[0] = 720.0f;

	PosX_[1] = 585.0f; // 左1
	PosY_[1] = 640.0f;

	PosX_[4] = 585.0f; // 左2
	PosY_[4] = 830.0f;

	PosX_[2] = 1155.0f; // 右1
	PosY_[2] = 640.0f;

	PosX_[3] = 1155.0f; // 右2
	PosY_[3] = 830.0f;
}

void Player::ThirdMoveUpdate()//陣3
{
	PosX_[0] = 870.0f; // 真ん中
	PosY_[0] = 800.0f;

	PosX_[1] = 800.0f; // 左1
	PosY_[1] = 620.0f;

	PosX_[4] = 720.0f; // 左2
	PosY_[4] = 720.0f;

	PosX_[2] = 940.0f; // 右1
	PosY_[2] = 620.0f;

	PosX_[3] = 1020.0f; // 右2
	PosY_[3] = 720.0f;
}

void Player::Draw() 
{ 
	Novice::DrawSprite(PosX_[0], PosY_[0], ShipUpanime_[Anime[0]], W_, H_, 0.0f, WHITE);
	Novice::DrawSprite(PosX_[1], PosY_[1], ShipUpanime_[Anime[1]], W_, H_, 0.0f, WHITE);
	Novice::DrawSprite(PosX_[2], PosY_[2], ShipUpanime_[Anime[2]], W_, H_, 0.0f, WHITE);
	Novice::DrawSprite(PosX_[3], PosY_[3], ShipUpanime_[Anime[3]], W_, H_, 0.0f, WHITE);
	Novice::DrawSprite(PosX_[4], PosY_[4], ShipUpanime_[Anime[4]], W_, H_, 0.0f, WHITE);
}


//セッター
void Player::SetX(int PosX_) { this->PosX_[5] = PosX_; }

void Player::SetY(int PosY_) { this->PosY_[5] = PosY_; }

void Player::SetW(int W_) { this->W_ = W_; }

void Player::SetH(int H_) { this->H_ = H_; }


