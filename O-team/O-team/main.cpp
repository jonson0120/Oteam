#include"DxLib.h"
#include"information.h"  //�g������ .h�t�@�C�� ���C���N���[�h���܂�

#include "Player.h"
Player player;

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

		DrawLine(320, 0, 320, 720, 0xffffff, TRUE);
		DrawLine(960, 0, 960, 720, 0xffffff, TRUE);


		player.Update();
		player.Draw();


		if (g_NowKey & PAD_INPUT_A) DrawString(0, 0, "TEST", 0xffffff);

		ScreenFlip();                      //����ʂ�\��ʂɔ��f
	}

	DxLib_End();				           // �c�w���C�u�����g�p�̏I������

	return 0;				               // �\�t�g�̏I�� 
}