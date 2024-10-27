#include "framework/Base.h"
#include "renderer/Pass.h"
#include "renderer/Technique.h"
#include "renderer/Material.h"
#include "scene/Node.h"

namespace gameplay
{

Pass::Pass(const char* id, std::shared_ptr<Technique> technique) :
    _id(id ? id : ""), _technique(technique), _effect(nullptr), _vaBinding(nullptr)
{
    RenderState::_parent = std::dynamic_pointer_cast<RenderState>(
       std::make_shared<Technique>(id, std::dynamic_pointer_cast<Material>(_technique)));
}

Pass::~Pass()
{
    SAFE_RELEASE(_vaBinding);
}

bool Pass::initialize(const char* vshPath, const char* fshPath, const char* defines)
{
    assert(vshPath);
    assert(fshPath);

    SAFE_RELEASE(_vaBinding);

    // Attempt to create/load the effect.
    _effect = Effect::createFromFile(vshPath, fshPath, defines);
    if (_effect == nullptr)
    {
        GP_WARN("Failed to create effect for pass. vertexShader = %s, fragmentShader = %s, defines = %s", vshPath, fshPath, defines ? defines : "");
        return false;
    }

    return true;
}

const char* Pass::getId() const
{
    return _id.c_str();
}

Effect* Pass::getEffect() const
{
    return _effect.get();
}

void Pass::setVertexAttributeBinding(std::shared_ptr<VertexAttributeBinding> binding)
{
    if (binding)
    {
        _vaBinding = binding;
    }
}

std::shared_ptr<VertexAttributeBinding> Pass::getVertexAttributeBinding() const
{
    return _vaBinding;
}

void Pass::bind()
{
    assert(_effect);

    // Bind our effect.
    _effect->bind();

    // Bind our render state
    RenderState::bind(this);

    // If we have a vertex attribute binding, bind it
    if (_vaBinding)
    {
        _vaBinding->bind();
    }
}

void Pass::unbind()
{
    // If we have a vertex attribute binding, unbind it
    if (_vaBinding)
    {
        _vaBinding->unbind();
    }
}

std::shared_ptr<Pass> Pass::clone(std::shared_ptr<Technique> technique, NodeCloneContext &context) const
{
    assert(_effect);

    std::shared_ptr<Pass> pass = std::make_shared<Pass>(getId(), technique);
    pass->_effect = _effect;

    RenderState::cloneInto(pass, context);
    pass->_parent = technique;
    return pass;
}

}
