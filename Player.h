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
