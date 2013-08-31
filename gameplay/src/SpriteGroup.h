#ifndef SPRITEGROUP_H_
#define SPRITEGROUP_H_

#include "Sprite.h"

namespace gameplay
{

/**
 * Defines a group of Sprites arranged in a 2D grid.
 */
class SpriteGroup : public Sprite
{

public:

	/**
     * The Sprite is transparent.
     */
    static const int TYPE_TRANSPARENT = 0;

	/**
     * The Sprite is the default Sprite defined by the SpriteGroup.
     */
    static const int TYPE_DEFAULT = 1;

	/**
     * The Sprite is child Sprite of this SpriteGroup.
     */
    static const int TYPE_CHILD = 2;

	/**
     * The gap between sprites animation property. Data=x,y
     */
	static const int ANIMATE_GAP = ANIMATE_TINT + 1;

	/**
     * The horizontal gap between sprites animation property. Data=x
     */
	static const int ANIMATE_GAP_HORZ = ANIMATE_GAP + 1;

	/**
     * The vertical gap between sprites animation property. Data=y
     */
	static const int ANIMATE_GAP_VERT = ANIMATE_GAP_HORZ + 1;

	/**
	 * Creates a new SpriteGroup for drawing.
	 * 
	 * @param id The ID for the new SpriteGroup.
	 * @param width The width (in number of sprites wide) of the SpriteGroup.
	 * @param height The height (in number of sprites tall) of the SpriteGroup.
	 * @param tileSheet The TileSheet that represents the tiles for this SpriteGroup.
	 * 
	 * @return A new SpriteGroup for drawing.
	 * @script{create}
	 */
	static SpriteGroup* create(const char* id, unsigned int width, unsigned int height, TileSheet* tileSheet);

	/**
     * Creates a SpriteGroup using the data from the Properties object defined at the specified URL, 
     * where the URL is of the format "<file-path>.<extension>#<namespace-id>/<namespace-id>/.../<namespace-id>"
     * (and "#<namespace-id>/<namespace-id>/.../<namespace-id>" is optional).
     * 
     * @param url The URL pointing to the Properties object defining the SpriteGroup.
	 * 
	 * @return A new SpriteGroup for drawing.
     * @script{create}
     */
	static SpriteGroup* create(const char* url);

	/**
     * Creates a SpriteGroup from the specified properties object.
     * 
     * @param spriteGroupProperties The properties object defining the sprite group 
	 *  (must have namespace equal to 'spritegroup').
	 * 
	 * @return A new SpriteGroup for drawing.
     * @script{create}
     */
	static SpriteGroup* create(Properties* spriteGroupProperties);

	/**
	 * Creates a new SpriteGroup for drawing.
	 * 
	 * @param id The ID for the new SpriteGroup.
	 * @param width The width (in number of sprites wide) of the SpriteGroup.
	 * @param height The height (in number of sprites tall) of the SpriteGroup.
	 * @param sprite A Sprite to copy for use as the default sprite for the 
	 *  SpriteGroup. Note: This does not use the Sprite, it mearly copies it.
	 * 
	 * @return A new SpriteGroup for drawing.
	 */
	static SpriteGroup* createFrom(const char* id, unsigned int width, unsigned int height, Sprite* sprite);

	/**
     * Get a named SpriteGroup from its ID.
     *
     * @param id The ID of the SpriteGroup to search for.
     *
     * @return The SpriteGroup with the specified ID, or NULL if one was not found.
     */
	static SpriteGroup* getSpriteGroup(const char* id);

	/**
     * Get the width of the the grid of the SpriteGroup.
     *
     * @return The SpriteGroup width.
     */
	unsigned int getGroupWidth() const;

	/**
     * Get the height of the the grid of the SpriteGroup.
     *
     * @return The SpriteGroup height.
     */
	unsigned int getGroupHeight() const;

	/**
	 * Gets the gap between Sprites in this SpriteGroup.
	 * 
	 * @return The gap between Sprites.
	 */
	Vector2 getGap() const;

	/**
	 * Sets the gap between Sprites in this SpriteGroup.
	 * 
	 * @param gap The gap between Sprites.
	 */
	void setGap(const Vector2& gap);

	/**
	 * Sets the gap between Sprites in this SpriteGroup.
	 * 
	 * @param x The gap horizontal between Sprites.
	 * @param y The gap vertical between Sprites.
	 */
	void setGap(float x, float y);

	/**
     * Get the horizontal gap between Sprites in this SpriteGroup.
     *
     * @return The horizontal gap between Sprites.
     */
	float getHorzGap() const;

	/**
     * Set the horizontal gap between Sprites in this SpriteGroup.
     *
     * @param gap The horizontal gap between Sprites.
     */
	void setHorzGap(float gap);

	/**
     * Get the vertical gap between Sprites in this SpriteGroup.
     *
     * @return The vertical gap between Sprites.
     */
	float getVertGap() const;

	/**
     * Set the vertical gap between Sprites in this SpriteGroup.
     *
     * @param gap The vertical gap between Sprites.
     */
	void setVertGap(float gap);

	/**
     * Get the type of sprite at the specified location within the SpriteGroup.
	 * 
	 * @param x The X position within the SpriteGroup.
	 * @param y The Y position within the SpriteGroup.
     *
     * @return The sprite type: TYPE_TRANSPARENT, TYPE_DEFAULT, TYPE_CHILD, or -1 on error.
     */
	int getSpriteType(unsigned int x, unsigned int y) const;

	/**
     * Set the type of sprite at the specified location within the SpriteGroup.
	 * 
	 * @param x The X position within the SpriteGroup.
	 * @param y The Y position within the SpriteGroup.
	 * @param type Either TYPE_TRANSPARENT or TYPE_DEFAULT for the specified sprite.
     *
     * @return true on success, false if TYPE_CHILD or any other type of sprite is used, or an error occurs.
     */
	bool setSpriteType(unsigned int x, unsigned int y, int type);

	/**
     * Get the sprite at the specified location within the SpriteGroup.
	 * 
	 * @param x The X position within the SpriteGroup.
	 * @param y The Y position within the SpriteGroup.
     *
     * @return "this" SpriteGroup if TYPE_DEFAULT, the sprite if TYPE_CHILD, or 
	 *  NULL if TYPE_TRANSPARENT or an error occured.
     */
	Sprite* getSprite(unsigned int x, unsigned int y);

	/**
     * Set the sprite at the specified location within the SpriteGroup.
	 * 
	 * @param x The X position within the SpriteGroup.
	 * @param y The Y position within the SpriteGroup.
	 * @param sprite NULL for a transparent sprite, "this" to set to default, or another Sprite to a child.
     *
     * @return true on success, false if an error occurs.
     */
	bool setSprite(unsigned int x, unsigned int y, Sprite* sprite);

	/**
	 * Draw the sprite group.
	 *
	 * @param isolateDraw If each draw call is unique and can't be batched. Batched calls 
	 *  have to be controlled by developer and are not handled internally. Technically, if 
	 *  this is true, this just calls start and finish on the TileSheet.
	 */
	virtual void draw(bool isolateDraw = true);

	/**
     * @see AnimationTarget::getAnimationPropertyComponentCount
     */
    virtual unsigned int getAnimationPropertyComponentCount(int propertyId) const;

    /**
     * @see AnimationTarget::getAnimationProperty
     */
    virtual void getAnimationPropertyValue(int propertyId, AnimationValue* value);

    /**
     * @see AnimationTarget::setAnimationProperty
     */
    virtual void setAnimationPropertyValue(int propertyId, AnimationValue* value, float blendWeight = 1.0f);

protected:

	/**
     * Constructor.
     */
    SpriteGroup(const char* id);

    /**
     * Destructor.
     */
    virtual ~SpriteGroup();

	/**
     * @see AnimationTarget::getPropertyId
     */
	virtual int getPropertyId(TargetType type, const char* propertyIdStr);

	/**
     * @see Sprite::clone
     */
    virtual Sprite* clone(NodeCloneContext &context);

	/**
     * Copies the data from this SpriteGroup into the given SpriteGroup.
     * 
     * @param group The SpriteGroup to copy the data to.
     * @param context The clone context.
     */
    void cloneInto(SpriteGroup* group, NodeCloneContext &context) const;

private:

    SpriteGroup(const SpriteGroup& copy);
    SpriteGroup& operator=(const SpriteGroup&);

	static bool parseGroup(SpriteGroup* group, Properties* spriteGroupProperties);

	std::string _path;

	unsigned int _groupWidth;
	unsigned int _groupHeight;

	std::map<unsigned int, Sprite*> _children;

protected:

	/**
	 * The horizontal gap between Sprites.
	 */
	float _horzGap;

	/**
	 * The vertical gap between Sprites.
	 */
	float _vertGap;

	/**
	 * When drawing, if an active camera exists, cull the map based on the frustum.
	 */
	bool _frustumCull;
};

}

#endif
