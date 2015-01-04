#include <core/internal/so/SoLoaderFactory.h>

#include <vendor/gtest/gtest.h>
#include <dlfcn.h>

namespace glove {

class SoLoaderFactoryTests : public ::testing::Test {
  protected:
    static const char* libraryFile;
};

const char* SoLoaderFactoryTests::libraryFile = "../lib/libtests_soloader_testlib.so";

TEST_F(SoLoaderFactoryTests, CanConstructSoLoader) {
    SoLoaderFactory factory;

    std::shared_ptr<ISharedLibraryLoader> loader;
    dlerror();
    ASSERT_NO_THROW(loader = factory.CreateLibraryLoader(libraryFile));
    ASSERT_EQ(nullptr, dlerror());
}
}