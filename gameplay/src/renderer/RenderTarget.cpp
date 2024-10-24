#include "framework/Base.h"
#include "renderer/RenderTarget.h"

namespace gameplay
{

static std::vector<RenderTarget*> __renderTargets;

RenderTarget::RenderTarget(const char* id)
    : _id(id ? id : ""), _texture(nullptr)
{
}

RenderTarget::~RenderTarget()
{
    SAFE_RELEASE(_texture);

    // Remove ourself from the cache.
    std::vector<RenderTarget*>::iterator it = std::find(__renderTargets.begin(), __renderTargets.end(), this);
    if (it != __renderTargets.end())
    {
        __renderTargets.erase(it);
    }
}

RenderTarget* RenderTarget::create(const char* id, unsigned int width, unsigned int height, Texture::Format format)
{
    // Create a new texture with the given width.
    Texture* texture = Texture::create(format, width, height, nullptr, false);
    if (texture == nullptr)
    {
        GP_ERROR("Failed to create texture for render target.");
        return nullptr;
    }

    RenderTarget* rt = create(id, texture);
    texture->release();

    return rt;
}

RenderTarget* RenderTarget::create(const char* id, Texture* texture)
{
    RenderTarget* renderTarget = new RenderTarget(id);
    renderTarget->_texture = texture;
    renderTarget->_texture->addRef();

    __renderTargets.push_back(renderTarget);

    return renderTarget;
}

RenderTarget* RenderTarget::getRenderTarget(const char* id)
{
    assert(id);

    // Search the vector for a matching ID.
    std::vector<RenderTarget*>::const_iterator it;
    for (it = __renderTargets.begin(); it < __renderTargets.end(); ++it)
    {
        RenderTarget* dst = *it;
        assert(dst);
        if (strcmp(id, dst->getId()) == 0)
        {
            return dst;
        }
    }

    return nullptr;
}

const char* RenderTarget::getId() const
{
    return _id.c_str();
}

Texture* RenderTarget::getTexture() const
{
    return _texture;
}

unsigned int RenderTarget::getWidth() const
{
    return _texture->getWidth();
}

unsigned int RenderTarget::getHeight() const
{
    return _texture->getHeight();
}

}
