#pragma once

#include <vendor/gmock/gmock.h>

#include <core/natex/ISubsystemDefinitionRegistry.h>

namespace glove {

class MockSubsystemDefinitionRegistry : public ISubsystemDefinitionRegistry {
public:
    virtual ~MockSubsystemDefinitionRegistry() = default;

    MOCK_METHOD1(RegisterSubsystemDefinition, void(const ISubsystemDefinitionPtr& subsystemDefinition));
    MOCK_METHOD1(RegisterSubsystemType, void(const SubsystemType& subsystemType));

    MOCK_METHOD0(GetTopologicallySortedSubsystemDefinitions, SubsystemDefinitionList());
};

}