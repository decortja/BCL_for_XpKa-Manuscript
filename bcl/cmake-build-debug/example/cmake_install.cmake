# Install script for directory: /home/decortja/bcl_clone/bcl/example

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/align/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/assemble/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/biol/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/bzip2/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/chemistry/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/cluster/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/crypt/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/command/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/contact/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/coord/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/density/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/descriptor/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/find/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/fold/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/function/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/graph/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/gzip/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/io/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/iterate/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/linal/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/math/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/mc/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/model/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/nmr/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/openblas/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/opencl/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/opti/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/pdb/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/pthread/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/quality/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/random/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/restraint/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/sched/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/score/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/scorestat/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/sdf/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/signal/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/sspred/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/storage/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/type/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/util/cmake_install.cmake")
  include("/home/decortja/bcl_clone/bcl/cmake-build-debug/example/apps/cmake_install.cmake")

endif()

