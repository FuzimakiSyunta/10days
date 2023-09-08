#include "Novice.h"

class TitleAction
{
public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();


	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	//�^�C�g���̃A�j���[�V����
	int TitleFrame;
	int TitleAnimation;
	//�{�^���̃A�j���[�V����
	int ButtonFrame;
	int ButtonAnimation;

private:
	
	//�^�C�g���摜�ǂݍ���
	int Titleimage[3] = { Novice::LoadTexture("./Resource./Title.png"), Novice::LoadTexture("./Resource./Title2.png"), };
	//B�{�^���Ŏn�߂�
	int Buttonimage[2]= { Novice::LoadTexture("./Resource./BButton.png"), Novice::LoadTexture("./Resource./BButton2.png"), };

};

