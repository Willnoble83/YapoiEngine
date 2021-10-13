#include "YAPOI_SceneNode.h"
#include "YAPOI_Renderer.h"


bool YapoiEngine::eSceneNode::Initialise()
{
	if (getDoesRender())
	{
		//std::cout << "Registering node to render" << std::endl;
		_renderInfoPtr = _rendererRef->RegisterRenderState(_name, RenderObject(_rendererRef->loadTexture(_currentimage), (int)_worldLocation._x, (int)_worldLocation._y, _renderPriority));
	}
	for (size_t i = 0; i < _children.size(); i++)
	{
		if (!(_children[i]->Initialise()))
		{
			return false;
		}
	}
	return true;
}

void YapoiEngine::eSceneNode::Tick()
{
	std::cout <<  "Velocity: " << _velocity.ToString() <<  " | Movement: " << (_velocity * _engineRef->GetDeltaTime()).ToString() << std::endl;
	Update(_velocity * _engineRef->GetDeltaTime());
	//std::cout << "Delta Time: " << _engineRef->GetDeltaTime();
	for (size_t i = 0; i < _children.size(); i++)
	{
		if (_children[i]->DoesTick())
		{
			_children[i]->Tick();
		}
	}
}

void YapoiEngine::eSceneNode::Update(vector2D change)
{
	//std::cout << _name << "received update!" << std::endl;
	_worldLocation = _worldLocation + change;
	if (getDoesRender())
	{
		UpdateRenderer(_currentimage);
	}
	for (size_t i = 0; i < _children.size(); i++)
	{
		_children[i]->Update(change);
	}
}

void YapoiEngine::eSceneNode::Shutdown(void)
{
	_rendererRef->RemoveRenderState(_name);
	for (size_t i = 0; i < _children.size(); i++)
	{
		_children[i]->Shutdown();
	}
	delete this;
}

void YapoiEngine::eSceneNode::ReceiveInput(SDL_Keycode Key, bool bKeyUp)
{
}

void YapoiEngine::eSceneNode::SetWorldLocation(vector2D newLoc)
{
	vector2D change = newLoc - _worldLocation;
	Update(change);
}

YapoiEngine::vector2D YapoiEngine::eSceneNode::AddVelocity(vector2D newVel, bool bOverride)
{
	if (getDoesRender())
	{
		if (bOverride)
		{
			_velocity = newVel;
			return _velocity;
		}
		else {
			_velocity += newVel;
			return _velocity;
		}
	}
	return _velocity;
}

void YapoiEngine::eSceneNode::UpdateRenderer(const std::string& file)
{
	if (getDoesRender())
	{
		if (_renderInfoPtr != nullptr)
		{
			//std::cout << _name << " Updating Renderer with info: (tex file, x, y): " << file << "," << _worldLocation._x << "," << _worldLocation._y << std::endl;
			_renderInfoPtr->_texture =  _rendererRef->loadTexture(file);
			_renderInfoPtr->_x = (int)_worldLocation._x;
			_renderInfoPtr->_y = (int)_worldLocation._y;
		}

	}
}

void YapoiEngine::eSceneNode::UpdateRenderPriority(int newPrio)
{
	_renderPriority = newPrio;
	_renderInfoPtr->_renderpriority = newPrio;
	_rendererRef->newRenderPriority(newPrio);
}


void YapoiEngine::eSceneNode::Add(eSceneNode* node, EngineModuleRefs modules)
{
	_children.push_back(node);
	node->_rendererRef = modules.rendererRef;
	node->_engineRef = modules.engineRef;
	node->_worldRef = modules.worldRef;
	node->_inputmanageRef = modules.inputmanageRef;
}

void YapoiEngine::eSceneNode::Remove(eSceneNode* node)
{
	for (size_t i = 0; i < _children.size(); i++)
	{
		if (_children[i] == node)
		{
			_children.erase(_children.begin() + i);
			break;
		}
		else {
			_children[i]->Remove(node);
		}
	}
}

YapoiEngine::eSceneNode* YapoiEngine::eSceneNode::Find(std::string name)
{
	if (name == _name)
	{
		return this;
	}
	for (size_t i = 0; i < _children.size(); i++)
	{
		eSceneNode* ptr = _children[i]->Find(name);
		if (ptr != nullptr)
		{
			return ptr;
		}
	}
	return nullptr;
}

bool YapoiEngine::eSceneNode::DoesTick()
{
	return bDoesTick;
}

