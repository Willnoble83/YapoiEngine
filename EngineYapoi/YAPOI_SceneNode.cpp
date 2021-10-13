#include "YAPOI_SceneNode.h"
#include "YAPOI_Renderer.h"


bool YapoiEngine::eSceneNode::Initialise(mRenderer* Renderer)
{
	_rendererRef = Renderer;
	for (size_t i = 0; i < _children.size(); i++)
	{
		if (!(_children[i]->Initialise(Renderer)))
		{
			return false;
		}
	}
	return true;
}

void YapoiEngine::eSceneNode::Update(vector2D change)
{
	_worldLocation = _worldLocation + change;
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

void YapoiEngine::eSceneNode::UpdateRenderer(const std::string& file)
{
	SDL_Texture* Tex =  _rendererRef->loadTexture(file);
	_rendererRef->UpdateRenderState(_name, RenderObject(Tex, (int)_worldLocation._x, (int)_worldLocation._y, _renderPriority));
}


void YapoiEngine::eSceneNode::Add(eSceneNode* node)
{
	_children.push_back(node);
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

