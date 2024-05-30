//=============================================================================
// �t�@�C��: model.h
//=============================================================================
// ���f���̐ݒ�E�`��𐧌�
//=============================================================================

#ifndef __MODEL_H__
#define __MODEL_H__

// �w�b�_�t�@�C���̃C���N���[�h
#include "animator.h"

// �t���[���ԍ��̍ő�l
int max_frame_count = 500;

// Model�N���X�̒�`�iModelerView�N���X���p���j
class Model : public ModelerView {
private:
    //�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`
	//��3�T�ۑ�
    //---------------------------------------------------------------------

	// �t���[���ԍ�
    int frame_count;
    
    //-------------------------------------------------------------------------
    // ����ϐ�
    //-------------------------------------------------------------------------

        // �`�`�`�ϐ���ǉ��`�`�`


    //�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`


public:
    // �R���X�g���N�^�i�X�[�p�[�N���X�̃R���X�g���N�^���Ăяo���j
    Model( int x, int y, int w, int h, char* label ) : ModelerView( x, y, w, h, label )
    {
        //�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`
		//��3�T�ۑ�
        //---------------------------------------------------------------------

        // �t���[���ԍ��̏�����
        frame_count = 0;
        
        //---------------------------------------------------------------------
        // ������
        //---------------------------------------------------------------------

            // �`�`�`�ϐ����������`�`�`


		//�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`
    }

    //�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`
	//��3�T�ۑ�
	//---------------------------------------------------------------------

    // �����A�j���[�V�����̐ݒ�
    void SetAutomaticAnimation()
    {
        //-----------------------------------------------------------------
        // �A�j���[�V����
        //-----------------------------------------------------------------

            // �`�`�`�v���O�������L�q�`�`�`

        //-----------------------------------------------------------------
    }

	// �蓮�A�j���[�V�����̐ݒ�
    void SetManualAnimation()
    {
        //-----------------------------------------------------------------
        // �A�j���[�V����
        //-----------------------------------------------------------------

            // �`�`�`�v���O�������L�q�`�`�`

		//-----------------------------------------------------------------
    }

    //�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`


    // �`��̑O����
    void BeginPaint()
    {
        // ������������L����
        glEnable( GL_BLEND );
        // �������@�̎w��
        glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    }

    // �`��̌㏈��
    void EndPaint()
    {
        // �����������𖳌���
        glDisable( GL_BLEND );
    }


    // �I�u�W�F�N�g�̕`��
    void draw()
    {
		//�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`
		//��3�T�ۑ�
		//---------------------------------------------------------------------
        // �����A�j���[�V�����̏���
        if ( IsAutomaticAnimation() && frame_count<max_frame_count ) {
            // �t���[���ԍ��̍X�V
            SetSliderValue( FRAME_CONTROLS, ++frame_count );
            // �����A�j���[�V����
            SetAutomaticAnimation();
        }
        // �蓮�A�j���[�V�����̏���
        else {
            // �t���[���ԍ����擾
            frame_count = (int)GetSliderValue( FRAME_CONTROLS );
            // �蓮�A�j���[�V����
            SetManualAnimation();            
        }
		//�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`


        // �X�[�p�[�N���X�̕`�惁�\�b�h���R�[���i�K�{�j
        ModelerView::draw();


        // �`��J�n
        BeginPaint();

        //---------------------------------------------------------------------
        // �I�u�W�F�N�g��`��
        //---------------------------------------------------------------------

		 // �`�`�`�v���O�������L�q�`�`�`

        //---------------------------------------------------------------------

        // �`��I��
        EndPaint();
    }
};

// __MODEL_H__
#endif