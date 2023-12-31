add_cxxflags("-target x86_64-pc-windows-gnu")
add_ldflags("-target x86_64-pc-windows-gnu")
add_rules("mode.release", "mode.debug")
set_languages("c11", "c++17")

target("heap_test")
    set_kind("binary")
    add_includedirs("include/")
    add_files("test/heap_sort_test.cpp")

target("09")
    set_kind("binary")
    add_files("09.cpp")

target("12")
    set_kind("binary")
    add_files("12.cpp")

target("221")
    set_kind("binary")
    add_files("221.cpp")

target("38")
    set_kind("binary")
    add_files("38.cpp")

target("9")
    set_kind("binary")
    add_files("9.cpp")

target("exam")
    set_kind("binary")
    add_files("exam.cpp")

target("main")
    set_kind("binary")
    add_files("main.cpp")

target("t1")
    set_kind("binary")
    add_files("t1.cpp")

target("t2")
    set_kind("binary")
    add_files("t2.cpp")

target("tmp")
    set_kind("binary")
    add_files("tmp.cpp")

target("test")
    set_kind("binary")
    add_files("test.c")

--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro defination
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

