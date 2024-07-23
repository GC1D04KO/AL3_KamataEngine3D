#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <vector>
#include "Player.h"
#include "DebugCamera.h"
#include "MapChipField.h"
#include "CameraController.h"
#include "Skydome.h"
#include "Enmey.h"
#include "list"
#include"DeathParticles.h"

/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

bool IsFinished() const { return finished_; };

private: // メンバ変数

	enum class Phase {
		kPlay,//ゲームプレイヤ
		kDeath
	};

	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>
	// ビュープロジェクション
	ViewProjection viewProjection_;
	// テクスチャハンドル
	uint32_t textureHandle_ = 0;
	// 自キャラ
	Player* player_ = nullptr;
	Enemy* enemy_ = nullptr;
	// モデルデータ
	Model* modelPlayer_ = nullptr;
	Model* modelBlock_ = nullptr;
	Model* modelSkydome_ = nullptr;
	Model* modelEnemy_ = nullptr;
	Model* modelDeathParticle_ = nullptr;
	std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;
	WorldTransform worldTransformSkydome_;
	// デバッグカメラ
	DebugCamera* debugCamera_ = nullptr;
	// デバッグカメラ有効
	bool isDebugCameraActive_ = false;
	// マップチップフィールド
	MapChipField* mapChipField_=nullptr;
	CameraController* cameraController = nullptr;

	std::list<Enemy*> enemies_;
	Enemy* newEnemy_ = nullptr;

	bool finished_ = false;
	Phase phase_= Phase::kPlay;

	DeathParticles* deathParticles_ = nullptr;

	void ChangePhase();

	void GenerateBlocks();

	void UpdateCamera();

	void UpdateBlocks();

	// 衝突判定と応答

	void CheckAllCollisions();

};
