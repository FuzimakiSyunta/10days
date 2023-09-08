#pragma once
#include "Novice.h"

class Enemy {
public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// ���L����
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	void SetX(int PosX_);
	void SetY(int PosY_);
	void SetSpeed(int Speed_);

private:

	float PosX_[5]; //�G��X���W
	float PosY_[5]; //�G��Y���W
	int Speed_; //�G�̃X�s�[�h
	int Shark_ = Novice::LoadTexture("./Resource./Shark.png"); //�e�N�X�`��
	int frame_; //�t���[��
	int timer_; //�^�C�}�[
	int formation_; //�t�H�[���[�V����
	int formation1_; //1�ڂ̃t�H�[���[�V�����t���O
	int formation2_; //2�ڂ̃t�H�[���[�V�����t���O
	int formation3_; //3�ڂ̃t�H�[���[�V�����t���O
	int Start_; //�t���[�����n�߂邽�߂̃t���O

	int TimePosW_;//���ԃo�[�̉��̒���
};