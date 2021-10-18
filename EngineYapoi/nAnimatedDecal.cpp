#include "nAnimatedDecal.h"

void YapoiEngine::nAnimatedDecal::Tick()
{
	_timeSinceLastSwitch += _engineRef->GetDeltaTime();
	if (_timeSinceLastSwitch > _timeBetweenAnims)
	{
		nextFrame();
		_timeSinceLastSwitch = 0;
	}
}

void YapoiEngine::nAnimatedDecal::nextFrame()
{
	if ((size_t)_currentFrame + 1 == _animationframes.size())
	{
		_currentFrame = 0;
		_currentimage = _animationframes[_currentFrame];
		UpdateRenderer(_currentimage);
		return;
	}
	else {
		_currentFrame++;
		_currentimage = _animationframes[_currentFrame];
		UpdateRenderer(_currentimage);
		return;
	}
}
