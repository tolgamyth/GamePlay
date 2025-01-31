#include "framework/Base.h"
#include "renderer/Technique.h"
#include "renderer/Material.h"
#include "scene/Node.h"
#include "renderer/Pass.h"

namespace gameplay
{

  Technique::Technique(const char* id, Material* material)
    : _id(id ? id : ""), _material(material)
  {
    RenderState::_parent = material;
  }

  Technique::~Technique()
  {
    // Destroy all the passes.
    for (size_t i = 0, count = _passes.size(); i < count; ++i)
    {
      SAFE_RELEASE(_passes[i]);
    }
  }

  const char* Technique::getId() const
  {
    return _id.c_str();
  }

  unsigned int Technique::getPassCount() const
  {
    return (unsigned int)_passes.size();
  }

  Pass* Technique::getPassByIndex(unsigned int index) const
  {
    assert(index < _passes.size());
    return _passes[index];
  }

  Pass* Technique::getPass(const char* id) const
  {
    assert(id);

    for (size_t i = 0, count = _passes.size(); i < count; ++i)
    {
      Pass* pass = _passes[i];
      assert(pass);
      if (strcmp(pass->getId(), id) == 0)
      {
        return pass;
      }
    }
    return nullptr;
  }

  void Technique::setNodeBinding(Node* node)
  {
    RenderState::setNodeBinding(node);

    for (size_t i = 0, count = _passes.size(); i < count; ++i)
    {
      _passes[i]->setNodeBinding(node);
    }
  }

  Technique* Technique::clone(Material* material, NodeCloneContext& context) const
  {
    Technique* technique = new Technique(getId(), material);
    for (const auto& pass : _passes)
    {
      assert(pass);
      technique->_passes.emplace_back(pass->clone(technique, context));
    }

    RenderState::cloneInto(technique, context);
    technique->_parent = material;
    return technique;
  }

}
