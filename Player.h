#include "Novice.h"

class Player {
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

	//������
	void Setup();

private:
	//Player���W
	float PosX_;
	float PosY_;
	//Player���a
	int W_;
	int H_;
	//�̗�
	int HP_;
};

//Player::Player() {}
//
//Player::~Player() {}
