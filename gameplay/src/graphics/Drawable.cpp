#include "framework/Base.h"
#include "graphics/Drawable.h"
#include "scene/Node.h"


namespace gameplay
{

Drawable::Drawable()
    : _node(nullptr)
{
}

Drawable::~Drawable()
{
}

std::shared_ptr<Node> Drawable::getNode() const
{
    return _node;
}

void Drawable::setNode(std::shared_ptr<Node> node)
{
    _node = node;
}

}
