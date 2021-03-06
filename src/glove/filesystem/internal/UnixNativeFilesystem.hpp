#pragma once

#if defined(ON_UNIX)
#include <sys/stat.h>
#include <string>

#include "glove/BlueDwarfFwd.hpp"
#include "glove/filesystem/FileInfo.hpp"
#include "glove/filesystem/IFilesystem.hpp"
#include "glove/filesystem/Path.hpp"

namespace BlueDwarf {

/// A UNIX/POSIX native filsystem abstraction layer with the ability to be rooted to a specific directory.
/// The root directory path will be prepended to all filesystem queries.
/// E.g.: \code{.cpp}
/// UnixNativeFilesystem filesystem("/opt/install")
/// Path aPath("/somefile");
/// filesystem.GetFileInfo(aPath); // Will actually be executed on "/opt/install/somefile"
/// \endcode
/// The filesystem root defaults to the executable's directory.
class UnixNativeFilesystem : public IFilesystem {
public:
    UnixNativeFilesystem();
    UnixNativeFilesystem(const std::string& nativeRoot);

    /// Translates \p path to the corresponding native filesystem path
    Path MakePathNativeAbsolute(const Path& path);

    virtual const FileInfo GetFileInfo(const Path& path) override;
    virtual std::istream* CreateFileReadStream(const Path& path) override;
    virtual std::ostream* CreateFileWriteStream(const Path& path) override;

private:
    std::string nativeRoot;
};

} /* namespace BlueDwarf */
#endif