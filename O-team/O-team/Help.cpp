#include"DxLib.h"
#include"information.h"  //�g������ .h�t�@�C�� ���C���N���[�h���܂�
#include"Help.h"  


/******************************************
 * �w���v���
 ******************************************/
void DrawHelp()
{
	// B(2)�{�^���`�F�b�N�}�X�N(X�L�[)�Ń��j���[�ɖ߂�
	if (g_KeyFlg & PAD_INPUT_B) g_GameMode = TITLE;

	// �w���v�摜�\��
	DrawGraph(0, 0, g_HelpImg, FALSE);

	// �����\��
	SetFontSize(16);
	DrawString(20, 200, "", 0xffffff, 0);

	DrawString(150, 450, "--- B�{�^���������ă^�C�g���֖߂� ---", 0xffffff, 0);
}