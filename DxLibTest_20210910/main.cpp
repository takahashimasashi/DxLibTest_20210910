#include "DxLib.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �E�B���h�E���[�h
	ChangeWindowMode(TRUE);
	// �E�C���h�E�̖��O��ύX
	SetWindowText("DxLib�@�e�X�g�v���W�F�N�g");

	// DxLib�̏�����
	if (DxLib_Init() == -1)	return -1;

	int i = 0;

	// ����ʂɕ`�悷��
	SetDrawScreen(DX_SCREEN_BACK);

	while (CheckHitKeyAll() == 0)
	{
		// �`�悳��Ă�����̂��폜
		ClearDrawScreen();

		i++;

		// �摜�̕`��
		LoadGraphScreen(i, 0, "Image/test1.bmp", FALSE);

		// ����ʂ̓��e��\��ʂɃR�s�[����
		ScreenFlip();

		// Windows����̃��b�Z�[�W����
		if (ProcessMessage() == -1) break;
	}

	// �L�[���͂ŏI���ł��邱�Ƃ�\������
	DrawString(0, 0, "�L�[���͂ŏI��", GetColor(255, 255, 255));
	// �L�[���͑҂�
	WaitKey();

	// �c�w���C�u�����g�p�̏I������
	DxLib_End();

	// �\�t�g�̏I�� 
	return 0;
}