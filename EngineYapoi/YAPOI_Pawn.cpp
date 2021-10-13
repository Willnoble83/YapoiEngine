#include "YAPOI_Pawn.h"

bool YapoiEngine::nPawn::Initialise()
{
	_currentimage = "Resources/smiley.bmp";
	eSceneNode::Initialise();
	SetMovementSpeed(GetDefaultMoveSpeed());
	return true;
}

void YapoiEngine::nPawn::Move(vector2D Direction)
{
	AddVelocity(Direction * _moveSpeed, false);
}



bool YapoiEngine::nPawn::getDoesRender()
{
	return true;
}
