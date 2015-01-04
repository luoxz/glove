#pragma once

#include <map>

#include "core/GloveFwd.h"

#include "../Rendering.h"
#include "IVertexData.h"
#include "VertexLayout.h"

namespace glove {

/// @brief Represents static (non-modifiable) vertex data.
/// @ingroup RenderSubsystemInterface
///
/// While it is still possible to modify a buffer's data by invoking the buffer API directly it is *not* possible to
/// change StaticVertexData::vertexCount once created. See DynamicVertexData if you need to modify your data.
class StaticVertexData : public IVertexData {
  public:
    /// @param [in] vertexLayout The vertex layout to use. This will be copy-constructed to
    ///                          StaticVertexData::vertexLayout.
    /// @param [in] buffers A std::map mapping GPU buffer indices to actual IGpuBuffer instances. This will be
    ///                     copy-constructed to StaticVertexData::bufferBindingMap.
    StaticVertexData(const VertexLayout& vertexLayout, const VertexBufferBindingMap& buffers, std::size_t numVertices);
    virtual ~StaticVertexData() = default;

    virtual GLOVE_INLINE const std::size_t GetGpuBufferCount() const;
    virtual GLOVE_INLINE const IGpuBufferPtr& GetGpuBuffer(std::size_t index) const;
    virtual GLOVE_INLINE const VertexLayout& GetVertexLayout() const;
    virtual GLOVE_INLINE const std::size_t GetVertexCount() const;

    virtual void BindAllBuffers();

  protected:
    VertexBufferBindingMap bufferBindingMap;
    VertexLayout vertexLayout;

  private:
    size_t vertexCount;
};

} // namespace glove