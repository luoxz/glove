#include <vendor/gmock/gmock.h>

#include <glove/GloveFwd.hpp>
#include <glove/GloveCore.h>

namespace glove {
class MockGloveCore : public GloveCore {
public:
    MockGloveCore() : GloveCore(1, new const char*[1]{""}) {}

    MOCK_CONST_METHOD0(GetEventBus, const EventBusPtr&());
};
}