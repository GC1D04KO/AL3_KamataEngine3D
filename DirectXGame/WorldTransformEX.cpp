#include"WorldTransform.h"
#include "Hako.h"

void WorldTransform::UpdateMatrix() {

matWorld_=MakeAffineMatrix(scale_,rotation_,translation_);

TransferMatrix();

}