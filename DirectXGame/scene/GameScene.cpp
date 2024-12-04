#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>

GameScene::GameScene() { 

	/*delete sprite_;*/

	delete model_;

    delete debugCamera_;
}

GameScene::~GameScene() {}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	textureHandle_ = TextureManager::Load("mario.jpg");

	/*sprite_ = Sprite::Create(textureHandle_, {});*/


	model_ = Model::Create();

	//ウールドトランスフォーム 初期化
	worldTransform_.Initialize();


	////ビュープロジェクション初期化
	viewProjection_.Initialize();


 //デバッグカメラの生成
	debugCamera_ =new DebugCamera(400,400);
	
}


void GameScene::Update() {

	debugCamera_->Update();


}

void GameScene::Draw() {


	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>
	
	/*sprite_->Draw();*/

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	//3Dモデル描画


	/*model_->Draw(worldTransform_, viewProjection_, textureHandle_);*/
	model_->Draw(worldTransform_, debugCamera_->GetViewProjection(), textureHandle_);


	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}

