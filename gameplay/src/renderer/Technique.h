#pragma once

#include "renderer/Pass.h"

namespace gameplay
{

  class Material;
  class NodeCloneContext;

  /**
   * Defines a technique for how an object to be rendered.
   *
   * You should use techniques to support different sets of
   * shader + definitions that will be all loaded when a material
   * is loaded. You can then change the rendering technique at
   * runtime without having to first load the shaders.
   *
   * A technique has one or more passes for supporting multi pass rendering.
   */
  class Technique : public RenderState
  {
    friend class Material;
    friend class Pass;
    friend class RenderState;

  public:

    /**
     * Constructor.
     */
    Technique(const char* id, std::shared_ptr<Material> material);

    /**
     * Destructor.
     */
    ~Technique();

    /**
     * Gets the id of this technique.
     *
     * @return The Id of this technique.
     */
    const char* getId() const;

    /**
     * Gets the number of passes in this technique.
     *
     * @return The number of passes in this technique.
     */
    unsigned int getPassCount() const;

    /**
     * Gets the pass at the specified index.
     *
     * @return The pass at the specified index.
     */
    std::shared_ptr<Pass> getPassByIndex(unsigned int index) const;

    /**
     * Gets the pass with the specified id.
     *
     * @return The pass at the specified id.
     */
    std::shared_ptr<Pass> getPass(const char* id) const;

    /**
     * @see RenderState::setNodeBinding
     */
    void setNodeBinding(std::shared_ptr<Node> node);

  private:

    /**
     * Hidden copy constructor.
     */
    Technique(const Technique&);

    /**
     * Hidden copy assignment operator.
     */
    Technique& operator=(const Technique&);

    std::shared_ptr<Technique> clone(std::shared_ptr<Material> material, NodeCloneContext& context) const;

    std::string _id;
    std::shared_ptr<Material> _material;
    std::vector<std::shared_ptr<Pass>> _passes;
  };

}
