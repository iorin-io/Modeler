//=============================================================================
// ファイル: model.h
//=============================================================================
// モデルの設定・描画を制御
//=============================================================================

#ifndef __MODEL_H__
#define __MODEL_H__

// ヘッダファイルのインクルード
#include "animator.h"

// フレーム番号の最大値
int max_frame_count = 500;

// Modelクラスの定義（ModelerViewクラスを継承）
class Model : public ModelerView {
private:
	//～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～
	//第3週課題
	//---------------------------------------------------------------------

	// フレーム番号
	int frame_count;

	//-------------------------------------------------------------------------
	// 制御変数
	//-------------------------------------------------------------------------

		// ～～～変数を追加～～～
	double dt;
	double G;
	double r;

	double angle_prev;
	double angle_curr;
	double angle_next;

	Vec3d pos;


	//～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～


public:
	// コンストラクタ（スーパークラスのコンストラクタを呼び出す）
	Model( int x, int y, int w, int h, char* label ) : ModelerView( x, y, w, h, label )
	{
		//～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～
		//第3週課題
		//---------------------------------------------------------------------

		// フレーム番号の初期化
		frame_count = 0;

		//---------------------------------------------------------------------
		// 初期化
		//---------------------------------------------------------------------

			// ～～～変数を初期化～～～
		dt = 0.06;
		G = 9.8;
		r = 6.0;

		angle_prev = angle_curr = angle_next = M_PI / 4.0;

		pos = Vec3d( r*sin(angle_next), -r*cos(angle_next), 0);

		//～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～
	}

	//～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～
	//第3週課題
	//---------------------------------------------------------------------

	// 自動アニメーションの設定
	void SetAutomaticAnimation()
	{
		//-----------------------------------------------------------------
		// アニメーション
		//-----------------------------------------------------------------

			// ～～～プログラムを記述～～～
		angle_next = 2.0 * angle_curr - angle_prev - G * dt * dt / r * sin(angle_curr);

		angle_prev = angle_curr;
		angle_curr = angle_next;

		pos = Vec3d( r*sin(angle_next), -r*cos(angle_next), 0);

		//-----------------------------------------------------------------
	}

	// 手動アニメーションの設定
	void SetManualAnimation()
	{
		//-----------------------------------------------------------------
		// アニメーション
		//-----------------------------------------------------------------

			// ～～～プログラムを記述～～～

        angle_prev = angle_curr;
    	angle_curr = angle_next;

	    angle_next = 2 * angle_curr - angle_prev - (G / r) * sin(angle_curr) * dt * dt;


	    pos = Vec3d(r * sin(angle_next), -r * cos(angle_next), 0);
		//-----------------------------------------------------------------
	}

	//～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～


	// 描画の前処理
	void BeginPaint()
	{
		// 半透明処理を有効化
		glEnable( GL_BLEND );
		// 混合方法の指定
		glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	}

	// 描画の後処理
	void EndPaint()
	{
		// 半透明処理を無効化
		glDisable( GL_BLEND );
	}


	// オブジェクトの描画
	void draw()
	{
		//～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～
		//第3週課題
		//---------------------------------------------------------------------
		// 自動アニメーションの処理
		if ( IsAutomaticAnimation() && frame_count<max_frame_count ) {
			// フレーム番号の更新
			SetSliderValue( FRAME_CONTROLS, ++frame_count );
			// 自動アニメーション
			SetAutomaticAnimation();
		}
		// 手動アニメーションの処理
		else {
			// フレーム番号を取得
			frame_count = (int)GetSliderValue( FRAME_CONTROLS );
			// 手動アニメーション
			SetManualAnimation();
		}
		//～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～


		// スーパークラスの描画メソッドをコール（必須）
		ModelerView::draw();


		// 描画開始
		BeginPaint();

		//---------------------------------------------------------------------
		// オブジェクトを描画
		//---------------------------------------------------------------------

		 // ～～～プログラムを記述～～～
		 // 拡散反射光を設定

		// 環境光を設定
		setAmbientColor(0.5f, 0.5f, 0.5f);
		// 鏡面反射光を設定
		setSpecularColor(1.0f, 1.0f, 1.0f);
		// ハイライトの強さを設定
		setShininess(20.0f);

		glPushMatrix();
			setDiffuseColor( 0.5f, 0.3f, 0.0f, 1.0f );
			glTranslated(-5, -10, -5);
			drawBox(10, 0.2, 10);
		glPopMatrix();
		/*
		glTranslated( GetSliderValue( X_POSITION ), GetSliderValue( Y_POSITION ), GetSliderValue( Z_POSITION ) );

		glPushMatrix();
			setDiffuseColor(0.0f, 0.0f, 0.5f, 1.0f);

			Vec3d A(-2, -2, 0);

			Vec3d B(2, -2, 0);

			Vec3d C(0, 2, 0);

			// 法線ベクトルの計算

			Vec3d N = (A - C) ^ (B - C);

			// ポリゴンの描画

			glBegin(GL_TRIANGLES);

				glNormal3d(N[0], N[1], N[2]);

				glVertex3d(A[0], A[1], A[2]);

				glVertex3d(B[0], B[1], B[2]);

				glVertex3d(C[0], C[1], C[2]);

			glEnd();
		glPopMatrix();
		for ( int i=0; i<=10; i++ ) {
			glPushMatrix();
				glTranslated( i-5, 0, 0 );
				glRotated( i*9, 1, 0, 0 );
				drawCylinder( 2, 0.2, 0.2 );
			glPopMatrix();
		}
		*/
		glBegin( GL_LINES );
			glVertex3d( 0, 0, 0 );
			glVertex3d( pos[0], pos[1], pos[2] );
		glEnd();

		setDiffuseColor(0.0f, 0.0f, 0.5f, 1.0f);
		glTranslated( pos[0], pos[1], pos[2] );
		drawSphere( 0.5 );
		//---------------------------------------------------------------------

		// 描画終了
		EndPaint();
	}
};

// __MODEL_H__
#endif