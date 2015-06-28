#include <zlib.h>
#include <png.h>
#include <boost/version.hpp>

#include "glove/natex/Natex.hpp"
#include "glove/GloveConfig.hpp"

#include "DwarfCore.hpp"

namespace BlueDwarf {

DwarfCore::DwarfCore(const Configuration& engineConfig, const ServiceRegistryHandle& serviceRegistry,
                     const std::vector<ModuleHandle>& loadedModules)
    : engineConfiguration(engineConfig), serviceRegistry(serviceRegistry), loadedModules(loadedModules) {
    logger.Info(fmt::format("Creating DwarfCore version {0}", BD_VERSION_STRING));

    logger.Info(fmt::format("Using ZLIB {0}", ZLIB_VERSION));
    logger.Info(fmt::format("Using libPng {0}", PNG_LIBPNG_VER_STRING));
    logger.Info(fmt::format("Using Boost {0}.{1}.{2}", (BOOST_VERSION / 100000), ((BOOST_VERSION / 100) % 1000), (BOOST_VERSION % 100)));
}
} /* namespace BlueDwarf */