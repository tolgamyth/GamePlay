#include "framework/Base.h"
#include "renderer/Technique.h"
#include "renderer/Material.h"
#include "scene/Node.h"

namespace gameplay
{

  Technique::Technique(const char* id, std::shared_ptr<Material> material)
    : _id(id ? id : ""), _material(material)
  {
    RenderState::_parent = material;
  }

  Technique::~Technique()
  {
    // Destroy all the passes.
    //for (size_t i = 0, count = _passes.size(); i < count; ++i)
    //{
    //  SAFE_RELEASE(_passes[i]);
    //}
  }

  const char* Technique::getId() const
  {
    return _id.c_str();
  }

  unsigned int Technique::getPassCount() const
  {
    return (unsigned int)_passes.size();
  }

  std::shared_ptr<Pass> Technique::getPassByIndex(unsigned int index) const
  {
    assert(index < _passes.size());
    return _passes[index];
  }

  std::shared_ptr<Pass> Technique::getPass(const char* id) const
  {
    assert(id);

    for (size_t i = 0, count = _passes.size(); i < count; ++i)
    {
      std::shared_ptr<Pass> pass = _passes[i];
      assert(pass);
      if (strcmp(pass->getId(), id) == 0)
      {
        return pass;
      }
    }
    return nullptr;
  }

  void Technique::setNodeBinding(std::shared_ptr<Node> node)
  {
    RenderState::setNodeBinding(node);

    for (size_t i = 0, count = _passes.size(); i < count; ++i)
    {
      _passes[i]->setNodeBinding(node);
    }
  }

  std::shared_ptr<Technique> Technique::clone(std::shared_ptr<Material> material, NodeCloneContext& context) const
  {
    std::shared_ptr<Technique> technique = std::make_shared<Technique>(getId(), material);
    for (const auto& pass : _passes)
    {
      assert(pass);
      std::shared_ptr<Pass> passCopy = pass->clone(technique, context);
      assert(passCopy);
      technique->_passes.push_back(passCopy);
    }
    RenderState::cloneInto(technique, context);
    technique->_parent = material;
    return technique;
  }

}
