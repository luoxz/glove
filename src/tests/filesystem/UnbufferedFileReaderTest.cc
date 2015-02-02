#include <vendor/gtest/gtest.h>

#include <core/filesystem/Path.hpp>
#include <core/filesystem/io/File.hpp>
#include <core/filesystem/io/UnbufferedFileReader.hpp>

namespace {
const glove::Path directoryPath("testdata/a_directory");
const glove::Path filePath("testdata/a_directory/a_file");
const glove::Path nonExistingPath("testdata/a_non_existing_directory");
}

namespace glove {

TEST(UnbufferedFileReaderTest, CanConstructFromFile) {
    File file(::filePath);
    UnbufferedFileReader reader(file);
}

TEST(FileTest, CanReadBytesFromFile) {
    File file(::filePath);
    UnbufferedFileReader reader(file);

    char character;
    reader.Read(&character, sizeof(char));

    EXPECT_EQ('G', character);
}

} /* namespace glove */