# Install script for directory: /home/decortja/bcl_clone/bcl

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

if(CMAKE_INSTALL_COMPONENT STREQUAL "BclReleaseAll" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE RENAME "bzip2License.txt" FILES "/home/decortja/bcl_clone/bcl/extern/noarch/bzip2/LICENSE.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "BclReleaseAll" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE RENAME "libbz2.so.1.0" FILES "/home/decortja/bcl_clone/bcl/extern/Linux2/x86_64/bzip2/1.0.5/lib/libbz2.so")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "BclReleaseAll" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE RENAME "zlibLicense.txt" FILES "/home/decortja/bcl_clone/bcl/extern/noarch/zlib/LICENSE.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "BclReleaseAll" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE RENAME "libz.so.1" FILES "/home/decortja/bcl_clone/bcl/extern/Linux2/x86_64/zlib/1.2.5/lib/libz.so")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "BclReleaseAll" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE RENAME "freeoclLicense.txt" FILES "/home/decortja/bcl_clone/bcl/extern/noarch/freeocl/LICENSE.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "BclReleaseAll" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE RENAME "libOpenCL.so.1" FILES "/home/decortja/bcl_clone/bcl/extern/Linux2/x86_64/freeocl/0.3.6/lib/libOpenCL.so")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "BclReleaseAll" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE RENAME "libstdc++.so.6" FILES "/usr/lib64/libstdc++.so.6.0.19")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "BclReleaseAll" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE RENAME "libgcc_s.so.1" FILES "/usr/lib64/libgcc_s-4.8.5-20150702.so.1")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "BclReleaseAll" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE DIRECTORY FILES "/home/decortja/bcl_clone/bcl/histogram")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "BclReleaseAll" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/model" TYPE DIRECTORY FILES "/home/decortja/bcl_clone/bcl/model/jufo")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "BclReleaseAll" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE DIRECTORY FILES "/home/decortja/bcl_clone/bcl/opencl_kernels")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "BclReleaseAll" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE DIRECTORY FILES "/home/decortja/bcl_clone/bcl/rotamer_library")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "BclLicense" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "/home/decortja/bcl_clone/bcl/installer/License.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "BclReleaseAll" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE RENAME "ReadMe.txt" FILES "/home/decortja/bcl_clone/bcl/installer/ReadMe_Linux.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/source/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/apps/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/decortja/bcl_clone/bcl/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
