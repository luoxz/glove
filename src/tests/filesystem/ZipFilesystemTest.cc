#include <gtest/gtest.hpp>

#include <glove/filesystem/Path.hpp>
#include <glove/filesystem/compression/ZipArchive.hpp>
#include "glove/DwarfException.hpp"
#include <glove/filesystem/compression/ZipFilesystem.hpp>
#include <glove/filesystem/Filesystem.hpp>
#include <glove/exceptions/OperationNotSupported.hpp>

namespace {
const BlueDwarf::Path zipFile("testdata/testzip.zip");
}

namespace BlueDwarf {

TEST(ZipFilesystemTest, CanConstructFromZipArchive) {
    ZipArchiveHandle archive(new ZipArchive(zipFile));
    ZipFilesystem zipFs(archive);
}

TEST(ZipFilesystemTest, CanConstructFromZipPathAndFilesystem) {
    ZipFilesystem zipFs(zipFile, FilesystemHandle(new NativeFilesystemAccessor()));
}

TEST(ZipFilesystemTest, CanQueryFileInformation) {
    ZipArchiveHandle archive(new ZipArchive(zipFile));
    ZipFilesystem zipFs(archive);

    FileInfo dirInfo = zipFs.GetFileInfo(Path("testdir/"));
    EXPECT_EQ(FileInfo::FileType::DIRECTORY, dirInfo.GetType());

    FileInfo fileInfo = zipFs.GetFileInfo(Path("testfile.txt"));
    EXPECT_EQ(FileInfo::FileType::REGULAR, fileInfo.GetType());
}

TEST(ZipFilesystemTest, CanCreateReadStreams) {
    ZipArchiveHandle archive(new ZipArchive(zipFile));
    ZipFilesystem zipFs(archive);

    typedef std::unique_ptr<std::istream> StreamHandle;
    StreamHandle stream = StreamHandle(zipFs.CreateFileReadStream(Path("testfile.txt")));

    char* destination = new char[6];
    stream->read(destination, 5);
    destination[5] = '\0';

    EXPECT_STREQ("Hello", destination);
}

TEST(ZipFilesystemTest, CannotCreateWriteStreams) {
    ZipArchiveHandle archive(new ZipArchive(zipFile));
    ZipFilesystem zipFs(archive);

    EXPECT_THROW(zipFs.CreateFileWriteStream(Path()), OperationNotSupportedException);
}

} /* namespace BlueDwarf */