# Install script for directory: /home/decortja/bcl_clone/bcl/source

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "DynamicLibrary" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbcl.so.4.3.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbcl.so.4.3.0")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbcl.so.4.3.0"
         RPATH ".")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/decortja/bcl_clone/bcl/cmake-build-debug/lib/libbcl.so.4.3.0")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbcl.so.4.3.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbcl.so.4.3.0")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbcl.so.4.3.0"
         OLD_RPATH "/home/decortja/bcl_clone/bcl/extern/Linux2/x86_64/bzip2/1.0.5/lib:/home/decortja/bcl_clone/bcl/extern/Linux2/x86_64/zlib/1.2.5/lib:/home/decortja/bcl_clone/bcl/extern/Linux2/x86_64/freeocl/0.3.6/lib:"
         NEW_RPATH ".")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libbcl.so.4.3.0")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "DynamicLibrary" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/decortja/bcl_clone/bcl/cmake-build-debug/lib/libbcl.so")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/align/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/app/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/assemble/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/biol/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/bzip2/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/chemistry/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/cluster/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/command/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/contact/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/coord/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/crypt/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/density/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/descriptor/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/find/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/fold/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/function/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/graph/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/gzip/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/iterate/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/io/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/linal/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/math/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/mc/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/model/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/nmr/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/opencl/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/openblas/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/opti/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/pdb/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/pthread/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/quality/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/random/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/restraint/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/sched/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/score/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/scorestat/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/sdf/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/signal/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/sspred/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/storage/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/type/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/util/cmake_install.cmake")

endif()

