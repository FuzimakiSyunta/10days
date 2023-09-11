#include "Novice.h"

class TitleAction
{
public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();
	void GameoverInitialize();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	void GameoverUpdate();


	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	void GameoverDraw();

	//�^�C�g���̃A�j���[�V����
	int TitleFrame;
	int TitleAnimation;
	//�{�^���̃A�j���[�V����
	int ButtonFrame;
	int ButtonAnimation;
	//�Q�[���I�[�o�[�A�j���[�V����
	int GameoverFrame;
	int GameoverAnimation;
	

private:
	
	//�^�C�g���摜�ǂݍ���
	int Titleimage[2] = { Novice::LoadTexture("./Resource./Title.png"), Novice::LoadTexture("./Resource./Title2.png"), };
	//B�{�^���Ŏn�߂�
	int Buttonimage[2]= { Novice::LoadTexture("./Resource./BButton.png"), Novice::LoadTexture("./Resource./BButton2.png"), };
	//�Q�[���I�[�o�[�摜�ǂݍ���
	int Gameoverimage[8] = { Novice::LoadTexture("./Resource./Gameover1.png"),Novice::LoadTexture("./Resource./Gameover2.png"),Novice::LoadTexture("./Resource./Gameover3.png"),Novice::LoadTexture("./Resource./Gameover4.png"),
		Novice::LoadTexture("./Resource./Gameover5.png"),Novice::LoadTexture("./Resource./Gameover6.png"),Novice::LoadTexture("./Resource./Gameover7.png"),
	Novice::LoadTexture("./Resource./Gameover8.png"), };
	//�S�[���摜�ǂݍ���
	//int Goalimage[5] = { Novice::LoadTexture("./Resource./Gameover1.png"), Novice::LoadTexture("./Resource./Gameover1.png"), };
};

