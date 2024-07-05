#include "Skyedome.h"
#include "WorldTransform.h"
#include "ViewProjection.h" 



void Skyedome::Initialize(Model*model,ViewProjection* viewProjection){

  worldTransform_.Initialize();

	 model_ = model;

	viewProjection_ = viewProjection;
};

void Skyedome::Update(){

};

void Skyedome::Draw(){

 model_->Draw(worldTransform_,*viewProjection_);
 };