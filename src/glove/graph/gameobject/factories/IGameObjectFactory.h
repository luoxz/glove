#pragma once

#include "glove/graph/Graph.h"

namespace glove {

class IGameObjectFactory {
public:
    virtual ~IGameObjectFactory() = default;

    virtual GameObjectHandle Create() = 0;
};

}