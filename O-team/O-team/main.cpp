#include"DxLib.h"
#include"information.h"  //�g������ .h�t�@�C�� ���C���N���[�h���܂�


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("Neko");             //�^�C�g����ݒ�
	ChangeWindowMode(TRUE);                //�E�B���h�E���[�h�ŋN��

	//�E�B���h�E�T�C�Y��ݒ�
	SetGraphMode(SCREENSIZE_X, SCREENSIZE_Y, 32);

	if (DxLib_Init() == -1) return -1;     //DX���C�u�����̏���������
	SetDrawScreen(DX_SCREEN_BACK);         //�`����ʂ𗠂ɂ���

	//���Ȃ���΃��[�v
	while (ProcessMessage() == 0)
	{

		//�L�[���͎擾 
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);    //��̃R���g���[���[�̓��͂��g���܂�
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();                 //��ʂ�������

		if (g_NowKey & PAD_INPUT_A) DrawString(0, 0, "TEST", 0xffffff);

		ScreenFlip();                      //����ʂ�\��ʂɔ��f
	}

	DxLib_End();				           // �c�w���C�u�����g�p�̏I������

	return 0;				               // �\�t�g�̏I�� 
}

/******************************************
 * �摜�Ǎ�
 ******************************************/
int LoadImages()
{
	// �w���v�摜�Ǎ�
	if ((g_HelpImg = LoadGraph("images/help.bmp")) == -1) return -1;
}