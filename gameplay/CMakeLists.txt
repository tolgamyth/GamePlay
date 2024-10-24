IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(GAMEPLAY_PLATFORM_SRC
            src/PlatformMacOSX.mm
            src/gameplay-main-macosx.mm
            )
else(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(GAMEPLAY_PLATFORM_SRC )
endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

set(GAMEPLAY_SRC
    ${GAMEPLAY_PLATFORM_SRC}
    ai/AIAgent.cpp
    ai/AIAgent.h
    ai/AIController.cpp
    ai/AIController.h
    ai/AIState.cpp
    ai/AIState.h
    ai/AIStateMachine.cpp
    ai/AIStateMachine.h
    animation/Animation.cpp
    animation/Animation.h
    animation/AnimationClip.cpp
    animation/AnimationClip.h
    animation/AnimationController.cpp
    animation/AnimationController.h
    animation/AnimationTarget.cpp
    animation/AnimationTarget.h
    animation/AnimationValue.cpp
    animation/AnimationValue.h
    animation/Joint.cpp
    animation/Joint.h
    audio/AudioBuffer.cpp
    audio/AudioBuffer.h
    audio/AudioController.cpp
    audio/AudioController.h
    audio/AudioListener.cpp
    audio/AudioListener.h
    audio/AudioSource.cpp
    audio/AudioSource.h
    framework/Base.h
    framework/FileSystem.cpp
    framework/FileSystem.h
    framework/gameplay-main-windows.cpp
    framework/Game.cpp
    framework/Game.h
    framework/Game.inl
    framework/Platform.cpp
    framework/Platform.h
    framework/ScreenDisplayer.cpp
    framework/ScreenDisplayer.h
    framework/Stream.cpp
    framework/Stream.h
    graphics/BoundingBox.cpp
    graphics/BoundingBox.h
    graphics/BoundingBox.inl
    graphics/BoundingSphere.cpp
    graphics/BoundingSphere.h
    graphics/BoundingSphere.inl
    graphics/Curve.cpp
    graphics/Curve.h
    graphics/Drawable.cpp
    graphics/Drawable.h
    graphics/Effect.cpp
    graphics/Effect.h
    graphics/Frustum.cpp
    graphics/Frustum.h
    graphics/HeightField.cpp
    graphics/HeightField.h
    graphics/Light.cpp
    graphics/Light.h
    graphics/Mesh.cpp
    graphics/Mesh.h
    graphics/MeshBatch.cpp
    graphics/MeshBatch.h
    graphics/MeshBatch.inl
    graphics/MeshPart.cpp
    graphics/MeshPart.h
    graphics/MeshSkin.cpp
    graphics/MeshSkin.h
    graphics/Model.cpp
    graphics/Model.h
    graphics/ParticleEmitter.cpp
    graphics/ParticleEmitter.h
    graphics/Plane.cpp
    graphics/Plane.h
    graphics/Plane.inl
    graphics/Ray.cpp
    graphics/Ray.h
    graphics/Ray.inl
    graphics/Rectangle.cpp
    graphics/Rectangle.h
    graphics/Sprite.cpp
    graphics/Sprite.h
    graphics/SpriteBatch.cpp
    graphics/SpriteBatch.h
    graphics/Terrain.cpp
    graphics/Terrain.h
    graphics/TerrainPatch.cpp
    graphics/TerrainPatch.h
    graphics/TileSet.cpp
    graphics/TileSet.h
    input/Gamepad.cpp
    input/Gamepad.h
    input/Gesture.h
    input/ImageControl.cpp
    input/ImageControl.h
    input/JoystickControl.cpp
    input/JoystickControl.h
    input/Keyboard.cpp
    input/Keyboard.h
    input/Mouse.cpp
    input/Mouse.h
    input/Touch.cpp
    input/Touch.h
    math/MathUtil.cpp
    math/MathUtil.h
    math/MathUtil.inl
    math/MathUtilNeon.inl
    math/Matrix.cpp
    math/Matrix.h
    math/Matrix.inl
    math/Quaternion.cpp
    math/Quaternion.h
    math/Quaternion.inl
    math/Transform.cpp
    math/Transform.h
    math/Vector2.cpp
    math/Vector2.h
    math/Vector2.inl
    math/Vector3.cpp
    math/Vector3.h
    math/Vector3.inl
    math/Vector4.cpp
    math/Vector4.h
    math/Vector4.inl
    physics/PhysicsCharacter.cpp
    physics/PhysicsCharacter.h
    physics/PhysicsCollisionObject.cpp
    physics/PhysicsCollisionObject.h
    physics/PhysicsCollisionShape.cpp
    physics/PhysicsCollisionShape.h
    physics/PhysicsConstraint.cpp
    physics/PhysicsConstraint.h
    physics/PhysicsController.cpp
    physics/PhysicsController.h
    physics/PhysicsFixedConstraint.cpp
    physics/PhysicsFixedConstraint.h
    physics/PhysicsGenericConstraint.cpp
    physics/PhysicsGenericConstraint.h
    physics/PhysicsGhostObject.cpp
    physics/PhysicsGhostObject.h
    physics/PhysicsHingeConstraint.cpp
    physics/PhysicsHingeConstraint.h
    physics/PhysicsRigidBody.cpp
    physics/PhysicsRigidBody.h
    physics/PhysicsSocketConstraint.cpp
    physics/PhysicsSocketConstraint.h
    physics/PhysicsSpringConstraint.cpp
    physics/PhysicsSpringConstraint.h
    physics/PhysicsVehicle.cpp
    physics/PhysicsVehicle.h
    physics/PhysicsVehicleWheel.cpp
    physics/PhysicsVehicleWheel.h
    renderer/Camera.cpp
    renderer/Camera.h
    renderer/DepthStencilTarget.cpp
    renderer/DepthStencilTarget.h
    renderer/Font.cpp
    renderer/Font.h
    renderer/FrameBuffer.cpp
    renderer/FrameBuffer.h
    renderer/Material.cpp
    renderer/Material.h
    renderer/RenderState.cpp
    renderer/RenderState.h
    renderer/RenderTarget.cpp
    renderer/RenderTarget.h
    renderer/Text.cpp
    renderer/Text.h
    renderer/Texture.cpp
    renderer/Texture.h
    renderer/VertexAttributeBinding.cpp
    renderer/VertexAttributeBinding.h
    renderer/VertexFormat.cpp
    renderer/VertexFormat.h
    scene/Bundle.cpp
    scene/Bundle.h
    scene/Node.cpp
    scene/Node.h
    scene/Properties.cpp
    scene/Properties.h
    scene/Scene.cpp
    scene/Scene.h
    scene/SceneLoader.cpp
    scene/SceneLoader.h
    scripting/Script.cpp
    scripting/Script.h
    scripting/ScriptController.cpp
    scripting/ScriptController.h
    scripting/ScriptController.inl
    scripting/ScriptTarget.cpp
    scripting/ScriptTarget.h
    ui/AbsoluteLayout.cpp
    ui/AbsoluteLayout.h
    ui/Button.cpp
    ui/Button.h
    ui/CheckBox.cpp
    ui/CheckBox.h
    ui/Container.cpp
    ui/Container.h
    ui/Control.cpp
    ui/Control.h
    ui/ControlFactory.cpp
    ui/ControlFactory.h
    ui/FlowLayout.cpp
    ui/FlowLayout.h
    ui/Form.cpp
    ui/Form.h
    ui/Image.cpp
    ui/Image.h
    ui/Image.inl
    ui/Label.cpp
    ui/Label.h
    ui/Layout.cpp
    ui/Layout.h
    ui/RadioButton.cpp
    ui/RadioButton.h
    ui/Slider.cpp
    ui/Slider.h
    ui/TextBox.cpp
    ui/TextBox.h
    ui/Theme.cpp
    ui/Theme.h
    ui/VerticalLayout.cpp
    ui/VerticalLayout.h
    utils/DebugNew.cpp
    utils/DebugNew.h
    utils/Logger.cpp
    utils/Logger.h
    utils/Ref.cpp
    utils/Ref.h
    utils/TimeListener.h
)

set(GAMEPLAY_RES
    res/logo_black.png
    res/logo_powered_black.png
    res/logo_powered_white.png
    res/logo_white.png
)

set(GAMEPLAY_RES_SHADERS
    res/shaders/colored.frag
    res/shaders/colored.vert
    res/shaders/font.frag
    res/shaders/font.vert
    res/shaders/form.frag
    res/shaders/form.vert
    res/shaders/lighting.frag
    res/shaders/lighting.vert
    res/shaders/skinning.vert
    res/shaders/skinning-none.vert
    res/shaders/sprite.frag
    res/shaders/sprite.vert
    res/shaders/terrain.frag
    res/shaders/terrain.vert
    res/shaders/textured.frag
    res/shaders/textured.vert
)

set(GAMEPLAY_RES_SHADERS
    res/ui/arial.gpb
    res/ui/default.png
    res/ui/default.theme
)

include_directories(
    src
    ../external-deps/include
)

IF(CMAKE_SYSTEM_NAME MATCHES "Linux")
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK2 REQUIRED gtk+-2.0)
include_directories(${GTK2_INCLUDE_DIRS})
add_definitions(${GTK2_CFLAGS_OTHER})
add_definitions(-D__linux__)
ENDIF(CMAKE_SYSTEM_NAME MATCHES "Linux")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    # using Clang
    add_definitions(-std=c++11 -stdlib=libc++)
else()
    add_definitions(-std=c++11)
    add_definitions(-lstdc++)
endif()

add_library(gameplay STATIC
    ${GAMEPLAY_SRC}
    ${GAMEPLAY_LUA}
)

set_target_properties(gameplay PROPERTIES
    OUTPUT_NAME "gameplay"
    CLEAN_DIRECT_OUTPUT 1
    VERSION ${GAMEPLAY_VERSION}
)

source_group(lua FILES ${GAMEPLAY_LUA})
source_group(res FILES ${GAMEPLAY_RES} ${GAMEPLAY_RES} ${GAMEPLAY_RES_SHADERS} ${GAMEPLAY_RES_UI})
source_group(src FILES ${GAMEPLAY_SRC})



